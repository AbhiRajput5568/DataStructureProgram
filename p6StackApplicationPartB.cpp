// Design, Develop and Implement a Program for the following Stack Applications b. Solving Tower of Hanoi problem with n disks 
#include <iostream>
using namespace std;

// Function to solve Tower of Hanoi problem
void towerOfHanoi(int n, char source, char auxiliary, char target) {
    if (n == 1) {
        cout << "Move disk 1 from " << source << " to " << target << endl;
        return;
    }
    // Move n-1 disks from source to auxiliary
    towerOfHanoi(n - 1, source, target, auxiliary);
    
    // Move the nth disk from source to target
    cout << "Move disk " << n << " from " << source << " to " << target << endl;
    
    // Move n-1 disks from auxiliary to target
    towerOfHanoi(n - 1, auxiliary, source, target);
}

int main() {
    cout<<"ABHISHEK SINGH 2315272/2435222"<<endl;
    int n;
    
    cout << "Enter the number of disks: ";
    cin >> n;

    cout << "The sequence of moves are:" << endl;
    towerOfHanoi(n, 'A', 'B', 'C');  // A, B, and C are the source, auxiliary, and target poles

    return 0;
}
