#pragma once
#include "pch.h"
#include <stdlib.h>
#include <vector>

using namespace std;
class Neuron{

public:
	Neuron() {}
	~Neuron() {}

	//used to initialise weights
	double initialiseNeuron(){
		return ((double)rand() / RAND_MAX);
	};

	//set weights
	void setListOfIncomingWeights(vector<double>setList)
	{
		weightsIn = setList;
	}

	void setListOfOutgoingWeights(vector <double>setlist)
	{
		weightsOut = setlist;
	}

	//get weights and other values(returns a reference)
	vector<double>&GetWeightsIn()
	{
		return weightsIn;
	}

	vector<double>&GetWeightsOut()
	{
		return weightsOut;
	}

	double getError()
	{
		return error;
	}

//training done in training.h
private:
	
	vector<double>weightsIn; //weight values passed into neuron
	vector<double>weightsOut; //weight values passed out from neuron
	double outputValue;
	double error;
	double sensibility;
};
