#include <iostream>
#include "Stack.h"
using namespace std;

int main()
{
    // Create a new stack "nums" with a capacity of 10;
    Stack nums;
    nums.push(10);
    nums.push(20);
    nums.push(30);
    nums.push(40);
    nums.push(50);

    // display "nums"
    nums.display();

    // pop the top element off the stack
    nums.pop();

    // display "nums"
    nums.display();

    // display the top element
    cout << "Top: " << nums.top() << endl;

    return 0;
}