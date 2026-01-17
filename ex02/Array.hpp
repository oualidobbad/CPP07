#pragma once
#include <exception>
#include <iostream>
#include <cstdlib>
#include <ctime>

template <typename T> 
class Array
{
	private:
		T *arr;
		size_t  _size;

	public:
		Array();
		Array(unsigned int n);
		Array(const Array& other);
		Array& operator=(const Array& other);
		~Array();

		T& operator[](unsigned int index);
		size_t size() const;
};

#include "Array.tpp"
