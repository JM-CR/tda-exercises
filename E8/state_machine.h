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

enum operation {
    ADD, SUBSTRACT, MULTIPLY, DIVIDE
};

typedef enum operation Operation_t;

/* Function prototypes */

/**
 * Perfoms an arithmetic operation between two numbers.
 *
 * @param n1 First number.
 * @param n2 Second number.
 * @param type Operation.
 * @return Result.
 */
 double operate( double n1, double n2, Operation_t type );

#endif
