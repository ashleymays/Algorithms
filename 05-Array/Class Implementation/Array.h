#ifndef ARRAY_H
#define ARRAY_H

class Array {
private:
	int* arr;
	int size;
	int capacity;

public:
	Array() : arr(nullptr), size(0), capacity(0) {}
	Array(int c) : arr(new int[c]), size(0), capacity(c) {}
	~Array();

	bool isEmpty();
	bool isFull();
	int getSize();
	int getCapacity();
	int getFront();
	int getBack();
	int search(int val);
	void insertAtBeg(int val);
	void insertAtIndex(int val, int i);
	void insertAtEnd(int val);
	void deleteValue(int val);
	void update(int val, int i);
	void display();
};

#endif /* ARRAY_H */