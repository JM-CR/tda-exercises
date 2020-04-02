// See library.h for more info
// Author: Josue Mosiah Contreras Rocha
// File: culloch_pitts.c
// Date: 31/03/20

// ------------------------------------------
// System and application specific headers
// ------------------------------------------
#include <stdlib.h>
#include <stdbool.h>
#include "culloch_pitts.h"


// -----------------------------
// Private elements
// -----------------------------

/* Private functions */

/**
 * Operates the neuron to perform a logical AND.
 *
 * @param self Neuron to test.
 * @return True when the neuron activates; otherwirse, false.
 */
static bool and( Neuron_t *self ) {
    return (self->x[0] + self->x[1]) >= 2 ? true : false;
}

/**
 * Operates the neuron to perform a logical OR.
 *
 * @param self Neuron to test.
 * @return True when the neuron activates; otherwirse, false.
 */
static bool or( Neuron_t *self ) {
    return (self->x[0] + self->x[1]) >= 1 ? true : false;
}

/**
 * Operates the neuron to perform a logical NOT.
 *
 * @param self Neuron to test.
 * @return True when the neuron activates; otherwirse, false.
 */
static bool not( Neuron_t *self ) {
    return *self->x != 0 ? true : false;
}

/**
 * Operates the neuron to perform a logical XOR.
 *
 * @param self Neuron to test.
 * @return True when the neuron activates; otherwirse, false.
 */
static bool xor( Neuron_t *self ) {
    return self->x[0] != self->x[1] ? true : false;
}


// -----------------------------
// Public elements
// -----------------------------

/* Implementation of the public functions */

Neuron_t *create( Type_t type ) {
    // Create
    static bool (* operations[])(Neuron_t *) = { and, or, not, xor };
    Neuron_t *neuron = malloc(sizeof(Neuron_t));

    // Assignment
    if ( type != NOT ) {
        neuron->x = calloc(2, sizeof(short));
    } else {
        neuron->x = malloc(sizeof(short));
    }
    neuron->type = type;
    neuron->test = operations[type];

    return neuron;
}
