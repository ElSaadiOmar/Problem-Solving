// Problem: Build a number from an array of digits, reverse it, and count a digit's frequency.
// Combines array input with the earlier digit-manipulation helpers.

#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;
int Readnumber(string Message)
{
    int number = 0;
    do
    {
        cout << Message << endl;
        cin >> number;
    } while (number <= 0);
    return number;
}
void FullTheAray(int number, short numberAray[])
{
    cout << "Enter array elements: " << endl;
    for (int i = 0; i < number; i++)
    {
        cout << "The element [" << i + 1 << "] : ";
        cin >> numberAray[i];
    }
}
int TheNumberOfArray(int number, short numberArray[])
{
    int newnumber = 0;
    for (int i = 0; i < number; i++)
    {
        newnumber = newnumber * 10 + numberArray[i];
    }
    return newnumber;
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
        cout << Remainder << " ";
    }
}
int CountDigitFrequency(int tallNumber, short loopNumber)
{
    int remainder = 0, frequencyNumber = 0;
    while (tallNumber > 0)
    {
        remainder = tallNumber % 10;
        tallNumber = tallNumber / 10;
        if (remainder == loopNumber)
            frequencyNumber++;
    }
    return frequencyNumber;
}
int main()
{
    int number = Readnumber("enter how many number you went");
    short numberAray[number];
    FullTheAray(number, numberAray);
    cout << endl;
    int checknumber = Readnumber("Enter the number you went to check : ");
    cout << "The Original array: ";
    PrintDigits(ReverseNumber(TheNumberOfArray(number, numberAray)));
    cout <<endl<< checknumber<< " Is frequency " 
    << CountDigitFrequency(TheNumberOfArray(number, numberAray), checknumber) 
    << " Times";
    return 0;
}