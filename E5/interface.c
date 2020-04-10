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

Type_t chooseNeuron( void ) {
    // Display
    printf(
        "\n------------------------\n\n"
        "Elige el tipo de neurona:\n\n"
        "  1. AND\n"
        "  2. OR\n"
        "  3. NOT\n"
        "  4. XOR\n\n"
    );
    int option;
    readOption(&option, 1, 4);

    // Translate
    Type_t type[] = { AND, OR, NOT, XOR };
    return type[option - 1];
}

bool askConnection( void ) {
    // Display
    printf(
        "\n------------------------\n\n"
        "¿Conectar con otra? \n\n"
        "  1. Sí\n"
        "  2. No\n\n"
    );
    int option;
    readOption(&option, 1, 2);

    // Translate
    return option == 1 ? true : false;
}

void askInputValues( Neuron_t *root ) {
    // Guard
    if ( root == NULL ) {
        return;
    }

    // Display
    printf(
        "\n------------------------\n\n"
        "Ingresar valores de entrada para cada neurona:\n\n"
        "  False = 0\n"
        "  True = 1\n\n"
    );

    // Translate
    int option;
    unsigned int id = 1;
    while ( root != NULL ) {
        // Get value
        for ( int input = 1; input <= 2; ++input ) {
            // Guards
            if ( id > 1 && root->type == NOT ) {
                break;
            } else if ( id > 1 ) {
                input = 2;
            }

            // Process
            printf("N(%d, %d) ", id, input);
            readOption(&option, 0, 1);

            // Check
            if ( id == 1 && root->type == NOT ) {
                setValue(root, 0, option);
                break;
            } else if ( id == 1 ) {
                setValue(root, input - 1 , option);
            } else {
                setValue(root, 1, option);
            }
        }

        // Update values
        root = root->next;
        id++;
    }
}
