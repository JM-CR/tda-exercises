// Operations with buffers.
// Author: Josue Mosiah Contreras Rocha
// File: datatype.h
// Date: 23/01/2020

// ---------------------------------------------------
// Data structures.
// ---------------------------------------------------

typedef enum {
    INT, DOUBLE, CHAR
} Data_t;

size_t valueType;

// ---------------------------------------------------
// Public interface.
// ---------------------------------------------------

Data_t getType( char buffer[], size_t size );
void *getValue( char buffer[], Data_t ofType );
