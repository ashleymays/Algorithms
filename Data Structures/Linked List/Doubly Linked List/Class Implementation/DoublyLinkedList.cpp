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
	DLLNode* cur = head;

	while (cur) 
	{
		if (val == cur->data) 
		{
			return true;
		}
		cur = cur->next;
	}
	return false;
}

void DLList::insertAtBeg(int val) 
{
	DLLNode* newNode(new DLLNode(val));

	if (!head) 
	{
		head = newNode;
		tail = newNode;
	}
	else 
	{
		newNode->next = head;
		head->prev = newNode;
		head = newNode;
	}
	++length;
}

void DLList::insertAtIndex(int val, int i) 
{
	if (i < 0 || i > length) 
	{
		return;
	}
	else if (i == 0) 
	{
		insertAtBeg(val);
	}
	else if (i == length) 
	{
		insertAtEnd(val);
	}
	else 
	{
		DLLNode* newNode(new DLLNode(val));
		DLLNode* cur = head;

		for (int j = 0; j < i - 1; ++j) 
		{
			cur = cur->next;
		}
		newNode->prev = cur;
		newNode->next = cur->next;
		cur->next = newNode;
		++length;
	}
}

void DLList::insertAtEnd(int val) 
{
	DLLNode* newNode(new DLLNode(val));

	if (!head) 
	{
		head = newNode;
		tail = newNode;
	}
	else 
	{
		tail->next = newNode;
		newNode->prev = tail;
		tail = newNode;
	}
	++length;
}

void DLList::deleteAtBeg() 
{
	if (!head) 
	{
		return;
	}
	else if (!head->next) 
	{
		head = nullptr;
		tail = nullptr;
	}
	else 
	{
		head = head->next;
		delete head->prev;
		head->prev = nullptr;
	}
	--length;
}

void DLList::deleteAtIndex(int i) 
{
	if (!head || i < 0 || i >= length) 
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
		for (int j = 0; j < i - 1; ++j) 
		{
			cur = cur->next;
		}
		cur->next = cur->next->next;
		delete cur->next->prev;
		cur->next->prev = cur;
		--length;
	}
}

void DLList::deleteAtEnd() 
{
	if (!head) 
	{
		return;
	}
	else if (!head->next) 
	{
		head = nullptr;
		tail = nullptr;
	}
	else 
	{
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