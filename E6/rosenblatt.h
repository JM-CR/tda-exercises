// This library implements the Hebb's algorithm for neuronal networks.
// Author: Josue Mosiah Contreras Rocha
// File: rosenblatt.h
// Date: 11/04/20

#ifndef ROSENBLATT_H
#define ROSENBLATT_H

// -----------------------------
// System headers
// -----------------------------
#include <stdbool.h>
#include <stddef.h>


// -----------------------------
// Public interface
// -----------------------------

/* Constants */

#define N 0.01
#define THRESHOLD 0.7

/* Types declarations */

struct neuron {
    double *x;
    double *w;
    unsigned int totalInputs;
    bool (* isActive)(struct neuron *);
    double (* getOutput)(struct neuron *);
    struct neuron *next;
    struct neuron *previous;
};

typedef struct neuron Neuron_t;    // Rosenblatt

/* Function prototypes */

/**
 * Creates a new neuron.
 *
 * @param totalInputs Number of inputs.
 * @return Pointer to the object.
 */
Neuron_t *create( size_t totalInputs );

#endif
