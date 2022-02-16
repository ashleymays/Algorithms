#include <iostream>
#include "Stack.h"

Stack::~Stack()
{
	delete[] stack;
}

int Stack::getSize()
{
	return size;
}

int Stack::getCapacity()
{
	return capacity;
}

bool Stack::isEmpty()
{
	return size == 0;
}

bool Stack::isFull()
{
	return size == capacity;
}

void Stack::push(int val)
{
	// check that there's space in the array before inserting
	if (!isFull())
	{
		++size;
		stack[size - 1] = val;
	}
}

void Stack::pop()
{
	// check that there's something in the array before removing
	if (!isEmpty())
	{
		--size;
	}
}

int Stack::top()
{
	// check that there is something in the array first
	if (!isEmpty())
	{
		return stack[size - 1];
	}
	return -1;
}

void Stack::display()
{
	std::cout << "Data: ";
	for (int i = 0; i < size; ++i)
	{
		std::cout << stack[i] << ' ';
	}
	std::cout << std::endl;
}