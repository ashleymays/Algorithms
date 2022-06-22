/*
    Stack - STL Implementation

    This is an implementation of a stack using the predefined header file in C++.

*/

#include <iostream>
#include <stack>
using namespace std;


// Display elements
void display(stack<int> stack)
{
    // We can't iterate through the stack, so we make
    // a copy of it (by passing the stack by value),
    // read the top element, and pop it off until the
    // stack is empty.

    int size = stack.size();

    cout << "Stack: ";
    for (int i = 0; i < size; ++i)
    {
        cout << stack.top() << ' ';
        stack.pop();
    }
    cout << endl;
}

int main()
{
    // Create new stack "nums"
    stack<int> nums;

    nums.push(10);
    nums.push(20);
    nums.push(30);
    nums.push(40);
    nums.push(50);

    // display "nums"
    display(nums);

    // pop the top element off the stack
    nums.pop();

    // display "nums"
    display(nums);

    // display the top element
    cout << "Top: " << nums.top() << endl;

    return 0;
}