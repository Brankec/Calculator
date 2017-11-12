#include "NumPos.h"



NumPos::NumPos() :
	m_size{ 0 }
{
}

void NumPos::push_back(std::string num = "0")
{
	m_numbers[m_size] = num;
	m_size++;
}

std::string& NumPos::operator[](unsigned int index)
{
	return m_numbers[index];
}

void NumPos::empty()
{
	m_size = 0;
}

void NumPos::remove(unsigned int index)
{
	for (int i = index; i < m_size; i++)
		m_numbers[i] = m_numbers[i + 1];
	m_size--;
}
unsigned int NumPos::length()
{
	return m_size;
}
