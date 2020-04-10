// Author: Josue Mosiah Contreras Rocha
// File: main.c
// Date: 31/03/20

// ------------------------------------------
// System and aplication specific headers
// ------------------------------------------
#include "interface.h"

int main( void ) {
    Neuron_t *root = create(AND);

    initialGuide();
    chooseNeuron();
    askConnection();
    askInputValues(root);

    return 0;
}
