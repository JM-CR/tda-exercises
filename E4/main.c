// Author: Josue Mosiah Contreras Rocha
// File: main.c
// Date: 22/02/20

// ------------------------------------------
// System and application specific headers
// ------------------------------------------
#include <stdlib.h>
#include "graph.h"

#define TOTAL 5
#define NEXT_SIZE 4

int main(void) {
	Node_t **arr = calloc(TOTAL, sizeof(Node_t));
	for ( int i = 0; i < TOTAL; ++i ) {
		arr[i] = newNode(i, 1, NULL, NEXT_SIZE, 0);
		printNode(arr[i]);
	}

    return 0;
}