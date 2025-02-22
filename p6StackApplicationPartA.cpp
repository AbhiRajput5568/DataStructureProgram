// Design, Develop and Implement a Program for the following Stack Applications a. Evaluation of Suffix expression with single digit operands and operators: +, -, *, /, %, ^
#include <iostream>
#include <stack>
#include <cmath>
using namespace std;

// Function to evaluate postfix expression
int evaluatePostfix(string exp)
{
    stack<int> s;
    for (char ch : exp)
    {
        if (isdigit(ch))
        {
            s.push(ch - '0'); // Convert char to int
        }
        else
        {
            int val2 = s.top();
            s.pop();
            int val1 = s.top();
            s.pop();
            switch (ch)
            {
            case '+':
                s.push(val1 + val2);
                break;
            case '-':
                s.push(val1 - val2);
                break;
            case '*':
                s.push(val1 * val2);
                break;
            case '/':
                s.push(val1 / val2);
                break;
            case '%':
                s.push(val1 % val2);
                break;
            case '^':
                s.push(pow(val1, val2));
                break;
            }
        }
    }
    return s.top();
}

int main()
{
    string postfixExp;
    cout << "Enter postfix expression: ";
    cin >> postfixExp;
    cout << "Result: " << evaluatePostfix(postfixExp) << endl;
    return 0;
}
