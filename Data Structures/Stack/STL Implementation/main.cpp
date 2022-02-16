
// Stack - STL Implementation

#include <iostream>
#include <stack>
using namespace std;

void display(stack<char> stack)
{
    // the stack library doesn't have iterators, so you
    // can't read through the stack. Make a copy of
    // the stack, read the element at the top of the stack,
    // then use the pop function to remove the element.
    // The next element in the stack will be at the top now.
    int size = stack.size();
    for (int i = 0; i < size; ++i)
    {
        cout << stack.top() << ' ';
        stack.pop();
    }
    cout << endl;
}

int main()
{
    // Create new stack "letters" and add characters
    stack<char> letters;
    letters.push('a');
    letters.push('b');
    letters.push('c');
    letters.push('d');
    letters.push('e');

    // Display "letters"
    cout << "Letters: ";
    display(letters);


    // Create new stack "secondStack" and add characters
    stack<char> secondStack;
    secondStack.push('x');
    secondStack.push('y');
    secondStack.push('z');


    // Display "secondStack"
    cout << "secondStack: ";
    display(secondStack);


    // Swap the contents of "letters" and "secondStack"
    letters.swap(secondStack);
    cout << "Swapped the stacks." << endl;


    // Display the stacks
    cout << "Letters: ";
    display(letters);
    cout << "secondStack: ";
    display(secondStack);




    return 0;
}
