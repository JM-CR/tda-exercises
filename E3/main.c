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

// Prototypes
void waitForEnter( void );
void printMenu( void );
void execute( char option );


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
    char option;
    do {
        printMenu();
        scanf("%c", &option);
        execute(option);
    } while ( option != '4' );

    return 0;
}


// -----------------------------
// Prototype's implementation
// -----------------------------

/**
 * Prints the options for the program.
 */
void printMenu(void) {
    printf("\e[1;1H\e[2J");
    printf(
        "--------------------\n"
        " Choose an option:\n"
        "--------------------\n"
        "\n1. Set new value."
        "\n2. Get value from buffer."
        "\n3. Add two elements."
        "\n4. Exit."
        "\n\n --> "
    );
}

/**
 * Pauses the program until the user presses [Enter].
 */
void waitForEnter(void) {
    printf("\n\n[Enter] to continue...");
    while( getchar() != '\n' );
    getchar();
}

/**
 * Decision control for the menu.
 *
 * @param option User's selection.
 */
void execute( char option ) {
    switch (option) {
        // Set
        case '1': {
            char newElement;
            printf("\nNew value to set: ");
            scanf(" %c", &newElement);

            int position;
            printf("\nPosition [1 - 4]: ");
            scanf(" %d", &position);
            setValue(newElement, position - 1);
            waitForEnter();
            break;
        }

        // Get
        case '2': {
            int position;
            printf("\nGet value from position [1 - 4]: ");
            scanf(" %d", &position);

            char currentValue = getValue(position - 1); 
            printf("\nCurrent value at %d is: %c", position, currentValue);
            waitForEnter();
            break;
        }

        // Sum
        case '3': {
            int firstValue;
            printf("\nFirst position from buffer [1 - 4]: ");
            scanf(" %d", &firstValue);

            int secondValue;
            printf("\nSecond position from buffer [1 - 4]: ");
            scanf(" %d", &secondValue);

            printf("\nThe sum is: %d", sumFromBuffer(firstValue, secondValue));
            waitForEnter();
            break;
        }
    }
}
