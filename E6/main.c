// Author: Josue Mosiah Contreras Rocha
// File: main.c
// Date: 11/04/20

// ------------------------------------------
// System and aplication specific headers
// ------------------------------------------
#include "perceptron.h"

int main( void ) {
    Perceptron_t *perceptron = newPerceptron(1, 1, 1, 0);
    Record_t **set = loadSample("not.csv", 1);
    train(set, perceptron);
    return 0;
}
