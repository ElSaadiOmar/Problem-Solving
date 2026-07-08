// Problem: Reverse the digits of a number (e.g. 123 -> 321).
// Builds the reversed number by shifting digits into a new value.

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
    int remainder = 0, newNumber = 0;
    while (number > 0)
    {
        remainder = number % 10;
        number = number / 10;
        newNumber = newNumber * 10 + remainder;
    }
    return newNumber;
}
int main()
{
    cout << endl
         << ReverseNumber(readnumber("enter number"));
}
/*
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
string SumOfDigits(int number)
{
    string arraynumber="";
    int Remainder = 0;
    while (number > 0)
    {
        Remainder = number % 10;
        number = number / 10;
        arraynumber+=to_string(Remainder);
    }
   return arraynumber;
}
int main()
{
    cout<<endl<<SumOfDigits(readnumber("enter number"));
}*/