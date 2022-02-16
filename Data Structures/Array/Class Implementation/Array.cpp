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

int Array::getFront()
{
	// Front is the first element in the array
	return arr[0];
}

int Array::getBack()
{
	// Rear is the last element in the array
	return arr[size - 1];
}

int Array::search(int val)
{
	// Linear search; returns the index of the
	// value, or -1 if it was not found
	for (int i = 0; i < size; ++i)
	{
		// If the value was found, return its index 'i'
		if (val == arr[i])
		{
			return i;
		}
	}
	return -1;
}

void Array::insertAtBeg(int val)
{
	// Make sure that the array isn't full before inserting
	if (!isFull())
	{
		// shift elements to the right one space 
		// (arr[1] = arr[0], arr[2] = arr[3], etc.)
		++size;
		for (int i = size - 2; i >= 0; --i)
		{
			arr[i + 1] = arr[i];
		}

		// put value at the front
		arr[0] = val;
	}
}

void Array::insertAtIndex(int val, int i)
{
	// Make sure that the array isn't full before inserting
	// and that i is a valid index to insert at
	if (!isFull() || i < 0 || i >= size)
	{
		return;
	}
	else if (i == 0)
	{
		insertAtBeg(val);
	}
	else if (i == size - 1)
	{
		insertAtEnd(val);
	}
	else
	{
		// shift elements to the right one space 
		// until we get to the corrent index
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
	// Make sure that the array isn't full before inserting
	if (!isFull())
	{
		arr[size] = val;
		++size;
	}
}

void Array::deleteValue(int val)
{
	// Confirm that the value is in the array and
	int i = search(val);


	// make sure that the array isn't empty before deleting
	if (!isEmpty() || i == -1)
	{
		// Shift all the elements to the left, which will
		// reassign the value at index 'i' to arr[i + 1]
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

void Array::display()
{
	std::cout << "Data: ";
	for (int i = 0; i < size; ++i)
	{
		std::cout << arr[i] << ' ';
	}
	std::cout << std::endl;
}