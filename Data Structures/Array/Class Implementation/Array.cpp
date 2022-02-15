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
	return arr[0];								// Front is the first element in the array
}

int Array::getBack()
{
	return arr[size - 1];						// Rear is the last element in the array
}

int Array::search(int val)						// Linear search; returns the index of the value, or -1 if it was not found
{
	for (int i = 0; i < size; ++i)
	{
		if (val == arr[i])						// If the value was found, return its index 'i'
		{
			return i;
		}
	}
	return -1;
}

void Array::insertAtBeg(int val)
{
	if (!isFull())								// Make sure that the array isn't full before inserting
	{
		++size;
		for (int i = size - 2; i >= 0; --i)		// shift elements to the right one space (arr[1] = arr[0], arr[2] = arr[3], etc.)
		{
			arr[i + 1] = arr[i];
		}
		arr[0] = val;							// put value at the front
	}
}

void Array::insertAtIndex(int val, int i)
{
	if (!isFull() || i < 0 || i >= size)		// Make sure that the array isn't full before inserting
	{											// and that i is a valid index to insert at
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
		++size;
		for (int j = size - 2; j >= i; --j)		// shift elements to the right one space until we get to the corrent index
		{
			arr[j + 1] = arr[j];
		}
		arr[i] = val;
	}
}

void Array::insertAtEnd(int val)
{
	if (!isFull())								// Make sure that the array isn't full before inserting
	{
		arr[size] = val;
		++size;
	}
}

void Array::deleteValue(int val)
{
	int i = search(val);						// Confirm that the value is in the array and
	if (!isEmpty() || i == -1)					// make sure that the array isn't empty before deleting
	{
		for (int j = i; j < size; ++j)			// Shift all the elements to the left, which will
		{										// reassign the value at index 'i' to arr[i + 1]
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