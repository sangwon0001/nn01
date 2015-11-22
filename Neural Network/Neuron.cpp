#include "Neuron.h"
/*
Neuron::Neuron()
{
	this->num_of_input = 0;
	this->input_weight = new double[num_of_input];
//	for (int i = 0; i < num_of_input; i++)
//		input_weight[i] = 0;
//	this->threshold = 0;
}

Neuron::Neuron(int num_of_input,double alpha)
{
	this->num_of_input = num_of_input;
	this->input_weight = new double[num_of_input + 1];
	this->weight_error = new double[num_of_input + 1];
	this->alpha = alpha;
	for (int i = 0; i < num_of_input; i++){
		this->input_weight[i] = ((double)rand() / RAND_MAX) * 2 - 1;
		this->weight_error[i] = 0.0;
	}
//	this->threshold = 0;
}

Neuron::~Neuron()
{
	delete[] input_weight;
	delete[] weight_error;
}

double Neuron::work(double input[])
{
	double sum = 0;
	for (int i = 0; i < num_of_input; i++) {
		sum += input_weight[i] * input[i];
	}
	sum += input_weight[num_of_input] * 1.0;
	return sigmoid(sum);
}
void Neuron::learn(double input[], double target)
{
	double output = work(input);
	double output_error = output - target;

	for (int i = 0; i < num_of_input; i++)
	{
		weight_error[i] += output_error * input[i] * output * (1 - output);
	}
	weight_error[num_of_input] += output_error * 1.0 * output * (1 - output);
}

void Neuron::fix()
{
	for (int i = 0; i < num_of_input + 1; i++)
	{
		input_weight[i] -= alpha * weight_error[i];
		weight_error[i] = 0.0;
	}


}
//*/
Neuron::Neuron(int num_of_input, double alpha)
{
	this->num_of_input = num_of_input;
	this->alpha = alpha;
	input_weight = new double[num_of_input + 1];	// The last one is for constant input!
	weight_error = new double[num_of_input + 1];

	for (int i = 0; i<num_of_input + 1; i++)
	{
		input_weight[i] = ((double)rand() / RAND_MAX) * 2 - 1; // -1 ~ 1 Random
		weight_error[i] = 0.0;
	}
	

}
Neuron::Neuron(int index, int num_of_input, double alpha): Neuron(num_of_input,alpha)
{
	this->id_num = index;
}
Neuron::~Neuron()
{
	delete[] input_weight;
	delete[] weight_error;
}

double Neuron::work(double input[])
{
	double sum = 0;
	for (int i = 0; i<num_of_input; i++)
	{
		sum += input_weight[i] * input[i];
	}
	sum += input_weight[num_of_input] * 1.0;	// Constant input

	return sigmoid(sum);
}

void Neuron::learn(double input[], double target)
{
	double output = work(input);
	double output_error = output - target;

	for (int i = 0; i<num_of_input; i++)
	{
		weight_error[i] += output_error * input[i] * output * (1 - output);
	}
	weight_error[num_of_input] += output_error * 1.0 * output * (1 - output);
}
void Neuron::fix()
{
	for (int i = 0; i < num_of_input + 1; i++)
	{
		input_weight[i] -= alpha * weight_error[i];
		weight_error[i] = 0.0;
	}
}
//*/