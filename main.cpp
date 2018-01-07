#include"Token.h"
#include<Windows.h>
#include<experimental\filesystem>

bool vectorToString(std::string& myString, std::vector<std::string>& myVector);
void stringToString(std::string& str);

using namespace OpenClI::myCalc;

int main()
{
	bool running = true;
	std::cout << std::setw(55) << "Kalkulator" << std::endl << std::endl;
	while (running) {
		std::string input;
		std::cout << "> ";

		std::getline(std::cin, input);

		if (input.empty())
			continue;

		std::stringstream parse(input);

		std::vector<std::string> symbols;

		std::string symbol;
		while (std::getline(parse, symbol, ' ')) {
			symbols.push_back(symbol);
		}

		if (symbol == "quit" || symbol == "exit") {
			running = false;
		}
		else if (symbols[0] == "c") {

			std::string myString;
			if(!vectorToString(myString, symbols))
				std::cout << "[ERROR] : UNESI ZADATAK" << std::endl;
			else
			{
				stringToString(myString);
				const std::vector<Token> myVec = Token::Tokenise(myString);
				std::deque<Token> myQueue = Token::shuntingYard(myVec);
				std::cout << "RJESENJE : "<< Token::EvaluateExpression(myQueue)<<std::endl;
			}
		}
	}
	return 0;
}

// FUNCTION TO CONVERT A VECTOR OF STRINGS BACK TO A STRING(WILL NOT COPY THE FIRST ELEMENT)
bool vectorToString(std::string& myString, std::vector<std::string>& myVector)
{
	auto length = myVector.size();
	if (length == 0 || length == 1)
		return false;

	for (auto i = 1; i<length; ++i)
		myString += myVector[i];
	return true;
}

void stringToString(std::string& str) 
{
	for (auto i = 0; i < str.size();){
		if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/' || str[i] == '^' || str[i] == '(' || str[i] == ')') {
			if (i == 0) 			
				str.insert(i + 1, 1, ' ');
			else {
				str.insert(i + 1, 1, ' ');
				str.insert(i, 1, ' ');
			}

			i += 2;
			continue;
		}
		i++;
	}

	char symbol = ' ';

	str.erase(
		std::unique(
			str.begin(),
			str.end(),
			[symbol](char l, char r) -> bool {
		return (l == symbol) && (l == r);
			}
		),
		str.end()
			);
}