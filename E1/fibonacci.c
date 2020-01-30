// Test for runtime perfomance using fibonacci
// fibonnaci.c

#include <stdio.h>
#include <time.h>
#include <stdbool.h>

enum { STEPS = 40 };

/**
 * Calculates the fibonacci number using an iterative approach.
 *
 * @param n Number of steps.
 * @return The fibonacci number.
 */
long long iterative(int n) {
    // Base case
    if ( n == 0 ) 
        return 0;
    else if ( n == 1 )
        return 1;
    
    // General case
    long long result = 0;
    for ( int i = 1, first = 0, second = 1; i < n; ++i ) {
        result = first + second;
        first = second;
        second = result;
    }
    return result;
}

/**
 * Calculates the fibonacci number using a recursive approach.
 *
 * @param n Number of steps.
 * @return The fibonacci number.
 */
long long recursive(int n) {
    // Base case
    if ( n == 0 ) 
        return 0;
    else if ( n == 1 )
        return 1;
        
    // Recursive case
    return recursive(n - 1) + recursive(n - 2);
}

/**
 * Appends data to a file using GNUPlot's format.
 *
 * @param file Filename.
 * @param data Values to write.
 * @param size Quantity of values.
 */
void saveState(const char *file, double data[], int size) {
    // Append data
    FILE *fp = fopen(file, "a");
    for ( int i = 0; i < size; ++i )
        fprintf(fp, "%lf ", data[i]);

    // Close
    fprintf(fp, "\n");
    fclose(fp);
}

/**
 * Send commands to GNUPlot.
 *
 * @param commands Settings for the plot.
 * @param size Number of commands.
 */
void plot(char *commands[], int size) {
    // Open stream
    FILE *pipe;
    if ( (pipe = popen("gnuplot -persistent", "w")) == NULL )
        return;

    // Read commands
    if ( commands != NULL )
        for ( int i = 0; i < size; ++i )
            fprintf(pipe, "%s\n", commands[i]);

    // Close stream
    pclose(pipe);
}


int main(void) {

    // Current state
    char file[] = "performance.txt";
    remove(file);

    // Testing
    double data[3];
    for ( int n = 0; n <= STEPS; ++n ) {
        // For iterative
        clock_t start_t1 = clock();
        (void) iterative(n);
        clock_t end_t1 = clock() - start_t1;
        data[1] = (double) end_t1 / CLOCKS_PER_SEC;

        // For recursive
        clock_t start_t2 = clock();
        (void) recursive(n);
        clock_t end_t2 = clock() - start_t2;
        data[2] = (double) end_t2 / CLOCKS_PER_SEC;

        // Save values
        data[0] = n;
        saveState(file, data, 3);
    }

    // Plot results
    char *commands[] = {
        "set title 'Performance test'",
        "set ylabel 'Time (s)'",
        "set xlabel 'Number of steps'",
        "plot 'performance.txt' u 1:2 title 'Iterative' with lines, '' u 1:3 title 'Recursive' with lines"
    };
    int length = sizeof(commands) / sizeof(char *);
    plot(commands, length);
    
    return 0;
}
