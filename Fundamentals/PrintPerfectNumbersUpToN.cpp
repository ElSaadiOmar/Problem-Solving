// Problem: Print every perfect number from 1 up to a given number.
// Reuses IsPerfectNumber() in a loop instead of checking a single value.

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
    for (int i = 1; i <= number; i++)
        if (IsPerfectNumber(i))
            cout << i << endl;
}
int main()
{
    int number = readnumber("Please enter number ");
    print_PerfectNumber(number);
    return 0;
}
