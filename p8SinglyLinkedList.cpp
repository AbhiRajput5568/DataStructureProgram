// Design, Develop and Implement a menu driven Program for the following operations on Singly Linked List (SLL) of Student Data with the fields: USN, Name, Branch, Sem, PhNo a. Create a SLL of N Students Data by using front insertion. b. Display the status of SLL and count the number of nodes in it c. Perform Insertion / Deletion at End of SLL d. Perform Insertion / Deletion at Front of SLL(Demonstration of stack) e. Exit
#include <iostream>
using namespace std;

struct Student {
    string urn, name, branch, sem, phno;
    Student* next;
};

class StudentList {
private:
    Student* head;

public:
    StudentList() {
        head = nullptr;
    }

    // Insert at front
    void insertFront(string urn, string name, string branch, string sem, string phno) {
        Student* newNode = new Student{urn, name, branch, sem, phno, head};
        head = newNode;
        cout << "Student added at front.\n";
    }

    // Insert at end
    void insertEnd(string urn, string name, string branch, string sem, string phno) {
        Student* newNode = new Student{urn, name, branch, sem, phno, nullptr};
        if (!head) {
            head = newNode;
        } else {
            Student* temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
        cout << "Student added at end.\n";
    }

    // Delete from front
    void deleteFront() {
        if (!head) {
            cout << "List is empty. Cannot delete.\n";
            return;
        }
        Student* temp = head;
        head = head->next;
        delete temp;
        cout << "Deleted student from front.\n";
    }

    // Delete from end
    void deleteEnd() {
        if (!head) {
            cout << "List is empty. Cannot delete.\n";
            return;
        }
        if (!head->next) {
            delete head;
            head = nullptr;
        } else {
            Student* temp = head;
            while (temp->next->next) {
                temp = temp->next;
            }
            delete temp->next;
            temp->next = nullptr;
        }
        cout << "Deleted student from end.\n";
    }

    // Display the list
    void display() {
        if (!head) {
            cout << "List is empty.\n";
            return;
        }
        Student* temp = head;
        int count = 0;
        cout << "\nStudent List:\n";
        while (temp) {
            cout << "URN: " << temp->urn << ", Name: " << temp->name 
                 << ", Branch: " << temp->branch << ", Sem: " << temp->sem 
                 << ", Phone: " << temp->phno << "\n";
            temp = temp->next;
            count++;
        }
        cout << "Total students: " << count << "\n";
    }
};

int main() {
    cout<<"ABHISHEK SINGH 2315272/2435222";
    StudentList sll;
    int choice;
    string urn, name, branch, sem, phno;

    do {
        cout << "\n1. Insert at Front\n2. Insert at End\n3. Delete from Front\n4. Delete from End\n5. Display\n6. Exit\nEnter choice: ";
        cin >> choice;
        cin.ignore(); // Clear buffer before string input

        switch (choice) {
            case 1:
                cout << "Enter URN: "; getline(cin, urn);
                cout << "Enter Name: "; getline(cin, name);
                cout << "Enter Branch: "; getline(cin, branch);
                cout << "Enter Semester: "; getline(cin, sem);  // Now accepts "4th", "6th", etc.
                cout << "Enter Phone: "; getline(cin, phno);
                sll.insertFront(urn, name, branch, sem, phno);
                break;

            case 2:
                cout << "Enter URN: "; getline(cin, urn);
                cout << "Enter Name: "; getline(cin, name);
                cout << "Enter Branch: "; getline(cin, branch);
                cout << "Enter Semester: "; getline(cin, sem);
                cout << "Enter Phone: "; getline(cin, phno);
                sll.insertEnd(urn, name, branch, sem, phno);
                break;

            case 3:
                sll.deleteFront();
                break;

            case 4:
                sll.deleteEnd();
                break;

            case 5:
                sll.display();
                break;

            case 6:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 6);

    return 0;
}
