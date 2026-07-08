// Problem: Implement a custom version of abs() from scratch.
// Compares the result against the standard library's abs().

#include <iostream>
#include <cmath>
using namespace std;
float Readnumber()
{
    float number = 0;
    cout << "enter" << endl;
    cin >> number;
    return number;
}
float My_abc(float number)
{
    if (number < 0)
        return -1 * number;
    else
        return number;
}
int main()
{
    int number = Readnumber();
    cout << "My abc result : " << My_abc(number) << endl;
    cout << "The c++ abc result : " << abs(number) << endl;
}
