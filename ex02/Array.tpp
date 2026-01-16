#include "Array.hpp"

template <typename T>
Array<T>::Array()
{
	arr = NULL;
	_size = 0;
}

template <typename T>
Array<T>::Array(unsigned int n)
{
	arr = new T[n]();
	_size = n;
}

template <typename T>
Array<T>::Array(const Array& other)
{
	if (other._size > 0)
	{
		this->arr = new T[other._size];
		for (size_t i = 0; i < other._size; i++)
			arr[i] = other.arr[i];
	}
	else
	{
		this->arr = NULL;
		_size = 0;
	}
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& other)
{
	if (other._size > 0)
	{
		for(size_t i = 0; i < other._size; i++)
			arr[i] = other.arr[i];
	}
	else
	{
		arr = NULL;
		_size = 0;
	}

	return *this;
}

template <typename T>
Array<T>::~Array()
{
	delete[] arr;
}

template <typename T>
T& Array<T>::operator[](unsigned int index)
{
	if (index >= _size)
		throw std::exception();
	return arr[index];
}

template <typename T>
size_t Array<T>::size() const
{
	return _size;
}
