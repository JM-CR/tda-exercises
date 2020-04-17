// Author: Josue Mosiah Contreras Rocha
// File: main.c
// Date: 11/04/20

// ------------------------------------------
// System and aplication specific headers
// ------------------------------------------
#include "interface.h"

int main( void ) {
    // Create perceptron
    char *instructions[] = {
        "Número de capas ",
        "Número de neuronas en la capa de entrada ",
        "Número de entradas por neurona ",
        "Número de neuronas en la capa de salida "
    };
    
    initialGuide();
    int layers = askValue(instructions[0], 1, 3);
    int iNeuron = askValue(instructions[1], 1, 3);
    int in = askValue(instructions[2], 1, 3);
    int out = layers > 1 ? askValue(instructions[3], 1, 2) : 0;

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
    while ( true ) {
        unsigned int *inputs = askInputs(in);
    }

    return 0;
}
