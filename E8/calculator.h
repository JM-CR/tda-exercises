// Functions for the calculator.
// Author: Josue Mosiah Contreras Rocha
// File: calculator.h
// Date: 02/05/20

#ifndef CALCULATOR_H
#define CALCULATOR_H

// -----------------------------
// Public interface
// -----------------------------

/* Types declarations */

enum state {
    ADD, SUBSTRACT, MULTIPLY, DIVIDE, NUM_STATES
};

typedef enum state State_t;

/* Function prototypes */

/**
 * Calculates the sum between two numbers.
 *
 * @param n1 First number.
 * @param n2 Second number.
 * @param state Current state.
 * @return Result.
 */
double add( double n1, double n2, State_t *state );

/**
 * Calculates the substraction between two numbers.
 *
 * @param n1 Minuend.
 * @param n2 Subtrahend.
 * @param state Current state.
 * @return Result.
 */
double substract( double n1, double n2, State_t *state );

/**
 * Calculates the multiplication between two numbers.
 *
 * @param n1 First number.
 * @param n2 Second number.
 * @param state Current state.
 * @return Result.
 */
double multiply( double n1, double n2, State_t *state );

/**
 * Calculates the division between two numbers.
 *
 * @param n1 Dividend.
 * @param n2 Divisor.
 * @param state Current state.
 * @return Result.
 */
double divide( double n1, double n2, State_t *state );

#endif
