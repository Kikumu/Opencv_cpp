#pragma once
#include "pch.h"
#include <stdlib.h>
#include "Layer.h"
#include "inputLayer.h"
#include "outputLayer.h"
#include "Neuron.h"
//TODO: Mutations
//needs to receive all data from previous layers
//similar to input layer but different
//functions are carried out here(activation functions, biases, drop outrates)
//confidence rates, probabilities, decision making etc etc
//'confidence scores' for which decision it decided to ultimately make

using namespace std;

class HiddenLayer : public Layer {

public:
	//constructor
	HiddenLayer()
	{

	}
	//destructor
	~HiddenLayer()
	{

	}
	//take in a vector of hidden layers, dependant on how many hidden layers you would like to have
	//take an input layer
	//take an output layer
	//set neurons on here?
	//first val decide whats in the hidden layer, how many hidden layers do you need,input and output layers.
	//restructure this to all neurons and vectors and layers to be designed in this function
	//decided to put neurons here
	vector<HiddenLayer> initialiseLayer(const HiddenLayer&, vector<HiddenLayer>&, const inputLayer&, const outputLayer&, vector<Neuron>&);
	void setNumberOfNeuronsInHiddenLayer(int numberOfNeurons) {
		this->numberOfNeuronsInLayer = numberOfNeurons; //snapped from layer.h
	}

private:


};
//NB: Disadvantages of inlining to consider:

//go deep into benefits of inlining
inline vector<HiddenLayer>HiddenLayer::initialiseLayer(const HiddenLayer& hiddenLayerDesign, vector<HiddenLayer>& storeListOfHiddenLayers, const inputLayer& inputLayer, const outputLayer& outputLayer, vector<Neuron>&nNeuron)
{
	//initialise weight of neurons coming in and out(dependant on number of neurons in layer
	//vector<Neuron>NeuronsInHiddenLayer;
	vector<double>incomingWeights; //neuron "data" in
	vector<double>outgoingWeights; //neuron "data" out

	//what happens in each hidden layer. Heavy weight here
	for (int i = 0; i < storeListOfHiddenLayers.size(); i++)
	{
		//what happens in each neuron in hidden layer
		for (int j = 0; j < nNeuron.size(); j++)
		{
			//for first loop take in data(neurons) from input layer and multiply them by their weights
			//y = sum of(weight * input) + bias
			//y being the "value" of the neuron
			//weight attatched to each neuron
			//biases
			Neuron iNeuron;

			size_t iLimitIn; //bias(bias has its own weight)
			size_t iLimitOut;

			if (i == 0)
			{
				iLimitIn = inputLayer.getListOfNeurons.
			}
		}
	}
}
