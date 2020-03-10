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
	Node_t *root = createGraph(3, 3);
	printRandomRoute(root);
	printContents(root);

    return 0;
}