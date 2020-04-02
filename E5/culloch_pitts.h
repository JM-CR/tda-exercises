// This library simulates the artificial neurons designed by McCulloch and Pitts.
// Author: Josue Mosiah Contreras Rocha
// File: culloc_pitts.h
// Date: 31/03/20

#ifndef CULLOCH_PITTS_H
#define CULLOCH_PITTS_H

// -----------------------------
// System headers
// -----------------------------
#include <stdbool.h>

// -----------------------------
// Public interface
// -----------------------------

/* Types declarations */

enum type {
    AND, OR, NOT, XOR
};

typedef enum type Type_t;    // Neuron's type

struct neuron {
    Type_t type;
    unsigned short *x;
    bool (* test)(struct neuron *);
};

typedef struct neuron Neuron_t;    // McCulloch and Pitts

/* Function prototypes */

/**
 * Creates an artificial neuron ready to use.
 *
 * @param type Neuron's type.
 * @return Pointer to the artifical neuron.
 */
Neuron_t *create( Type_t type );

#endif
