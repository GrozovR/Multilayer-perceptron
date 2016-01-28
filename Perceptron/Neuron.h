#ifndef NEURON_H_20150611
#define NEURON_H_20150611
#define _SCL_SECURE_NO_WARNINGS

#include <math.h>

//Class of neuron.

//When you create an instance of the class you must specify  
//the number of inputs of the neuron.
//Activation function - logistic.

class neuron
{

public:
	neuron(const int Imputs);
	neuron() = default;
	~neuron() = default;
	
	void writeWeight(const int number,const double weight);
	void pushInputs(const int number,const double input);

	double getWeight(const int number);
	double getInput(const int number);
	double getIndLocField();	
	double out();
	
private:		
	void setIndLocField();
	void setOut();

private:
	int numberOfInputs_{ 0 };
	double* inputs_{ nullptr };
	double* weights_{ nullptr };
	double out_{ 0 };
	double inducedLocalField_{ 0 };
};

#endif NEURON_H_20150611