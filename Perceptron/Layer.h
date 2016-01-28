#ifndef LAYER_H_20150611
#define LAYER_H_20150611
#define _SCL_SECURE_NO_WARNINGS

#include "Neuron.h"
#include <cstdlib>

//Class of layer of perceptron.

//When you create an instance of the class you must specify  
//the number of neurons in layer and inputs of the neuron.
//Number of inputs equal number of outputs of previous layer.

class layer
{
public:
	
	layer(int numberOfNeurons, int Inputs);
	layer() = default;

	void writeWeight(int numbNeur, int numberWeigth, double Weigth);
	void setError(const int numbNeur, const double error);

	void setInputs(const double *inputs);
	double * outputsOfLayer();


	double getWeightNeur(const int Neuron, const int numberOfWeight);
	double getErrorOfNeuron(const int Neuron);
	double getInputs(const int input);
	double getOutOfNeuron(const int number);
	double getILFîfNeuron(const int number);
	
	double NeuronsInLayer();
	double NumberOfInputs();
	
private:	
	void weightsFirstInitialize();
	void setOut();

private:
	int numberOfNeurons_{ 0 };
	int Inputs_{ 0 };
	double * inputsArr_{ nullptr };
	double * outs_{ nullptr };
	neuron * Neurons_{ nullptr };
	double * errors_{ nullptr };
};

#endif LAYER_H_20150611