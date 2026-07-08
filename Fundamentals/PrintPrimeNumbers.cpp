// Problem: Print all prime numbers from 1 up to a given number.
// Uses a helper enum-based CheckPrime() to test each number.

#include <iostream>
#include <string>
#include <cmath>
using namespace std;
enum enPrimNotPrim
{
    Prim = 1,
    NotPrim = 2,
};
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
enPrimNotPrim CheckPrime(int number)
{
    int M = round(number / 2);
    for (int i = 2; i <= M; i++)
    {
        if (number % i == 0)
            return enPrimNotPrim::NotPrim;
    }
    return enPrimNotPrim::Prim;
}
void printPrimNumber(int number)
{
    for (int i = 1; i <= number; i++)
    {
        if (CheckPrime(i) == enPrimNotPrim::Prim)
        {
            cout << i << endl;
        }
    }
}
int main()
{
    printPrimNumber(readnumber("enter the number"));
    return 0;
}