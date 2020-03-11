// Graph simulator.
// Author: Josue Mosiah Contreras Rocha
// Author: Gabriela Rojano
// File: main.c
// Date: 07/03/20

// ------------------------------------------
// System and application specific headers
// ------------------------------------------
#include <stdlib.h>
#include "graph.h"

int main(void) {
	// Create
	int cols = 2;
	int rows = 2;
	Node_t *root = createGraph(rows, cols);
	printRandomRoute(root, 2, rows, cols);

	// Find nodes
	int id[] = { 1, 3, 2 };
	size_t size = sizeof(id) / sizeof(int);
	Node_t **result = findNode(root, id, size);
	for( int i = 0; i < size; ++i )
		printNode(result[i]);

    return 0;
}
