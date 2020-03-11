// Functions to create the necessary nodes for the graph.
// Author: Josue Mosiah Contreras Rocha
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
 * Assigns a node to the base node.
 * 
 * @param baseNode Root node.
 * @param node Node that will be assign.
 * @param position Array index ('nextN' element).
 */
void addConnection( Node_t **baseNode, Node_t **node, size_t position );

/**
 * Prints a node's content.
 *
 * @param pNode Node to print.
 */
void printNode( const Node_t *node );

/**
 * Get the id of the node
 *
 * @param pNode Node to get id
 */
int getNodeId( const Node_t *node );

#endif
