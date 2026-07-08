// Problem: Check whether a number is a palindrome (reads the same reversed).
// Reverses the number and compares it to the original.

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
bool IsPalindromeNumber(int number)
{
    return ReverseNumber(number) == number;
}
int main()
{
    if (IsPalindromeNumber(ReadPositiveNumber(
            "please enter the number")))
    cout << "thes number is Palindrome number\n";
    else 
    cout << "thes number is not Palindrome number\n";
}
