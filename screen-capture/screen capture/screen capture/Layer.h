#pragma once
#include "pch.h"
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

	//output number of neurons in layer
	vector<Neuron>& getListOfNeurons()
	{
		//return ListOfNeuron;
		//this->Neurons = getListOfNeurons
		//this->getListOfNeurons = Neurons;
		return Neurons;
	}

	//set neuron list
	void setListOfNeurons(vector<Neuron>&ListOfNeurons)
	{
		Neurons = ListOfNeurons;
	}

	void setNumberOfNeuronsInLayer(int number)
	{
		numberOfNeuronsInLayer = number;
	}

	size_t getNumberOfNeuronsInLayer() const
	{
		return numberOfNeuronsInLayer;
	}

	
protected:
	vector<Neuron>Neurons;
	//dictate number of neurons
	size_t numberOfNeuronsInLayer;
};