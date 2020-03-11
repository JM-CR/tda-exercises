// See node.h for more info
// Author: Josue Mosiah Contreras Rocha
// Author: Gabriela Rojano
// File: node.c
// Date: 03/03/20

// ------------------------------------------
// System and aplication specific headers
// ------------------------------------------
#include <stdlib.h>
#include <stdio.h>
#include "node.h"


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
    return node;
}

void addConnection( Node_t **baseNode, Node_t **node, size_t position ) {
    // Guards
    if ( *baseNode == NULL || *node == NULL ) {
        return;
    }

    // Create connection
    (*baseNode)->nextN[position] = *node;
}

void printNode( const Node_t *node ) {
    // Guards
    if ( node == NULL ) {
        return;
    }

    // Get content
    printf(
        "\nID: %d\nCost: %f\nState: 0x%X0\n",
        node->id,
        node->cost,
        node->c_state
    );
}

int getNodeId( const Node_t *node ) {
    // Guards
    if ( node == NULL ) {
        return 0;
    }else{
        return node->id;
    }
}
