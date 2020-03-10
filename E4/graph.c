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

void printRandomRoute( Node_t *initialNode ) {
	/* Checar si el initialNode tiene nodos adyacentes */
	/* aleatoriamente escoger un nodo */
	/* hacer lo mismo hasta que haya un null de lado que se eligio*/
	Node_t *current, *lastLine;
	current = lastLine = initialNode;
	
	int randomnumber;
	int inicio = 0;
	printNode(current);
	while ( lastLine != NULL ) {
		srand(time(NULL)); //Es aqui Mosh quiero que esto sea super aleatorio y cuando lo corro me sale el mismo valor siempre
		randomnumber = rand() % ((4+1)-1) + 1;
		printf("El numero random es: %d\n",randomnumber);
		if(randomnumber == 1){
			current = getAdjacentNode(current, UP);
		}
		if(randomnumber == 2){
			current = getAdjacentNode(current, DOWN);
		}
		if(randomnumber == 3){
			current = getAdjacentNode(current, LEFT);
		}
		if(randomnumber == 4){
			current = getAdjacentNode(current, RIGHT);
		}
		if(current == NULL && inicio == 0){
			srand(time(NULL));
			randomnumber = rand() % ((4+1)-1) + 1;
			printf("El numero random de inicio es: %d\n",randomnumber);
		}else{
			printNode(current);
			if(current == NULL){
				lastLine = NULL;
			}
		}
		inicio=inicio+1;
	}
	
	printf("\n\n");
}

Node_t *getAdjacentNode( const Node_t *node, Direction_t from ) {
	int8_t bits = getMask(from);
	return (node->c_state & bits) == bits ? node->nextN[from] : NULL;
}
