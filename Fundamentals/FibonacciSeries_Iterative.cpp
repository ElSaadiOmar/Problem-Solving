// Problem: Print the first N numbers of the Fibonacci series.
// Iterative solution using two running previous-value variables.

#include <iostream>
#include <ctime>
#include <cmath>
#include <string>
#include <iomanip>
#include <cstdlib>
using namespace std;
void printFibonacciSeries(int number)
{
    int FebNumber = 0;
    int Prev2 = 0, Prev1 = 1;
    cout << "1      ";
    for (int i = 0; i <= number - 2; i++)
    {
        FebNumber = Prev1 + Prev2;
        cout << FebNumber << "      ";
        Prev2=Prev1;
        Prev1=FebNumber;
    }
}
int main()
{
    printFibonacciSeries(10);
}
/*void printFibonacciSeries(int number)
{
    int number1 = 1;
    int number2 = 1;
    cout<<number1<<"      "<<number2;
    for (int i = 0; i < number - 2; i++)
    {
        number2 += number1 ;
        cout<<"       "<<number2;
        swap(number2, number1);
    }
}*/