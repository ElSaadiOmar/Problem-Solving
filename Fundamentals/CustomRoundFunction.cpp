// Problem: Implement a custom version of round() from scratch.
// Compares the result against the standard library's round().

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
float GetFractionPart(float Number)
{
    return Number - int(Number);
}
int MyRound(float Number)
{
    int IntPart;
    IntPart = int(Number);
    float FractionsPart = GetFractionPart(Number);
    if (abs(FractionsPart) >= .5)
    {
        if (Number > 0)
            return ++IntPart;
        else
            return --IntPart;
    }
    else
    {
        return IntPart;
    }
}
int main()
{
    float Number = Readnumber();
    cout << "My Round Result : " << MyRound(Number) << endl;
    cout << "C++ Round Result: " << round(Number) << endl;
    return 0;
}
/*int My_Round(float number)
{
    if (number - (int)number >= 0.5)
        return (int)number + 1;
    else if (number - (int)number <= -0.5)
        return (int)number - 1;
    else
        return (int)number;
}
int main()
{
    float number = Readnumber();
    cout << "My round is : " << My_Round(number) << endl;
    cout << "C++ round is : " << round(number) << endl;
}*/