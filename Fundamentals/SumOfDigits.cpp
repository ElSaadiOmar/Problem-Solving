// Problem: Calculate the sum of all digits in a number.
// Same digit-extraction loop as above, but accumulates a running total.

#include <iostream>
#include <string>
#include <cmath>
using namespace std;
float readnumber(string Message)
{
    int number = 0;
    do
    {
        cout << Message << endl;
        cin >> number;
    } while (number <= 0);
    return number;
}
int ReverseNumber(int number)
{
    int Sum = 0, Remainder = 0;
    while (number > 0)
    {
        Remainder = number % 10;
        number = number / 10;
        Sum += Remainder;
    }
    return Sum;
}
int main()
{
    cout << "\nThe sum of digits = "
         << ReverseNumber(readnumber("enter number"));
}