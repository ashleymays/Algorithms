#include <iostream>
#include "DoublyLinkedList.h"

int main()
{
	DLList list = DLList();

	for (int i = 0; i < 5; ++i)
	{
		list.insertAtEnd(i + 1);
	}

	list.display();

	return 0;
}