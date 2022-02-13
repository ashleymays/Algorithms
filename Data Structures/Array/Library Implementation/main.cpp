
// Array - Library Implementation

#include <iostream>
#include <array>
using namespace std;

int main()
{
    array<int, 5> arr = { 1,2,3,4,5 };
    cout << "Front: " << arr.front() << endl;
    cout << "Back: " << arr.back() << endl;
    cout << "Size: " << arr.size() << endl;
    cout << "arr[1]: " << arr[1] << endl;

    return 0;
}
