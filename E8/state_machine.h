// Implements a calculator using a state machine.
// Author: Josue Mosiah Contreras Rocha
// File: state_machine.h
// Date: 02/05/20

#ifndef STATE_MACHINE_H
#define STATE_MACHINE_H

// -----------------------------
// System headers
// -----------------------------


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
 * Perfoms an arithmetic operation between two numbers.
 *
 * @param n1 First number.
 * @param n2 Second number.
 * @param type State to test.
 * @return Result.
 */
 double run( double n1, double n2, State_t type );

#endif
