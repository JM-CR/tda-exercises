// Author: Josue Mosiah Contreras Rocha
// File: main.c
// Date: 02/05/20

// ------------------------------------------
// System and aplication specific headers
// ------------------------------------------
#include <stdbool.h>
#include "interface.h"
#include "state_machine.h"

int main( void ) {
    // Iterate
    initialGuide();
    do {
        // User interaction
        printMenu();
        State_t type = askMenuValue("Ingresa el tipo ", 1, 4);

        // Run
        startMachine(&type);
        clearScreen();
    } while ( true );

    return 0;
}
