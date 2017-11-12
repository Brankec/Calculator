#include "menu.h"
#include "ParenthesisExtractor.h"


void menu()
{
	char option;

	std::cout << "Enter A for Advanced calculator or enter B for Basic Calculator" << std::endl;
	while(std::cin >> option)
	if (option == 'A')
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
	else if (option == 'B')
	{
		std::cout << "CALCULATOR (Enter expression OR [?] to exit!)" << std::endl;
		while (true)
		{
			std::string input;
			std::cout << "::::";
			std::cin >> input;
			if (input[0] == '?')
				break;
			ParenthesisExtractor advance(input);
			advance.calculate();
			std::cout << ">>>>" << advance.result() << std::endl;
		}
	}
	else
	{
		std::cout << "Unknown answer, try again..." << std::endl;
		continue;
	}
}