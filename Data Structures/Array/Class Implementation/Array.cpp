#include "Array.h"
#include <iostream>

Array::~Array() 
{
	delete[] arr;
}

bool Array::isEmpty() 
{
	return size == 0;
}

bool Array::isFull() 
{
	return size == capacity;
}

int Array::getSize() 
{
	return size;
}

int Array::getCapacity() 
{
	return capacity;
}

int Array::search(int val) 
{
	for (int i = 0; i < size; ++i) 
	{
		if (val == arr[i]) 
		{
			return i;
		}
	}
	return -1;
}

void Array::insertAtBeg(int val) 
{
	if (!isFull()) 
	{
		++size;
		for (int j = size - 2; j >= 0; --j) 
		{
			arr[j + 1] = arr[j];
		}
		arr[0] = val;
	}
}

void Array::insertAtIndex(int val, int i) 
{
	if (!isFull()) 
	{
		++size;
		for (int j = size - 2; j >= i; --j) 
		{
			arr[j + 1] = arr[j];
		}
		arr[i] = val;
	}
}

void Array::insertAtEnd(int val) 
{
	if (!isFull()) 
	{
		arr[size] = val;
		++size;
	}
}

void Array::deleteValue(int val) 
{
	if (!isEmpty()) 
	{
		int i = search(val);

		if (i == -1) 
		{
			return;
		}

		for (int j = i; j < size; ++j) 
		{
			arr[j] = arr[j + 1];
		}
		--size;
	}
}

void Array::update(int val, int i) 
{
	arr[i] = val;
}

int Array::front() 
{
	return arr[0];
}

int Array::back() 
{
	return arr[size - 1];
}

void Array::display() 
{
	std::cout << "Data: ";
	for (int i = 0; i < size; ++i) 
	{
		std::cout << arr[i] << ' ';
	}
	std::cout << std::endl;
}