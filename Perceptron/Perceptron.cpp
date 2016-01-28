#include "Neuron.h"
#include "Layer.h"
#include "Network.h"
#include <iostream>


int main()
{

	network Perceptron;
	Perceptron.pathData = "D:\\input.txt";
	Perceptron.setData();

	// training
	for (int ep = 0; ep < 100; ep++)
	{
		Perceptron.train();
		std::cout << ep << std::endl;
	}

	//test network
	int error{ 0 };
	for (int i = 0; i < 150; i++)
	{
		double inputs[4];
		double rightOut[3];

		for (int j = 0; j < 4; j++)
		{
			inputs[j] = Perceptron.trainData[i][j];
		}
		for (int j = 0; j < 3; j++)
		{
			rightOut[j] = Perceptron.trainData[i][j+4];
		}

		Perceptron.pushInputs(inputs);
		
		int rightexit{ 0 };
		int exit{ 0 };

		if (rightOut[0] == 1) rightexit = 1;
		if (rightOut[1] == 1) rightexit = 2;
		if (rightOut[2] == 1) rightexit = 3;

		exit = Perceptron.getNumberOfClass();

		if (exit != rightexit)
		{
			error++;
			std::cout << "error in line " << i + 1 << std::endl;
			std::cout << "Right: " << rightexit << std::endl;
			std::cout << "Exit: " << exit << std::endl;
		}

	}
	std::cout << "Count of error: " << error << std::endl;

	system("pause");
	return 0;
}