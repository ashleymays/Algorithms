#include <iostream>
#include "DoublyLinkedList.h"

DLList::~DLList()
{
	DLLNode* cur = head;
	while (cur != nullptr)
	{
		DLLNode* node = cur->next;
		delete cur;
		cur = node;
	}
}

int DLList::getLength()
{
	return length;
}

int DLList::getFront()
{
	return head->data;
}

int DLList::getRear()
{
	return tail->data;
}

bool DLList::search(int val)
{
	// Node 'cur' is used to read through the list
	DLLNode* cur = head;
	while (cur != nullptr)
	{
		if (val == cur->data)
		{
			return true;
		}

		// Assign cur to the next node in th elist to iterate
		cur = cur->next;
	}
	return false;
}

void DLList::insertAtBeg(int val)
{
	// Put the value in a node
	DLLNode* newNode(new DLLNode(val));

	// !head means that the head is nullptr, i.e. the lsit is empty
	if (head == nullptr)
	{
		// newNode is now both the head and the tail
		head = newNode;
		tail = newNode;
	}
	else
	{
		// Link the old head node and the new node so
		// that the new node comes before the old head node.
		// Then make the new node the head of the list.
		newNode->next = head;
		head->prev = newNode;
		head = newNode;
	}
	++length;
}

void DLList::insertAtIndex(int val, int i)
{
	// List starts at index 0
	

	// If the index is invalid, exit the method
	if (i < 0 || i > length)
	{
		return;
	}

	// If the index is 0 or the list is empty,
	// insert at the beginning of the list.
	else if (i == 0 || head == nullptr)
	{
		insertAtBeg(val);
	}

	// Inserting at this index is the same as inserting
	// at the end of the list.
	else if (i == length)
	{
		insertAtEnd(val);
	}


	else {
		// Put value in a node called 'newNode'
		DLLNode* newNode(new DLLNode(val));

		// Node 'cur' is used to read through the list
		DLLNode* cur = head;
		for (int j = 0; j < i - 1; ++j)
		{
			cur = cur->next;
		}


		// 'cur' is now at index i - 1, i.e. the node 
		// before where we want to insert at. 
		// Now we put newNode between cur and cur->next.
		// Doing so will reassign cur->next to newNode
		newNode->prev = cur;
		newNode->next = cur->next;
		cur->next = newNode;
		++length;
	}
}

void DLList::insertAtEnd(int val)
{
	// Put value in a node called 'newNode'
	DLLNode* newNode(new DLLNode(val));

	// !head means that the head is nullptr, i.e. the list is empty
	if (head == nullptr)
	{
		// newNode is now both the head and the tail
		head = newNode;
		tail = newNode;
	}
	else
	{
		// Make the newNode come after the old tail node.
		// Then make the old tail be the node before newNode.
		// Lastly, make newNode the tail of the list.
		tail->next = newNode;
		newNode->prev = tail;
		tail = newNode;
	}
	++length;
}

void DLList::deleteAtBeg()
{
	// !head means that the list is empty (the head is nullptr)
	if (head == nullptr)
	{
		return;
	}

	// Means there's only one element in the list
	else if (head->next == nullptr)
	{
		head = nullptr;
		tail = nullptr;
	}
	else
	{
		// Make the second element in the list the head
		// Free memory at the old head and assign it to nullptr
		// so that its value will not be displayed when the
		// display() method id used.
		head = head->next;
		delete head->prev;
		head->prev = nullptr;
	}
	--length;
}

void DLList::deleteAtIndex(int i)
{
	// If the list is empty, or i is an invalid index, exit the method
	if (head == nullptr || i < 0 || i >= length)
	{
		return;
	}
	else if (i == 0)
	{
		deleteAtBeg();
	}
	else if (i == length - 1)
	{
		deleteAtEnd();
	}
	else
	{
		DLLNode* cur = head;
		for (int j = 0; j < i; ++j)
		{
			cur = cur->next;
		}

		// "cur" is now the node we want to delete
		// Create two nodes 'beforeCur' and 'afterCur'
		// for better code readability.
		DLLNode* beforeCur = cur->prev;
		DLLNode* afterCur = cur->next;

		// Make the list skip over 'cur'.
		// Then free the memory at 'cur'
		beforeCur->next = afterCur;
		afterCur->prev = beforeCur;
		delete cur;

		--length;
	}
}

void DLList::deleteAtEnd()
{
	// !head means the list is empty
	if (head == nullptr)
	{
		return;
	}

	// Means there is only one element in the list
	else if (head->next == nullptr)
	{
		head = nullptr;
		tail = nullptr;
	}

	else
	{
		// Make the second-to-last element in the 
		// list the tail. Free memory at the old tail,
		// then assign the old tail nullptr so that
		// the display() method won't read its value.
		tail = tail->prev;
		delete tail->next;
		tail->next = nullptr;
	}
	--length;
}

void DLList::display()
{
	std::cout << "Data: ";
	DLLNode* cur = head;
	while (cur != nullptr)
	{
		std::cout << cur->data << ' ';
		cur = cur->next;
	}
	std::cout << std::endl;
}