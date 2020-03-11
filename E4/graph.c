// See graph.h for more info
// Author: Josue Mosiah Contreras Rocha 
// File: graph.c
// Date: 07/03/20

// ------------------------------------------
// System and aplication specific headers
// ------------------------------------------
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <time.h>
#include "graph.h"


// -----------------------------
// Private elements
// -----------------------------

/* Private macros and constants */

#define MAX_CONNECTIONS 4

#define U_MASK 0x08   // Up
#define D_MASK 0x04   // Down
#define L_MASK 0x02	  // Left
#define R_MASK 0x01   // Right

static const int8_t masks[] = {
	U_MASK, D_MASK, L_MASK, R_MASK
};


/* Private functions */

/**
 * Translates a direction to its corresponding bitmask.
 *
 * @param from Direction to translate.
 * @return Corresponding bitmask.
 */
static int8_t getMask( Direction_t from ) {
	return masks[from];
}

/**
 * Inserts a node over the base node at the given slot.
 *
 * @param baseNode Root node.
 * @param insertNode Node to insert.
 * @param slot Insertion's orientation.
 */
static void setSlot( Node_t **baseNode, Node_t **insertNode, Direction_t slot ) {
	// Update node
	addConnection(baseNode, insertNode, slot);
	(*baseNode)->c_state |= getMask(slot);
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

/**
 * Produces a random direction.
 *
 * @return The direction.
 */
static Direction_t randomDirection( void ) {
	// Initial set up
	static bool firstRun = true;
	if ( firstRun ) {
		firstRun = false;
		srand(time(0));
	}

	// Get random
	return (Direction_t)(rand() % (RIGHT + 1));
}

/**
 * Fills a grid with the desired character.
 *
 * @param rows Number of rows.
 * @param cols Number of columns.
 * @param grid Grid to fill.
 * @param with Char to use.
 */
static void fillGrid( size_t rows, size_t cols, char grid[cols][rows], char with ) {
	for ( int r = 0; r < rows; ++r )
		for ( int c = 0; c < cols; ++c )
			grid[r][c] = with;
}

/**
 * Used to print a random path.
 * 
 * @param rows Number of rows.
 * @param cols Number of columns.
 * @param path Path to draw.
 */
static void printRoute( size_t rows, size_t cols, char path[rows][cols] ) {
	for ( int r = 0; r < rows; ++r ) {
		for ( int c = 0; c < cols; ++c  ) {
			printf("%c ", path[r][c]);
		}
		printf("\n");
	}
}

/**
 * Checks one id against an array of elements.
 *
 * @param id ID to check.
 * @param elements Objects to compare.
 * @param size Number of elements.
 * @return True if there is a match; otherwise, false.
 */
static bool containsId( int id, int elements[], size_t size ) {
	bool flag = false;
	for ( int i = 0; i < size; ++i ) {
		if ( id == elements[i] ) {
			flag = true;
			break;
		}
	}
	return flag;
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

void printContents( Node_t *initialNode ) {
	// Initial values
	Node_t *current, *lastLine;
	current = lastLine = initialNode;

	while ( lastLine != NULL ) {
		// Print content
		printNode(current);
		current = getAdjacentNode(current, RIGHT);

		// Next line
		if ( current == NULL ) {
			lastLine = current = getAdjacentNode(lastLine, DOWN);
		}
	}
}

void printRandomRoute( Node_t *initialNode, int pathNumber, int rows, int cols ) {
	// Guards
	if ( initialNode == NULL || pathNumber <= 0 || rows <= 0 || cols <= 0 ) {
		return;
	}

	// Create route
	Node_t *currentNode, *lastNode;
	currentNode = lastNode = initialNode;
	
	char coordinates[rows][cols];
	fillGrid(rows, cols, coordinates, ' ');

	for ( unsigned int x = 0, y = 0, count = 0; count < pathNumber; ) {
		// Get random node
		Direction_t value = randomDirection();
		currentNode = getAdjacentNode(currentNode, value);
		
		// Guards
		if ( currentNode == NULL ) {
			currentNode = lastNode;
			continue;
		} else {
			lastNode = currentNode;
			++count;
		}

		// Draw point
		coordinates[x][y] = '*';

		// Update coordinates
		if ( value == UP ) 		   y = (y > 0) ? (y - 1) : y;
		else if ( value == DOWN  ) ++y;
		else if ( value == LEFT  ) x = (x > 0) ? (x - 1) : x;
		else if ( value == RIGHT ) ++x;
	}
	printRoute(rows, cols, coordinates);
}

Node_t **findNode( Node_t *baseNode, int id[], size_t size ) {
	// Create memory
	int lastFound = 0;
    Node_t **matches = calloc(size, sizeof(Node_t));
	for ( int i = 0; i < size; ++i ) {
		matches[i] = NULL;
	}

	// Search
	Node_t *current, *lastLine;
	current = lastLine = baseNode;
	while ( lastLine != NULL ) {
		// Find matches
		if ( containsId(current->id, id, size) ) {
			matches[lastFound++] = current;
		}

		// Next line
		current = getAdjacentNode(current, RIGHT);
		if ( current == NULL ) {
			lastLine = current = getAdjacentNode(lastLine, DOWN);
		}
	}

	return matches;
}

Node_t *getAdjacentNode( const Node_t *node, Direction_t from ) {
	int8_t bits = getMask(from);
	return (node->c_state & bits) == bits ? node->nextN[from] : NULL;
}
