#pragma once
#include <stdlib.h>
#include <vector>
#include "Neuron.h"

using namespace std;
class Layer
{
public:
	Layer() {}
	~Layer() {}

	void printLayer() const {}

protected:
	vector<Neuron>Neurons;
	//dictate number of neurons
	size_t numberOfNeuronsInLayer;
};