/* 
 * This is a basic implementation of a Dense layer expected to be found within
 * a Neural Network written in C. 
 *
 * A Dense layer feeds all outputs from the previous layer to its neurons, and
 * then each neuron in the layer provides a single output to the next layer. 
 * The layer performs the following transformation:
 * f(x) = <W*x> + b
 *
 * Author: William Ye
 *
 * INPUT:
 *      double inputs[BATCH_SIZE][INPUT_SIZE]
 *      double weights[INPUT_SIZE][OUTPUT_SIZE]
 *      double bias[OUTPUT_SIZE]
 *
 * OUTPUT:
 *      double outputs[BATCH_SIZE][OUTPUT_SIZE]
 */ 

#define BATCH_SIZE 1        // # of samples per batch
#define INPUT_SIZE 10       // # of neurons in input layer
#define OUTPUT_SIZE 5       // # of neurons in output layer

void dense_layer(
        double inputs[BATCH_SIZE][INPUT_SIZE], 
        double weights[INPUT_SIZE][OUTPUT_SIZE], 
        double bias[OUTPUT_SIZE], 
        double outputs[BATCH_SIZE][OUTPUT_SIZE])
{
    int batch, i, j;
    for (batch = 0; batch < BATCH_SIZE; batch++) {
        // For each batch, determine the output layer produced by that batch

        for (i = 0; i < OUTPUT_SIZE; i++) {
            // For each output neuron, the output is the sum of all input
            // neurons multiplied by their respective weights, plus a bias
            // output = inputs * weights + bias

            double neuron_output = 0.0;
            for (j = 0; j < INPUT_SIZE; j++) {
                neuron_output += inputs[batch][j] * weights[j][i];
            }
            outputs[batch][i] = neuron_output + bias[i];
        } 
    }
}
