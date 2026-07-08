// Problem: Check whether a number exists anywhere in an array (true/false).
// Builds on the linear search function, converting its result to a bool.

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
short SearchInArray(int Array[100], int Arrlength, int SearchNumber)
{
    for (int i = 0; i < Arrlength; i++)
    {
        if (SearchNumber == Array[i])
            return i;
    }
    return -1;
}
bool FoundInArray(int Array[100],int Arrlength, int SearchNumber)
{
    return SearchInArray(Array, Arrlength, SearchNumber)!=-1;
}
int main()
{
    srand((unsigned)time(NULL));

    int Array[100];
    int Arrlength = Readnumber("enter the length of array");

    FillArrayWithRandomNumbers(Array, Arrlength);

    cout << "Array 1 elements: " << endl;
    printArray(Array, Arrlength);
    int SearchNumber = 0;
    SearchNumber = Readnumber("please enter a number to search in array");
    cout << "The number your are looking is : " << SearchNumber << endl;

    if (FoundInArray(Array, Arrlength, SearchNumber))
        cout << "Yes, the number is found:-(" << endl;
    else
    {
        cout << "No, the number is not found:-(" << endl;
    }
    return 0;
}