// See calculator.h for more info
// Author: Josue Mosiah Contreras Rocha
// File: calculator.c
// Date: 02/05/20

// ------------------------------------------
// System and aplication specific headers
// ------------------------------------------
#include "calculator.h"


// -----------------------------
// Public elements
// -----------------------------

/* Implementation of the public functions */

double add( double n1, double n2, State_t *state  ) {
    return n1 + n2;
}

double substract( double n1, double n2, State_t *state  ) {
    return n1 - n2;
}

double multiply( double n1, double n2, State_t *state  ) {
    return n1 * n2;
}

double divide( double n1, double n2, State_t *state ) {
    return n1 / n2;
}
