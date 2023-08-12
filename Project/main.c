#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <sodium.h> // For randombytes_buf function
#include "constants.h"
#include "mymodel.h"


int main()
{
    // Initialize the 2D array to store the data
    double data[MAX_ROWS][MAX_COLS]; // data from the.txt file based on the max rows and colums in the file
    readfile(data); // function that reads the file and updates the data variables with the results

    int num_train = MAX_ROWS *train_split; // number of training variables
    int num_val = MAX_ROWS *(1-train_split); // number of validation variables

    printf("num_train =%d\n",num_train); // print statement for training variables
    printf("num_val = %d\n",num_val); // print statement for validation variables
    

    double X_train[num_train][num_inputs]; // input training variables 
    double Y_train[num_train][num_outputs]; // output training variables
    double X_val[num_val][num_inputs]; // input validation variables
    double Y_val[num_val][num_outputs]; // output validation variables

    for (int row = 0; row < num_train; row++) // loop to set up the input and output values for the training variables
    {
        X_train[row][0] = data[row][0]; // sets up the first input for the training data set 
        X_train[row][1] = data[row][1]; // sets up the second input for the training data set 
        Y_train[row][0] = data[row][2]; // sets up the first output for the training data set 
        Y_train[row][1] = data[row][3]; // sets up the second output for the training data set 
    }

    for (int row = num_train; row < MAX_ROWS; row++) // looping the validation data set after the num_train or train data set values
    {
        X_val[row - num_train][0] = data[row][0]; // does the inputs for the validation data set after the train set
        X_val[row - num_train][1] = data[row][1];
        Y_val[row - num_train][0] = data[row][2]; // does the output for the valiation data set after the train set
        Y_val[row - num_train][1] = data[row][3];
    }

    // weights and biases going into the second layer from the inputs
    double W2[num_neurons_layer2][num_inputs]; // initializes the weights based on the neurons and input values
    double b2[num_neurons_layer2][1]; // initalizes the bias value based on the number of neurons in the layer

    // weights and biases going into the third layer
    double W3[num_neurons_layer3][num_neurons_layer2]; 
    double b3[num_neurons_layer3][1];

    // weights and biases going to the  final output layer
    double W4[num_outputs][num_neurons_layer3];
    double b4[num_outputs][1];
    
    // Initialize W2 and b2 arrays with random values between -a and +a
    for (int i = 0; i < num_neurons_layer2; i++)
    {
        for (int j = 0; j < num_inputs; j++)
        {
            W2[i][j] = random_double(-initial_range, initial_range);
        }
        b2[i][0] = random_double(-initial_range, initial_range);
    }

    // Initialize W3 and b3 arrays with random values between -a and +a
    for (int i = 0; i < num_neurons_layer3; i++)
    {
        for (int j = 0; j < num_neurons_layer2; j++)
        {
            W3[i][j] = random_double(-initial_range, initial_range);
        }
        b3[i][0] = random_double(-initial_range, initial_range);
    }

    // Initialize W4 and b4 arrays with random values between -a and +a
    for (int i = 0; i < num_outputs; i++)
    {
        for (int j = 0; j < num_neurons_layer3; j++)
        {
            W4[i][j] = random_double(-initial_range, initial_range);
        }
        b4[i][0] = random_double(-initial_range, initial_range);
    }

    // the final output of each layer, every column is for a set of inputs
    double a2[num_neurons_layer2][num_train]; // result from layer 2
    double a3[num_neurons_layer3][num_train]; // result from layer 3
    double a4[num_outputs][num_train]; // result going out to the output

    double PL1[num_neurons_layer2][num_train]; //
    double PL2[num_neurons_layer3][num_train]; //
    double PL3[num_outputs][num_train]; //

    for (int ep = 0; ep < epochs; ep++) // goes through the iteration of the ANN model
    {
        // ###################################################### ForwardPass start
        ForwardPass(num_train, X_train, Y_train,
                    W2, W3, W4,
                    b2, b3, b4,
                    a2, a3, a4);
        // ###################################################### end of ForwardPass

        // ###################################################### BackwardPass start
        BackwardPass(num_train, X_train, Y_train,
                    W2, W3, W4,
                    b2, b3, b4,
                    a2, a3, a4,
                    PL1, PL2, PL3);
        // ###################################################### end of BackwardPass

        // ###################################################### Evaluation of accuracies starts
        if (ep%100==0)
        {
        double a4_eval_train[num_outputs][num_train]; // final output layer with trained data
        Evaluation(num_train, X_train, Y_train,
                    W2, W3, W4,
                    b2, b3, b4,
                    a2, a3, a4_eval_train,
                    X_val, Y_val, num_val,
                    ep);
        // ###################################################### end of Evaluation
        }
    }
}
