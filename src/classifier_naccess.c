#include "classifier.h"

/* Autogenerated code from the script config2c.pl */

static const char *naccess_residue_name[] = {"A", "ALA", "ANY", "ARG", "ASN", "ASP", "C", "CYS", "DA", "DC", "DG", "DI", "DT", "DU", "G", "GLN", "GLU", "GLY", "HIS", "I", "ILE", "LEU", "LYS", "MET", "PHE", "PRO", "SEC", "SER", "T", "THR", "TRP", "TYR", "U", "VAL", };
static const char *naccess_A_atom_name[] = {"C4", "C2", "C5", "N1", "N7", "C6", "N6", "N9", "N3", "C8", };
static double naccess_A_atom_radius[] = {1.80, 1.80, 1.80, 1.60, 1.60, 1.80, 1.60, 1.60, 1.60, 1.80, };
static int naccess_A_atom_class[] = {FREESASA_ATOM_APOLAR, FREESASA_ATOM_APOLAR, FREESASA_ATOM_APOLAR, FREESASA_ATOM_POLAR, FREESASA_ATOM_POLAR, FREESASA_ATOM_APOLAR, FREESASA_ATOM_POLAR, FREESASA_ATOM_POLAR, FREESASA_ATOM_POLAR, FREESASA_ATOM_APOLAR, };
static struct classifier_residue naccess_A_cfg = {
    .name = "A", .n_atoms = 10,
    .atom_name = (char**) naccess_A_atom_name,
    .atom_radius = (double*) naccess_A_atom_radius,
    .atom_class = (freesasa_atom_class*) naccess_A_atom_class,
    .max_area = {NULL, 0, 0, 0, 0, 0},
};

static const char *naccess_ALA_atom_name[] = {"CB", };
static double naccess_ALA_atom_radius[] = {1.87, };
static int naccess_ALA_atom_class[] = {FREESASA_ATOM_APOLAR, };
static struct classifier_residue naccess_ALA_cfg = {
    .name = "ALA", .n_atoms = 1,
    .atom_name = (char**) naccess_ALA_atom_name,
    .atom_radius = (double*) naccess_ALA_atom_radius,
    .atom_class = (freesasa_atom_class*) naccess_ALA_atom_class,
    .max_area = {.name = "ALA", .total = 107.93, .main_chain = 42.94, .side_chain = 64.99, .polar = 35.27, .apolar = 72.65},
};

static const char *naccess_ANY_atom_name[] = {"CA", "P", "C4'", "O3'", "CB", "O", "C3'", "C2'", "N", "OP3", "OP2", "C5'", "OP1", "O2'", "O4'", "C", "O5'", "C1'", "OXT", };
static double naccess_ANY_atom_radius[] = {1.87, 1.90, 1.80, 1.40, 1.87, 1.40, 1.80, 1.80, 1.65, 1.40, 1.40, 1.80, 1.40, 1.40, 1.40, 1.76, 1.40, 1.80, 1.40, };
static int naccess_ANY_atom_class[] = {FREESASA_ATOM_APOLAR, FREESASA_ATOM_APOLAR, FREESASA_ATOM_APOLAR, FREESASA_ATOM_POLAR, FREESASA_ATOM_APOLAR, FREESASA_ATOM_POLAR, FREESASA_ATOM_APOLAR, FREESASA_ATOM_APOLAR, FREESASA_ATOM_POLAR, FREESASA_ATOM_POLAR, FREESASA_ATOM_POLAR, FREESASA_ATOM_APOLAR, FREESASA_ATOM_POLAR, FREESASA_ATOM_POLAR, FREESASA_ATOM_POLAR, FREESASA_ATOM_APOLAR, FREESASA_ATOM_POLAR, FREESASA_ATOM_APOLAR, FREESASA_ATOM_POLAR, };
static struct classifier_residue naccess_ANY_cfg = {
    .name = "ANY", .n_atoms = 19,
    .atom_name = (char**) naccess_ANY_atom_name,
    .atom_radius = (double*) naccess_ANY_atom_radius,
    .atom_class = (freesasa_atom_class*) naccess_ANY_atom_class,
    .max_area = {NULL, 0, 0, 0, 0, 0},
};

static const char *naccess_ARG_atom_name[] = {"CZ", "NE", "NH2", "NH1", "CD", "CG", };
static double naccess_ARG_atom_radius[] = {1.76, 1.65, 1.65, 1.65, 1.87, 1.87, };
static int naccess_ARG_atom_class[] = {FREESASA_ATOM_APOLAR, FREESASA_ATOM_POLAR, FREESASA_ATOM_POLAR, FREESASA_ATOM_POLAR, FREESASA_ATOM_APOLAR, FREESASA_ATOM_APOLAR, };
static struct classifier_residue naccess_ARG_cfg = {
    .name = "ARG", .n_atoms = 6,
    .atom_name = (char**) naccess_ARG_atom_name,
    .atom_radius = (double*) naccess_ARG_atom_radius,
    .atom_class = (freesasa_atom_class*) naccess_ARG_atom_class,
    .max_area = {.name = "ARG", .total = 242.94, .main_chain = 40.19, .side_chain = 202.75, .polar = 159.97, .apolar = 82.98},
};

static const char *naccess_ASN_atom_name[] = {"CG", "ND2", "OD1", };
static double naccess_ASN_atom_radius[] = {1.76, 1.65, 1.40, };
static int naccess_ASN_atom_class[] = {FREESASA_ATOM_APOLAR, FREESASA_ATOM_POLAR, FREESASA_ATOM_POLAR, };
static struct classifier_residue naccess_ASN_cfg = {
    .name = "ASN", .n_atoms = 3,
    .atom_name = (char**) naccess_ASN_atom_name,
    .atom_radius = (double*) naccess_ASN_atom_radius,
    .atom_class = (freesasa_atom_class*) naccess_ASN_atom_class,
    .max_area = {.name = "ASN", .total = 156.99, .main_chain = 40.94, .side_chain = 116.05, .polar = 115.65, .apolar = 41.34},
};

static const char *naccess_ASP_atom_name[] = {"CG", "OD2", "OD1", };
static double naccess_ASP_atom_radius[] = {1.76, 1.40, 1.40, };
static int naccess_ASP_atom_class[] = {FREESASA_ATOM_APOLAR, FREESASA_ATOM_POLAR, FREESASA_ATOM_POLAR, };
static struct classifier_residue naccess_ASP_cfg = {
    .name = "ASP", .n_atoms = 3,
    .atom_name = (char**) naccess_ASP_atom_name,
    .atom_radius = (double*) naccess_ASP_atom_radius,
    .atom_class = (freesasa_atom_class*) naccess_ASP_atom_class,
    .max_area = {.name = "ASP", .total = 146.34, .main_chain = 39.75, .side_chain = 106.59, .polar = 103.66, .apolar = 42.68},
};

static const char *naccess_C_atom_name[] = {"N1", "O2", "C6", "C4", "C2", "C5", "N4", "N3", };
static double naccess_C_atom_radius[] = {1.60, 1.40, 1.80, 1.80, 1.80, 1.80, 1.60, 1.60, };
static int naccess_C_atom_class[] = {FREESASA_ATOM_POLAR, FREESASA_ATOM_POLAR, FREESASA_ATOM_APOLAR, FREESASA_ATOM_APOLAR, FREESASA_ATOM_APOLAR, FREESASA_ATOM_APOLAR, FREESASA_ATOM_POLAR, FREESASA_ATOM_POLAR, };
static struct classifier_residue naccess_C_cfg = {
    .name = "C", .n_atoms = 8,
    .atom_name = (char**) naccess_C_atom_name,
    .atom_radius = (double*) naccess_C_atom_radius,
    .atom_class = (freesasa_atom_class*) naccess_C_atom_class,
    .max_area = {NULL, 0, 0, 0, 0, 0},
};

static const char *naccess_CYS_atom_name[] = {"SG", };
static double naccess_CYS_atom_radius[] = {1.85, };
static int naccess_CYS_atom_class[] = {FREESASA_ATOM_APOLAR, };
static struct classifier_residue naccess_CYS_cfg = {
    .name = "CYS", .n_atoms = 1,
    .atom_name = (char**) naccess_CYS_atom_name,
    .atom_radius = (double*) naccess_CYS_atom_radius,
    .atom_class = (freesasa_atom_class*) naccess_CYS_atom_class,
    .max_area = {.name = "CYS", .total = 134.80, .main_chain = 40.42, .side_chain = 94.37, .polar = 35.44, .apolar = 99.35},
};

static const char *naccess_DA_atom_name[] = {"N1", "N7", "C6", "N6", "C2", "C4", "C5", "N3", "C8", "N9", };
static double naccess_DA_atom_radius[] = {1.60, 1.60, 1.80, 1.60, 1.80, 1.80, 1.80, 1.60, 1.80, 1.60, };
static int naccess_DA_atom_class[] = {FREESASA_ATOM_POLAR, FREESASA_ATOM_POLAR, FREESASA_ATOM_APOLAR, FREESASA_ATOM_POLAR, FREESASA_ATOM_APOLAR, FREESASA_ATOM_APOLAR, FREESASA_ATOM_APOLAR, FREESASA_ATOM_POLAR, FREESASA_ATOM_APOLAR, FREESASA_ATOM_POLAR, };
static struct classifier_residue naccess_DA_cfg = {
    .name = "DA", .n_atoms = 10,
    .atom_name = (char**) naccess_DA_atom_name,
    .atom_radius = (double*) naccess_DA_atom_radius,
    .atom_class = (freesasa_atom_class*) naccess_DA_atom_class,
    .max_area = {NULL, 0, 0, 0, 0, 0},
};

static const char *naccess_DC_atom_name[] = {"C4", "C2", "C5", "O2", "N1", "C6", "N3", "N4", };
static double naccess_DC_atom_radius[] = {1.80, 1.80, 1.80, 1.40, 1.60, 1.80, 1.60, 1.60, };
static int naccess_DC_atom_class[] = {FREESASA_ATOM_APOLAR, FREESASA_ATOM_APOLAR, FREESASA_ATOM_APOLAR, FREESASA_ATOM_POLAR, FREESASA_ATOM_POLAR, FREESASA_ATOM_APOLAR, FREESASA_ATOM_POLAR, FREESASA_ATOM_POLAR, };
static struct classifier_residue naccess_DC_cfg = {
    .name = "DC", .n_atoms = 8,
    .atom_name = (char**) naccess_DC_atom_name,
    .atom_radius = (double*) naccess_DC_atom_radius,
    .atom_class = (freesasa_atom_class*) naccess_DC_atom_class,
    .max_area = {NULL, 0, 0, 0, 0, 0},
};

static const char *naccess_DG_atom_name[] = {"O6", "C8", "N3", "N9", "N1", "N7", "N2", "C6", "C2", "C4", "C5", };
static double naccess_DG_atom_radius[] = {1.40, 1.80, 1.60, 1.60, 1.60, 1.60, 1.60, 1.80, 1.80, 1.80, 1.80, };
static int naccess_DG_atom_class[] = {FREESASA_ATOM_POLAR, FREESASA_ATOM_APOLAR, FREESASA_ATOM_POLAR, FREESASA_ATOM_POLAR, FREESASA_ATOM_POLAR, FREESASA_ATOM_POLAR, FREESASA_ATOM_POLAR, FREESASA_ATOM_APOLAR, FREESASA_ATOM_APOLAR, FREESASA_ATOM_APOLAR, FREESASA_ATOM_APOLAR, };
static struct classifier_residue naccess_DG_cfg = {
    .name = "DG", .n_atoms = 11,
    .atom_name = (char**) naccess_DG_atom_name,
    .atom_radius = (double*) naccess_DG_atom_radius,
    .atom_class = (freesasa_atom_class*) naccess_DG_atom_class,
    .max_area = {NULL, 0, 0, 0, 0, 0},
};

static const char *naccess_DI_atom_name[] = {"C6", "N7", "N1", "C5", "C4", "C2", "N3", "C8", "O6", "N9", };
static double naccess_DI_atom_radius[] = {1.80, 1.60, 1.60, 1.80, 1.80, 1.80, 1.60, 1.80, 1.40, 1.60, };
static int naccess_DI_atom_class[] = {FREESASA_ATOM_APOLAR, FREESASA_ATOM_POLAR, FREESASA_ATOM_POLAR, FREESASA_ATOM_APOLAR, FREESASA_ATOM_APOLAR, FREESASA_ATOM_APOLAR, FREESASA_ATOM_POLAR, FREESASA_ATOM_APOLAR, FREESASA_ATOM_POLAR, FREESASA_ATOM_POLAR, };
static struct classifier_residue naccess_DI_cfg = {
    .name = "DI", .n_atoms = 10,
    .atom_name = (char**) naccess_DI_atom_name,
    .atom_radius = (double*) naccess_DI_atom_radius,
    .atom_class = (freesasa_atom_class*) naccess_DI_atom_class,
    .max_area = {NULL, 0, 0, 0, 0, 0},
};

static const char *naccess_DT_atom_name[] = {"C2", "C4", "C5", "O4", "O2", "N1", "C7", "C6", "N3", };
static double naccess_DT_atom_radius[] = {1.80, 1.80, 1.80, 1.40, 1.40, 1.60, 1.80, 1.80, 1.60, };
static int naccess_DT_atom_class[] = {FREESASA_ATOM_APOLAR, FREESASA_ATOM_APOLAR, FREESASA_ATOM_APOLAR, FREESASA_ATOM_POLAR, FREESASA_ATOM_POLAR, FREESASA_ATOM_POLAR, FREESASA_ATOM_APOLAR, FREESASA_ATOM_APOLAR, FREESASA_ATOM_POLAR, };
static struct classifier_residue naccess_DT_cfg = {
    .name = "DT", .n_atoms = 9,
    .atom_name = (char**) naccess_DT_atom_name,
    .atom_radius = (double*) naccess_DT_atom_radius,
    .atom_class = (freesasa_atom_class*) naccess_DT_atom_class,
    .max_area = {NULL, 0, 0, 0, 0, 0},
};

static const char *naccess_DU_atom_name[] = {"N3", "C6", "O2", "N1", "O4", "C5", "C4", "C2", };
static double naccess_DU_atom_radius[] = {1.60, 1.80, 1.40, 1.60, 1.40, 1.80, 1.80, 1.80, };
static int naccess_DU_atom_class[] = {FREESASA_ATOM_POLAR, FREESASA_ATOM_APOLAR, FREESASA_ATOM_POLAR, FREESASA_ATOM_POLAR, FREESASA_ATOM_POLAR, FREESASA_ATOM_APOLAR, FREESASA_ATOM_APOLAR, FREESASA_ATOM_APOLAR, };
static struct classifier_residue naccess_DU_cfg = {
    .name = "DU", .n_atoms = 8,
    .atom_name = (char**) naccess_DU_atom_name,
    .atom_radius = (double*) naccess_DU_atom_radius,
    .atom_class = (freesasa_atom_class*) naccess_DU_atom_class,
    .max_area = {NULL, 0, 0, 0, 0, 0},
};

static const char *naccess_G_atom_name[] = {"O6", "C8", "N3", "N9", "N1", "N7", "N2", "C6", "C4", "C2", "C5", };
static double naccess_G_atom_radius[] = {1.40, 1.80, 1.60, 1.60, 1.60, 1.60, 1.60, 1.80, 1.80, 1.80, 1.80, };
static int naccess_G_atom_class[] = {FREESASA_ATOM_POLAR, FREESASA_ATOM_APOLAR, FREESASA_ATOM_POLAR, FREESASA_ATOM_POLAR, FREESASA_ATOM_POLAR, FREESASA_ATOM_POLAR, FREESASA_ATOM_POLAR, FREESASA_ATOM_APOLAR, FREESASA_ATOM_APOLAR, FREESASA_ATOM_APOLAR, FREESASA_ATOM_APOLAR, };
static struct classifier_residue naccess_G_cfg = {
    .name = "G", .n_atoms = 11,
    .atom_name = (char**) naccess_G_atom_name,
    .atom_radius = (double*) naccess_G_atom_radius,
    .atom_class = (freesasa_atom_class*) naccess_G_atom_class,
    .max_area = {NULL, 0, 0, 0, 0, 0},
};

static const char *naccess_GLN_atom_name[] = {"CD", "NE2", "OE1", "CG", };
static double naccess_GLN_atom_radius[] = {1.76, 1.65, 1.40, 1.87, };
static int naccess_GLN_atom_class[] = {FREESASA_ATOM_APOLAR, FREESASA_ATOM_POLAR, FREESASA_ATOM_POLAR, FREESASA_ATOM_APOLAR, };
static struct classifier_residue naccess_GLN_cfg = {
    .name = "GLN", .n_atoms = 4,
    .atom_name = (char**) naccess_GLN_atom_name,
    .atom_radius = (double*) naccess_GLN_atom_radius,
    .atom_class = (freesasa_atom_class*) naccess_GLN_atom_class,
    .max_area = {.name = "GLN", .total = 182.67, .main_chain = 40.32, .side_chain = 142.35, .polar = 127.23, .apolar = 55.44},
};

static const char *naccess_GLU_atom_name[] = {"CD", "OE1", "OE2", "CG", };
static double naccess_GLU_atom_radius[] = {1.76, 1.40, 1.40, 1.87, };
static int naccess_GLU_atom_class[] = {FREESASA_ATOM_APOLAR, FREESASA_ATOM_POLAR, FREESASA_ATOM_POLAR, FREESASA_ATOM_APOLAR, };
static struct classifier_residue naccess_GLU_cfg = {
    .name = "GLU", .n_atoms = 4,
    .atom_name = (char**) naccess_GLU_atom_name,
    .atom_radius = (double*) naccess_GLU_atom_radius,
    .atom_class = (freesasa_atom_class*) naccess_GLU_atom_class,
    .max_area = {.name = "GLU", .total = 175.98, .main_chain = 40.53, .side_chain = 135.45, .polar = 113.62, .apolar = 62.36},
};

static const char *naccess_GLY_atom_name[] = {"CA", };
static double naccess_GLY_atom_radius[] = {1.87, };
static int naccess_GLY_atom_class[] = {FREESASA_ATOM_APOLAR, };
static struct classifier_residue naccess_GLY_cfg = {
    .name = "GLY", .n_atoms = 1,
    .atom_name = (char**) naccess_GLY_atom_name,
    .atom_radius = (double*) naccess_GLY_atom_radius,
    .atom_class = (freesasa_atom_class*) naccess_GLY_atom_class,
    .max_area = {.name = "GLY", .total = 79.57, .main_chain = 79.57, .side_chain = 0.00, .polar = 40.70, .apolar = 38.87},
};

static const char *naccess_HIS_atom_name[] = {"NE2", "CD2", "CE1", "ND1", "CG", };
static double naccess_HIS_atom_radius[] = {1.65, 1.76, 1.76, 1.65, 1.76, };
static int naccess_HIS_atom_class[] = {FREESASA_ATOM_POLAR, FREESASA_ATOM_APOLAR, FREESASA_ATOM_APOLAR, FREESASA_ATOM_POLAR, FREESASA_ATOM_APOLAR, };
static struct classifier_residue naccess_HIS_cfg = {
    .name = "HIS", .n_atoms = 5,
    .atom_name = (char**) naccess_HIS_atom_name,
    .atom_radius = (double*) naccess_HIS_atom_radius,
    .atom_class = (freesasa_atom_class*) naccess_HIS_atom_class,
    .max_area = {.name = "HIS", .total = 190.92, .main_chain = 39.81, .side_chain = 151.11, .polar = 89.89, .apolar = 101.03},
};

static const char *naccess_I_atom_name[] = {"N7", "N1", "C6", "C2", "C4", "C5", "O6", "C8", "N3", "N9", };
static double naccess_I_atom_radius[] = {1.60, 1.60, 1.80, 1.80, 1.80, 1.80, 1.40, 1.80, 1.60, 1.60, };
static int naccess_I_atom_class[] = {FREESASA_ATOM_POLAR, FREESASA_ATOM_POLAR, FREESASA_ATOM_APOLAR, FREESASA_ATOM_APOLAR, FREESASA_ATOM_APOLAR, FREESASA_ATOM_APOLAR, FREESASA_ATOM_POLAR, FREESASA_ATOM_APOLAR, FREESASA_ATOM_POLAR, FREESASA_ATOM_POLAR, };
static struct classifier_residue naccess_I_cfg = {
    .name = "I", .n_atoms = 10,
    .atom_name = (char**) naccess_I_atom_name,
    .atom_radius = (double*) naccess_I_atom_radius,
    .atom_class = (freesasa_atom_class*) naccess_I_atom_class,
    .max_area = {NULL, 0, 0, 0, 0, 0},
};

static const char *naccess_ILE_atom_name[] = {"CG1", "CD1", "CG2", };
static double naccess_ILE_atom_radius[] = {1.87, 1.87, 1.87, };
static int naccess_ILE_atom_class[] = {FREESASA_ATOM_APOLAR, FREESASA_ATOM_APOLAR, FREESASA_ATOM_APOLAR, };
static struct classifier_residue naccess_ILE_cfg = {
    .name = "ILE", .n_atoms = 3,
    .atom_name = (char**) naccess_ILE_atom_name,
    .atom_radius = (double*) naccess_ILE_atom_radius,
    .atom_class = (freesasa_atom_class*) naccess_ILE_atom_class,
    .max_area = {.name = "ILE", .total = 179.97, .main_chain = 40.24, .side_chain = 139.73, .polar = 35.44, .apolar = 144.53},
};

static const char *naccess_LEU_atom_name[] = {"CD1", "CD2", "CG", };
static double naccess_LEU_atom_radius[] = {1.87, 1.87, 1.87, };
static int naccess_LEU_atom_class[] = {FREESASA_ATOM_APOLAR, FREESASA_ATOM_APOLAR, FREESASA_ATOM_APOLAR, };
static struct classifier_residue naccess_LEU_cfg = {
    .name = "LEU", .n_atoms = 3,
    .atom_name = (char**) naccess_LEU_atom_name,
    .atom_radius = (double*) naccess_LEU_atom_radius,
    .atom_class = (freesasa_atom_class*) naccess_LEU_atom_class,
    .max_area = {.name = "LEU", .total = 184.04, .main_chain = 40.38, .side_chain = 143.66, .polar = 35.27, .apolar = 148.77},
};

static const char *naccess_LYS_atom_name[] = {"CG", "CE", "NZ", "CD", };
static double naccess_LYS_atom_radius[] = {1.87, 1.87, 1.50, 1.87, };
static int naccess_LYS_atom_class[] = {FREESASA_ATOM_APOLAR, FREESASA_ATOM_APOLAR, FREESASA_ATOM_POLAR, FREESASA_ATOM_APOLAR, };
static struct classifier_residue naccess_LYS_cfg = {
    .name = "LYS", .n_atoms = 4,
    .atom_name = (char**) naccess_LYS_atom_name,
    .atom_radius = (double*) naccess_LYS_atom_radius,
    .atom_class = (freesasa_atom_class*) naccess_LYS_atom_class,
    .max_area = {.name = "LYS", .total = 201.37, .main_chain = 40.40, .side_chain = 160.97, .polar = 83.21, .apolar = 118.16},
};

static const char *naccess_MET_atom_name[] = {"CE", "SD", "CG", };
static double naccess_MET_atom_radius[] = {1.87, 1.85, 1.87, };
static int naccess_MET_atom_class[] = {FREESASA_ATOM_APOLAR, FREESASA_ATOM_APOLAR, FREESASA_ATOM_APOLAR, };
static struct classifier_residue naccess_MET_cfg = {
    .name = "MET", .n_atoms = 3,
    .atom_name = (char**) naccess_MET_atom_name,
    .atom_radius = (double*) naccess_MET_atom_radius,
    .atom_class = (freesasa_atom_class*) naccess_MET_atom_class,
    .max_area = {.name = "MET", .total = 198.82, .main_chain = 42.23, .side_chain = 156.60, .polar = 35.20, .apolar = 163.63},
};

static const char *naccess_PHE_atom_name[] = {"CE2", "CE1", "CG", "CZ", "CD1", "CD2", };
static double naccess_PHE_atom_radius[] = {1.76, 1.76, 1.76, 1.76, 1.76, 1.76, };
static int naccess_PHE_atom_class[] = {FREESASA_ATOM_APOLAR, FREESASA_ATOM_APOLAR, FREESASA_ATOM_APOLAR, FREESASA_ATOM_APOLAR, FREESASA_ATOM_APOLAR, FREESASA_ATOM_APOLAR, };
static struct classifier_residue naccess_PHE_cfg = {
    .name = "PHE", .n_atoms = 6,
    .atom_name = (char**) naccess_PHE_atom_name,
    .atom_radius = (double*) naccess_PHE_atom_radius,
    .atom_class = (freesasa_atom_class*) naccess_PHE_atom_class,
    .max_area = {.name = "PHE", .total = 209.45, .main_chain = 40.34, .side_chain = 169.11, .polar = 33.96, .apolar = 175.49},
};

static const char *naccess_PRO_atom_name[] = {"CD", "CG", };
static double naccess_PRO_atom_radius[] = {1.87, 1.87, };
static int naccess_PRO_atom_class[] = {FREESASA_ATOM_APOLAR, FREESASA_ATOM_APOLAR, };
static struct classifier_residue naccess_PRO_cfg = {
    .name = "PRO", .n_atoms = 2,
    .atom_name = (char**) naccess_PRO_atom_name,
    .atom_radius = (double*) naccess_PRO_atom_radius,
    .atom_class = (freesasa_atom_class*) naccess_PRO_atom_class,
    .max_area = {.name = "PRO", .total = 140.04, .main_chain = 32.08, .side_chain = 107.96, .polar = 19.37, .apolar = 120.67},
};

static const char *naccess_SEC_atom_name[] = {"SE", };
static double naccess_SEC_atom_radius[] = {1.80, };
static int naccess_SEC_atom_class[] = {FREESASA_ATOM_APOLAR, };
static struct classifier_residue naccess_SEC_cfg = {
    .name = "SEC", .n_atoms = 1,
    .atom_name = (char**) naccess_SEC_atom_name,
    .atom_radius = (double*) naccess_SEC_atom_radius,
    .atom_class = (freesasa_atom_class*) naccess_SEC_atom_class,
    .max_area = {NULL, 0, 0, 0, 0, 0},
};

static const char *naccess_SER_atom_name[] = {"OG", };
static double naccess_SER_atom_radius[] = {1.40, };
static int naccess_SER_atom_class[] = {FREESASA_ATOM_POLAR, };
static struct classifier_residue naccess_SER_cfg = {
    .name = "SER", .n_atoms = 1,
    .atom_name = (char**) naccess_SER_atom_name,
    .atom_radius = (double*) naccess_SER_atom_radius,
    .atom_class = (freesasa_atom_class*) naccess_SER_atom_class,
    .max_area = {.name = "SER", .total = 116.28, .main_chain = 38.65, .side_chain = 77.63, .polar = 66.11, .apolar = 50.17},
};

static const char *naccess_T_atom_name[] = {"N3", "O4", "N1", "O2", "C7", "C6", "C2", "C4", "C5", };
static double naccess_T_atom_radius[] = {1.60, 1.40, 1.60, 1.40, 1.80, 1.80, 1.80, 1.80, 1.80, };
static int naccess_T_atom_class[] = {FREESASA_ATOM_POLAR, FREESASA_ATOM_POLAR, FREESASA_ATOM_POLAR, FREESASA_ATOM_POLAR, FREESASA_ATOM_APOLAR, FREESASA_ATOM_APOLAR, FREESASA_ATOM_APOLAR, FREESASA_ATOM_APOLAR, FREESASA_ATOM_APOLAR, };
static struct classifier_residue naccess_T_cfg = {
    .name = "T", .n_atoms = 9,
    .atom_name = (char**) naccess_T_atom_name,
    .atom_radius = (double*) naccess_T_atom_radius,
    .atom_class = (freesasa_atom_class*) naccess_T_atom_class,
    .max_area = {NULL, 0, 0, 0, 0, 0},
};

static const char *naccess_THR_atom_name[] = {"OG1", "CG2", };
static double naccess_THR_atom_radius[] = {1.40, 1.87, };
static int naccess_THR_atom_class[] = {FREESASA_ATOM_POLAR, FREESASA_ATOM_APOLAR, };
static struct classifier_residue naccess_THR_cfg = {
    .name = "THR", .n_atoms = 2,
    .atom_name = (char**) naccess_THR_atom_name,
    .atom_radius = (double*) naccess_THR_atom_radius,
    .atom_class = (freesasa_atom_class*) naccess_THR_atom_class,
    .max_area = {.name = "THR", .total = 140.39, .main_chain = 40.35, .side_chain = 100.04, .polar = 62.51, .apolar = 77.88},
};

static const char *naccess_TRP_atom_name[] = {"CD2", "NE1", "CH2", "CZ2", "CD1", "CZ3", "CG", "CE3", "CE2", };
static double naccess_TRP_atom_radius[] = {1.76, 1.65, 1.76, 1.76, 1.76, 1.76, 1.76, 1.76, 1.76, };
static int naccess_TRP_atom_class[] = {FREESASA_ATOM_APOLAR, FREESASA_ATOM_POLAR, FREESASA_ATOM_APOLAR, FREESASA_ATOM_APOLAR, FREESASA_ATOM_APOLAR, FREESASA_ATOM_APOLAR, FREESASA_ATOM_APOLAR, FREESASA_ATOM_APOLAR, FREESASA_ATOM_APOLAR, };
static struct classifier_residue naccess_TRP_cfg = {
    .name = "TRP", .n_atoms = 9,
    .atom_name = (char**) naccess_TRP_atom_name,
    .atom_radius = (double*) naccess_TRP_atom_radius,
    .atom_class = (freesasa_atom_class*) naccess_TRP_atom_class,
    .max_area = {.name = "TRP", .total = 252.59, .main_chain = 38.26, .side_chain = 214.33, .polar = 60.54, .apolar = 192.05},
};

static const char *naccess_TYR_atom_name[] = {"CZ", "CD1", "CD2", "OH", "CG", "CE2", "CE1", };
static double naccess_TYR_atom_radius[] = {1.76, 1.76, 1.76, 1.40, 1.76, 1.76, 1.76, };
static int naccess_TYR_atom_class[] = {FREESASA_ATOM_APOLAR, FREESASA_ATOM_APOLAR, FREESASA_ATOM_APOLAR, FREESASA_ATOM_POLAR, FREESASA_ATOM_APOLAR, FREESASA_ATOM_APOLAR, FREESASA_ATOM_APOLAR, };
static struct classifier_residue naccess_TYR_cfg = {
    .name = "TYR", .n_atoms = 7,
    .atom_name = (char**) naccess_TYR_atom_name,
    .atom_radius = (double*) naccess_TYR_atom_radius,
    .atom_class = (freesasa_atom_class*) naccess_TYR_atom_class,
    .max_area = {.name = "TYR", .total = 223.61, .main_chain = 39.66, .side_chain = 183.95, .polar = 76.91, .apolar = 146.70},
};

static const char *naccess_U_atom_name[] = {"N3", "O2", "N1", "O4", "C6", "C4", "C2", "C5", };
static double naccess_U_atom_radius[] = {1.60, 1.40, 1.60, 1.40, 1.80, 1.80, 1.80, 1.80, };
static int naccess_U_atom_class[] = {FREESASA_ATOM_POLAR, FREESASA_ATOM_POLAR, FREESASA_ATOM_POLAR, FREESASA_ATOM_POLAR, FREESASA_ATOM_APOLAR, FREESASA_ATOM_APOLAR, FREESASA_ATOM_APOLAR, FREESASA_ATOM_APOLAR, };
static struct classifier_residue naccess_U_cfg = {
    .name = "U", .n_atoms = 8,
    .atom_name = (char**) naccess_U_atom_name,
    .atom_radius = (double*) naccess_U_atom_radius,
    .atom_class = (freesasa_atom_class*) naccess_U_atom_class,
    .max_area = {NULL, 0, 0, 0, 0, 0},
};

static const char *naccess_VAL_atom_name[] = {"CG2", "CG1", };
static double naccess_VAL_atom_radius[] = {1.87, 1.87, };
static int naccess_VAL_atom_class[] = {FREESASA_ATOM_APOLAR, FREESASA_ATOM_APOLAR, };
static struct classifier_residue naccess_VAL_cfg = {
    .name = "VAL", .n_atoms = 2,
    .atom_name = (char**) naccess_VAL_atom_name,
    .atom_radius = (double*) naccess_VAL_atom_radius,
    .atom_class = (freesasa_atom_class*) naccess_VAL_atom_class,
    .max_area = {.name = "VAL", .total = 153.90, .main_chain = 40.04, .side_chain = 113.87, .polar = 34.75, .apolar = 119.15},
};

static struct classifier_residue *naccess_residue_cfg[] = {
    &naccess_A_cfg, &naccess_ALA_cfg, &naccess_ANY_cfg, &naccess_ARG_cfg, &naccess_ASN_cfg, &naccess_ASP_cfg, &naccess_C_cfg, &naccess_CYS_cfg, &naccess_DA_cfg, &naccess_DC_cfg, &naccess_DG_cfg, &naccess_DI_cfg, &naccess_DT_cfg, &naccess_DU_cfg, &naccess_G_cfg, &naccess_GLN_cfg, &naccess_GLU_cfg, &naccess_GLY_cfg, &naccess_HIS_cfg, &naccess_I_cfg, &naccess_ILE_cfg, &naccess_LEU_cfg, &naccess_LYS_cfg, &naccess_MET_cfg, &naccess_PHE_cfg, &naccess_PRO_cfg, &naccess_SEC_cfg, &naccess_SER_cfg, &naccess_T_cfg, &naccess_THR_cfg, &naccess_TRP_cfg, &naccess_TYR_cfg, &naccess_U_cfg, &naccess_VAL_cfg, };

const freesasa_classifier freesasa_naccess_classifier = {
    .n_residues = 34,    .residue_name = (char**) naccess_residue_name,
    .residue = (struct classifier_residue **) naccess_residue_cfg,
    .name = "NACCESS",
};

