#include <iostream>
#include "SinglyLinkedList.h"


// Destructor - Called before the program ends
SLList::~SLList()
{
	// Make a node "cur" to run through the list
	SLLNode* cur = head;

	// Run through the list
	while (cur && cur->next)
	{
		// Assign a node "node" to contain the node after "cur"
		SLLNode* node = cur->next;

		// Free the memory
		delete cur;

		// Update "cur" so that it points to the next node in the list
		cur = node;
	}
}

int SLList::getLength()
{
	return length;
}

int SLList::getFront()
{
	// if the list is empty return -1
	if (!head)
	{
		std::cout << "List is empty." << std::endl;
		return -1;
	}

	// if the list isn't empty return the data at the head
	return head->data;
}

int SLList::getRear()
{
	// if the list is empty return -1
	if (!head)
	{
		std::cout << "List is empty." << std::endl;
		return -1;
	}


	SLLNode* cur = head;

	// Iterate through the list to get to the last node
	while (cur->next)
	{
		cur = cur->next;
	}
	return cur->data;
}

bool SLList::search(int val)
{
	SLLNode* cur = head;

	// Iterate through the list
	while (cur)
	{
		// We found the value in the list -> return true
		if (cur->data == val)
		{
			return true;
		}

		// Update "cur" to move to the next node
		cur = cur->next;
	}
	return false;
}

// TODO
void SLList::insertAtHead(int val)
{
	// Make a new node "newNode" to contain the value
	SLLNode* newNode = new SLLNode(val);

	// The list is empty -> assign "newNode" as the head of the list
	if (!head)
	{
		head = newNode;
	}

	// The list isn't empty -> make the original head node 
	// the node after "newNode" and assign "newNode" as the head of the list
	else
	{
		newNode->next = head;
		head = newNode;
	}

	++length;
}

void SLList::insertAtIndex(int val, int i)
{
	// Make a new node "newNode" to contain the value
	SLLNode* newNode = new SLLNode(val);

	// i is not a valid index -> exit the method
	if (i < 0 || i > length)
	{
		return;
	}

	else if (i == 0)
	{
		insertAtHead(val);
	}

	else if (i == length)
	{
		insertAtTail(val);
	}

	else
	{
		// Create a node "cur" to iterate through the list
		SLLNode* cur = head;

		// Find the node at index i-1
		for (int j = 0; j < i - 1; ++j)
		{
			cur = cur->next;
		}

		// "tmp" is the node that originally comes after "cur"
		SLLNode* tmp = cur->next;

		// Make "newNode" come before tmp (so now the list looks like "newNode"->"tmp")
		newNode->next = tmp;

		// Make "newNode" come after cur (now the list looks like "cur"->"newNode"->"tmp)
		cur->next = newNode;

		++length;
	}
}

void SLList::insertAtTail(int val)
{
	// Make a new node "newNode" to contain the value
	SLLNode* newNode = new SLLNode(val);

	// list is empty -> make "newNode" the head
	if (!head)
	{
		head = newNode;
	}

	// else get to the last node in the list and make "newNode" come after it
	else
	{
		SLLNode* cur = head;
		while (cur->next)
		{
			cur = cur->next;
		}
		cur->next = newNode;
	}
	++length;
}

void SLList::deleteAtHead()
{
	// exit method if list is empty
	if (!head)
	{
		return;
	}

	// if list has 1 node free memory at the head and make it point to nothing
	else if (!head->next)
	{
		delete head;
		head = nullptr;
	}

	// list has more than one node
	else
	{
		SLLNode* tmp = head->next;
		delete head;
		head = tmp;
	}

	--length;
}

void SLList::deleteAtIndex(int i)
{
	// exit method if list is empty of the index is invalid
	if (!head || i < 0 || i > length - 1)
	{
		return;
	}

	else if (i == 0)
	{
		deleteAtHead();
	}

	else if (i == length - 1)
	{
		deleteAtTail();
	}

	// if list has more than one node get to the node before the last node
	else
	{
		SLLNode* cur = head;

		// go to the node at index i - 1 (the one before the node we will delete)
		for (int j = 0; j < i - 1; ++j)
		{
			cur = cur->next;
		}

		// pre: the node before the node we will delete
		// post: the node after the node we will delete
		SLLNode* pre = cur;
		SLLNode* post = cur->next->next;

		// free memory at the node at index i and make it point to nothing
		delete pre->next;
		pre->next = nullptr;


		// shift the elements after index i
		pre->next = post;
	}

	--length;
}

void SLList::deleteAtTail()
{
	// exit method if list is empty
	if (!head)
	{
		return;
	}

	// if list has 1 node free memory at the head and make it point to nothing
	else if (!head->next)
	{
		delete head;
		head = nullptr;
	}

	// if list has more than one node get to the node before the last node
	else
	{
		SLLNode* cur = head;
		while (cur->next->next)
		{
			cur = cur->next;
		}

		// free the memory at the last node
		SLLNode* lastNode = cur->next;
		delete lastNode;

		// make the last node point to nothing
		cur->next = nullptr;
	}

	--length;
}

void SLList::display()
{
	SLLNode* cur = head;
	std::cout << "List: ";
	while (cur)
	{
		std::cout << cur->data << ' ';
		cur = cur->next;
	}
	std::cout << std::endl;
}