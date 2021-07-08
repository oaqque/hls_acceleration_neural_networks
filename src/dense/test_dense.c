/* A test to ensure that the dense layer is working as intended.
 *
 * Author: William Ye
 */

#include "dense.c"
#include <stdio.h>

#define BATCH_SIZE 1
#define INPUT_SIZE 10
#define OUTPUT_SIZE 5

void printOutput(double output_layer[BATCH_SIZE][OUTPUT_SIZE]);

int main(void) {
    // Initialise the variables
    double inputs[BATCH_SIZE][INPUT_SIZE] = {{0.2, 0.2, 0.2, 0.2, 0.2, 0.2, 0.2, 0.2, 0.2, 0.2}};
    double weights[OUTPUT_SIZE][INPUT_SIZE] = {
        {0.2, 0.2, 0.2, 0.2, 0.2, 0.2, 0.2, 0.2, 0.2, 0.2},
        {0.2, 0.2, 0.2, 0.2, 0.2, 0.2, 0.2, 0.2, 0.2, 0.2},
        {0.2, 0.2, 0.2, 0.2, 0.2, 0.2, 0.2, 0.2, 0.2, 0.2},
        {0.2, 0.2, 0.2, 0.2, 0.2, 0.2, 0.2, 0.2, 0.2, 0.2},
        {0.2, 0.2, 0.2, 0.2, 0.2, 0.2, 0.2, 0.2, 0.2, 0.2},
    };
    double bias[OUTPUT_SIZE] = {0.5, 0.5, 0.5, 0.5, 0.5};
    double outputs[BATCH_SIZE][OUTPUT_SIZE];

    // Run the variables through our Dense layer
    dense_layer(inputs, weights, bias, outputs);

    // Print the resulting output layer
    printOutput(outputs);
}

void printOutput(double output_layer[BATCH_SIZE][OUTPUT_SIZE]) {
    for (int i = 0; i < BATCH_SIZE; i++) {
        for (int j = 0; j < OUTPUT_SIZE; j++) {
            printf("%f ", output_layer[i][j]);
        }
    }
    printf("\n");
}
