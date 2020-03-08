// See graph.h for more info
// Author: 
// File: graph.c
// Date: 07/03/20

// ------------------------------------------
// System and aplication specific headers
// ------------------------------------------
#include <stdlib.h>
#include <stdbool.h>
#include "graph.h"


// -----------------------------
// Private elements
// -----------------------------

/* Private macros and constants */

#define MAX_CONNECTIONS 4

#define U_MASK 0x80   // Up
#define D_MASK 0x40   // Down
#define L_MASK 0x20	  // Left
#define R_MASK 0x10   // Right


/* Private functions */

/**
 * Inserts a node over the base node at the given slot.
 *
 * @param baseNode Root node.
 * @param insertNode Node to insert.
 * @param slot Insertion's orientation.
 */
static void setSlot( Node_t **baseNode, Node_t **insertNode, Direction_t slot ) {
	// Update node
	switch (slot) {
	case UP:
		addConnection(baseNode, insertNode, 0);
		(*baseNode)->c_state |= U_MASK;
		break;

	case DOWN:
		addConnection(baseNode, insertNode, 1);
		(*baseNode)->c_state |= D_MASK;
		break;

	case LEFT:
		addConnection(baseNode, insertNode, 2);
		(*baseNode)->c_state |= L_MASK;
		break;

	case RIGHT:
		addConnection(baseNode, insertNode, 3);
		(*baseNode)->c_state |= R_MASK;
		break;
	}
}

/**
 * Creates a row fully connected between nodes.
 *
 * @param totalNodes Number of nodes in the row.
 * @param initialId ID for the initial node.
 * @return Pointer to the first element of the array.
 */
static Node_t **createRow( size_t totalNodes, unsigned int initialId ) { 
	// Create nodes
	unsigned int maxId = initialId + totalNodes;
	Node_t **row = calloc(totalNodes, sizeof(Node_t));

	for ( unsigned int i = 0, j = initialId; j < maxId; ++i, ++j ) {
		row[i] = newNode(j, 1, NULL, MAX_CONNECTIONS, 0);
	}

	// Connect nodes
	for ( unsigned int i = 0; i < totalNodes - 1; ++i ) {
		setSlot(&row[i], &row[i + 1], RIGHT);
		setSlot(&row[i + 1], &row[i], LEFT);
	}

	return row;
}


// -----------------------------
// Public elements
// -----------------------------

/* Implementation of the public functions */

Node_t *createGraph( size_t rows, size_t cols ) {
	// Guards
	if ( rows == 0 || cols == 0 ) {
		return NULL;
	}

	if ( rows == 1 ) {
		return *createRow(cols, 1);
	}

	// Start row's linkage
	Node_t **firstRow = createRow(cols, 1);
	Node_t *root = *firstRow;
	unsigned int id = 1 + cols;

	for ( unsigned int i = 1; i < rows; ++i ) {
		// Create
		Node_t **secondRow = createRow(cols, id); 

		// Link
		for ( unsigned int j = 0; j < cols; ++j ) {
			setSlot(&firstRow[j], &secondRow[j], DOWN);
			setSlot(&secondRow[j], &firstRow[j], UP);
		}

		// Update
		firstRow = secondRow;
		id += cols;
	}

	return root;
}

Node_t **findNode( int id[] ) {
	return NULL;
}

void printContents( Node_t *initialNode ) {
	// Initial values
	Node_t *current, *lastLine;
	current = lastLine = initialNode;

	while ( true ) {
		// Exit condition
		if ( lastLine == NULL ) break;

		// Print content
		printNode(current);
		current = getAdjacentNode(current, RIGHT);

		// Next line
		if ( current == NULL ) {
			lastLine = current = getAdjacentNode(lastLine, DOWN);
		}
	}
}

Node_t *getAdjacentNode( const Node_t *node, Direction_t from ) {
	switch (from) {
	case UP:
		return (node->c_state & U_MASK) == U_MASK ? node->nextN[0] : NULL;

	case DOWN:
		return (node->c_state & D_MASK) == D_MASK ? node->nextN[1] : NULL;

	case LEFT:
		return (node->c_state & L_MASK) == L_MASK ? node->nextN[2] : NULL;

	default:
		return (node->c_state & R_MASK ) == R_MASK ? node->nextN[3] : NULL;
	}
}
