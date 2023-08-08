#define num_inputs 2          // N1 = 2, Number of inputs for the 2D arrays to hold values regarding the input from the data.txt file
#define num_neurons_layer2 40 // N2 = 40, Number of neurons for layer 2 used to create arrays for weights, activation functions and biases 
#define num_neurons_layer3 20 // N3 = 20, Number of neurons for layer 3 used to create arrays for weights, acitvation functions, and biases 
#define num_outputs 2         // N4 = 2, Number of output values that are used to hold values for 2D arrays that deal with the output of the model
#define initial_range 0.2 //range of number from -initial_range to +inital_range used to create the random values for the weights

#define Learning_rate 0.005  // 0 - 1, 0.01 - 0.0001, 
#define epochs 100000 // Number of times the model is ran

#define MAX_ROWS 48120 // Max number of rows for the data.txt file
#define MAX_COLS 4 // Max numer of colums for the data.txt file
#define train_split 0.003 // 0.3 percent of data will be used for train


// good values : L1= 11, L2=8, LR=0.001, TS =0.049, epochs = 100001 or more