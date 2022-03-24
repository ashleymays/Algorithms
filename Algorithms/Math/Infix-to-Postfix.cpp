/*
    Infix to Postfix

    This algorithm converts a mathematical expression from infix notation to postfix notation, also
    known as Reverse Polish notation. For example, the infix expression "3 * 2 + 4" will be converted to
    "3 2 * 4 +".

    Time Complexity: O(n^2) because of the while loops inside the for loop in the algorithm
    Space Complexity: O(n) because of the creation of a postfix string

    This implementation also has a method 'solvePostfix()' which will solve the expression when it is in postfix notation.
    Further explanation of the algorithm is in the method "convertInfixToPostfix"

    Read more at https://www.tutorialspoint.com/Convert-Infix-to-Postfix-Expression#:~:text=To%20convert%20infix%20expression%20to,maintaining%20the%20precedence%20of%20them.
*/

#include <iostream>
#include <string>
#include <stack>
#include <cmath>

class Expression
{
public:
    Expression() : postfix(""), result(0) {}
    void convertInfixToPostfix(const std::string& infix);
    void solvePostfix();
    std::string getPostfix();
    float getResult();
private:
    bool isDigit(const char& c);
    bool isOperator(const char& c);
    int assignPrecedence(const char& c);
    bool hasGreaterPrecedence(const char& a, const char& b);
    bool hasEqualPrecedence(const char& a, const char& b);
    bool isLeftAssociative(const char& c);
    float operation(const float& a, const float& b, const char& op);
    std::string postfix;
    float result;
};

std::string Expression::getPostfix()
{
    return postfix;
}

float Expression::getResult()
{
    return result;
}

bool Expression::isDigit(const char& c)
{
    return c >= 48 && c <= 57;
}

bool Expression::isOperator(const char& c)
{
    return (c == '^') || (c == '*') || (c == '/') || (c == '+') || (c == '-');
}

int Expression::assignPrecedence(const char& c)
{
    // We assign a value to each operator.
    // A bigger number implies higher precedence.
    if (c == '^') return 4;
    if ((c == '*') || (c == '/')) return 3;
    if ((c == '+') || (c == '-')) return 2;
    else return -1;
}

bool Expression::hasGreaterPrecedence(const char& a, const char& b)
{
    return assignPrecedence(a) > assignPrecedence(b);
}

bool Expression::hasEqualPrecedence(const char& a, const char& b)
{
    return assignPrecedence(a) == assignPrecedence(b);
}

bool Expression::isLeftAssociative(const char& c)
{
    return isOperator(c) && (c == '+' || c == '-' || c == '*' || c == '/');
}

float Expression::operation(const float& a, const float& b, const char& op)
{
    if (op == '^')
    {
        return pow(b, a);
    }
    else if (op == '+')
    {
        return a + b;
    }
    else if (op == '-')
    {
        return b - a;
    }
    else if (op == '/')
    {
        return b / a;
    }
    else
    {
        return a * b;
    }
}

void Expression::convertInfixToPostfix(const std::string& infix)
{
    std::stack<char> operators;
    for (int i = 0; i < infix.size(); ++i)
    {
        // If it's a digit, add it to the postfix string
        if (isDigit(infix[i]))
        {
            postfix += infix[i];
        }

        // If it's an operator, we need to insert it at the right position in the string. So we
        // need to take PEMDAS into account.
        else if (isOperator(infix[i]))
        {
            // First check if there are operators in the stack.
            // Then check that either the next operator in the stack has greater precedence than the one in the infix string (remember PEMDAS),
            // or that they have equal precendence (e.g. + and -), and that the operator in the infix string is left associative
            // Also check that the operator in the stack isn't a left parenthesis. Parentheses are taken care of in the next 'else if' statement.
            while (!operators.empty()
                && (hasGreaterPrecedence(operators.top(), infix[i])
                    || hasEqualPrecedence(operators.top(), infix[i]) && isLeftAssociative(infix[i]))
                && operators.top() != '(')
            {
                postfix += operators.top();
                operators.pop();
            }
            operators.push(infix[i]);
        }

        else if (infix[i] == '(')
        {
            operators.push(infix[i]);
        }

        // When there's a right parenthesis ')', like in the string 1 * (2 + 3), then we read the operators than
        // are contained in the parentheses in the infix notation (in the above example, this would be the operator +). 
        // We do this until we are done reading what is inside the parentheses. When we do reach the left parenthesis '(',
        // we pop it off the stack so that it won't be added to the postfix expression.
        else if (infix[i] == ')')
        {
            while (operators.top() != '(')
            {
                postfix += operators.top();
                operators.pop();
            }
            if (operators.top() == '(')
            {
                operators.pop();
            }
        }
    }

    // After the infix expression is done being read, we check if there are any operators left in the stack.
    // If there are, we insert them into the postfix string.
    while (!operators.empty())
    {
        if (operators.top() != '(')
        {
            postfix += operators.top();
        }
        operators.pop();
    }
}

void Expression::solvePostfix()
{
    std::stack<float> nums;
    float operand1, operand2;
    for (int i = 0; i < postfix.size(); ++i)
    {
        // If the postfix expression has a number, add it to the stack.
        if (isDigit(postfix[i]))
        {
            nums.push(postfix[i] % 48);
        }

        // If the postfix expression has an operator, we pop off two numbers
        // from the stack, and perform the operation on them according to the operator.
        // Then we push the result of the operation into the stack so that it may be operated on later, if needed.
        if (isOperator(postfix[i]))
        {
            operand1 = nums.top();
            nums.pop();
            operand2 = nums.top();
            nums.pop();
            nums.push(operation(operand1, operand2, postfix[i]));
        }
    }
    // The number remaining in the stack is the final answer for the postfix expression.
    result = nums.top();
}


int main()
{
    Expression obj;
    std::string infix = "5^2 / (2 * 4)";
    obj.convertInfixToPostfix(infix);
    obj.solvePostfix();

    std::cout << obj.getPostfix() << std::endl;
    std::cout << obj.getResult() << std::endl;

    return 0;
}