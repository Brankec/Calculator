#pragma once

template<typename T>
T in_de_crement(std::vector<T> numberArray)
{
	T sum = 0;
	for (uint8_t i = 0; i < numberArray.size(); i++)
	{
		sum += numberArray[i];
	}
	return sum;
};
///////////////
template<typename T>
T multiplication(std::vector<T> numberArray)
{
	T multisum = 1;
	for (uint8_t i = 0; i < numberArray.size(); i++)
	{
		multisum *= numberArray[i];
	}
	return multisum;
};
///////////////
template<typename T>
T division(std::vector<T> numberArray)
{
	T accumulator = numberArray[0];
	for (uint8_t i = 1; i < numberArray.size(); i++)
	{
		accumulator /= numberArray[i];
	}

	return accumulator;
};
///////////////
template<typename T>
T root(T number)
{
	return sqrt(number);
}
template<typename T>
T power_to(T number, T power_to)
{
	return pow(number, power_to);
}
