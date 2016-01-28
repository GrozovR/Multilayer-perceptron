#ifndef NETWORK_H_20150611
#define NETWORK_H_20150611
#define _SCL_SECURE_NO_WARNINGS

#include "Layer.h"
#include <fstream>
#include <string>

//Class of multilayer perceptron.
//Parameters of perceptron defines in this class.


class network
{
public:
	network() = default;
	std::string pathData{ 0 };
	double trainData[150][7];

	void setData();
	void train();
	void pushInputs(double inputs[4]);
	int getNumberOfClass();
	double getOutNet(const int numberOfOuts);

private:
	// Define structure of the network,
	// also must change constant number in function in Network.cpp 
	// setData(), setInputsAndOutputs(), train(), pushInputs()

	layer l1{ 4,4 };
	layer l2{ 6,4 };
	layer l3{ 6,6 };
	layer l4{ 3,6 };
	double speedOfLearning{ 0.15 };

	void setInputsAndOutputs(const int pointOfData);
	void setErrorsLastLayer(layer& rhs);
	void setErrorsNotLastLayer(layer& rhs, layer& nextL);
	void changeWeights(layer& rhs);
	double f_derive(const double InLokF);

	double numberOfOuts{ 3 };
	double trainInputs_[4];
	double trainOutputs_[3];
	double NetOutputs_[3];
};

#endif NETWORK_H_20150611