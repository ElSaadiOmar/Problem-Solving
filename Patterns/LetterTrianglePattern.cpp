// Problem: Print an ascending triangle made of letters (A, AB, ABC...).
// Same idea as the inverted version but growing top to bottom.

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
    cout << endl;
    for (int i = 65; i <= 64 + number; i++)
    {
        for (int j = 1; j <= i - 64 ; j++)//number+(i-64-number)
        {
            cout << (char)i;
        }
        cout << endl;
    }
}
int main()
{
    printInvertedNumber(ReadPositiveNumber("enter number"));
    return 0;
}