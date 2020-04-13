// See interface.h for more info
// Author: Josue Mosiah Contreras Rocha
// File: interface.c
// Date: 02/04/20

// ------------------------------------------
// System and aplication specific headers
// ------------------------------------------
#include <stdio.h>
#include <limits.h>
#include "interface.h"


// -----------------------------
// Private elements
// -----------------------------

/* Private functions */

/**
 * Reads an integer from the console and saves the result.
 *
 * @param state Location for the result.
 * @param lower Minimum value.
 * @param upper Maximum value.
 */
static void readOption( int *state, int lower, int upper ) {
    // Read
    int option = INT_MAX;
    printf("-> ");
    do {
        scanf("%d", &option);
        setbuf(stdin, NULL);
    } while ( option < lower || option > upper );

    // Save
    *state = option;
}


// -----------------------------
// Public elements
// -----------------------------

/* Implementation of the public functions */

void initialGuide( void ) {
    printf(
        "\nRed neuronal (perceptrón).\n\n"
        "Correcto uso del programa:\n"
        "\t1. Ingresar parámetros del perceptrón a crear.\n"
        "\t2. Seleccionar uno de los archivos de entrenamiento.\n"
        "\t3. Esperar entrenamiento el perceptrón.\n"
        "\t4. Indicar entradas manuales de prueba.\n\n"
        "Consideraciones:\n"
        "\t1. Máximo de capas = 3.\n"
        "\t2. Máximo de entradas = 3.\n"
        "\t3. Máximo de neuronas en la capa de entrada = 3.\n"
        "\t4. Máximo de neuronas en la cada de salida = 2.\n\n"
        "*Importante:\n"
        "\t1. Los archivos de entrenamiento se encuentran en training_files/.\n"
        "\t2. Los valores del usuario deben ser coherentes para que funcione el programa.\n"
        "\t3. El funcionamiento no se garantiza para perceptrones mayores a 1 x 1 X 1.\n"
        "\t4. Cuando converge, la gráfica muestra una línea completamente horizontal.\n"
    );
}

unsigned int askValue( char *text, int lower, int upper ) {
    // Display
    printf(
        "\n------------------------\n\n"
        "%s", text
    );
    int option;
    readOption(&option, lower, upper);

    // Translate
    return option;
}

char *askFile( void ) {
    // Display
    printf(
        "\n------------------------\n\n"
        "Elige el archivo de entrenamiento: \n\n"
        "  1. and.csv\n"
        "  2. or.csv\n"
        "  3. not.csv\n"
        "  4. xor.csv\n\n"
    );
    int option;
    readOption(&option, 1, 4);

    // Translate
    char *files[] = { "and.csv", "or.csv", "not.csv", "xor.csv" };
    return files[option - 1];
}
