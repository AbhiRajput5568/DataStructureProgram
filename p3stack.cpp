#include <iostream>
using namespace std;

#define MAX 5 // Define maximum size of stack

class Stack
{
private:
    int top;
    int arr[MAX]; // Array to store stack elements

public:
    Stack() { top = -1; } // Constructor initializes stack as empty

    // Push operation
    void push(int value)
    {
        if (top >= MAX - 1)
        { // Check for overflow
            cout << "Stack Overflow! Cannot push " << value << endl;
            return;
        }
        arr[++top] = value;
        cout << value << " pushed onto stack." << endl;
    }

    // Pop operation
    int pop()
    {
        if (top == -1)
        { // Check for underflow
            cout << "Stack Underflow! No elements to pop." << endl;
            return -1;
        }
        cout << arr[top] << " popped from stack." << endl;
        return arr[top--];
    }

    // Display Stack
    void display()
    {
        if (top == -1)
        {
            cout << "Stack is empty." << endl;
            return;
        }
        cout << "Stack elements: ";
        for (int i = top; i >= 0; i--)
            cout << arr[i] << " ";
        cout << endl;
    }

    // Check Palindrome
    bool isPalindrome()
    {
        if (top == -1)
        {
            cout << "Stack is empty! Cannot check palindrome." << endl;
            return false;
        }
        for (int i = 0, j = top; i < j; i++, j--)
        {
            if (arr[i] != arr[j])
            {
                cout << "Stack does NOT form a palindrome." << endl;
                return false;
            }
        }
        cout << "Stack forms a palindrome!" << endl;
        return true;
    }

    // Demonstrate Overflow
    void demonstrateOverflow()
    {
        cout << "Demonstrating Stack Overflow:" << endl;
        for (int i = 1; i <= MAX + 1; i++)
        {
            push(i);
        }
    }

    // Demonstrate Underflow
    void demonstrateUnderflow()
    {
        cout << "Demonstrating Stack Underflow:" << endl;
        while (top >= -1)
        {
            pop();
        }
    }
};

int main()
{
    Stack s;
    int choice, value;

    do
    {
        cout << "\nMenu:\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Check Palindrome\n";
        cout << "4. Display Stack\n";
        cout << "5. Demonstrate Overflow\n";
        cout << "6. Demonstrate Underflow\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value to push: ";
            cin >> value;
            s.push(value);
            break;
        case 2:
            s.pop();
            break;
        case 3:
            s.isPalindrome();
            break;
        case 4:
            s.display();
            break;
        case 5:
            s.demonstrateOverflow();
            break;
        case 6:
            s.demonstrateUnderflow();
            break;
        case 7:
            cout << "Exiting program..." << endl;
            break;
        default:
            cout << "Invalid choice! Try again." << endl;
        }
    } while (choice != 7);

    return 0;
}
