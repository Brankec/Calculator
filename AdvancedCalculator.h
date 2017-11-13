#pragma once
#include <string>
#include <sstream>
#include <algorithm>
#include "NumPos.h"

class AdvancedCalculator
{
private:
	std::string m_question;
	std::string m_answer;
	std::string m_operators;
	NumPos m_numbers;
public:
	AdvancedCalculator(std::string);
	void extractor();
	void calculator();
	std::string result();
private:
	int findoptrpos(const std::string& str, char c, int pos);
	void apply(char optr, unsigned int pos);
};
