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
	int cols = 4;
	int rows = 4;
	Node_t *root = createGraph(rows, cols);
	printRandomRoute(root, 10, rows, cols);

	int id[] = { 1, 2 };
	int size = sizeof(id) / sizeof(int);
	Node_t **result = findNode(id, root, size);
	for( int i = 0; i < size; i++) {
		printNode(result[i]);
	}
    return 0;
}