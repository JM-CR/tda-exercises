// This library facilitates the use of the McCulloch and Pitts neuron.
// Author: Josue Mosiah Contreras Rocha
// File: interface.h
// Date: 02/04/20

#ifndef INTERFACE_H
#define INTERFACE_H

// -----------------------------
// System headers
// -----------------------------
#include <stdbool.h>
#include "perceptron.h"


// -----------------------------
// Public interface
// -----------------------------

/* Function prototypes */

/**
 * A little description about the program's behaviour.
 */
void initialGuide( void );

/**
 * Expects an input value from the user.
 *
 * @param text Instructions.
 * @param lower Minimum value.
 * @param upper Maximum value.
 * @return Given value by the user.
 */
unsigned int askValue( char *text, int lower, int upper );

/**
 * Displays a menu that loads the training set.
 *
 * @return File to load.
 */
char *askFile( void );

#endif
