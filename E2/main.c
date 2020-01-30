// Author: Josue Mosiah Contreras Rocha
// File: main.c

#include <stdio.h>
#include "datatype.h"

#define LENGTH 64

int main(void) {
    
    // Load buffer
    char buffer[LENGTH] = { '\0' };
    fgets(buffer, LENGTH - 1, stdin);

    // Get buffer's content
    Data_t test = getType(buffer, LENGTH);
    void *result = getValue(buffer, test);

    // Print
    switch (valueType) {
    case sizeof(char):
        printf("Buffer's value: %s\n", (char *)result);
        break;
    
    case sizeof(double):
        printf("Buffer's value: %f\n", *(double *)result);
        break;

    case sizeof(int):
        printf("Buffer's value: %d\n", *(int *)result);
        break;
    }

    return 0;
}