#pragma once
#include <vector>
#include "calculus.h"

//CALL ORDER: First call howMany() Function, then addNumber() function AND THEN one of the mathematical functions(eg. increment)

template<typename T>
class calculation
{
public:
	void howMany(int sizeArray) { this->sizeArray = sizeArray; };
	void addNumber()
	{
		std::cout << "\n\n\nEnter " << sizeArray << " number(s): ";
		for (uint8_t i = 0; i < sizeArray; i++)
		{
			std::cin >> number;
			numberArray.push_back(number);
		}
	}

public: //R stands for Return
	T R_in_de_crement() { return in_de_crement<T>(numberArray); };
	T R_multiplication() { return multiplication<T>(numberArray); };
	T R_division() { return division<T>(numberArray); };

private:
	T number;
	int sizeArray = 0;
	std::vector<T> numberArray;
};