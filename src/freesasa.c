/*
  Copyright Simon Mitternacht 2013-2015.

  This file is part of FreeSASA.

  FreeSASA is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  FreeSASA is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with FreeSASA.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <sys/time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <assert.h>
#include <math.h>
#include <errno.h>
#if HAVE_CONFIG_H
# include <config.h>
#endif

#include "structure.h"
#include "sasa.h"
#include "pdb.h"
#include "freesasa.h"
#include "srp.h"
#include "classify.h"

#define NBUF 100
#define DEF_NTHREADS 1

#ifdef PACKAGE_NAME
const char *freesasa_name = PACKAGE_NAME;
#else
const char *freesasa_name = "freesasa";
#endif
#ifdef PACKAGE_VERSION
const char *freesasa_version = PACKAGE_VERSION;
#else
const char *freesasa_version = "";
#endif

// to control error messages (used for debugging and testing)
static freesasa_verbosity verbosity;

const freesasa_parameters freesasa_default_parameters = {
    .alg = FREESASA_SHRAKE_RUPLEY,
    .probe_radius = FREESASA_DEF_PROBE_RADIUS,
    .shrake_rupley_n_points = FREESASA_DEF_SR_N,
    .lee_richards_delta = FREESASA_DEF_LR_D,
    .n_threads = DEF_NTHREADS,
};

const char *freesasa_alg_names[] = {"Lee & Richards", "Shrake & Rupley"};

freesasa_strvp* freesasa_strvp_new(int n);

static void freesasa_err_impl(int err, const char *format, va_list arg)
{
    fprintf(stderr, "%s: ", freesasa_name);
    switch (err) {
    case FREESASA_FAIL: fputs("error: ", stderr); break;
    case FREESASA_WARN: fputs("warning: ", stderr); break;
    default: break;
    }
    vfprintf(stderr, format, arg);
    va_end(arg);
    fputc('\n', stderr);
    fflush(stderr);
}

int freesasa_fail(const char *format,...)
{
    va_list arg;
    if (verbosity == FREESASA_V_SILENT) return FREESASA_FAIL;
    va_start(arg, format);
    freesasa_err_impl(FREESASA_FAIL,format,arg);
    va_end(arg);
    return FREESASA_FAIL;
}

int freesasa_warn(const char *format,...)
{
    va_list arg;
    if (verbosity == FREESASA_V_NOWARNINGS ||
        verbosity == FREESASA_V_SILENT) return FREESASA_WARN;
    va_start(arg, format);
    freesasa_err_impl(FREESASA_WARN,format,arg);
    va_end(arg);
    return FREESASA_WARN;
}

freesasa_strvp* freesasa_result_classify(const freesasa_result *result, 
                                         const freesasa_structure *structure,
                                         const freesasa_classifier *c) 
{
    assert(structure);

    int n_atoms;
    int n_classes;
    freesasa_strvp *strvp;
    const freesasa_classifier *classifier = c;
    if (c == NULL) classifier = &freesasa_default_classifier;

    n_atoms = freesasa_structure_n(structure);
    n_classes = classifier->n_classes;
    strvp = freesasa_strvp_new(n_classes);
    assert(strvp);
    for(int i = 0; i < n_classes; ++i) {
        strvp->string[i] = strdup(classifier->class2str(i,classifier));
        strvp->value[i] = 0;
    }
    for (int i = 0; i < n_atoms; ++i) {
        const char *res_name = freesasa_structure_atom_res_name(structure,i);
        const char *atom_name = freesasa_structure_atom_name(structure,i);
        int c = classifier->sasa_class(res_name,atom_name,classifier);
        strvp->value[c] += result->sasa[i];
    }
    return strvp;
}

void freesasa_result_free(freesasa_result *r)
{
    if (r) {
        free(r->sasa);
        free(r);
    }
}

static freesasa_result* freesasa_calc(const freesasa_coord *c, 
                                      const double *radii,
                                      const freesasa_parameters *parameters)

{
    assert(c);
    assert(radii);

    freesasa_result *result = malloc(sizeof(freesasa_result));
    int ret;
    const freesasa_parameters *p = parameters;
    if (p == NULL) p = &freesasa_default_parameters;

    //struct timeval t1, t2;
    //gettimeofday(&t1,NULL);
    
    
    result->sasa = malloc(sizeof(double)*freesasa_coord_n(c));
    assert(result->sasa);
    result->n_atoms = freesasa_coord_n(c);

    switch(p->alg) {
    case FREESASA_SHRAKE_RUPLEY:
        ret = freesasa_shrake_rupley(result->sasa, c, radii,
                                     p->probe_radius,
                                     p->shrake_rupley_n_points, 
                                     p->n_threads);
        break;
    case FREESASA_LEE_RICHARDS:
        ret = freesasa_lee_richards(result->sasa, c, radii,
                                    p->probe_radius,
                                    p->lee_richards_delta, 
                                    p->n_threads);
        break;
    default:
        assert(0); //should never get here
        break;
    }
    result->total = 0;
    for (int i = 0; i < freesasa_coord_n(c); ++i) {
        result->total += result->sasa[i];
    }

    //gettimeofday(&t2,NULL);
    //s->elapsed_time = (t2.tv_sec-t1.tv_sec);
    //s->elapsed_time += (t2.tv_usec-t1.tv_usec) / 1e6; // s

    if (ret == FREESASA_FAIL) {
        freesasa_result_free(result);
        return NULL;
    }

    return result;
}

freesasa_result* freesasa_calc_coord(const double *xyz, 
                                     const double *radii,
                                     int n,
                                     const freesasa_parameters *parameters)
{
    assert(xyz);
    assert(radii);
    // We don't want to store the supplied parameters (to allow const-ness),
    // and want to make sure user doesn't access outdated parameters
    freesasa_coord *c = freesasa_coord_new_linked(xyz,n);
    freesasa_result *result = freesasa_calc(c,radii,parameters);
    freesasa_coord_free(c);

    return result;
}
freesasa_result* freesasa_calc_structure(const freesasa_structure* structure,
                                         const double *radii,
                                         const freesasa_parameters* parameters)
{
    assert(structure);
    assert(radii);

    return freesasa_calc(freesasa_structure_xyz(structure),
                         radii,parameters);
}

double* freesasa_structure_radius(const freesasa_structure *structure,
                                  const freesasa_classifier *classifier)
{
    assert(structure);

    int n = freesasa_structure_n(structure);
    double *r = malloc(sizeof(double)*n);
    const freesasa_classifier *c = classifier;

    if (c == NULL) c = &freesasa_default_classifier;

    for (int i = 0; i < n; ++i) {
        const char *res_name = 
            freesasa_structure_atom_res_name(structure, i);
        const char *atom_name = 
            freesasa_structure_atom_name(structure, i);
        r[i] = c->radius(res_name,atom_name,c);
        if (r[i] < 0) {
            free(r);
            return NULL;
        }
    }
    return r;
}

int freesasa_log(FILE *log, 
                 freesasa_result *result,
                 const char *name,
                 const freesasa_parameters *parameters,
                 const freesasa_strvp* class_area)
{
    assert(log);

    const freesasa_parameters *p = parameters;
    if (p == NULL) p = &freesasa_default_parameters;

    // Using errno to check for fprintf-errors. Perhaps not completely
    // portable, but makes function a lot simpler than checking every
    // return value. 
    errno = 0;

    if (name == NULL) fprintf(log,"name: unknown\n");
    else              fprintf(log,"name: %s\n",name);

    fprintf(log,"n_atoms: %d\n",result->n_atoms);

    fprintf(log,"algorithm: %s\nprobe-radius: %f A\n",
            freesasa_alg_names[p->alg],
            p->probe_radius);
    if(HAVE_LIBPTHREAD) {
        fprintf(log,"n_thread: %d\n",p->n_threads);
    }
    switch(p->alg) {
    case FREESASA_SHRAKE_RUPLEY:
        fprintf(log,"n_testpoint: %d\n",p->shrake_rupley_n_points);
        break;
    case FREESASA_LEE_RICHARDS:
        fprintf(log,"d_slice: %f Å\n",p->lee_richards_delta);
        break;
    default:
        assert(0);
        break;
    }
    if (class_area == NULL) {
        fprintf(log,"\nTotal: %9.2f A2\n",result->total);
    } else {
        int m = 6;
        char fmt[21];
        for (int i = 0; i < class_area->n; ++i) {
            int l = strlen(class_area->string[i]);
            m = (l > m) ? l : m;
        }
        sprintf(fmt," %%%ds: %%10.2f A2\n",m);
        fprintf(log,"\n");
        fprintf(log,fmt,"Total",result->total);
        for (int i = 0; i < class_area->n; ++i) {
            fprintf(log,fmt,
                    class_area->string[i],
                    class_area->value[i]);
        }
    } 
    if (errno != 0) { 
        return freesasa_fail("%s: %s",__func__,strerror(errno));
    }
    return FREESASA_SUCCESS;
}


int freesasa_per_residue_type(FILE *output, 
                              freesasa_result *result,
                              const freesasa_structure *structure)
{
    assert(output);
    assert(structure);

    const freesasa_classifier *c = &freesasa_residue_classifier;
    freesasa_strvp *residue_area
        = freesasa_result_classify(result,structure,c);

    for (int i = 0; i < c->n_classes; ++i) {
        double sasa = residue_area->value[i];
        int result = 0;
        errno = 0;
        if (i < 20 || sasa > 0) {
            result = fprintf(output,"RES: %s %9.2f\n",
                             residue_area->string[i],sasa);
        }
        if (result < 0) {
            freesasa_strvp_free(residue_area);
            return freesasa_fail("%s: %s", __func__,strerror(errno));
        }
    }
    freesasa_strvp_free(residue_area);
    return FREESASA_SUCCESS;
}


static double freesasa_single_residue_sasa(const freesasa_result *r,
                                           const freesasa_structure *s, 
                                           int r_i)
{
    assert(r);
    assert(s);
    
    int first, last;
    const double *sasa = r->sasa;            
    double a = 0;
    
    freesasa_structure_residue_atoms(s,r_i,&first,&last);
    
    for (int j = first; j <= last; ++j) {
        a += sasa[r_i];
    }        
    return a;
}


int freesasa_per_residue(FILE *output,
                         freesasa_result *result,
                         const freesasa_structure *structure)
{
    assert(output);
    assert(structure);
    
    const int naa = freesasa_structure_n_residues(structure);
    for (int i = 0; i < naa; ++i) {
        errno = 0;
        int area =
            fprintf(output,"SEQ: %s %7.2f\n",
                    freesasa_structure_residue_descriptor(structure,i),
                    freesasa_single_residue_sasa(result,structure,i));
        if (area < 0)
            return freesasa_fail("%s: %s", __func__,strerror(errno));
    }
    return FREESASA_SUCCESS;
}

freesasa_strvp* freesasa_strvp_new(int n)
{
    freesasa_strvp* svp = malloc(sizeof(freesasa_strvp));
    assert(svp);
    svp->value = malloc(sizeof(double)*n);
    svp->string = malloc(sizeof(char*)*n);
    assert(svp->value && svp->string);
    svp->n = n;
    return svp;
}

void freesasa_strvp_free(freesasa_strvp *svp)
{
    if (svp) {
        if (svp->value) free(svp->value);
        if (svp->string) {
            for (int i = 0; i < svp->n; ++i) {
                if (svp->string[i]) free(svp->string[i]);
            }
            free(svp->string);
        }
        free(svp);
    }
}

int freesasa_set_verbosity(freesasa_verbosity s) {
    if (s == FREESASA_V_NORMAL ||
        s == FREESASA_V_NOWARNINGS ||
        s == FREESASA_V_SILENT) {
        verbosity = s;
        return FREESASA_SUCCESS;
    }
    return FREESASA_WARN;
}

freesasa_verbosity freesasa_get_verbosity(void) {
    return verbosity;
}

