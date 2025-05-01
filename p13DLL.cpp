/*
13). Design, Develop and Implement a menu driven Program for the following operations on Doubly Linked List (DLL) of Employee Data with the fields: SSN, Name, Dept, Designation, Sal, PhNo
a. Insert new student at beginning of list.
b. Insert new student at end of list.
c. Insert new student in the middle of the list.
d. Display all records and count the number of nodes in it.
e. Delete first student from the list.
f. Delete last student from the list
g. Delete nth student the list.
h. Exit.
*/
#include <iostream>
#include <string>
using namespace std;

struct Employee
{
    int SSN;
    string name, dept, designation, phNo;
    double sal;
    Employee *prev, *next;
};

Employee *head = nullptr;

void inputEmployeeDetails(Employee *emp)
{
    cout << "Enter SSN: ";
    cin >> emp->SSN;
    cin.ignore();
    cout << "Enter Name: ";
    getline(cin, emp->name);
    cout << "Enter Department: ";
    getline(cin, emp->dept);
    cout << "Enter Designation: ";
    getline(cin, emp->designation);
    cout << "Enter Salary: ";
    cin >> emp->sal;
    cin.ignore();
    cout << "Enter Phone Number: ";
    getline(cin, emp->phNo);
}

void insertAtBeginning()
{
    Employee *newEmployee = new Employee;
    inputEmployeeDetails(newEmployee);
    newEmployee->prev = nullptr;
    newEmployee->next = head;

    if (head != nullptr)
        head->prev = newEmployee;

    head = newEmployee;
    cout << "Employee added at the beginning.\n";
}

void insertAtEnd()
{
    Employee *newEmployee = new Employee;
    inputEmployeeDetails(newEmployee);
    newEmployee->next = nullptr;

    if (!head)
    {
        newEmployee->prev = nullptr;
        head = newEmployee;
    }
    else
    {
        Employee *temp = head;
        while (temp->next)
            temp = temp->next;
        temp->next = newEmployee;
        newEmployee->prev = temp;
    }
    cout << "Employee added at the end.\n";
}

void insertAtMiddle()
{
    int position;
    cout << "Enter the position to insert the employee: ";
    cin >> position;
    if (position <= 0)
    {
        cout << "Invalid position.\n";
        return;
    }

    Employee *newEmployee = new Employee;
    inputEmployeeDetails(newEmployee);

    Employee *temp = head;
    for (int i = 1; temp != nullptr && i < position; i++)
        temp = temp->next;

    if (!temp)
    {
        cout << "Position out of bounds.\n";
        delete newEmployee;
        return;
    }

    newEmployee->prev = temp->prev;
    newEmployee->next = temp;
    if (temp->prev)
        temp->prev->next = newEmployee;
    temp->prev = newEmployee;
    if (position == 1)
        head = newEmployee;

    cout << "Employee inserted in the middle.\n";
}

void display()
{
    if (!head)
    {
        cout << "No employees to display.\n";
        return;
    }

    Employee *temp = head;
    int count = 0;
    cout << "\nEmployee Records:\n";
    while (temp)
    {
        cout << "SSN: " << temp->SSN << ", Name: " << temp->name << ", Dept: " << temp->dept
             << ", Designation: " << temp->designation << ", Salary: " << temp->sal
             << ", Phone No: " << temp->phNo << endl;
        temp = temp->next;
        count++;
    }
    cout << "Total Employees: " << count << endl;
}

void deleteEmployee(Employee *target)
{
    if (target == nullptr)
        return;
    if (target->prev)
        target->prev->next = target->next;
    if (target->next)
        target->next->prev = target->prev;
    if (target == head)
        head = target->next;
    delete target;
}

void deleteFirst()
{
    if (head)
        deleteEmployee(head);
    else
        cout << "No employee to delete.\n";
}
void deleteLast()
{
    if (!head)
        cout << "No employee to delete.\n";
    else
    {
        Employee *temp = head;
        while (temp->next)
            temp = temp->next;
        deleteEmployee(temp);
    }
}

void deleteNth()
{
    int position;
    cout << "Enter the position of the employee to delete: ";
    cin >> position;

    if (position <= 0)
    {
        cout << "Invalid position.\n";
        return;
    }

    Employee *temp = head;
    for (int i = 1; temp != nullptr && i < position; i++)
        temp = temp->next;

    if (!temp)
        cout << "Position out of bounds.\n";
    else
        deleteEmployee(temp);
}

int main()
{
    cout << "ABHISHEK SINGH 2315272/2435222";
    char choice;
    do
    {
        cout << "\n--- Employee Records Management Menu ---\n";
        cout << "a. Insert new employee at beginning of list.\n";
        cout << "b. Insert new employee at end of list.\n";
        cout << "c. Insert new employee in the middle of the list.\n";
        cout << "d. Display all employee records and count the number of nodes.\n";
        cout << "e. Delete first employee from the list.\n";
        cout << "f. Delete last employee from the list.\n";
        cout << "g. Delete nth employee from the list.\n";
        cout << "h. Exit.\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 'a':
            insertAtBeginning();
            break;
        case 'b':
            insertAtEnd();
            break;
        case 'c':
            insertAtMiddle();
            break;
        case 'd':
            display();
            break;
        case 'e':
            deleteFirst();
            break;
        case 'f':
            deleteLast();
            break;
        case 'g':
            deleteNth();
            break;
        case 'h':
            cout << "Exiting program.\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 'h');

    return 0;
}