// Problem: Print each digit of a number, one per line.
// Extracts digits right-to-left using % 10 and / 10.

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
void SumOfDigits(int number)
{
    int remainder = 0;
    while (number > 0)
    {
        remainder = number % 10;
        number = number / 10;
        cout << remainder <<endl;
    }
}
int main()
{
    SumOfDigits(readnumber("enter number"));
}