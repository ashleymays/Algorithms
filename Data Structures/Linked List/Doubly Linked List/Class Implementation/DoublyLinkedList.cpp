#include <iostream>
#include "DoublyLinkedList.h"

DLList::~DLList()
{
	DLLNode* cur = head;
	while (cur)
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
	DLLNode* cur = head;								// Node 'cur' is used to read through the list
	while (cur)
	{
		if (val == cur->data)
		{
			return true;
		}
		cur = cur->next;								// Assign cur to the next node in th elist to iterate
	}
	return false;
}

void DLList::insertAtBeg(int val)
{
	DLLNode* newNode(new DLLNode(val));					// Put the value in a node
	if (!head)											// !head means that the head is nullptr, i.e. the lsit is empty
	{
		head = newNode;									// newNode is now both the head and the tail
		tail = newNode;
	}
	else
	{
		newNode->next = head;							// newNode -> head
		head->prev = newNode;							// newNode <- head
		head = newNode;									// Make newNode the head of the list
	}
	++length;
}

void DLList::insertAtIndex(int val, int i)				// List starts at index 0
{
	if (i < 0 || i > length)							// If the index is invalid, exit the method
	{
		return;
	}
	else if (i == 0)									// Inserting at index 0 is the same as inserting at the head
	{
		insertAtBeg(val);
	}
	else if (i == length)								// Inserting at this index is the same as inserting at the end
	{
		insertAtEnd(val);
	}
	else {
		DLLNode* newNode(new DLLNode(val));				// Put value in a node called 'newNode'
		DLLNode* cur = head;							// Node 'cur' is used to read through the list

		for (int j = 0; j < i - 1; ++j)					// Read through the list until we get to the corrent index to insert at
		{
			cur = cur->next;
		}												// 'cur' is now at index i - 1, i.e. the node before where we want to insert at

		newNode->prev = cur;							// Next 3 lines: Putting newNode between cur and cur->next
		newNode->next = cur->next;
		cur->next = newNode;
		++length;
	}
}

void DLList::insertAtEnd(int val)
{
	DLLNode* newNode(new DLLNode(val));
	if (!head)											// !head means that the head is nullptr, i.e. the lsit is empty
	{
		head = newNode;									// newNode is now both the head and the tail
		tail = newNode;
	}
	else
	{
		tail->next = newNode;							// old tail -> newNode
		newNode->prev = tail;							// newNode <- old tail
		tail = newNode;									// Make newNode the tail
	}
	++length;
}

void DLList::deleteAtBeg()
{
	if (!head)											// !head means that the list is empty (the head is nullptr)
	{
		return;
	}
	else if (!head->next)								// Means there's only one element in the list
	{
		head = nullptr;
		tail = nullptr;
	}
	else
	{
		head = head->next;								// Make the second element in the list the head
		delete head->prev;								// Free memory at the old head and assign it to nullptr
		head->prev = nullptr;
	}
	--length;
}

void DLList::deleteAtIndex(int i)
{
	if (!head || i < 0 || i >= length)					// If the list is empty, or i is an invalid index, exit the method
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
		}												// "cur" is now the node we want to delete

		DLLNode* beforeCur = cur->prev;
		DLLNode* afterCur = cur->next;

		beforeCur->next = afterCur;						// Make the list skip over the node to be deleted
		afterCur->prev = beforeCur;
		delete cur;

		--length;
	}
}

void DLList::deleteAtEnd()
{
	if (!head)											// !head means the list is empty
	{
		return;
	}
	else if (!head->next)								// Means there is only one element in the list
	{
		head = nullptr;
		tail = nullptr;
	}
	else
	{
		tail = tail->prev;								// Make the second-to-last element the tail
		delete tail->next;								// Free memory at the old tail
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