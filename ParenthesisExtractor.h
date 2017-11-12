#pragma once
#include "AdvancedCalculator.h"

class ParenthesisExtractor
{
private:
	std::string m_input;
	std::string m_output;
public:
	ParenthesisExtractor(std::string input);
	void calculate();
	std::string result();
private:
	std::string parenthesisExtractor(std::string);
	int pBegin(const std::string&);
	int pEnd(const std::string&);
};

