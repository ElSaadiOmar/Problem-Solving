// Problem: Print a number triangle with zero-padded digits per row.
// Uses printf("%0*d", ...) so every row has aligned digit widths.

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
short LengthOfNumber(int Number)
{
    short Count = 0;
    if (Number == 0)
        return 1;
    while (Number > 0)
    {
        Number /= 10;
        Count++;
    }
    return Count;
}
void printInvertedNumber(int number)
{
    for (int i = 1; i <= number; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            printf("%0*d", LengthOfNumber(number), i);
        }
        cout << endl;
    }
}
int main()
{
     printInvertedNumber(ReadPositiveNumber("enter number"));
    return 0;
}