// Problem: Print the first N numbers of the Fibonacci series using recursion.
// Same series as the iterative version, solved with a recursive function instead.

#include <iostream>
#include <ctime>
#include <cmath>
#include <string>
#include <iomanip>
#include <cstdlib>
using namespace std;
void printFibonacciSeries(short number, int Prev1, int Prev2)
{
    if (number > 0)
    {

        int FebNumber = Prev1 + Prev2;
        Prev2 = Prev1;
        Prev1 = FebNumber;
        cout << FebNumber << "      ";
        printFibonacciSeries(number - 1, Prev1, Prev2);
    }
}
int main()
{
    printFibonacciSeries(10, 0, 1);
}