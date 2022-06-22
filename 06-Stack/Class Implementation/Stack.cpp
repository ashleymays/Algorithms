#include <iostream>
#include "Stack.h"
using namespace std;

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
	if (!isFull())
	{
		++size;
		stack[size - 1] = val;
	}
}

void Stack::pop()
{
	if (!isEmpty())
	{
		--size;
	}
}

int Stack::top()
{
	// stack isn't empty -> return the element at the end
	if (!isEmpty())
	{
		return stack[size - 1];
	}

	// stack is empty -> return -1
	return -1;
}

void Stack::display()
{
	cout << "Stack: ";
	for (int i = 0; i < size; ++i)
	{
		cout << stack[i] << ' ';
	}
	cout << endl;
}