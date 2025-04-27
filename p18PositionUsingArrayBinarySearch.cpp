/*Write a Program to find the position of an element in an array using Binary search Algorithm*/
#include <iostream>
using namespace std;

int binarySearch(int arr[], int size, int target)
{
    int left = 0;
    int right = size - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        // If the target is present at mid
        if (arr[mid] == target)
            return mid; // Return the index of the element

        // If target is greater, ignore the left half
        if (arr[mid] < target)
            left = mid + 1;

        // If target is smaller, ignore the right half
        else
            right = mid - 1;
    }

    return -1; // Return -1 if the element is not found
}

int main()
{
    cout << "ABHISHEK SINGH 2315272/2435222";
    int arr[] = {2, 5, 8, 12, 15, 18, 23, 35, 42, 56}; // Example sorted array
    int size = sizeof(arr) / sizeof(arr[0]);           // Calculate the size of the array
    int target;

    cout << "Enter the element to search for: ";
    cin >> target;

    int result = binarySearch(arr, size, target);

    if (result != -1)
    {
        cout << "Element found at index: " << result << endl;
    }
    else
    {
        cout << "Element not found in the array!" << endl;
    }

    return 0;
}
