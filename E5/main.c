// Author: Josue Mosiah Contreras Rocha
// File: main.c
// Date: 31/03/20

// ------------------------------------------
// System and aplication specific headers
// ------------------------------------------
#include <stdio.h>
#include <stdbool.h>
#include "interface.h"

int main( void ) {
    // Initialize
    initialGuide();
    Type_t type = chooseNeuron();
    Neuron_t *root = create(type);
    
    // More neurons?
    while ( askConnection() ) {
        type = chooseNeuron();
        connect(root, create(type));
    }

    // Get values
    globalState(root);
    askInputValues(root);

    // Results
    bool result = testNetwork(root);
    printf("\nRed neuronal %s.\n\n", result ? "encendida" : "apagada");

    return 0;
}
