#ifndef MYMODEL
#define MYMODEL

double sigmoid(double x);

double random_double(double min, double max);

int readfile(double input[MAX_ROWS][MAX_COLS]);

void ForwardPass(int num_train, double X_train[][num_inputs], double Y_train[][num_outputs],
                 double W2[][num_inputs], double W3[][num_neurons_layer2], double W4[][num_neurons_layer3],
                 double b2[][1], double b3[][1], double b4[][1],
                 double a2[][num_train], double a3[][num_train], double a4[][num_train]);

void BackwardPass(int num_train, double X_train[][num_inputs], double Y_train[][num_outputs],
                 double W2[][num_inputs], double W3[][num_neurons_layer2], double W4[][num_neurons_layer3],
                 double b2[][1], double b3[][1], double b4[][1],
                 double a2[][num_train], double a3[][num_train], double a4[][num_train],
                 double PL1[][num_train], double PL2[][num_train], double PL3[][num_train]);

void Evaluation(int num_train, double X_train[][num_inputs], double Y_train[][num_outputs],
                 double W2[][num_inputs], double W3[][num_neurons_layer2], double W4[][num_neurons_layer3],
                 double b2[][1], double b3[][1], double b4[][1],
                 double a2[][num_train], double a3[][num_train], double a4_eval_train[][num_train],
                 double X_val[][num_inputs],double Y_val[][num_inputs],int num_val, int ep);

#endif