/* This code provides a basic implementation of a convoluational layer which
 * would be found within a Neural Network, implemented in C
 *
 * This is a simplified example of a convolutional layer, ignoring the
 * flatenning of input and any padding which would have been included with the
 * input layer.
 *
 * We assume a square input, hence INPUT_HEIGHT == INPUT_WIDTH
 *
 * Author: William Ye
 *
 * INPUTS:
 *      double inputs[BATCH_SIZE][INPUT_HEIGHT][INPUT_WIDTH]
 *      double filter[FILT_HEIGHT][FILT_WIDTH] 
 *      int stride
 *
 * OUTPUTS:
 *      double outputs[BATCH_SIZE][OUTPUT_HEIGHT][OUTPUT_WIDTH]
 *
 * note: OUTPUT_HEIGHT = (INPUT_HEIGHT - FILT_HEIGHT) / (STRIDE) + 1
 */

#include "conv.h"

void conv_layer(
        double inputs[BATCH_SIZE][INPUT_HEIGHT][INPUT_WIDTH],
        double filter[FILT_HEIGHT][FILT_WIDTH],
        double outputs[BATCH_SIZE][OUTPUT_HEIGHT][OUTPUT_WIDTH])
{
    int batch, out_i, out_j, filt_i, filt_j;
    int stride = STRIDE;
    for (batch = 0; batch < BATCH_SIZE; batch++) {
        // For every batch calculate the output layer
        for (out_i = 0; out_i < OUTPUT_HEIGHT; out_i++) {
            for (out_j = 0; out_j < OUTPUT_WIDTH; out_j++) {
                // For every output neuron, convolve the input with the filter
                double conv = 0.0;
                for (filt_i = 0; filt_i < FILT_HEIGHT; filt_i++) {
                    for (filt_j = 0; filt_j < FILT_WIDTH; filt_j++) {
                        // The starting location of the input depends on the stride
                        int in_i = out_i * stride + filt_i;
                        int in_j = out_i * stride + filt_j;
                        conv += inputs[batch][in_i][in_j] * filter[filt_i][filt_j];
                    }
                }
                outputs[batch][out_i][out_j] = conv;
            }
        }
    }
}
