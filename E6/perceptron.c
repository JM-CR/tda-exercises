// See perceptron.h for more info
// Author: Josue Mosiah Contreras Rocha
// File: perceptron.c
// Date: 11/04/20

// ------------------------------------------
// System and aplication specific headers
// ------------------------------------------
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include "perceptron.h"


// -----------------------------
// Private elements
// -----------------------------

/* Private macros and constants */

/* Private types */

/* Private global variables */

/* Private functions */

/**
 * Generates a random number.
 *
 * @return The number.
 */
static double randomNumber( void ) {
    // Initial set up
	static bool firstRun = true;
	if ( firstRun ) {
		firstRun = false;
		srand(time(0));
	}

    // Get random
    return (double)rand() / (double)RAND_MAX;
}

/**
 * Initializes the weight's array with random numbers.
 *
 * @param neuron Neuron to initializate.
 */
static void getWeights( Neuron_t *neuron ) {
	for ( unsigned int i = 0; i < neuron->totalInputs; ++i ) {
        neuron->w[i] = randomNumber();
    }
}

/**
 * Calculates the linear combination (Z).
 *
 * @param neuron Neuron to check.
 * @return Result.
 */
double getOutput( Neuron_t *neuron ) {
    double result = 0.0;
    for ( unsigned int i = 0; i < neuron->totalInputs; ++i ) {
        result += neuron->x[i] * neuron->w[i];
    }
    return result;
}

/**
 * Checks the activation function for the given neuron.
 *
 * @param neuron Neuron to check.
 * @return True if active; otherwise, false.
 */
bool isActive( Neuron_t *neuron ) {
    return neuron->getOutput(neuron) >= THRESHOLD ? true : false;
}

/**
 * Creates a new neuron.
 *
 * @param totalInputs Number of inputs.
 * @return Pointer to the object.
 */
static Neuron_t *create( size_t totalInputs ) {
    // Create
    Neuron_t *neuron = malloc(sizeof(Neuron_t));

    // Assignment
    neuron->x = calloc(totalInputs, sizeof(double));
    neuron->w = calloc(totalInputs, sizeof(double));
    neuron->totalInputs = totalInputs;
    neuron->getOutput = getOutput;
    neuron->isActive = isActive;
    neuron->next = neuron->previous = NULL;

    // Fill
    getWeights(neuron);
    return neuron;
}

/**
 * Connects two neurons.
 *
 * @param neuron Base neuron.
 * @param with Target neuron.
 */
void connect( Neuron_t *neuron, Neuron_t *with ) {
    neuron->next = with;
    with->previous = neuron;
}


// -----------------------------
// Public elements
// -----------------------------

/* Implementation of the public functions */

Neuron_t *newPerceptron( size_t layer, size_t row, size_t input, size_t output ) {
    return NULL;
}