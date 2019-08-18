#pragma once
//link assist: https://towardsdatascience.com/under-the-hood-of-neural-network-forward-propagation-the-dreaded-matrix-multiplication-a5360b33426
//BIASES HAVE A VECTOR OF ONES?
//why do we need to transpose?
//to avoid mis multiplication of the matrices

#include "Hidden layer.h"
#include "Layer.h"
#include "Matrix.h"
#include "enum.h"
#include "identityMatrix.h"
#include "inputLayer.h"
#include "outputLayer.h"

class Network
{
public:
	Network();
	~Network();

	Network initializeNetwork(int numberOfInputNeurons, int numberOfHiddenLayers, int NumberOfHiddenLayerNeurons, int numberOfOutputNeurons); //design network
	Network trainNetwork(Network n);
	void printNetwork(Network n);
	void printTrainedResult(Network n);
private:
	inputLayer inputLayer;
	HiddenLayer hiddenLayer;
	outputLayer outputLayer;
	vector<HiddenLayer>listOfHiddenLayer;
	int numberOfHiddenLayers;

	vector<vector<double>>trainset; //saves a vector of a vector of doubles
	vector<double> realOutputSet; //what does this do?
	vector<vector<double>>realMatrixOutputSet; //have an idea what it does but not sure tho
	
    //what are epochs? link: https://uk.mathworks.com/matlabcentral/answers/62668-what-is-epoch-in-neural-network
	int maxEpochs;
	//basically the amount of time data passes through before weights are updated?
	//similar to LR?
	//link assist?: https://towardsdatascience.com/epoch-vs-iterations-vs-batch-size-4dfb9c7ce9c9
	double LearningRate;
	double targetError;
	double trainingError;
	double MeanError;

	vector<double>listOfMSE;
	//measures network performance as per errors
	//mse definition link: https://edoras.sdsu.edu/doc/matlab/toolbox/nnet/mse.html

};

Network::Network()
{
}

Network::~Network()
{
}

inline Network Network::initializeNetwork(int numberOfInputNeurons, int numberOfHiddenLayers, int NumberOfHiddenLayerNeurons, int numberOfOutputNeurons)
{
	return Network();
}
inline Network Network::trainNetwork(Network n)
{
	return Network();
}
inline void Network::printNetwork(Network n)
{
}
inline void Network::printTrainedResult(Network n)
{
}

