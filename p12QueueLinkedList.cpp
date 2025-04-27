/*
12). Design, Develop and Implement a menu driven Program for the following operations on QUEUE (Linked Implementation)
a. Check Overflow and Underflow situations on QUEUE
b. Insert an Element on to QUEUE
c. Delete an Element from QUEUE
d. Display the elements of QUEUE
e. Exit
Support the program with appropriate functions for each of the above operations
*/
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* front = nullptr;
Node* rear = nullptr;

void insert(int value) {
    Node* newNode = new Node();
    if (newNode == nullptr) {
        cout << "Overflow! Cannot insert.\n";
        return;
    }
    newNode->data = value;
    newNode->next = nullptr;
    if (rear == nullptr) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
    cout << value << " inserted.\n";
}

void deleteElement() {
    if (front == nullptr) {
        cout << "Underflow! Queue is empty.\n";
        return;
    }
    Node* temp = front;
    cout << temp->data << " deleted.\n";
    front = front->next;
    if (front == nullptr) {
        rear = nullptr;
    }
    delete temp;
}

void display() {
    if (front == nullptr) {
        cout << "Queue is empty.\n";
        return;
    }
    Node* temp = front;
    cout << "Queue: ";
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    cout<<"ABHISHEK SINGH 2315272/2435222";
    char choice;
    int value;
    do {
        cout << "\n--- Queue Operations Menu ---\n";
        cout << "a. Insert an element into Queue\n";
        cout << "b. Delete an element from Queue\n";
        cout << "c. Display elements of Queue\n";
        cout << "d. Check Overflow/Underflow\n";
        cout << "e. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 'a':
            case 'A':
                cout << "Enter value: ";
                cin >> value;
                insert(value);
                break;
            case 'b':
            case 'B':
                deleteElement();
                break;
            case 'c':
            case 'C':
                display();
                break;
            case 'd':
            case 'D':
                if (front == nullptr)
                    cout << "Queue Underflow (Empty Queue).\n";
                else
                    cout << "Queue has elements (No Overflow or Underflow).\n";
                break;
            case 'e':
            case 'E':
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 'e' && choice != 'E');

    return 0;
}

