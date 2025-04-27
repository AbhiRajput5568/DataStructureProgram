/*
14).Implement a Program to find the sum of two polynomials POLY1(x,y,z) and POLY2(x,y,z) and store the result in POLYSUM(x,y,z)
*/
#include <iostream>
using namespace std;

// Define the Polynomial structure
struct Polynomial
{
    int coeff[8]; // Array to hold the coefficients for x, y, z, xy, xz, yz, xyz
};

// Function to input polynomial coefficients
void inputPolynomial(Polynomial &poly)
{
    cout << "Enter the coefficients for the polynomial:\n";
    cout << "a0 (constant term): ";
    cin >> poly.coeff[0];
    cout << "a1 (x): ";
    cin >> poly.coeff[1];
    cout << "a2 (y): ";
    cin >> poly.coeff[2];
    cout << "a3 (z): ";
    cin >> poly.coeff[3];
    cout << "a4 (xy): ";
    cin >> poly.coeff[4];
    cout << "a5 (xz): ";
    cin >> poly.coeff[5];
    cout << "a6 (yz): ";
    cin >> poly.coeff[6];
    cout << "a7 (xyz): ";
    cin >> poly.coeff[7];
}

// Function to add two polynomials and store the result in POLYSUM
void addPolynomials(Polynomial &poly1, Polynomial &poly2, Polynomial &polySum)
{
    for (int i = 0; i < 8; i++)
    {
        polySum.coeff[i] = poly1.coeff[i] + poly2.coeff[i];
    }
}

// Function to display the polynomial
void displayPolynomial(const Polynomial &poly)
{
    cout << "Polynomial: ";
    cout << poly.coeff[0] << " + "
         << poly.coeff[1] << "x + "
         << poly.coeff[2] << "y + "
         << poly.coeff[3] << "z + "
         << poly.coeff[4] << "xy + "
         << poly.coeff[5] << "xz + "
         << poly.coeff[6] << "yz + "
         << poly.coeff[7] << "xyz\n";
}

int main()
{
    cout << "ABHISHEK SINGH 2315272/2435222";
    Polynomial poly1, poly2, polySum;

    // Input polynomials
    cout << "Enter the first polynomial:\n";
    inputPolynomial(poly1);

    cout << "Enter the second polynomial:\n";
    inputPolynomial(poly2);

    // Add the polynomials
    addPolynomials(poly1, poly2, polySum);

    // Display the sum of polynomials
    cout << "\nThe sum of the two polynomials is:\n";
    displayPolynomial(polySum);

    return 0;
}
