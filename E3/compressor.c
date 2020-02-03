// See compressor.h for more info
// Author: Josue Mosiah Contreras Rocha
// File: compressor.c
// Date: 03/02/20

// ------------------------------------------
// System and aplication specific headers
// ------------------------------------------
#include <stdio.h>
#include "compressor.h"


// -----------------------------
// Private elements
// -----------------------------

// Private global variables
static uint32_t buffer = 0;


// Private functions

/**
 * Converts one char into a 32 bits integer.
 *
 * @param element Char to convert.
 * @return Conversion's result.
 */
static uint32_t translate( char element ) {
    return 1;
}


// -----------------------------
// Public elements
// -----------------------------

// Public functions

/**
 * Checks if the char's value is less or equal to 255.
 *
 * @param element Character to checks.
 * @return True if the char passes.
 */
bool validInput( unsigned char element ) {
    return element <= 255;
}

/**
 * Fills the buffer with one char at a specific position.
 *
 * @param element Element to insert.
 * @param position Alignment inside the buffer [0 - 3].
 */
void setValue( char element, int position ) {
    
}

/**
 * Gets a char from the buffer.
 *
 * @param position Element to obtain.
 * @return Value at the position.
 */
char getValue( int position ) {
    return 'a';
}

/**
 * Sums two elements from the buffer.
 *
 * @param first Position of the first element.
 * @param second Position of the second element.
 * @return Sum's result.
 */
uint32_t sum( int first, int second ) {
    return 1;
}
