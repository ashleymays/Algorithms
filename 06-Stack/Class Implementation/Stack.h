#ifndef STACK_H
#define STACK_H

class Stack {
private:
	int* stack;
	int size;
	int capacity;

public:
	Stack() : size(0), capacity(0), stack(nullptr) {}
	Stack(int c) : size(0), capacity(c), stack(new int[c]) {}
	~Stack();

	int getSize();
	int getCapacity();
	bool isEmpty();
	bool isFull();
	void push(int val);
	void pop();
	int top();
	void display();
};

#endif /* STACK_H */