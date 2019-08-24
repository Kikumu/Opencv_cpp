#pragma once
#include "pch.h"
#include <stdlib.h>
#include "Layer.h"
#include "inputLayer.h"
#include "outputLayer.h"

//TODO: Mutations
//TOD0: FORWARD AND BACK PROPAGATION
//needs to receive all data from previous layers(this will be done and linked during network and training)
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
	//set neurons on here?
	vector<HiddenLayer> initialiseLayer(outputLayer output, inputLayer input, vector<HiddenLayer> storeListOfHiddenLayers,int numberOfNeuronsInHiddenLayer);
	size_t getNumberOfNeuronsInHiddenLayer()
	{
		return getNumberOfNeuronsInLayer(); //returns number of neurons in a layer
	}

private:

};
//YOU NEED THE INPUT AND OUTPUT LAYER TO MAKE THE HIDDEn LAYER PROPERLY
inline vector<HiddenLayer>HiddenLayer::initialiseLayer(outputLayer output,inputLayer input, vector<HiddenLayer> storeListOfHiddenLayers, int numberOfNeuronsInHiddenLayer)
{
	//THIS REVIEW THIS
	vector<double>incomingWeights; //neuron "weights" in
	vector<double>outgoingWeights; //neuron "weights" out
	vector<Neuron>Temp; //storing temporary neurons
	vector<double>Dtemp; //storing temporary weights
	//FOUND ERRORS. RE-IMPLEMENTING.....
	//step 1, set up hidden layer without biases(done)
	//step 2, add biases(added)
	//step 3, set up weights
	//NOTE: First layer is connected to the INPUT LAYER and last layer is connected to the OUTPUT LAYER. SET WEIGHTS ACCORDINGLY

	for (int i = 0; i < storeListOfHiddenLayers.size(); i++) //for each layer
	{
		if (i == 0) {
			//get number of neurons from input layer
			//extract weights leaving the input layer
			
		}
		for (int j = 0; j < numberOfNeuronsInHiddenLayer; j++) {
			//create number of desired neurons as per variable stated
			//and push them back as per number in hidden layer
			Neuron hNeuron;
			Temp.push_back(hNeuron);
		}
		Neuron bNeuron; //bias added to each layer
		Temp.push_back(bNeuron);//bias neuron
		//push back neuron to desired layer
		storeListOfHiddenLayers[i].setListOfNeurons(Temp);
		//clear neuron vector
		Temp.clear();
	}
	return storeListOfHiddenLayers;
}
