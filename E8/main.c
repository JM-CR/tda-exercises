// Author: Josue Mosiah Contreras Rocha
// File: main.c
// Date: 02/05/20

// ------------------------------------------
// System and aplication specific headers
// ------------------------------------------
#include "interface.h"

int main( void ) {
    // Ask operation type
    initialGuide();
    printMenu();
    State_t type = askMenuValue("Ingresa el tipo ", 1, 4);

    // Ask numbers
    double n1 = askInputValue("Ingresa el primer número ");
    double n2 = askInputValue("Ingresa el segundo número ");

    // Result
    double output = run(n1, n2, type);
    printResult(output);

    return 0;
}
