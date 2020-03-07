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

/* Function prototypes */

/**
 * Creates a grid fully connected with size of r * c.
 *
 * @param rows Number of rows.
 * @param cols Number of columns.
 * @return Pointer to the root node.
 */
Node_t *createGraph( size_t rows, size_t cols );

#endif
