// Compress chars into an integer.
// Author: Josue Mosiah Contreras Rocha
// File: compressor.h
// Date: 03/02/20

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

// -----------------------------
// Private elements
// -----------------------------

// Objects
static uint32_t buffer = 0;

// Function
static uint32_t translate( char element );


// -----------------------------
// Public interface
// -----------------------------

// Functions
bool validInput( char element );
void setValue( char element, int position );
char getValue( int position );
uint32_t sum( int first, int second );
