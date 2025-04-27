/* 11) Design, Develop and Implement a menu driven Program for the following operations on STACK of Integers (Linked Implementation)
a. Push an Element on to Stack
b. Pop an Element from Stack
c. To check Overflow and Underflow situations on Stack
d. Display the elements of Stack
e. Exit*/
#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

class Stack
{
private:
    Node *top;

public:
    Stack()
    {
        top = nullptr;
    }

    void push(int value)
    {
        Node *newNode = new Node();
        if (newNode == nullptr)
        {
            cout << "Overflow! Cannot push.\n";
            return;
        }
        newNode->data = value;
        newNode->next = top;
        top = newNode;
        cout << value << " pushed.\n";
    }

    void pop()
    {
        if (top == nullptr)
        {
            cout << "Underflow! Stack is empty.\n";
            return;
        }
        Node *temp = top;
        cout << temp->data << " popped.\n";
        top = top->next;
        delete temp;
    }

    void display()
    {
        if (top == nullptr)
        {
            cout << "Stack is empty.\n";
            return;
        }
        Node *temp = top;
        cout << "Stack: ";
        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main()
{
    Stack s;
    int choice, value;

    do
    {
        cout << "ABHISHEK SINGH 2315272/2435222" << endl;
        cout << "\n1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Display" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            s.push(value);
            break;
        case 2:
            s.pop();
            break;
        case 3:
            s.display();
            break;
        case 4:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice.\n";
        }
    } while (choice != 4);

    return 0;
}
