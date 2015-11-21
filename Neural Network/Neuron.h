#pragma once
#include <cstdlib>
#include <cmath>
#define sigmoid(x) (1.0 / (1.0 + exp(-(x))))
#define INIT_WEIGHT -0.3
class Neuron
{
private: 
	int id_num,num_of_input;
	double * input_weight,*weight_error;
	double alpha;
public:
	Neuron(int num_of_input, double alpha);
	Neuron(int index, int num_of_input, double alpha);
	~Neuron();
	double work(double input[]);
	void learn(double input[], double target);
	void fix();
};

