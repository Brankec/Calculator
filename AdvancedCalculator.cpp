#include "AdvancedCalculator.h"



AdvancedCalculator::AdvancedCalculator(std::string question) :
	m_question{ question }, m_numbers()
{
}

void AdvancedCalculator::extractor()
{
	int pos = 0;

	//m_question.erase(remove_if(m_question.begin(), m_question.end(), isspace), m_question.end());

	for (int i = 0; i < m_question.length(); i++)
	{
		if (m_question[i] == '/' || m_question[i] == '*' || m_question[i] == '+' || m_question[i] == '-')
		{
			m_operators += m_question[i];
			m_numbers.push_back(m_question.substr(pos, i - pos));
			pos = i + 1;
		}
		if (i == (m_question.length() - 1))
			m_numbers.push_back(m_question.substr(pos, i - pos + 1));
	}
}

void AdvancedCalculator::calculator()
{
	std::string optrs("/*+-");
	for (int cnt = 0; cnt < optrs.length(); cnt++)
	{
		int pos = 0;
		while (true)
		{
			pos = findoptrpos(m_operators, optrs[cnt], pos);
			if (pos == -1)
				break;
			else
			{
				apply(optrs[cnt], pos);
				pos++;
			}
		}
	}
	m_answer = m_numbers[0];
}

int AdvancedCalculator::findoptrpos(const std::string& str, char c, int pos)
{
	for (int i = pos; i < str.length(); i++)
		if (str[i] == c)
			return i;
	return -1;
}

void AdvancedCalculator::apply(char optr, unsigned int pos)
{
	double first, second, result;
	std::stringstream stream;
	stream.clear();
	stream.str(m_numbers[pos]);
	stream >> first;
	stream.clear();
	stream.str(m_numbers[pos + 1]);
	stream >> second;

	switch (optr)
	{
	case '/':
		result = first / second;
		break;
	case '*':
		result = first * second;
		break;
	case '+':
		result = first + second;
		break;
	case '-':
		result = first - second;
		break;
	}

	m_numbers[pos] = std::to_string(result);
	m_numbers.remove(pos + 1);
}

std::string AdvancedCalculator::result()
{
	return m_answer;
}
