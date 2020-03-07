// See node.h for more info
// Author: 
// File: node.c
// Date: 03/03/20

// ------------------------------------------
// System and aplication specific headers
// ------------------------------------------
#include <stdlib.h>
#include <stdio.h>
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

Node_t *newNode( int id, float cost, Node_t **nextN, size_t size, int8_t c_state ) {
    // Create node
    Node_t *node = malloc(sizeof(Node_t));
    node->id = id;
    node->cost = cost;
    node->c_state = c_state;
    node->nextN = calloc(size, sizeof(Node_t));

    // Connect
    newConnection(&node, nextN, size);
    return node;
}

void newConnection( Node_t **ppBase, Node_t *nodes[], size_t size ) {
    // Validate objects
    if ( *ppBase == NULL || nodes == NULL ) {
        return;
    }

    // Create connections
    for ( unsigned int i = 0; i < size; ++i  ) {
        (*ppBase)->nextN[i] = nodes[i];
    }
}

Node_t **findNode( int id[] ) {
    return NULL;
}

void printNode( const Node_t *pNode ) {
    printf(
        "\nID: %d\nCost: %f\nNext: %p\nState: 0x%02X\n",
        pNode->id,
        pNode->cost,
        pNode->nextN,
        pNode->c_state
    );
}
