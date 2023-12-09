/*Implement a class Complex which represents the Complex Number data type. Implement the following 1. Constructor (including a default constructor which creates the complex number 0+0i). 2. Overload operator+ to add two complex numbers. 3. Overload operator* to multiply two complex numbers. 4. Overload operators << and >> to print and read Complex Numbers.*/

#include <iostream>
#include <string>
using namespace std;

class Complex
{

public:
    int real, imag;
    Complex();
    void input();
    void display();
};

Complex ::Complex()
{
    real = 0;
    imag = 0;
}

void Complex ::input()
{
    cout << "Enter Real part of the complex number : ";
    cin >> real;
    cout << "Enter Imaginary part of the complex number : ";
    cin >> imag;
}

void Complex ::display()
{
    cout << "Complex Number = " << real << " + " << imag << "i" << endl;
}

void operator+(Complex c1, Complex c2)
{
    Complex sum;
    sum.real = c1.real + c2.real;
    sum.imag = c1.imag + c2.imag;
    cout << "Sum = " << sum.real << " + " << sum.imag << "i" << endl;
}

void operator*(Complex c1, Complex c2)
{
    Complex multilicaion;
    multilicaion.real = (c1.real * c2.real) - (c1.imag * c2.imag);
    multilicaion.imag = (c1.real * c2.imag) + (c1.imag * c2.real);
    cout << "Multiplication = " << multilicaion.real << " + " << multilicaion.imag << "i" << endl;
}

void operator<<(ostream &cout, Complex c)
{
    cout << c.real << " + " << c.imag << "i" << endl;
}

void operator>>(istream &cin, Complex &c)
{
    cout << "Enter Real part of the complex number : ";
    cin >> c.real;

    cout << "Enter imag part of the complex number : ";
    cin >> c.imag;
}

int main()
{
    Complex c1, c2, c3, c4;
    cout << endl
         << "Inputting" << endl;
    c1.input();
    c2.input();
    cin >> c3;
    cin >> c4;
    cout << endl
         << "Displaying" << endl;
    cout << c1;
    cout << c2;
    cout << c3;
    cout << c4;
    cout << endl
         << "Operations" << endl;
    c1 + c2;
    c3 *c4;
    return 0;
}
