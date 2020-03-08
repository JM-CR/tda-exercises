// Author: Josue Mosiah Contreras Rocha
// File: main.c
// Date: 22/02/20

// ------------------------------------------
// System and application specific headers
// ------------------------------------------
#include <stdlib.h>
#include "graph.h"

int main(void) {
	Node_t *root = createGraph(2, 3);
	printContents(root);

    return 0;
}