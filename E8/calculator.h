// Functions for the calculator.
// Author: Josue Mosiah Contreras Rocha
// File: calculator.h
// Date: 02/05/20

#ifndef CALCULATOR_H
#define CALCULATOR_H

// -----------------------------
// Public interface
// -----------------------------

/* Function prototypes */

/**
 * Calculates the sum between two numbers.
 *
 * @param n1 First number.
 * @param n2 Second number.
 * @return Result.
 */
double add( double n1, double n2 );

/**
 * Calculates the substraction between two numbers.
 *
 * @param n1 Minuend.
 * @param n2 Subtrahend.
 * @return Result.
 */
double substract( double n1, double n2 );

/**
 * Calculates the multiplication between two numbers.
 *
 * @param n1 First number.
 * @param n2 Second number.
 * @return Result.
 */
double multiply( double n1, double n2 );

/**
 * Calculates the division between two numbers.
 *
 * @param n1 Dividend.
 * @param n2 Divisor.
 * @return Result.
 */
double divide( double n1, double n2 );

#endif
