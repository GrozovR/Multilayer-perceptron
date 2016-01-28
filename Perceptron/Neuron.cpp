#include "Neuron.h"

neuron::neuron(const int Inputs)
	:numberOfInputs_{ Inputs }
{	
	inputs_ = new double[numberOfInputs_];
	weights_= new double[numberOfInputs_];
}

void neuron::writeWeight(const int number, const double weight)
{
	weights_[number] = weight;
}
void neuron::pushInputs(const int number, const double input)
{
	inputs_[number] = input;
}
double neuron::getWeight(const int number)
{
	return weights_[number];
}
double neuron::getInput(const int number)
{
	return inputs_[number];
}
void neuron::setIndLocField()
{
	inducedLocalField_ = 0;
	for (int i = 0; i < numberOfInputs_; i++)
	{
		inducedLocalField_ += (weights_[i] * inputs_[i]);
	}
}
double neuron::getIndLocField()
{
	setIndLocField();
	return inducedLocalField_;
}

void neuron::setOut()
{
	out_ = 1 / (1 + exp(-getIndLocField()));
}
double neuron::out()
{	
	setOut();
	return out_;
}
