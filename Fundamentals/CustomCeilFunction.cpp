// Problem: Implement a custom version of ceil() from scratch.
// Compares the result against the standard library's ceil().

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
int My_Ceil(float number)
{
    if (number > (int)number)
        return (int)number + 1;
    else
        return (int)number;
}
int main()
{
    float number = Readnumber();
    cout << "My ceil is : " << My_Ceil(number) << endl;
    cout << "C++ ceil is : " << ceil(number) << endl;
}