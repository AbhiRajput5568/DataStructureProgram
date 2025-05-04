// 21.Write a program to sort list using insertion sort.
#include <iostream>
using namespace std;

void insertionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i]; // Current element to be inserted
        int j = i - 1;

        // Move elements greater than key to one position ahead
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key; // Insert the key at correct position
    }
}

void printArray(int arr[], int n)
{
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    int arr[] = {20, 5, 40, 60, 10, 30};
    int n = sizeof(arr) / sizeof(arr[0]);

    insertionSort(arr, n);
    printArray(arr, n);

    cout << "\nProgram by ABHISHEK SINGH" << endl;
    cout << "Roll No: 2315272/2435222" << endl;

    return 0;
}
