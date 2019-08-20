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

	Network initializeNetwork(vector<Neuron>InputNeurons, vector<Neuron>ListOfNeuronsInHiddenLayer, int NumberOfHiddenLayers, vector<Neuron>outputLayer); //design network
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
	ActivationFncENUM activationFunc; //switch activatio func mode
	ActivationFncENUM activationOutput; //switch output type "activation"
	TrainingTypesENUM trainType; //back propagate opt etc etc

public:
	//inputLayer &getInputLayer()
	//getters and setters
	void getInputLayer() {
		return inputLayer.printLayer;
	}
	void getHiddenLayer() //not done
	{
		//return HiddenLayer.;
	}
	int getMaxEpochs()
	{
		return maxEpochs;
	}

	int getTargetError()
	{
		return targetError;
	}

	double getLearningRate() {
		return LearningRate;
	}

	double GetErrorMean() {
		return trainingError;
	}

	double getMeanError() {
		return MeanError;
	}

	ActivationFncENUM getActivationfunction() {
		return activationFunc;
	}

	TrainingTypesENUM getTrainingType() {
		return trainType;
	}

	void setTrainingType(TrainingTypesENUM t) {
		trainType = t;
	}

	void setActivationFunction(ActivationFncENUM e) {
		activationFunc = e;
	}

	void setLearningRate(const double s) {
		LearningRate = s;
	}

	void setEpochs(const int e) {
		maxEpochs = e;
	}

	//accepts neurons. inputlayer is basically made up of neurons
	void setInputLayer(vector<Neuron>Neurons){
		inputLayer.setListOfNeurons(Neurons);
	 }
	
	void setHiddenLayer(vector<HiddenLayer>L) {
		//set number of neurons and copy paste the "empty" neurons to the new empty layers
		//hiddenLayer.setListOfNeurons
		//hiddenLayer = Layer;
		listOfHiddenLayer = L;
	}

	
};

Network::Network()
{
}

Network::~Network()
{
}

//connect input with hidden layer with output
inline Network Network::initializeNetwork(vector<Neuron>InputNeurons, vector<Neuron>ListOfNeuronsInHiddenLayer, int NumberOfHiddenLayers, vector<Neuron>outputLayer)
{
	//inputLayer.setListOfNeurons = 
	inputLayer.setListOfNeurons(InputNeurons);
	for (int i = 0; i < numberOfHiddenLayers; i++) {
		hiddenLayer.setListOfNeurons(ListOfNeuronsInHiddenLayer);
		listOfHiddenLayer.push_back(hiddenLayer);
	}
	outputLayer.setNumberOfNeuronsInLayer(outputLayer);
	//need to connect the list of hidden layer with input and outputlayer
	
	Network neuralNetwork;
	neuralNetwork.setInputLayer(InputNeurons);
	neuralNetwork.setHiddenLayer(listOfHiddenLayer);
	neuralNetwork.setOutputLayer(outputNeuron);

	return neuralNetwork;
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

