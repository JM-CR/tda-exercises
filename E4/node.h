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
#include <stddef.h>


// -----------------------------
// Public interface
// -----------------------------

/* Types declarations */

typedef struct Node {
    int id;
    float cost;
    struct Node **nextN;
    int8_t c_state;
} Node_t;

/* Function prototypes */

/**
 * Creates a new node.
 * 
 * @param id Node's id.
 * @param cost Arrival cost time.
 * @param nextN Nodes to connect.
 * @param size Number of nodes to connect.
 * @param c_state Connections' state.
 * @return Pointer to the new node.
 */
Node_t *newNode( int id, float cost, Node_t **nextN, size_t size, int8_t c_state );

/**
 * Assigns nodes to a root node.
 * 
 * @param ppBase Root node.
 * @param nodes Nodes that will be assign to the base node.
 * @param size Number of nodes.
 */
void newConnection( Node_t **ppBase, Node_t *nodes[], size_t size );

/**
 * Find a set of nodes using the given ids. 
 * 
 * @param id Ids to search.
 * @return Found nodes.
 */
Node_t **findNode( int id[] );

/**
 * Prints a node's content.
 *
 * @param pNode Node to print.
 */
void printNode( const Node_t *pNode );

#endif
