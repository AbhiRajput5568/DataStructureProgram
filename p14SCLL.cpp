/*
14) Design, Develop and Implement a Program to perform insertion, deletion and traversing in a sorted Singly Circular Linked List (SCLL) with header nodes.
*/
#include <iostream>
using namespace std;

// Structure for Node
struct Node
{
    int data;
    Node *next;
};

// Class for Sorted Singly Circular Linked List
class SCLL
{
private:
    Node *header;

public:
    // Constructor to initialize the list
    SCLL()
    {
        header = new Node();
        header->next = header; // Circular linked list with one node
    }

    // Function to insert a new node in sorted order
    void insert(int value)
    {
        Node *newNode = new Node();
        newNode->data = value;
        Node *temp = header;

        // Traverse the list to find the correct position
        while (temp->next != header && temp->next->data < value)
        {
            temp = temp->next;
        }

        // Insert the new node after temp
        newNode->next = temp->next;
        temp->next = newNode;
    }

    // Function to delete a node with a specific value
    void deleteNode(int value)
    {
        Node *temp = header;
        Node *toDelete = nullptr;

        // Traverse to find the node
        while (temp->next != header && temp->next->data != value)
        {
            temp = temp->next;
        }

        // If the node is found
        if (temp->next != header)
        {
            toDelete = temp->next;
            temp->next = temp->next->next;
            delete toDelete;
            cout << "Deleted " << value << endl;
        }
        else
        {
            cout << "Node with value " << value << " not found!" << endl;
        }
    }

    // Function to traverse and print the list
    void traverse()
    {
        Node *temp = header->next;
        if (temp == header)
        {
            cout << "List is empty!" << endl;
            return;
        }

        cout << "List contents: ";
        while (temp != header)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Destructor to free allocated memory
    ~SCLL()
    {
        Node *temp = header->next;
        while (temp != header)
        {
            Node *toDelete = temp;
            temp = temp->next;
            delete toDelete;
        }
        delete header;
    }
};

int main()
{
    cout << "ABHISHEK SINGH 231527282435222";
    SCLL list;

    int choice, value;
    while (true)
    {
        // Menu
        cout << "\n--- Sorted Singly Circular Linked List Menu ---\n";
        cout << "1. Insert an element\n";
        cout << "2. Delete an element\n";
        cout << "3. Traverse the list\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter the value to insert: ";
            cin >> value;
            list.insert(value);
            break;

        case 2:
            cout << "Enter the value to delete: ";
            cin >> value;
            list.deleteNode(value);
            break;

        case 3:
            list.traverse();
            break;

        case 4:
            cout << "Exiting program.\n";
            return 0;

        default:
            cout << "Invalid choice! Please try again.\n";
        }
    }

    return 0;
}
