#include "menu.h"
#include "ParenthesisExtractor.h"

std::string removeSpaces(std::string input)
{
	for (int i = 0; i<input.length(); i++)
		if (input[i] == ' ') input.erase(i, 1);

	return input;
}

int menu()
{
	char option;

	std::cout << "Enter A for Calculator with an interpreter / Enter B for Basic Calculator" << std::endl;
	while (std::cin >> option)
	{
		if (option == 'B')
		{
			calculation<double> calc;

			uint16_t size;

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
				return 0;
				break;
			case '*':
				std::cout << "\n\nEnter the amount of number(s) you want to multiply: ";

				std::cin >> size;
				calc.howMany(size);
				calc.addNumber();

				std::cout << "Value: " << calc.R_multiplication() << std::endl;
				return 0;
				break;
			case '/':
				std::cout << "\n\nEnter the amount of number(s) you want to divide: ";

				std::cin >> size;
				calc.howMany(size);
				calc.addNumber();

				std::cout << "Value: " << calc.R_division() << std::endl;
				return 0;
				break;
			case 's':
				calc.addNumber();

				std::cout << "Value: " << calc.R_root() << std::endl;
				return 0;
				break;
			case '^':
				std::cout << "Enter the n power you want: ";
				std::cin >> calc.n_power_to;
				calc.addNumber();

				std::cout << "Value: " << calc.R_power_to() << std::endl;
				return 0;
				break;
			case 't':
				std::cout << "\n S ------------- sinus " << std::endl;
				std::cout << " C ------------- cosinus " << std::endl;
				std::cout << " T ------------- tanges " << std::endl;
				std::cout << " t ------------- cotanges " << std::endl;
				std::cout << "Choose an option: ";
				std::cin >> option;
				if (option == 'S')
				{
					std::cout << "*its in radians*" << std::endl;
					calc.addNumber();


					std::cout << "Value: " << calc.R_sinus() << std::endl;
					return 0;
				}
			}
		}
		else if (option == 'A')
		{
			std::cout << "CALCULATOR (Enter expression OR [?] to exit)" << std::endl;
			while (true)
			{
				std::string input;
				std::cout << "::::";
				std::getline(std::cin, input);
				//std::cin >> input;
				if (input[0] == '?')
					return 0;
				input = removeSpaces(input);
				ParenthesisExtractor advance(input);
				advance.calculate();
				std::cout << ">>>>" << advance.result() << std::endl;
			}
		}
		else
		{
			std::cout << "Unknown answer, try again..." << std::endl;
			return 0;
		}
	}
}
