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
    struct neuron *next;
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

/**
 * Connects new neurons.
 * 
 * @param root Initial neuron.
 * @param insert New neuron.
 */
void connect( Neuron_t *root, Neuron_t *insert );

/**
 * Perfoms the logical test from the neuronal network.
 *
 * @param root Initial neuron.
 * @return True if the network activates; otherwise, false. 
 */
bool testNetwork( Neuron_t *root );


#endif
