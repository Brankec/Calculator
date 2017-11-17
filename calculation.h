#pragma once
#include <vector>
#include "calculus.h"
#include "trigonometry.h"

//CALL ORDER: First call howMany() Function, then addNumber() function AND THEN one of the mathematical functions(eg. increment)

template<typename T>
class calculation
{
public:
	int n_power_to = 2;
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
	T R_root() { return root<T>(numberArray[0]); };
	T R_power_to() { return power_to<T>(numberArray[0], n_power_to); };
	T R_sinus() { return sinus<T>(numberArray[0]); };

private:
	T number;

	int sizeArray = 1;
	std::vector<T> numberArray;
};