// 
// Author: 
// File: node.h
// Date: 03/03/20

#ifndef NODE_H
#define NODE_H

// ------------------------------------------
// System specific headers
// ------------------------------------------
#include <stdbool.h>
#include <inttypes.h>
#include <stdio.h>


// -----------------------------
// Public interface
// -----------------------------

/* Types declarations */

typedef struct Node {
    int id;
    float cost;
    struct Node *nextN[];
    int8_t c_state;
} Node_t;

/* Function prototypes */

/**
 * Creates a new node.
 * 
 * @param id Node's id.
 * @param cost Arrival cost time.
 * @param nextN Nodes to connect.
 * @param c_state Connections' state.
 * @return Pointer to the new node.
 */
Node_t *newNode( int id, float cost, Node_t **nextN, int8_t c_state );

/**
 * Assigns nodes to a root node.
 * 
 * @param nodes Nodes that will be assign to the base node.
 * @param size Number of nodes.
 * @param ppBase Root node.
 * @return True if all assignments were correctly created; otherwise, false.
 */
bool newConnection( Node_t *nodes[], size_t size, Node_t **ppBase );

/**
 * Find a set of nodes using the given ids. 
 * 
 * @param id Ids to search.
 * @return Found nodes.
 */
Node_t **findNode( int id[] );

#endif
