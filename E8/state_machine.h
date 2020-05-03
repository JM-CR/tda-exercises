// Implements a calculator using a state machine.
// Author: Josue Mosiah Contreras Rocha
// File: state_machine.h
// Date: 02/05/20

#ifndef STATE_MACHINE_H
#define STATE_MACHINE_H

// -----------------------------
// System headers
// -----------------------------
#include "calculator.h"


// -----------------------------
// Public interface
// -----------------------------

/* Types declarations */

struct stateMachine {
    State_t currentState;
    double (* calculate)(double, double, State_t *);
};

typedef struct stateMachine StateMachine_t;

/* Function prototypes */

/**
 * Starts the machine.
 *
 * @param type Initial state.
 */
void startMachine( State_t *state );

#endif
