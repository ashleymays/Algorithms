
// Doubly Linked List - STL Demonstration
// Read more at https://www.cplusplus.com/reference/list/list/

#include <iostream>
#include <list>
#include <algorithm>


// Display elements
void display(std::list<int>& list)
{
    std::list<int>::iterator it;
    for (it = list.begin(); it != list.end(); ++it)
    {
        std::cout << *it << ' ';
    }
    std::cout << std::endl;
}

int main()
{
    std::list<int> list = { 1,2,3,4,5 };
    std::cout << "Front: " << list.front() << std::endl;
    std::cout << "Back: " << list.back() << std::endl;
    std::cout << "Size: " << list.size() << std::endl;

    list.push_front(0);
    std::cout << "Pushed 0 to front." << std::endl;

    list.pop_back();
    std::cout << "Popped back." << std::endl;

    std::list<int>::iterator secondElement = list.begin();
    std::advance(secondElement, 2);
    list.erase(secondElement);
    std::cout << "Erased third element." << std::endl;

    display(list);


    return 0;
}
