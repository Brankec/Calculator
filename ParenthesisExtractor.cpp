#include "ParenthesisExtractor.h"

ParenthesisExtractor::ParenthesisExtractor(std::string input) :
	m_input{ input }, m_output{ "ERROR" }
{
}

void ParenthesisExtractor::calculate()
{
	m_output = parenthesisExtractor(m_input);
}

std::string ParenthesisExtractor::result()
{
	return m_output;
}

std::string ParenthesisExtractor::parenthesisExtractor(std::string input)
{

	std::string resultStr(input);
	while (true)
	{
		int sPos, ePos;
		sPos = pBegin(resultStr);
		if (sPos == -1)
		{
			AdvancedCalculator basic(resultStr);
			basic.extractor();
			basic.calculator();
			std::string res = basic.result();
			return res;
		}
		else
		{
			ePos = pEnd(resultStr);
			if (ePos == -1)
				ePos = resultStr.length() - 1;
			int len = resultStr.length();
			std::string inParenthesis = resultStr.substr(sPos + 1, ePos - sPos - 1);
			std::string beforeParenthesis = resultStr.substr(0, sPos);
			std::string afterParenthesis = resultStr.substr(ePos + 1, len - ePos - 1);
			resultStr = beforeParenthesis + parenthesisExtractor(inParenthesis) + afterParenthesis;
		}
	}
}

int ParenthesisExtractor::pBegin(const std::string& str)
{
	for (int i = 0; i < str.length(); i++)
		if (str[i] == '(')
			return i;
	return -1;
}

int ParenthesisExtractor::pEnd(const std::string& str)
{
	for (int i = (str.length() - 1); i > -1; i--)
		if (str[i] == ')')
			return i;
	return -1;
}