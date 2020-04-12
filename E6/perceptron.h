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
    size_t totalInput;
    bool (* isActive)(struct neuron *);
    double (* getOutput)(struct neuron *);
};

typedef struct neuron Neuron_t;

struct perceptron {
    Neuron_t **inputLayer;
    Neuron_t **hiddenLayer;
    Neuron_t **outputLayer;
};

typedef struct perceptron Perceptron_t;

/* Function prototypes */

/**
 * Creates a generic perceptron.
 *
 * @param layer Number of layers (maximum three).
 * @param iNeuron Number of neurons at the input layer (maximum three).
 * @param in Number of inputs (maximum four).
 * @param out Number of outputs (maximum four).
 * @return Pointer to the new perceptron.
 */
Perceptron_t *newPerceptron( size_t layer, size_t iNeuron, size_t in, size_t out );

#endif
