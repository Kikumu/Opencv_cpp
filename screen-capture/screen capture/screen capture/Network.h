#pragma once
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
	//NB: YOU WILL HAVE TO DESIGN INPUT AND OUTPUT LAYER FIRST BEFORE PASSING THEM INTO THE NETWORK
	//NB: NO NEED TO CREATE NEW NEURON VARIABLES BECAUSE THEY WILL ALL HAVE THEIR OWN BECAUSE THEY ALL EXTRACT DATA FROM PARENT/BASE CLASS(LAYER). YOU WILL JUST NEED TO SET HOW MANY NEURONS YOU NEED
	//EXAMPLE: "INPUTLAYER.SETLISTOFNEURONS(VECTOR<NEURONS>N)"

	Network initializeNetwork(inputLayer Input, vector<Neuron>ListOfNeuronsInHiddenLayer, int NumberOfHiddenLayers, outputLayer Output); //design network
	Network trainNetwork(Network n);
	void printNetwork(Network n);
	void printTrainedResult(Network n);
private:
	inputLayer InputLayer;
	HiddenLayer hiddenLayer;
	outputLayer OutputLayer;
	vector<HiddenLayer>listOfHiddenLayer;
	int numberOfHiddenLayers;

	vector<vector<double>>trainset; //saves a vector of a vector of doubles
	vector<double> realOutputSet; //what does this do?
	vector<vector<double>>realMatrixOutputSet; //have an idea what it does but not sure tho
	
	int maxEpochs;
	//basically the amount of time data passes through before weights are updated?
	//similar to LR?
	double LearningRate;
	double targetError;
	double trainingError;
	double MeanError;

	vector<double>listOfMSE;
	//measures network performance as per errors
	ActivationFncENUM activationFunc; //switch activatio func mode
	ActivationFncENUM activationOutput; //switch output type "activation"
	TrainingTypesENUM trainType; //back propagate opt etc etc

public:
	//inputLayer &getInputLayer()
	//getters and setters
	void getInputLayer() {
		return InputLayer.printLayer;
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
	vector<vector<double>>getTrainedSet() { //hypothesis, stores weights?
		return trainset;
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
	
	void setHiddenLayer(vector<HiddenLayer>L) {
		listOfHiddenLayer = L;
	}

	void setInputLayer(inputLayer I) {
		InputLayer = I;
	}

	void setOutputLayer(outputLayer O) {
		OutputLayer = O;
	}
	
	void setTrainSet(vector<vector<double>>n) {
		trainset = n;
	}
	
};

Network::Network()
{
}

Network::~Network()
{
}

//connect input with hidden layer with output
inline Network Network::initializeNetwork(inputLayer Input, vector<Neuron>ListOfNeuronsInHiddenLayer, int NumberOfHiddenLayers, outputLayer Output)
{
	for (int i = 0; i < numberOfHiddenLayers; i++) {
		hiddenLayer.setListOfNeurons(ListOfNeuronsInHiddenLayer);
		listOfHiddenLayer.push_back(hiddenLayer);
	}

	Network neuralNetwork;
	neuralNetwork.setInputLayer(Input); //FIXED
	neuralNetwork.setHiddenLayer(listOfHiddenLayer); //FIXED
	neuralNetwork.setOutputLayer(Output);//FIXED
	return neuralNetwork;
}

inline Network Network::trainNetwork(Network n)
{
	Network trainedNetwork;
	switch (n.trainType)
	{
		//to be implemented
	case TrainingTypesENUM::PERCEPTRON:
	{
		//PERCEPTRON h;
		//trainedNetwork
		return trainedNetwork;
	}
	case TrainingTypesENUM::BACKPROPAGATION:
	{
		return trainedNetwork;
	}
	default:
		cout << "Error network not trained";
	}
	return trainedNetwork;
}
inline void Network::printNetwork(Network n)
{
}
inline void Network::printTrainedResult(Network n)
{
}

