#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

struct DLLNode {
	DLLNode() : next(nullptr), prev(nullptr), data(0) {}
	DLLNode(int d) : next(nullptr), prev(nullptr), data(d) {}
	DLLNode(int d, DLLNode* n, DLLNode* p) : next(n), prev(p), data(d) {}
	~DLLNode() {}

	DLLNode* next;
	DLLNode* prev;
	int data;
};

class DLList {
private:
	int length;
	DLLNode* head;
	DLLNode* tail;
public:
	DLList() : head(nullptr), tail(nullptr), length(0) {}
	~DLList();

	int getLength();
	int getFront();
	int getRear();
	bool search(int val);
	void insertAtBeg(int val);
	void insertAtIndex(int val, int i);
	void insertAtEnd(int val);
	void deleteAtBeg();
	void deleteAtIndex(int i);
	void deleteAtEnd();
	void display();
};

#endif /* DOUBLYLINKEDLIST_H */