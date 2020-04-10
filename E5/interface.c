// See interface.h for more info
// Author: Josue Mosiah Contreras Rocha
// File: interface.c
// Date: 02/04/20

// ------------------------------------------
// System and aplication specific headers
// ------------------------------------------
#include <stdio.h>
#include "interface.h"


// -----------------------------
// Private elements
// -----------------------------

/* Private macros and constants */

/* Private types */

/* Private global variables */

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
    int option = 0;
    do {
        printf("-> ");
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
        "\nSimulador de neuronas tipo McCulloch & Pitts.\n\n"
        "Correcto uso del programa:\n"
        "\t1. Elegir el tipo de neurona a crear.\n"
        "\t2. Indicar si se desea conectar con otra.\n"
        "\t3. Ingresar las entradas solicitadas.\n"
        "\t4. Recibir resultados.\n\n"
        "La notación manejada se describe a continuación:\n"
        "\t1. Cada neurona tiene un id según su orden de creación.\n"
        "\t2. Las entradas se pedirán de la forma N(x,y) donde: x = id & y = entrada.\n"
        "\t3. Al conectar neuronas, la salida de una será la primer entrada de otra.\n"
        "\t4. Las entradas solo pueden tener valor de 0 ó 1.\n"
    );
}

int chooseNeuron( void ) {
    // Display
    printf(
        "\n------------------------\n\n"
        "Elige el tipo de neurona a crear: \n"
        "  1. AND\n"
        "  2. OR\n"
        "  3. NOT\n"
        "  4. XOR\n\n"
    );

    // Choose
    int option;
    readOption(&option, 1, 4);
    return option;
}

int askConnection( void ) {
    // Display
    printf(
        "\n------------------------\n\n"
        "¿Conectar con otra? \n"
        "  1. Sí\n"
        "  2. No\n\n"
    );

    // Choose
    int option;
    readOption(&option, 1, 2);
    return option;
}
