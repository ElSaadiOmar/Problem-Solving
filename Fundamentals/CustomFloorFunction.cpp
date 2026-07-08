// Problem: Implement a custom version of floor() from scratch.
// Compares the result against the standard library's floor().

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
int My_Floor(float number)
{
    if (number == (int)number)
        return (int)number;
    else
    {
        if (number < 0)
            return (int)number - 1;
        else
            return (int)number;
    }
}
int main()
{
    float number = Readnumber();
    cout << "My floor is : " << My_Floor(number) << endl;
    cout << "C++ floor is : " << floor(number) << endl;
}