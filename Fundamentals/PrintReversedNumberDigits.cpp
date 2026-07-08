// Problem: Reverse a number, then print its digits one by one.
// Combines ReverseNumber() and a digit-printing loop.

#include <iostream>
#include <string>
using namespace std;
int ReadPositiveNumber(string Message)
{
    int Number = 0;
    do
    {
        cout << Message << endl;
        cin >> Number;
    } while (Number <= 0);
    return Number;
}
int ReverseNumber(int Number)
{
    int Remainder = 0, Number2 = 0;
    while (Number > 0)
    {
        Remainder = Number % 10;
        Number = Number / 10;
        Number2 = Number2 * 10 + Remainder;
    }
    return Number2;
}
void PrintDigits(int Number)
{
    int Remainder = 0;
    while (Number > 0)
    {
        Remainder = Number % 10;
        Number = Number / 10;
        cout << Remainder <<" ";
    }
}
int main()
{
PrintDigits(ReverseNumber(ReadPositiveNumber("please enter number?")));
return 0;
}

/*#include <iostream>
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
/*int ReverseNumber(int number)
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
void truenumber(int number)
{
    int remainder = 0, newNumber = 0;
    while (number > 0)
    {
        remainder = number % 10;
        number = number / 10;
        newNumber = newNumber * 10 + remainder;
    }
    while (newNumber > 0)
    {
        remainder = newNumber % 10;
        newNumber = newNumber / 10;
        cout << remainder <<endl;
    }
}
void printnumber(int number)
{
    int newnumber=ReverseNumber(number);
    int remainder = 0;
    while (newnumber > 0)
    {
        remainder = newnumber % 10;
        newnumber = newnumber / 10;
        cout << remainder <<endl;
    }
}
int main()
{
   truenumber(readnumber("enter number"));
}*/