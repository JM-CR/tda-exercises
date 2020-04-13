// Author: Josue Mosiah Contreras Rocha
// File: main.c
// Date: 11/04/20

// ------------------------------------------
// System and aplication specific headers
// ------------------------------------------
#include "interface.h"

int main( void ) {
    // Create perceptron
    initialGuide();
    int layers = askValue("Número de capas ", 1, 3);
    int iNeuron = askValue("Número de neuronas en la capa de entrada ", 1, 3);
    int in = askValue("Número de entradas ", 1, 3);
    int out = askValue("Número de neuronas en la capa de salida ", 1, 2);
    Perceptron_t *perceptron = newPerceptron(layers, iNeuron, in, out);
    
    // Record_t **set = loadSample("not.csv", 1);
    // train(set, perceptron);
    return 0;
}
