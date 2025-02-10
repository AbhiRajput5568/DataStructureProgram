#include <iostream>
using namespace std;

int main() {
    int a[2][2], b[2][2], sum[2][2];

    // Input first matrix
    cout << "Enter elements of first 2x2 matrix:\n";
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            cin >> a[i][j];

    // Input second matrix
    cout << "Enter elements of second 2x2 matrix:\n";
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            cin >> b[i][j];

    // Add matrices
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            sum[i][j] = a[i][j] + b[i][j];

    // Display result
    cout << "Sum of matrices:\n";
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++)
            cout << sum[i][j] << " ";
        cout << endl;
    }

    return 0;
}
