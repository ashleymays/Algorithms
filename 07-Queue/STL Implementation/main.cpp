
// Queue - STL Implementation
// Read more at https://www.cplusplus.com/reference/queue/queue/

#include <iostream>
#include <queue>

int main()
{
	std::queue<int> q;
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	q.push(5);

	std::cout << "Front: " << q.front() << std::endl;
	std::cout << "Back: " << q.back() << std::endl;

	q.pop();

	std::cout << "Front: " << q.front() << std::endl;
	std::cout << "Back: " << q.back() << std::endl;

	return 0;
}