// Problem: Implement a custom version of sqrt() from scratch.
// Uses pow(number, 0.5) and compares it against the standard sqrt().

#include <iostream>
#include <cmath>
#include <string>
using namespace std;
float Readnumber()
{
    float number = 0;
    cout << "enter number you went round it" << endl;
    cin >> number;
    return number;
}
float My_Sqrt(float number)
{
    return pow(number,0.5);
}
int main()
{
    float number = Readnumber();
    cout << "My ceil is : " << My_Sqrt(number) << endl;
    cout << "C++ ceil is : " << sqrt(number) << endl;
}