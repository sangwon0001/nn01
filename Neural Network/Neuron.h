#pragma once
//http://redcarrot.tistory.com/12
//http://blog.secmem.org/197
//http://blog.secmem.org/199
#include <cstdlib>
#include <cmath>
#define sigmoid(x) (1.0 / (1.0 + exp(-(x))))
#define INIT_WEIGHT -0.3
class Neuron
{
private: 
	int num_of_input;
	double * input_weight,*weight_error;
//	double threshold;
	double alpha;
public:
	Neuron();
	Neuron(int num_of_input,double alpha);
	~Neuron();
	double work(double input[]);
	void learn(double input[], double target);
	void fix();
};

