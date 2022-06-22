#include <iostream>
#include "Stack.h"
using namespace std;

int Stack::getSize()
{
	return size;
}

bool Stack::isEmpty()
{
	return size == 0;
}

void Stack::push(int val)
{
	++size;
	stack[size - 1] = val;
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
