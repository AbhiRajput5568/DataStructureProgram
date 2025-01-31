#include <iostream>
using namespace std;

void createArray(int arr[], int &n) {
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
}

void displayArray(int arr[], int n) {
    cout << "Array Elements: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void insertElement(int arr[], int &n, int elem, int pos) {
    if (pos < 1 || pos > n + 1) {
        cout << "Invalid position!" << endl;
        return;
    }
    for (int i = n; i >= pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos - 1] = elem;
    n++;
    cout << "Element inserted successfully." << endl;
}

void deleteElement(int arr[], int &n, int pos) {
    if (pos < 1 || pos > n) {
        cout << "Invalid position!" << endl;
        return;
    }
    for (int i = pos - 1; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    n--;
    cout << "Element deleted successfully." << endl;
}

int main() {
    cout<<"2315272/2435222 ABHISHEK SINGH";
    const int MAX_SIZE = 100;
    int arr[MAX_SIZE];
    int n = 0;
    int choice;

    do {
        cout << "\nMenu:" << endl;
        cout << "1. Create Array" << endl;
        cout << "2. Display Array" << endl;
        cout << "3. Insert Element" << endl;
        cout << "4. Delete Element" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                createArray(arr, n);
                break;
            case 2:
                displayArray(arr, n);
                break;
            case 3: {
                int elem, pos;
                cout << "Enter the element to insert: ";
                cin >> elem;
                cout << "Enter the position: ";
                cin >> pos;
                insertElement(arr, n, elem, pos);
                break;
            }
            case 4: {
                int pos;
                cout << "Enter the position to delete: ";
                cin >> pos;
                deleteElement(arr, n, pos);
                break;
            }
            case 5:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}
