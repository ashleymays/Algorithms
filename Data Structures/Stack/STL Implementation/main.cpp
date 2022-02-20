
// Stack - STL Implementation
// Read more at https://www.cplusplus.com/reference/stack/stack/

#include <iostream>
#include <stack>


// Display elements
void display(std::stack<char> stack)
{
    // the stack library doesn't have iterators, so you have to make
    // a copy of it (pass by value) and pop elements off
    int size = stack.size();
    for (int i = 0; i < size; ++i)
    {
        std::cout << stack.top() << ' ';
        stack.pop();
    }
    std::cout << std::endl;
}

int main()
{
    // Create new stack "letters" and add characters
    std::stack<char> letters;
    letters.push('a');
    letters.push('b');
    letters.push('c');
    letters.push('d');
    letters.push('e');

    display(letters);

    letters.pop();
    std::cout << "Popped." << std::endl;

    display(letters);


    return 0;
}
