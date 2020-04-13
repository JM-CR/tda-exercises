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
    int in = askValue("Número de entradas por neurona ", 1, 3);
    int out = layers > 1 ? askValue("Número de neuronas en la capa de salida ", 1, 2) : 0;
    Perceptron_t *perceptron = newPerceptron(layers, iNeuron, in, out);

    // Load training set
    char *file = askFile();
    Record_t **set = loadSample(file, in);
    
    // Start training
    train(set, perceptron);

    // Create error graph
    char *commands[] = {
        "set title 'Error de entrenamiento'",
        "set xlabel 'Ciclo'",
        "set ylabel 'Error absoluto",
        "plot 'error.txt' title '' with lines"
    };
    int length = sizeof(commands) / sizeof(char *);
    plot(commands, length);

    // Test network

    return 0;
}
