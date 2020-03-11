// Functions that simulates a graph using the Top-Down approach.
// Author: Josue Mosiah Contreras Rocha
// Author: Gabriela Rojano
// File: graph.h
// Date: 07/03/20

#ifndef GRAPH_H
#define GRAPH_H

// ------------------------------------------
// System specific headers
// ------------------------------------------
#include "node.h"


// -----------------------------
// Public interface
// -----------------------------

/* Types declarations */

enum direction {
	UP, DOWN, LEFT, RIGHT
};

typedef enum direction Direction_t;   // Used to track c_state


/* Function prototypes */

/**
 * Creates a grid fully connected with size of r * c.
 * If one or both parameters are zero, it will return a NULL pointer.
 *
 * @param rows Number of rows.
 * @param cols Number of columns
 * @return Pointer to the root node.
 */
Node_t *createGraph( size_t rows, size_t cols );

/**
 * Prints nodes' contents using the fully connected graph.
 *
 * @param initialNode Root node.
 */
void printContents( Node_t *initialNode );

/**
 * Prints a random route using the fully connected graph.
 *
 * @param initialNode Root node.
 * @param pathNumber Number of segments to draw.
 * @param rows Number of rows that the graph has.
 * @param cols Number of columns that the graph has.
 */
void printRandomRoute( Node_t *initialNode, int pathNumber, int rows, int cols );

/**
 * Searchs if a node has an adjacent element in the indicated direction.
 *
 * @param node Start point.
 * @param from Direction to look for.
 * @return Found node; otherwise, NULL.
 */
Node_t *getAdjacentNode( const Node_t *node, Direction_t from );

/**
 * Finds a set of nodes using the given ids. 
 * 
 * @param baseNode Root node.
 * @param id Ids to search.
 * @param size Number of ids to search.
 * @return Sorted array with the found nodes.
 */
Node_t **findNode( Node_t *baseNode, int id[], size_t size );

#endif
