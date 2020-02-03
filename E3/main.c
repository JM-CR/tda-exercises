// Author: Josue Mosiah Contreras Rocha
// File: main.c
// Date: 03/02/20

// ------------------------------------------
// System and aplication specific headers
// ------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "compressor.h"

/**
 * Current status for the program.
 */
int main( int argc, char *argv[] ) {

    // Check arguments
    if ( argc > 5 ) {
        fprintf(stderr, "\nUse only one to four characters as arguments.\n");
        fprintf(stderr, "\nUsage: ./a.out <char1> <char2> <char3> <char4>\n\n");
        exit(EXIT_FAILURE);
    }

    for ( int i = 1; i <= argc - 1; ++i )
        if ( strlen(argv[i]) != 1 ) {
            fprintf(stderr, "\nArguments can only be one length characters.\n\n");
            exit(EXIT_FAILURE);
        }

    // Initialize from console
    if ( argc > 1 ) 
        for ( int i = 1; i <= argc - 1; ++i ) {
            if ( validInput(*argv[i]) ) {
                setValue(*argv[i], i - 1);
            } else {
                fprintf(stderr, "\nInvalid characters from arguments.\n\n");
                exit(EXIT_FAILURE);
            }
        }

    // Print menu

    return 0;
}