
#include <iostream>
using namespace std;

#define MAX 5 // Maximum size of the queue

class Queue
{
private:
    int arr[MAX]; // Array to hold the queue elements
    int front, rear;

public:
    Queue()
    {
        front = -1; // Initialize front to -1 (empty queue)
        rear = -1;  // Initialize rear to -1 (empty queue)
    }

    // Check if the queue is full (Overflow condition)
    bool isFull()
    {
        if (rear == MAX - 1)
        {
            return true;
        }
        return false;
    }

    // Check if the queue is empty (Underflow condition)
    bool isEmpty()
    {
        if (front == -1 || front > rear)
        {
            return true;
        }
        return false;
    }

    // Insert an element into the queue
    void insert()
    {
        if (isFull())
        {
            cout << "Overflow! Queue is full." << endl;
        }
        else
        {
            int value;
            cout << "Enter the element to insert: ";
            cin >> value;

            if (front == -1)
            {
                front = 0; // If it's the first element, set front to 0
            }
            rear++;
            arr[rear] = value;
            cout << "Element " << value << " inserted successfully." << endl;
        }
    }

    // Delete an element from the queue
    void deleteElement()
    {
        if (isEmpty())
        {
            cout << "Underflow! Queue is empty." << endl;
        }
        else
        {
            cout << "Element " << arr[front] << " deleted successfully." << endl;
            front++; // Move front pointer to the next element
        }
    }

    // Display the elements of the queue
    void display()
    {
        if (isEmpty())
        {
            cout << "Queue is empty." << endl;
        }
        else
        {
            cout << "Queue elements: ";
            for (int i = front; i <= rear; i++)
            {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }

    // Check and display overflow situation
    void checkOverflow()
    {
        if (isFull())
        {
            cout << "Overflow! Queue is full." << endl;
        }
        else
        {
            cout << "Queue is not full. Space is available for new elements." << endl;
        }
    }

    // Check and display underflow situation
    void checkUnderflow()
    {
        if (isEmpty())
        {
            cout << "Underflow! Queue is empty." << endl;
        }
        else
        {
            cout << "Queue is not empty. Elements are present." << endl;
        }
    }
};

// Menu-driven program to perform operations
int main()
{
    cout << "ABHISHEK SINGH 2315272/2435222" << endl;
    Queue q;
    int choice;

    while (true)
    {

        cout << "Menu:\n";
        cout << "1. Insert an Element\n";
        cout << "2. Delete an Element\n";
        cout << "3. Display the Queue\n";
        cout << "4. Check Overflow\n";
        cout << "5. Check Underflow\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            q.insert();
            break;
        case 2:
            q.deleteElement();
            break;
        case 3:
            q.display();
            break;
        case 4:
            q.checkOverflow();
            break;
        case 5:
            q.checkUnderflow();
            break;
        case 6:
            cout << "Exiting program." << endl;
            return 0;
        default:
            cout << "Invalid choice! Please try again." << endl;
        }
    }

    return 0;
}
