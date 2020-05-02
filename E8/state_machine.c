// See state_machine.h for more info
// Author: Josue Mosiah Contreras Rocha
// File: state_machine.c
// Date: 02/05/20

// ------------------------------------------
// System and aplication specific headers
// ------------------------------------------
#include "state_machine.h"
#include "calculator.h"


// -----------------------------
// Private elements
// -----------------------------

/* Private functions */


// -----------------------------
// Public elements
// -----------------------------

/* Implementation of the public functions */

double run( double n1, double n2, State_t type ) {
    double (* calc[])(double, double) = { add, substract, multiply, divide };
    return calc[type](n1, n2);
}
