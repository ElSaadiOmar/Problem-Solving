// Problem: Search for a number in an array and return its position.
// Classic linear search; returns -1 when the number isn't found.

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
    cout << "number your looking is : " << SearchNumber << endl;
    int numberPosition = SearchInArray(Array, Arrlength, SearchNumber);
    if (numberPosition == -1)
        cout << "The number is not find:-(" << endl;
    else
    {
        cout << "the number found at position: " << numberPosition << endl;
        cout << "the number found its order : " << numberPosition + 1 << endl;
    }
    return 0;
}