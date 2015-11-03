#include <iostream>
#include"Neuron.h"
#include <ctime>
using namespace std;
/*
void main() {
	Neuron* input_n1 = new Neuron(2);
	Neuron* input_n2 = new Neuron(2);
	Neuron* output_n = new Neuron(2);
	bool input[4][2] = { { 0,0 },{ 0,1 },{ 1,0 },{1,1} };
	bool middle_output[2] = { 0,0 };
	bool output;
	for (int i = 0; i < 4; i++) {
		middle_output[0] = input_n1->work(input[i]);
		middle_output[1] = input_n2->work(input[i]);
		output = output_n->work(middle_output);
		cout << "input : " << input[i][0] << " " << input[i][1] << " / output : " << output << endl;
	}
	delete input_n1;
	delete input_n2;
	delete output_n;
}
*/
void main()
{
	srand((unsigned)time(NULL));	// Set random seed

	Neuron* neuron = new Neuron(2, 0.1);

	// Sample Sets //
	double sample_input[4][2] = { { 0,0 },{ 0,1 },{ 1,0 },{ 1,1 } };
	double sample_output[4] = {1, 0, 0, 0 };

	for (int i = 0; i < 5000; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			neuron->learn(sample_input[j], sample_output[j]);
		}
		neuron->fix();

		// Print result //
		if ((i + 1) % 100 == 0)
		{
			cout << "------ Learn " << i + 1 << " times -----" << endl;
			for (int j = 0; j < 4; j++)
			{
				cout << sample_input[j][0] << ' ' << sample_input[j][1] << " : "<< neuron->work(sample_input[j]) << endl;
			}
		}
	}

	delete neuron;
}