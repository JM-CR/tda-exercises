// See state_machine.h for more info
// Author: Josue Mosiah Contreras Rocha
// File: state_machine.c
// Date: 02/05/20

// ------------------------------------------
// System and aplication specific headers
// ------------------------------------------
#include "interface.h"
#include "state_machine.h"


// -----------------------------
// Private elements
// -----------------------------

/* Private global variables */

static const StateMachine_t stateMachine[NUM_STATES] = {
    { ADD, add },
    { SUBSTRACT, substract },
    { MULTIPLY, multiply },
    { DIVIDE, divide }
};


// -----------------------------
// Public elements
// -----------------------------

/* Implementation of the public functions */

void startMachine( State_t *state ) {
    // Initialize
    State_t previous_state;

    // Start
    for (;;) {
        // Watch-dog
        previous_state = *state;
        if ( *state > NUM_STATES ) {
            *state = previous_state;
        } else {
            // Ask numbers
            double n1 = askInputValue("Ingresa el primer número ");
            double n2 = askInputValue("Ingresa el segundo número ");

            // Call calculator
            double result = stateMachine[*state].calculate(n1, n2, state);
            printResult(result);
            break;
        }
    }
}
