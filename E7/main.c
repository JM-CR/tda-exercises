// Author: Josue Mosiah Contreras Rocha
// File: main.c
// Date: 02/05/20

// ------------------------------------------
// System and aplication specific headers
// ------------------------------------------
#include <stdio.h>
#include "calculator.h"

int main( void ) {
    double n1 = 3.0;
    double n2 = 4.0;
    double result = operate(n1, n2, ADD);
    printf("%.2lf\n", result);

    return 0;
}
