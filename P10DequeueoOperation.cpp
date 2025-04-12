#include <iostream>
#define MAX 5
using namespace std;

class Dequeue
{
private:
    int arr[MAX];
    int front, rear;

public:
    Dequeue()
    {
        front = -1;
        rear = -1;
    }

    // Check if Dequeue is full
    bool isFull()
    {
        return ((front == 0 && rear == MAX - 1) || (front == rear + 1));
    }

    // Check if Dequeue is empty
    bool isEmpty()
    {
        return (front == -1);
    }

    // Insert at front
    void insertFront(int item)
    {
        if (isFull())
        {
            cout << "Overflow! Cannot insert at front.\n";
            return;
        }
        if (isEmpty())
        {
            front = rear = 0;
        }
        else if (front == 0)
        {
            front = MAX - 1;
        }
        else
        {
            front--;
        }
        arr[front] = item;
    }

    // Insert at rear
    void insertRear(int item)
    {
        if (isFull())
        {
            cout << "Overflow! Cannot insert at rear.\n";
            return;
        }
        if (isEmpty())
        {
            front = rear = 0;
        }
        else if (rear == MAX - 1)
        {
            rear = 0;
        }
        else
        {
            rear++;
        }
        arr[rear] = item;
    }

    // Delete from front
    void deleteFront()
    {
        if (isEmpty())
        {
            cout << "Underflow! Cannot delete from front.\n";
            return;
        }
        cout << "Deleted element from front: " << arr[front] << "\n";
        if (front == rear)
        {
            front = rear = -1; // Queue becomes empty
        }
        else if (front == MAX - 1)
        {
            front = 0;
        }
        else
        {
            front++;
        }
    }

    // Delete from rear
    void deleteRear()
    {
        if (isEmpty())
        {
            cout << "Underflow! Cannot delete from rear.\n";
            return;
        }
        cout << "Deleted element from rear: " << arr[rear] << "\n";
        if (front == rear)
        {
            front = rear = -1;
        }
        else if (rear == 0)
        {
            rear = MAX - 1;
        }
        else
        {
            rear--;
        }
    }

    // Display the Dequeue
    void display()
    {
        if (isEmpty())
        {
            cout << "Dequeue is empty.\n";
            return;
        }
        cout << "Dequeue elements are: ";
        int i = front;
        while (true)
        {
            cout << arr[i] << " ";
            if (i == rear)
                break;
            i = (i + 1) % MAX;
        }
        cout << "\n";
    }

    // Show overflow/underflow status
    void checkStatus()
    {
        if (isFull())
            cout << "Queue is Full (Overflow)\n";
        else if (isEmpty())
            cout << "Queue is Empty (Underflow)\n";
        else
            cout << "Queue has space and elements.\n";
    }
};

int main()
{
    cout << "ABHISHEK SINGH 2315272/2435222" << endl;
    Dequeue dq;
    int choice, item;

    do
    {
        cout << "\n--- DEQUEUE Menu ---\n";
        cout << "1. Insert at Front\n";
        cout << "2. Insert at Rear\n";
        cout << "3. Delete from Front\n";
        cout << "4. Delete from Rear\n";
        cout << "5. Display Queue\n";
        cout << "6. Check Overflow/Underflow\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter the element to insert at front: ";
            cin >> item;
            dq.insertFront(item);
            break;
        case 2:
            cout << "Enter the element to insert at rear: ";
            cin >> item;
            dq.insertRear(item);
            break;
        case 3:
            dq.deleteFront();
            break;
        case 4:
            dq.deleteRear();
            break;
        case 5:
            dq.display();
            break;
        case 6:
            dq.checkStatus();
            break;
        case 7:
            cout << "Exiting program...\n";
            break;
        default:
            cout << "Invalid choice!\n";
        }
    } while (choice != 7);

    return 0;
}
