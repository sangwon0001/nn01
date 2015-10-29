#pragma once
//http://redcarrot.tistory.com/12
// http://blog.secmem.org/197
#define INIT_WEIGHT -0.3
class Neuron
{
private: 
	int num_of_input;
	double * input_weight;
	double threshold;
public:
	Neuron();
	Neuron(int num_of_input);
	~Neuron();
	bool work(bool input[]);
};

