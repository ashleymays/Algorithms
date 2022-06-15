/*
	Singly Linked List - Class Implementation

	A singly linked list is a container for elements of the same type.
	Unlike a doubly linked list, the singly linked list only reads forwards, not backwards.

	Read more at https://www.programiz.com/dsa/linked-list-types#singly
*/

#include <iostream>
#include "SinglyLinkedList.h"

int main()
{
	SLList list = SLList();

	list.insertAtTail(0);
	list.insertAtTail(1);
	list.insertAtTail(2);
	list.insertAtTail(4);
	list.insertAtIndex(3, 3);
	list.display();

	list.deleteAtIndex(2);

	list.display();


	std::cin.get();
}