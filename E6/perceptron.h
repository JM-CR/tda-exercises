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
#include "gnuplot.h"


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
    double error;
    size_t totalInput;
};

typedef struct neuron Neuron_t;

struct perceptron {
    Neuron_t **inputLayer;
    Neuron_t **hiddenLayer;
    Neuron_t **outputLayer;
};

typedef struct perceptron Perceptron_t;

struct record {
    double in[2];
    double out;
};

typedef struct record Record_t;   // CSV

/* Function prototypes */

/**
 * Creates a generic perceptron.
 *
 * @param layer Number of layers (maximum three).
 * @param iNeuron Number of neurons at the input layer (maximum three).
 * @param in Number of inputs (maximum three).
 * @param out Number of neurons at the output layer (maximum two).
 * @return Pointer to the new perceptron.
 */
Perceptron_t *newPerceptron( size_t layer, size_t iNeuron, size_t in, size_t out );

/**
 * Loads one of the template files as a training set.
 *
 * @param filename File to read.
 * @param in Number of input columns (maximum two).
 * @return Array with the records.
 */
Record_t **loadSample( const char *filename, size_t in );

/**
 * Starts the training of the neuronal network.
 *
 * @param set Training set.
 * @param perceptron Perceptron to train.
 * @return True if the network converges; otherwise, false.
 */
bool train( Record_t **set, Perceptron_t *perceptron );

/**
 * Prints the weights of a neuron.
 * 
 * @param neuron Neuron to print.
 */
void printNeuron( Neuron_t *neuron );

/**
 * Tests a perceptron with the given input values.
 *
 * @param perceptron Perceptron to test.
 * @param in Input values.
 * @return True if the perceptron activates; otherwise, false.
 */
bool testPerceptron( Perceptron_t *perceptron, unsigned int *in );

#endif
