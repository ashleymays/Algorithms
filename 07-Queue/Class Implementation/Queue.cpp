#include <iostream>
#include "Queue.h"

Queue::~Queue()
{
	delete[] queue;
}

int Queue::getSize()
{
	return size;
}

int Queue::getCapacity()
{
	return capacity;
}

int Queue::getFront()
{
	return queue[front];
}

int Queue::getBack()
{
	return queue[back];
}

bool Queue::isEmpty()
{
	return size == 0;
}

bool Queue::isFull()
{
	return size == capacity;
}

void Queue::enqueue(int val)
{
	if (!isFull())
	{
		// Insert at the end of the array
		++size;
		++back;
		queue[back] = val;
	}
}

int Queue::dequeue()
{
	if (!isEmpty())
	{
		// Delete at the beginning of the array
		--size;
		++front;
		return queue[front];
	}
	return -1;
}

void Queue::display()
{
	std::cout << "Data: ";
	for (int i = front; i <= back; ++i)
	{
		std::cout << queue[i] << ' ';
	}
	std::cout << std::endl;
}