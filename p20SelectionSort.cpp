// Write a program to sort list using selection sort.
#include <iostream>
using namespace std;

void selectionSort(int arr[], int n)
{
    // One by one move the boundary of the unsorted subarray
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;

        // Find the minimum element in the remaining unsorted array
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }

        // Swap the found minimum element with the first element
        if (minIndex != i)
        {
            int temp = arr[minIndex];
            arr[minIndex] = arr[i];
            arr[i] = temp;
        }
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
    int arr[] = {29, 10, 14, 37, 13};
    int n = sizeof(arr) / sizeof(arr[0]);

    selectionSort(arr, n);
    printArray(arr, n);

    cout << "\nProgram by ABHISHEK SINGH" << endl;
    cout << "Roll No: 2315272/2435222" << endl;

    return 0;
}
