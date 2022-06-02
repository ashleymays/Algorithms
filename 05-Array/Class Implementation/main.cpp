#include <iostream>
#include "Array.h"

int main()
{
	Array A = Array(5);

	for (int i = 0; i < 5; ++i)
	{
		A.insertAtEnd(i + 1);
	}

	A.display();

	return 0;
}