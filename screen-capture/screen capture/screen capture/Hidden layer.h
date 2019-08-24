#pragma once
#include "pch.h"
#include <stdlib.h>
#include "Layer.h"
#include "inputLayer.h"
#include "outputLayer.h"

//TODO: Mutations
//TOD0: FORWARD AND BACK PROPAGATION
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
	vector<HiddenLayer> initialiseLayer(vector<HiddenLayer> storeListOfHiddenLayers, const inputLayer& inputLayer, const outputLayer& outputLayer);

	//void setNumberOfNeuronsInHiddenLayer(int numberOfNeurons) {
	//	//this->numberOfNeuronsInLayer = numberOfNeurons; //snapped from layer.h
	//	//Layer l;
	//	setNumberOfNeuronsInLayer(numberOfNeurons);
	//}

	size_t getNumberOfNeuronsInHiddenLayer()
	{
		//this->getNumberOfNeuronsInHiddenLayer = getNumberOfNeuronsInLayer();
		//return getNumberOfNeuronsInLayer();
		//return getNumberOfNeuronsInLayer();
		return getNumberOfNeuronsInLayer();
	}

private:

};
//NB: Disadvantages of inlining to consider:
//go deep into benefits of inlining






inline vector<HiddenLayer>HiddenLayer::initialiseLayer(vector<HiddenLayer> storeListOfHiddenLayers, const inputLayer& inputLayer, const outputLayer& outputLayer)
{
	
	//initialise weight of neurons coming in and out(dependant on number of neurons in layer
	//THIS REVIEW THIS
	vector<Neuron>NeuronsInHiddenLayer;
	vector<double>incomingWeights; //neuron "data" in
	vector<double>outgoingWeights; //neuron "data" out

	//FOUND ERRORS. RE-IMPLEMENTING.....
	for (int i = 0; i < storeListOfHiddenLayers.size(); i++)
	{
		//what happens in each neuron in hidden layer
		for (int j = 0; j < getNumberOfNeuronsInHiddenLayer(); j++)
		{
			Neuron iNeuron;
			//limits are added to each neuron. ILIMIT IN AND ILIMIT OUT ARE JUST NEURONS
			size_t iLimitIn; //current number of neurons
			size_t iLimitOut; //new number of neurons(+ bias)

			//for each layer put a bias
			//after initialising all neurons in a vector put a bias
			if (i == 0)
			{
				iLimitIn = inputLayer.getNumberOfNeuronsInLayer;
				//get number of inputs/neurons
				//this probably will be a loop to grab all weight values and feed them into one neuron?
				//all these values are then squeezed and transformed between values of zero and one(decimals)
				//need to review this
				//aaah its added i+1 because of bias
				//the plusses and minuses are due to bias
				if (storeListOfHiddenLayers.size() > 1)
				{
					//iLimitOut = inputLayer.getNumberOfNeuronsInLayer; //gets number of neurons in input layer
					iLimitOut = storeListOfHiddenLayers[i + 1].getNumberOfNeuronsInLayer;
				}
				//if its only a one layered hidden layer
				else if (storeListOfHiddenLayers.size() == 1)
				{
					//TODO: IMPLEMENT OUTPUT LAYER
					iLimitOut = outputLayer.getNumberOfNeuronsInLayer;
				}
			}
			else if (i == (storeListOfHiddenLayers.size() - 1))
			{
				iLimitIn = storeListOfHiddenLayers[i + 1].getNumberOfNeuronsInLayer;
				iLimitOut = outputLayer.getNumberOfNeuronsInLayer;
			}
			else
			{
				iLimitIn = storeListOfHiddenLayers[i + 1].getNumberOfNeuronsInLayer;
				iLimitOut = outputLayer.getNumberOfNeuronsInLayer;
			}
			iLimitIn--;
			iLimitOut++;
			if (j >= 1)
			{
				for (size_t k = 0; k <= iLimitIn; k++)
				{
					//WEIGHT INITIALISED AND STORED HERE
					incomingWeights.push_back(iNeuron.initialiseNeuron());

				}
			}
			for (size_t k = 0; k <= iLimitOut; k++) {
				outgoingWeights.push_back(iNeuron.initialiseNeuron());
			}
			iNeuron.setListOfIncomingWeights(incomingWeights);
			iNeuron.setListOfOutgoingWeights(outgoingWeights);
		}
	}
	return storeListOfHiddenLayers;
}
