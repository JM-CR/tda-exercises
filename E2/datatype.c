// Author: Josue Mosiah Contreras Rocha
// File: datatype.c

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#include "datatype.h"

/**
 * Infers the datatype from a string buffer.
 * 
 * @param buffer Buffer with the data to check.
 * @param size Buffer's size.
 * @return Enum value.
 */
Data_t getType( char buffer[], size_t size ) {
    // Char precedence
    for ( int i = 0; i < size; ++i )
        if ( isalpha(buffer[i]) ) 
            return CHAR;
 
    // Float precedence
    if ( strstr(buffer, ".") != NULL )
        return DOUBLE;

    // Int precedence
    return INT;
}

/**
 * Gets the value from the buffer and converts it to the chosen type. 
 * The pointer's type is saved on the extern 'valueType' variable.
 *
 * @param buffer Buffer with the value.
 * @param ofType Type to convert.
 * @return Generic pointer to the new value, NULL in case of error.
 */
void *getValue( char buffer[], Data_t ofType ) {
    // Convert
    switch (ofType) {
        case CHAR: 
            valueType = sizeof(char);
            return buffer;

        case DOUBLE: {
            double value = atof(buffer), *ptr = &value;
            valueType = sizeof(double);
            return ptr;
        }

        case INT: {
            int value = atoi(buffer), *ptr = &value;
            valueType = sizeof(int);
            return ptr;
        }

        default:
            return NULL;
    }
}