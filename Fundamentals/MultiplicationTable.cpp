// Problem: Print the multiplication table from 1 to 10.
// Prints a formatted grid where each cell [i][j] = i * j.

#include <iostream>
#include <string>
#include <cmath>
using namespace std;
void printTableHeader()
{
    cout << "\n\t\t\t Multiplication Table From 1 To 10\n\n";
    for (int number = 1; number <= 10; number++)
    {
        cout << "\t" << number;
    }
    cout << "\n___________________________________________________________________________________"
         << endl;
}
string space(int number)
{
    if (number < 10)
        return "    |";
    else
        return "   |";
}
void printMultiplicationTable()
{
    printTableHeader();
    for (int i = 1; i <= 10; i++)
    {
        cout << " " << i << space(i);
        for (int j = 1; j <= 10; j++)
        {
            cout << i * j << "\t";
        }
        cout << endl;
    }
}
int main()
{
    printMultiplicationTable();
}