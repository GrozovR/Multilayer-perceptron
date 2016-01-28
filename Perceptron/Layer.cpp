#include "Layer.h"

layer::layer(int numberOfNeurons, int Inputs)
	:numberOfNeurons_{ numberOfNeurons }
	, Inputs_{ Inputs }
{
	inputsArr_ = new double[numberOfNeurons_];
	outs_ = new double[numberOfNeurons_];
	Neurons_ = new neuron[numberOfNeurons_];
	errors_ = new double[numberOfNeurons_];

	for (int i = 0; i < numberOfNeurons_; i++)
	{
		Neurons_[i] = neuron{ Inputs_ };
	}
	weightsFirstInitialize();
}

void layer::weightsFirstInitialize()
{
	double weight{ 0 };
	for (int neuron = 0; neuron < numberOfNeurons_; neuron++)
	{
		for (int numberWeight = 0; numberWeight < Inputs_; numberWeight++)
		{
			weight = rand() % 1000;
			weight /= 1000;
			weight -= 0.5;

			writeWeight(neuron, numberWeight, weight);
		}
	}
}
void layer::writeWeight(int numbNeur, int numberWeigth, double Weigth)
{
	Neurons_[numbNeur].writeWeight(numberWeigth, Weigth);
}
void layer::setError(const int numbNeur, const double error)
{
	errors_[numbNeur] = error;
}

double layer::NeuronsInLayer()
{
	return numberOfNeurons_;
}
double layer::NumberOfInputs()
{
	return Inputs_;
}

double layer::getILFîfNeuron(const int number)
{
	return Neurons_[number].getIndLocField();
}
double layer::getOutOfNeuron(const int number)
{
	return Neurons_[number].out();
}
double layer::getWeightNeur(const int Neuron, const int number)
{
	return Neurons_[Neuron].getWeight(number);
}
double layer::getErrorOfNeuron(const int Neuron)
{
	return errors_[Neuron];
}

double layer::getInputs(const int input)
{
	return inputsArr_[input];
}
void layer::setInputs(const double *inputs)
{
	for (int neuron = 0; neuron < numberOfNeurons_; neuron++)
	{
		for (int inputNumb = 0; inputNumb < Inputs_; inputNumb++)
		{
			Neurons_[neuron].pushInputs(inputNumb, inputs[inputNumb]);
			inputsArr_[inputNumb] = inputs[inputNumb];
		}
	}
}
void layer::setOut()
{
	for (int neuron = 0; neuron < numberOfNeurons_; neuron++)
	{
		outs_[neuron] = Neurons_[neuron].out();
	}
}
double * layer::outputsOfLayer()
{
	setOut();
	return  outs_;
}

