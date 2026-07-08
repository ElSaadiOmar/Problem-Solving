// Problem: Print a triangle where row i repeats the number i, i times.
// Classic nested-loop pattern-printing exercise.

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
void printInvertedNumber(int number)
{
    for (int i = number; i > 0; i--)
    {
        for (int j = i; j > 0; j--)
        {
            cout << i;
        }
        cout << endl;
    }
}
int main()
{
    printInvertedNumber(ReadPositiveNumber("enter number"));
    return 0;
}