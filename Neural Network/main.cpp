#include <iostream>
#include"Neuron.h"
using namespace std;

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