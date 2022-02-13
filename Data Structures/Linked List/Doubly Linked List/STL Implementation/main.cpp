
// List - STL Demonstration

#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

int main()
{
    list<int> list = { 1,2,3,4,5 };
    cout << "Front: " << list.front() << endl;
    cout << "Back: " << list.back() << endl;
    cout << "Size: " << list.size() << endl;

    list.push_front(0);
    cout << "Pushed 0 to front." << endl;

    list.push_front(-1);
    cout << "Pushed -1 to front." << endl;

    list.push_back(6);
    cout << "Pushed 6 to back." << endl;

    list.pop_back();
    cout << "Popped back." << endl;

    list.pop_front();
    cout << "Popped front." << endl;

    std::list<int>::iterator secondElement = list.begin();
    advance(secondElement, 2);
    list.erase(secondElement);
    cout << "Erased third element." << endl;

    // Display elements
    std::list<int>::iterator it;
    for (it = list.begin(); it != list.end(); ++it)
    {
        cout << *it << ' ';
    }
    cout << endl;

    return 0;
}
