// See compressor.h for more info
// Author: Josue Mosiah Contreras Rocha
// File: compressor.c
// Date: 03/02/20

// ------------------------------------------
// System and aplication specific headers
// ------------------------------------------
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "compressor.h"


// -----------------------------
// Private elements
// -----------------------------

// Private global variables
static uint32_t buffer = 0;

static uint32_t bitmask[] = {
    0xFFFFFF00, 0xFFFF00FF, 0xFF00FFFF, 0x00FFFFFF
};


// Private functions

/**
 * Converts one char into a 32 bits integer.
 *
 * @param element Char to convert.
 * @return Conversion's result.
 */
static uint32_t translate( char element ) {
    return element;
}

/**
 * Prints the binary equivalent of a number.
 *
 * @param x Number.
 * @return String with the result.
 */
static const char *numberToBinary(int x) {
    // Initial size
    static char b[33];
    b[0] = '\0';

    // Convert
    for ( uint32_t z = pow(2, 31); z > 0; z >>= 1 )
        strcat(b, ((x & z) == z) ? "1" : "0");

    return b;
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
void setValue( unsigned char element, int position ) {
    // Create value
    uint32_t valueToInsert = translate(element);
    valueToInsert <<= position * 8;

    // Insert
    buffer &= bitmask[position];
    buffer |= valueToInsert;
}

/**
 * Gets a char from the buffer.
 *
 * @param position Element to obtain.
 * @return Value at the position.
 */
char getValue( int position ) {
    // Get specific byte
    uint32_t value = buffer & ~bitmask[position];

    // Convert
    return value >> position * 8;
}

/**
 * Sums two elements from the buffer.
 *
 * @param first Position of the first element.
 * @param second Position of the second element.
 * @return Sum's result.
 */
uint32_t sumFromBuffer( int first, int second ) {
    return getValue(first) + getValue(second);
}
