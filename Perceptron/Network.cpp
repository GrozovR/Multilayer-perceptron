#include "Network.h"

void network::setData()
{
	std::ifstream istrm;
	istrm.open(pathData);

	for (int i = 0; i < 150; i++)
	{
		istrm >> trainData[i][0];
		istrm >> trainData[i][1];
		istrm >> trainData[i][2];
		istrm >> trainData[i][3];
		istrm >> trainData[i][4];
		istrm >> trainData[i][5];
		istrm >> trainData[i][6];
	}
	istrm.close();
}
double f(const double InLokField)
{
	double out{ 0 };
	out = 1 / (1 + exp(-InLokField));
	return out;
}
double network::f_derive(const double InLokField)
{
	double outFder_{ 0 };
	outFder_ = f(InLokField)*(1 - f(InLokField));
	return outFder_;
}

///<summary> Method for get train data< / summary>
void network::setInputsAndOutputs(const int pointOfData)
{
	for (int j = 0; j < 4; j++)
	{
		trainInputs_[j] = trainData[pointOfData][j];
	}
	for (int j = 0; j < 3; j++)
	{
		trainOutputs_[j] = trainData[pointOfData][4 + j];
	}
}
void network::setErrorsLastLayer(layer& rhs)
{
	double error{ 0 };
	for (int neuron_ = 0; neuron_ < rhs.NeuronsInLayer(); neuron_++)
	{
		error = (trainOutputs_[neuron_] - getOutNet(neuron_))*f_derive(rhs.getILFîfNeuron(neuron_));
		rhs.setError(neuron_, error);
	}
}
void network::setErrorsNotLastLayer(layer& rhs, layer& nextL)
{
	double error{ 0 };
	double errSigmIn{ 0 };
	for (int neuron_ = 0; neuron_ < rhs.NeuronsInLayer(); neuron_++)
	{
		errSigmIn = 0;
		for (int neurInPrvLayer = 0; neurInPrvLayer < nextL.NeuronsInLayer(); neurInPrvLayer++)
		{
			errSigmIn += nextL.getErrorOfNeuron(neurInPrvLayer) * nextL.getWeightNeur(neurInPrvLayer, neuron_);
		}

		error = errSigmIn*f_derive(rhs.getILFîfNeuron(neuron_));
		rhs.setError(neuron_, error);
	}
}
void network::changeWeights(layer& rhs)
{	
	for (int neuron_ = 0; neuron_ < rhs.NeuronsInLayer(); neuron_++)
	{
		double newWeight{ 0 };
		double weightBias{ 0 };

		for (int input_ = 0; input_ < rhs.NumberOfInputs(); input_++)
		{
			newWeight = rhs.getWeightNeur(neuron_, input_);
			weightBias = rhs.getErrorOfNeuron(neuron_)*rhs.getInputs(input_)*speedOfLearning;
			newWeight += weightBias;
			rhs.writeWeight(neuron_, input_, newWeight);
		}
	}
}
void network::train()
{	
	for (int pointOfData = 0; pointOfData < 150; pointOfData++)
	{
		setInputsAndOutputs(pointOfData);
		pushInputs(trainInputs_);

		//define structure of network 
		setErrorsLastLayer(l4);
		setErrorsNotLastLayer(l3, l4);
		setErrorsNotLastLayer(l2, l3);
		setErrorsNotLastLayer(l1, l2);

		changeWeights(l4);
		changeWeights(l3);
		changeWeights(l2);
		changeWeights(l1);	
	}
}

int network::getNumberOfClass()
{
	double max = NetOutputs_[0];
	double numerofclass{ 0 };

	for (int i = 1; i < numberOfOuts; i++)
	{
		if (NetOutputs_[i] > max)
		{
			max = NetOutputs_[i];
			numerofclass = i;
		}
	}

	return (numerofclass + 1);
}
double network::getOutNet(const int numberOfOuts)
{
	return NetOutputs_[numberOfOuts];
}
void network::pushInputs(double inputs[4])
{
	l1.setInputs(inputs);
	l2.setInputs(l1.outputsOfLayer());
	l3.setInputs(l2.outputsOfLayer());
	l4.setInputs(l3.outputsOfLayer());

	for (int i = 0; i < l4.NeuronsInLayer(); i++)
	{
		NetOutputs_[i] = l4.getOutOfNeuron(i);
	}
}