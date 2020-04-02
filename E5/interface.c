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
        "\t4. Las entradas solo pueden tener valor de 0 ó 1.\n\n"
    );
}
