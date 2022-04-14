#ifndef QUEUE_H
#define QUEUE_H

class Queue
{
private:
	int* queue;
	int front, back, size, capacity;
public:
	Queue() : front(0), back(0), size(0), capacity(0), queue(nullptr) {}
	Queue(int c) : front(0), back(-1), size(0), capacity(c), queue(new int[c]) {}
	~Queue();

	int getSize();
	int getCapacity();
	int getFront();
	int getBack();
	bool isEmpty();
	bool isFull();
	void enqueue(int val);
	int dequeue();
	void display();
};

#endif /* QUEUE_H */