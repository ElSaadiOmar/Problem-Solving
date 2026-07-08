// Problem: Print a descending (inverted) triangle made of letters.
// Converts loop counters to characters using ASCII arithmetic.

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
    cout<<endl;
    for (int i = 64 + number; i > 64 ; i--)
    {
        for (int j = i-64; j > 0; j--)
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