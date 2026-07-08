// Problem: Check whether a single given number is a perfect number.
// A perfect number equals the sum of its proper divisors (e.g. 28).

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
bool IsPerfectNumber(int number)
{
    int sum = 0;
    for (int i = 1; i < number; i++)
    {
        if (number % i == 0)
            sum += i;
    }
    return sum == number;
}
void print_PerfectNumber(int number)
{
    if (IsPerfectNumber(number))
        cout << number << " is perfect number" << endl;
    else
        cout << number << " is perfect number" << endl;
}
int main()
{
    int number = readnumber("Please enter number ");
    print_PerfectNumber(number);
    return 0;
}
