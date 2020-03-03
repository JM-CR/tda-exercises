// See node.h for more info
// Author: 
// File: node.c
// Date: 17/02/20

// ------------------------------------------
// System and aplication specific headers
// ------------------------------------------
#include <stdlib.h>
#include "node.h"


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

Node_t *newNode( int id, float cost, Node_t **nextN, int8_t c_state ) {
    Node_t *node = malloc(sizeof(Node_t));
    node->id = id;
    node->cost = cost;
    node->c_state = c_state;
    node->nextN = nextN;
    return node;
}

bool newConnection( Node_t *nodes[], size_t size, Node_t **ppBase ) {
    Node_t *pBase = *ppBase;
    
}

Node_t **findNode( int id[] ) {
    
}
