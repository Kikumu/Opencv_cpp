#pragma once
#include <stdlib.h>
#include <vector>

using namespace std;
class Neuron{

public:
	Neuron() {}
	~Neuron() {}

	double initialiseNeuron(){
		return ((double)rand() / RAND_MAX);
	};

private:
	
	vector<double>weightsIn; //weight values passed into neuron
	vector<double>weightsOut; //weight values passed out from neuron
	double outputValue;
	double error;
	double sensibility;
}
