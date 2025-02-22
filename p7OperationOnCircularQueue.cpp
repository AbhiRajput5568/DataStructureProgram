// Design, Develop and Implement a menu driven Program for the following operations on Circular QUEUE of Characters (Array Implementation of Queue with maximum size MAX) a. Insert an Element on to Circular QUEUE b. Delete an Element from Circular QUEUE c. Demonstrate Overflow and Underflow situations on Circular QUEUE d. Display the status of Circular QUEUE
#include <iostream>
#define MAX 5
using namespace std;

class CircularQueue
{
private:
    char queue[MAX];
    int front, rear;

public:
    CircularQueue()
    {
        front = rear = -1;
    }

    bool isFull()
    {
        return (front == 0 && rear == MAX - 1) || (front == rear + 1);
    }

    bool isEmpty()
    {
        return front == -1;
    }

    void insert(char element)
    {
        if (isFull())
        {
            cout << "Queue Overflow! Cannot insert." << endl;
            return;
        }
        if (front == -1)
            front = 0;
        rear = (rear + 1) % MAX;
        queue[rear] = element;
        cout << "Inserted: " << element << endl;
    }

    void remove()
    {
        if (isEmpty())
        {
            cout << "Queue Underflow! Cannot delete." << endl;
            return;
        }
        cout << "Deleted: " << queue[front] << endl;
        if (front == rear)
        {
            front = rear = -1;
        }
        else
        {
            front = (front + 1) % MAX;
        }
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Queue is Empty!" << endl;
            return;
        }
        cout << "Circular Queue: ";
        int i = front;
        while (true)
        {
            cout << queue[i] << " ";
            if (i == rear)
                break;
            i = (i + 1) % MAX;
        }
        cout << endl;
    }

    void checkStatus()
    {
        if (isFull())
        {
            cout << "\nQueue Overflow Condition:\n";
            display();
        }
        else if (isEmpty())
        {
            cout << "\nQueue Underflow Condition:\nQueue is empty, no elements to display.\n";
        }
        else
        {
            cout << "Queue is neither full nor empty." << endl;
            display();
        }
    }
};

int main()
{
    CircularQueue cq;
    int choice;
    char element;
    do
    {
        cout << "\n1. Insert\n2. Delete\n3. Display\n4. Check Queue Status(overflow/underflow)\n5. Exit\nEnter choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter character to insert: ";
            cin >> element;
            cq.insert(element);
            break;
        case 2:
            cq.remove();
            break;
        case 3:
            cq.display();
            break;
        case 4:
            cq.checkStatus();
            break;
        case 5:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice!" << endl;
        }
    } while (choice != 5);
    return 0;
}
