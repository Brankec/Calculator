#include "menu.h"


void menu()
{
	calculation<double> calc;

	uint16_t size;
	char option;

	options(); //List of all options
	std::cin >> option;

	switch (option)
	{
	case '+':
		std::cout << "\n\nEnter the amount of number(s) you want to summarize: ";

		std::cin >> size;
		calc.howMany(size);
		calc.addNumber();

		std::cout << "Value: " << calc.R_in_de_crement() << std::endl;

		break;
	case '*':
		std::cout << "\n\nEnter the amount of number(s) you want to multiply: ";

		std::cin >> size;
		calc.howMany(size);
		calc.addNumber();

		std::cout << "Value: " << calc.R_multiplication() << std::endl;

		break;
	case '/':
		std::cout << "\n\nEnter the amount of number(s) you want to divide: ";

		std::cin >> size;
		calc.howMany(size);
		calc.addNumber();

		std::cout << "Value: " << calc.R_division() << std::endl;
		break;
	}
}