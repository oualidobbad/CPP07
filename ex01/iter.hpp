#pragma once
#include <iostream>

template <typename T, typename F> 
void iter(T *arr, int length, F func)
{
	for (int i = 0; i < length; i++)
		func(arr[i]);
}

template <typename T>
void increment(T& value)
{
    value += 1;
}

template <typename T>
void printElement(const T& value) {
    std::cout << value << " ";
}



