#include "Neuron.h"

Neuron::Neuron()
{
	this->num_of_input = 0;
	this->input_weight = new double[num_of_input];
	//for (int i = 0; i < num_of_input; i++)
	//	input_weight[i] = 0;
	this->threshold = 0;
}

Neuron::Neuron(int num_of_input)
{
	this->num_of_input = 0;
	this->input_weight = new double[num_of_input];
	for (int i = 0; i < num_of_input; i++)
		input_weight[i] = -0.2;
	this->threshold = 0;
}
Neuron::~Neuron()
{
	delete[] input_weight;
}

bool Neuron::work(bool input[])
{
	double sum = 0;
	for (int i = 0; i < num_of_input; i++) {
		if (input[i])
			sum += input_weight[i];
	}
	if (sum >= threshold)
		return true;
	return false;
}
