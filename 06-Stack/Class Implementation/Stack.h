#ifndef STACK_H
#define STACK_H

class Stack {
private:
	int stack[400];
	int size;

public:
	int getSize();
	bool isEmpty();
	void push(int val);
	void pop();
	int top();
	void display();
};

#endif /* STACK_H */