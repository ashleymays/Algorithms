#ifndef SLLIST_H
#define SLLIST_H

struct SLLNode {
	SLLNode() : next(nullptr), data(0) {}
	SLLNode(int d) : next(nullptr), data(d) {}
	SLLNode(int d, SLLNode* n) : next(n), data(d) {}
	~SLLNode() {}

	SLLNode* next;
	int data;
};

class SLList {
private:
	int length;
	SLLNode* head;
public:
	SLList() : head(nullptr), length(0) {}
	~SLList();

	int getLength();
	int getFront();
	int getRear();
	bool search(int val);
	void insertAtHead(int val);
	void insertAtIndex(int val, int i);
	void insertAtTail(int val);
	void deleteAtHead();
	void deleteAtIndex(int i);
	void deleteAtTail();
	void display();
};

#endif /* SLLLIST_H */