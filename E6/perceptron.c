// See perceptron.h for more info
// Author: Josue Mosiah Contreras Rocha
// File: perceptron.c
// Date: 11/04/20

// ------------------------------------------
// System and aplication specific headers
// ------------------------------------------
#include <time.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "perceptron.h"


// -----------------------------
// Private elements
// -----------------------------

/* Private constants */

#define TRAINING_CYCLES 150

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
static void randomWeights( Neuron_t *neuron ) {
	for ( unsigned int i = 0; i < neuron->totalInput; ++i ) {
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
    for ( unsigned int i = 0; i < neuron->totalInput; ++i ) {
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
    return getOutput(neuron) >= THRESHOLD ? true : false;
}

/**
 * Creates a new neuron.
 *
 * @param input Number of inputs.
 * @return Pointer to the object.
 */
static Neuron_t *newNeuron( size_t input ) {
    // Create
    Neuron_t *neuron = malloc(sizeof(Neuron_t));

    // Assignment
    neuron->x = calloc(input, sizeof(double));
    neuron->w = calloc(input, sizeof(double));
    neuron->error = 0.0;
    neuron->totalInput = input;

    // Fill
    randomWeights(neuron);
    return neuron;
}

/**
 * Creates a new layer.
 *
 * @param in Number of inputs.
 * @param total Number of neurons.
 * @return Array with the layer.
 */
static Neuron_t **createLayer( size_t in, size_t total ) {
    // Create
    Neuron_t **layer = calloc(total + 1, sizeof(Neuron_t));

    // Fill
    for ( unsigned int i = 0; i < total; ++i ) {
        layer[i] = newNeuron(in);
    }
    layer[total] = NULL;   /* Last element */
    
    return layer;
}

/**
 * Calculates the error in the first and second layer according 
 * to the new hebb algorithm.
 *
 * @param initialLayer First layer.
 * @param nextLayer Second layer.
 * @param position Neuron to update in the initialLayer.
 */
static void updateLayerError( Neuron_t **initialLayer, Neuron_t **nextLayer, size_t position ) {
    // Guards
    if ( initialLayer == NULL || nextLayer == NULL ) {
        return;
    }
    
    // Initialize
    double result = 0.0;
    unsigned int iCur = 1;
    Neuron_t *current = nextLayer[0];

    // Get results
    while ( current != NULL ) {
        // Total weight
        double totalWeight = 0.0;
        for ( unsigned int i = 0; i < current->totalInput; ++i ) {
            totalWeight += current->w[i];
        }
       
       // Calculation
        result += current->w[position] * current->error / totalWeight;
        current = nextLayer[iCur++];
    }

    // Update
    initialLayer[position]->error = result;
}

/**
 * Calculates the error for a single layer perceptron.
 *
 * @param layer Layer to update.
 * @param expectedValue Output value from the training set.
 * @param position Neuron to update in the layer.
 */
static void updateError( Neuron_t **layer, double expectedValue, size_t position ) {
    // Guard
    if ( layer == NULL ) {
        return;
    }

    // Calculation
    Neuron_t *current = layer[position];
    layer[position]->error = expectedValue - getOutput(current);
}

/**
 * Trains a single layer perceptron. No hidden or output layer is needed
 *
 * @param set Training set.
 * @param layer Layer to train.
 */
static void singleTraining( Record_t **set, Neuron_t **layer ) {
    // Initialize
    unsigned int iRec, iNeu;
    Record_t *currentRecord;
    Neuron_t *currentNeuron;

    // Start training
    for ( unsigned int i = 0; i < TRAINING_CYCLES; ++i ) {
        // Initial setup
        iRec = iNeu = 0;
        currentRecord = set[0];
        currentNeuron = layer[0];
        
        // Test samples
        while ( currentNeuron != NULL ) {
            while ( currentRecord != NULL ) {
                // Insert values
                currentNeuron->x = currentRecord->in;

                // Guard
                if ( isActive(currentNeuron) == currentRecord->out ) {
                    currentRecord = set[++iRec];
                    continue;
                }

                // Update neuron
                updateError(layer, currentRecord->out, iNeu);
                for ( unsigned int i = 0; i < currentNeuron->totalInput; ++i ) {
                    double error = currentNeuron->error;
                    double x = currentNeuron->x[i];
                    currentNeuron->w[i] += N * error * x;  /* Weight */
                }

                // Next cycle
                currentRecord = set[++iRec];
            }
            // Next cycle
            currentNeuron = layer[++iNeu];
        }
    }
}

/**
 * Trains a multi layer perceptron.
 *
 * @param set Training set.
 * @param perceptron Perceptron to train.
 */
static void multiTraining( Record_t **set, Perceptron_t *perceptron ) {

}


// -----------------------------
// Public elements
// -----------------------------

/* Implementation of the public functions */

Perceptron_t *newPerceptron( size_t layer, size_t iNeuron, size_t in, size_t out ) {
    // Guards
    if ( layer == 0 || layer > 3 || iNeuron == 0 || iNeuron > 3 ) {
        return NULL;
    }

    if ( in == 0 || in > 3 || out > 2 ) {
        return NULL;
    }

    // Create layers
    size_t hiddenInput = iNeuron >= out ? iNeuron : out;
    Neuron_t **inputLayer = createLayer(in, iNeuron);
    Neuron_t **hiddenLayer = NULL, **outputLayer = NULL;

    if ( layer == 2 ) {
        outputLayer = createLayer(hiddenInput, out);
    } else if ( layer == 3 ) {
        outputLayer = createLayer(hiddenInput, out);
        hiddenLayer = createLayer(iNeuron, hiddenInput);
    }

    // Container
    Perceptron_t *perceptron = malloc(sizeof(Perceptron_t));
    perceptron->inputLayer = inputLayer;
    perceptron->hiddenLayer = hiddenLayer;
    perceptron->outputLayer = outputLayer;

    return perceptron;
}

Record_t **loadSample( const char *filename, size_t in ) {
    // Guards
    if ( in > 2 || in == 0 ) {
        return NULL;
    }

    // Open file
    char *dir = "./training_files/";
    char *path = malloc(strlen(dir) + strlen(filename) + 1);
    strcpy(path, dir);
    strcat(path, filename);
    FILE *fp = fopen(path, "r");
    if ( fp == NULL ) {
        fprintf(stderr, "\nError leyendo archivo.\n");
        return NULL;
    }

    // Initialize
    size_t max = 2 * in;
    Record_t **record = calloc(max + 1, sizeof(Record_t));

    // Read
    for ( unsigned int i = 0; i < max; ++i ) {
        record[i] = malloc(sizeof(Record_t));
        if ( in == 1 ) {
            fscanf(fp, "%lf,%lf\n", &record[i]->in[0], &record[i]->out);
        } else {
            fscanf(
                fp, 
                "%lf,%lf,%lf", 
                &record[i]->in[0], &record[i]->in[1], &record[i]->out
            );
        }
    }
    record[max] = NULL;  /* Ending element */

    return record;
}

bool train( Record_t **set, Perceptron_t *perceptron ) {
    // Guards
    if ( set == NULL || perceptron == NULL ) {
        return false;
    }

    // Start training
    if ( perceptron->outputLayer == NULL ) {
        singleTraining(set, perceptron->inputLayer);
    } else {
        multiTraining(set, perceptron);
    }

    return true;
}
