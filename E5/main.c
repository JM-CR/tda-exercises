// Author: Josue Mosiah Contreras Rocha
// File: main.c
// Date: 31/03/20

// ------------------------------------------
// System and aplication specific headers
// ------------------------------------------
#include <stdio.h>
#include "culloch_pitts.h"

int main( void ) {
    Neuron_t *root = create(AND);
    connect(root, create(NOT));
    root->x[0] = 1;
    root->x[1] = 1;

    printf("%s\n", testNetwork(root) ? "true" : "false");

    return 0;
}
