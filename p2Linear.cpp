#include <iostream>
using namespace std;

void linearSearch(int arr[], int n, int key)
{
    bool found = false;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == key)
        {
            cout << "Element " << key << " found at position " << i + 1 << "." << endl;
            found = true;
            break;
        }
    }
    if (!found)
    {
        cout << "Element " << key << " not found in the array." << endl;
    }
}

int main()
{
    cout << "2315272/2435222 ABHISHEK SINGH";

    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    int arr[n];
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int key;
    cout << "Enter the element to search for: ";
    cin >> key;

    linearSearch(arr, n, key);

    return 0;
}
