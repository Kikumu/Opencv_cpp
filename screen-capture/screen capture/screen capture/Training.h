#pragma once
//forward propagation
#include "Network.h"

using namespace std;
class Training
{
public:
	Training();
	~Training();

	Network trainNetwork(Network n);
	

private:
	int epochs = NULL;
	double error = NULL;
	double MeanSquaredError = NULL;

	vector<Neuron>TeachLayerNeurons(size_t, size_t, Network, double); //whats this? incoming val plus weights, network layer and activation func?
	//activation functions
	// where the variable "n" is the summation of inputs and weights
	
	double fncSigmoid(double n) { return 1.0 / (1.0 + exp(-n)); }
	
		//for back propagation
	double fncSigmoidDerivative(double n) {

	}
	double funcSinc(double n) {
		int x = NULL;
		if (n != 0)
			x = sin(n) / n;
		else if (n == 1)
			x = 0;
		return x;
	}

	//for back propagation
	double funcSincDerivative(double n) {
		int x = NULL;
		if (n != 0)
			x = cos(n) / n - sin(x) / pow(n, 2);
		else if (n == 0)
			x = 0;
		return x;
	}
};

Training::Training()
{
}

Training::~Training()
{
}

inline Network Training::trainNetwork(Network n)
{

	return Network();
}
inline vector<Neuron> Training::TeachLayerNeurons(size_t, size_t, Network, double)
{
	return vector<Neuron>();
}


