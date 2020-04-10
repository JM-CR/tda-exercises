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
#include "culloch_pitts.h"


// -----------------------------
// Public interface
// -----------------------------

/* Constants */

/* Types declarations */

/* Global variables */

/* Function prototypes */

/**
 * A little description about the program's behaviour.
 */
void initialGuide( void );

/**
 * Displays a menu that allows the creation of a neuron.
 *
 * @return Chosen type.
 */
Type_t chooseNeuron( void );

/**
 * Displays a menu that indicates if a new connection is required.
 *
 * @return True for new; otherwise, false.
 */
bool askConnection( void );

/**
 * Reads the required value for each neuron.
 *
 * @param root First neuron.
 */
void askInputValues( Neuron_t *root );

#endif
