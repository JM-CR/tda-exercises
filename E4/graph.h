// 
// Author: 
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
 * Finds a set of nodes using the given ids. 
 * 
 * @param id Ids to search.
 * @return Found nodes.
 */
Node_t **findNode( int id[] );

/**
 * Prints nodes' contents of the full graph.
 *
 * @param initialNode Root node.
 */
void printContents( Node_t *initialNode );

/**
 * Searchs if a node has an adjacent element in the indicated direction.
 *
 * @param node Start point.
 * @param from Direction to look for.
 * @return Found node; otherwise, NULL.
 */
Node_t *getAdjacentNode( const Node_t *node, Direction_t from );

#endif
