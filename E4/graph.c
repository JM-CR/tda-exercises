// See graph.h for more info
// Author: 
// File: graph.c
// Date: 07/03/20

// ------------------------------------------
// System and aplication specific headers
// ------------------------------------------
#include <stdlib.h>
#include "graph.h"


// -----------------------------
// Private elements
// -----------------------------

/* Private macros and constants */

#define MAX_CONNECTIONS 4

/* Private types */

enum direction {
	UP, DOWN, LEFT, RIGHT
};

typedef enum direction Direction_t;   // Used to track c_state

/* Private functions */

/**
 * Inserts a node over the base node at the given slot.
 *
 * @param baseNode Root node.
 * @param insertNode Node to insert.
 * @param slot Insertion's orientation.
 */
void setSlot( Node_t **baseNode, Node_t **insertNode, Direction_t slot ) {
	// Update slot
	switch (slot) {
	case UP:
		addConnection(baseNode, insertNode, 0);
		(*baseNode)->c_state |= 0x80;
		break;

	case DOWN:
		addConnection(baseNode, insertNode, 1);
		(*baseNode)->c_state |= 0x40;
		break;

	case LEFT:
		addConnection(baseNode, insertNode, 2);
		(*baseNode)->c_state |= 0x20;
		break;

	case RIGHT:
		addConnection(baseNode, insertNode, 3);
		(*baseNode)->c_state |= 0x10;
		break;
	}
}

/**
 * Creates a row fully connected between nodes.
 *
 * @param totalNodes Number of nodes in the row.
 * @param initialId ID for the initial node.
 * @return Pointer to the first array's element.
 */
static Node_t **createRow( size_t totalNodes, unsigned int initialId ) { 
	// Create nodes
	Node_t **row = calloc(totalNodes, sizeof(Node_t));
	unsigned int maxId = initialId + totalNodes;
	for ( unsigned int i = initialId; i < maxId; ++i ) {
		row[i] = newNode(i, 1, NULL, MAX_CONNECTIONS, 0);
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
	Node_t **row = createRow(cols, 0);

	return NULL;
}
