// Compress chars into an integer.
// Author: Josue Mosiah Contreras Rocha
// File: compressor.h
// Date: 03/02/20

// -----------------------------
// System headers
// -----------------------------
#include <stdint.h>
#include <stdbool.h>


// -----------------------------
// Public interface
// -----------------------------

// Functions
bool validInput( unsigned char element );
void setValue( unsigned char element, int position );
char getValue( int position );
uint32_t sum( int first, int second );
