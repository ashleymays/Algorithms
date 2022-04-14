#include <iostream>
#include "Queue.h"

int main()
{
	Queue q(10);

	q.enqueue(1);
	q.enqueue(2);
	q.enqueue(3);
	q.enqueue(4);
	q.enqueue(5);

	q.display();

	std::cout << "Front: " << q.getFront() << std::endl;
	std::cout << "Back: " << q.getBack() << std::endl;
	std::cout << "Size: " << q.getSize() << std::endl;
	std::cout << "Capacity: " << q.getCapacity() << std::endl;

	q.dequeue();

	q.display();

	std::cout << "Front: " << q.getFront() << std::endl;
	std::cout << "Back: " << q.getBack() << std::endl;
	std::cout << "Size: " << q.getSize() << std::endl;
	std::cout << "Capacity: " << q.getCapacity() << std::endl;



	return 0;
}