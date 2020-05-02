// See calculator.h for more info
// Author: Josue Mosiah Contreras Rocha
// File: calculator.c
// Date: 02/05/20

// ------------------------------------------
// System and aplication specific headers
// ------------------------------------------
#include "calculator.h"


// -----------------------------
// Private elements
// -----------------------------

/* Private functions */

/**
 * Calculates the sum between two numbers.
 *
 * @param n1 First number.
 * @param n2 Second number.
 * @return Result.
 */
static double add( double n1, double n2 ) {
    return n1 + n2;
}

/**
 * Calculates the substraction between two numbers.
 *
 * @param n1 Minuend.
 * @param n2 Subtrahend.
 * @return Result.
 */
static double substract( double n1, double n2 ) {
    return n1 - n2;
}

/**
 * Calculates the multiplication between two numbers.
 *
 * @param n1 First number.
 * @param n2 Second number.
 * @return Result.
 */
static double multiply( double n1, double n2 ) {
    return n1 * n2;
}

/**
 * Calculates the division between two numbers.
 *
 * @param n1 Dividend.
 * @param n2 Divisor.
 * @return Result.
 */
static double divide( double n1, double n2 ) {
    return n1 / n2;
}


// -----------------------------
// Public elements
// -----------------------------

/* Implementation of the public functions */

double operate( double n1, double n2, Operation_t type ) {
    double (* calc[])(double, double) = { add, substract, multiply, divide };
    return calc[type](n1, n2);
}
