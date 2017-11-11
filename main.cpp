#include <iostream>
#include "menu.h"

int main()
{
	char option;

	menu();



////RESET////
    std::cout << "\n\n\nReset?     ( y/n )" << std::endl;
	while (std::cin >> option)
	{
		if (option == 'y')
		{ 
			system("cls");
			return main(); 
		}    
		else if (option == 'n')
			return 0;    
		else 
		{
			std::cout << "Unknown answer, try again..." << std::endl;
			continue;
		} 
	}

}