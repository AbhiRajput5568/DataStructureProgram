//  Design, Develop and Implement a Program for converting an Infix Expression to Postfix Expression. Program should support for both parenthesized and free parenthesized expressions with the operators: +, -, *, /, %(Remainder), ^(Power) and alphanumeric operands.
#include <iostream>
#include <stack>
#include <string>
#include <cctype>

using namespace std;

// Function to return precedence of operators
int precedence(char op)
{
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/' || op == '%')
        return 2;
    if (op == '^')
        return 3;
    return 0;
}

// Function to check if the character is an operand (alphanumeric)
bool is_operand(char c)
{
    return isalnum(c); // Operand is an alphanumeric character
}

// Function to convert infix expression to postfix
string infix_to_postfix(const string &expression)
{
    stack<char> operators; // Stack to store operators
    string postfix = "";   // Resulting postfix expression

    for (int i = 0; i < expression.length(); i++)
    {
        char current = expression[i];

        // If the character is an operand, add it to the result
        if (is_operand(current))
        {
            postfix += current;
        }
        // If the character is '(', push it to the stack
        else if (current == '(')
        {
            operators.push(current);
        }
        // If the character is ')', pop from stack to result until '(' is found
        else if (current == ')')
        {
            while (!operators.empty() && operators.top() != '(')
            {
                postfix += operators.top();
                operators.pop();
            }
            if (!operators.empty())
            {
                operators.pop(); // Remove '(' from stack
            }
        }
        // If the character is an operator, handle precedence and stack operations
        else if (current == '+' || current == '-' || current == '*' || current == '/' || current == '%' || current == '^')
        {
            while (!operators.empty() && precedence(operators.top()) >= precedence(current))
            {
                postfix += operators.top();
                operators.pop();
            }
            operators.push(current);
        }
    }

    // Pop all remaining operators in the stack
    while (!operators.empty())
    {
        postfix += operators.top();
        operators.pop();
    }

    return postfix;
}

int main()
{
    cout << "ABHISHEK SINGH 2315272/2435222" << endl;
    string infix_expression;

    // Input the infix expression
    cout << "Enter the infix expression: ";
    getline(cin, infix_expression);

    // Convert to postfix expression
    string postfix_expression = infix_to_postfix(infix_expression);

    // Output the result
    cout << "Postfix expression: " << postfix_expression << endl;

    return 0;
}
