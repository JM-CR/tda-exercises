// This library facilitates the use of the calculator.
// Author: Josue Mosiah Contreras Rocha
// File: interface.h
// Date: 02/05/20

#ifndef INTERFACE_H
#define INTERFACE_H

// -----------------------------
// System headers
// -----------------------------
#include "calculator.h"


// -----------------------------
// Public interface
// -----------------------------

/* Function prototypes */

/**
 * A little description about the program's behaviour.
 */
void initialGuide( void );

/**
 * Displays the available operations.
 */
void printMenu( void );

/**
 * Expects an input value from the user.
 *
 * @param text Instructions.
 * @return Given value by the user.
 */
double askInputValue( char *text );

/**
 * Allows the user to choose an option from the menu.
 *
 * @param text Instructions.
 * @param lower Minimum value.
 * @param upper Maximum value.
 * @return Chosen option.
 */
Operation_t askMenuValue( char *text, int lower, int upper );

/**
 * Prints the result of an operation.
 *
 * @param result Number to display.
 */
void printResult( double result );

#endif
