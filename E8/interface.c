// See interface.h for more info
// Author: Josue Mosiah Contreras Rocha
// File: interface.c
// Date: 02/05/20

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
        "\nCalculadora con máquina de estados.\n"
        "\nCorrecto uso del programa:\n"
        "\t1. Seleccionar el tipo de operación.\n"
        "\t2. Ingresar números a operar.\n"
        "\t3. Esperar el resultado en pantalla.\n"
    );
}

void printMenu( void ) {
    printf(
        "\n------------------------\n\n"
        "Operaciones disponibles:\n"
        "\t1. Suma.\n"
        "\t2. Resta.\n"
        "\t3. Multiplicación.\n"
        "\t4. División.\n"
    );
}

double askInputValue( char *text ) {
    // Display
    printf(
        "\n------------------------\n\n"
        "%s-> ", text
    );
    double value;
    scanf("%lf", &value);

    // Translate
    return value;
}

Operation_t askMenuValue( char *text, int lower, int upper ) {
    // Display
    printf("\n%s", text);
    int option;
    readOption(&option, lower, upper);

    // Translate
    Operation_t type[] = { ADD, SUBSTRACT, MULTIPLY, DIVIDE };
    return type[option - 1];
}

void printResult( double result ) {
    // Display
    printf(
        "\n------------------------\n\n"
        "Resultado = %.2lf\n\n", result
    );
}
