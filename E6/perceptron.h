// This library implements the Hebb's algorithm for neuronal networks.
// Author: Josue Mosiah Contreras Rocha
// File: perceptron.h
// Date: 11/04/20

#ifndef PERCEPTRON_H
#define PERCEPTRON_H

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

typedef struct neuron Neuron_t;    // perceptron

/* Function prototypes */

/**
 * Creates a fully connected perceptron.
 *
 * @param layer Number of layers (maximum three).
 * @param row Number of rows (maximum three).
 * @param input Number of inputs.
 * @param output Number of outputs.
 */
Neuron_t *newPerceptron( size_t layer, size_t row, size_t input, size_t output );

#endif
