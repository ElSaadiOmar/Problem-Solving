// Problem: Count how many even numbers are in an array.
// Reuses the same IsOdd() helper, counting the opposite case.

#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;
int Readnumber(string Message)
{
    int number = 0;
    do
    {
        cout << Message << endl;
        cin >> number;
    } while (number <= 0);
    return number;
}
int RandomNumber(int From, int To)
{
    int RanNum = rand() % (To - From + 1) + From;

    return RanNum;
}
void FillArrayWithRandomNumbers(int Array[100], int Arrlength)
{
    for (int i = 0; i < Arrlength; i++)
    {
        Array[i] = RandomNumber(1, 100);
    }
    cout << endl;
}
void printArray(int Array[100], int Arrlength)
{
    for (int i = 0; i < Arrlength; i++)
    {
        cout << Array[i] << " ";
    }
    cout << "\n\n";
}
bool IsOdd(int number)
{
    return number % 2 != 0;
}
int CounterEven(int Array[100], int Arrlength)
{
    int counter = 0;
    for (int i = 0; i < Arrlength; i++)
    {
        if (!IsOdd(Array[i]))
            counter++;
    }
    return counter;
}
int main()
{
    srand((unsigned)time(NULL));

    int Array[100];
    int Arrlength = Readnumber("enter the length of array");

    FillArrayWithRandomNumbers(Array, Arrlength);

    cout << "Array elements: " << endl;
    printArray(Array, Arrlength);

    cout << "Even numbers count is : " << CounterEven(Array, Arrlength);

    return 0;
}