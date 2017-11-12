#pragma once
#include <string>

class NumPos
{
private:
	unsigned int m_size;
	std::string m_numbers[1024];
public:
	NumPos();
	void push_back(std::string);
	std::string& operator[](unsigned int index);
	void empty();
	void remove(unsigned int index);
	unsigned int length();
};

