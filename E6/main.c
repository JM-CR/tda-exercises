// Author: Josue Mosiah Contreras Rocha
// File: main.c
// Date: 11/04/20

// ------------------------------------------
// System and aplication specific headers
// ------------------------------------------
#include "perceptron.h"

int main( void ) {
    Perceptron_t *perceptron = newPerceptron(3, 2, 2, 1);
    Record_t **set = loadSample("and.csv", 2);
    train(set, perceptron);
    return 0;
}
