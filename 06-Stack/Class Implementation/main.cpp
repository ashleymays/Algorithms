#include <iostream>
#include "Stack.h"

int main()
{
	Stack s(10);
	s.push(10);
	s.push(20);
	s.push(30);
	s.push(40);
	s.push(50);

	s.display();

	s.pop();

	s.display();


	return 0;
}