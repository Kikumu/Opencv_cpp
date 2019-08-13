#pragma once
#include "pch.h"
#include <iostream>
#include <stdlib.h>
#include <vector>
#include "Neuron.h"
#include "Layer.h"


using namespace std;
class inputLayer:public Layer //this is 'new'. review this later
{
public:
	inputLayer();
	~inputLayer();

	inputLayer& initLayer(inputLayer& inputLayer);
	void printLayer(inputLayer& inputLayer);
private:

};

inputLayer::inputLayer()
{
}

inputLayer::~inputLayer()
{
}

inline inputLayer & inputLayer::initLayer(inputLayer & inputLayer)
{
	// TODO: insert return statement here
	//each layer has neurons and weights connected to it hence:
	vector<double>listOfWeightsInTemp;
	vector<Neuron>pNeurons; 

	//need to properly understand whats going on. why? because:
	// the input layer can have a set number of neurons depending on how much input you wanna have
	// the hidden layers, the one in between input and output neurons, you can decide how many neurons can be in each layer. its not determined by anything*
	for (size_t i = 0; i < inputLayer.numberOfNeuronsInLayer; i++)
	{
		Neuron cNeuron; //create instance of neuron

		listOfWeightsInTemp.push_back(cNeuron.initialiseNeuron()); //assigns weight to neuron randomly(see neuron.h)
		//cNeuron.setListOfIncomingWeights =listOfWeightsInTemp; //dont really know whats going on here. i understand but what i dont know is where are the weights initialised in neuron.h?
		//cNeuron.setListOfIncomingWeights(listOfWeightsInTemp);
		//well they are public so random values i guess? from main?
		//yeah definitely from main. because the connections to layers may vary during training
		pNeurons.push_back(cNeuron); //push back to vector the input vals
		//listOfWeightsInTemp.clear();
	}
	Neuron cNeuron;
	cNeuron.setListOfIncomingWeights(listOfWeightsInTemp);
	listOfWeightsInTemp.clear();

	inputLayer.Neurons = pNeurons; //initialise gathered neurons from loop into the input layer
	return inputLayer;
}

inline void inputLayer::printLayer(inputLayer& inputLayer)//pass by reference
{
      cout <<" INPUT LAYER ";
	  int nNeuron = 1;
	//for each neuron in layer initialise weights
	for (Neuron& neuron : inputLayer.Neurons)
	{
		cout << "Neuron: ";
		cout << nNeuron;
		cout << "\n";
		cout << "input weights: ";
		//vector<double*>weights = neuron.GetWeightsIn;
		///*for (double weight : weights)
		//{
		//	cout << weight;
		//}*/
		
		
		nNeuron++;
	}
}
