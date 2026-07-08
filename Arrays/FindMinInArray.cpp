// Problem: Find the minimum value inside an array.
// Same scanning approach as the max version, tracking the smallest value.

#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;
int RandomNumber(int From, int To)
{
    int RanNum = rand() % (To - From + 1) + From;
    return RanNum;
}
void FillArrayWithRandomNumbers(int Array[100], int &Arrlength)
{
    cout << "\nenter number of element: \n";
    cin >> Arrlength;
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
    cout << "\n";
}
int MinNumberInArray(int Array[100], int Arrlength)
{
    int MinNumber=0;
    MinNumber=Array[0];
    for (int i = 0; i < Arrlength; i++)
    {
        if(MinNumber>Array[i])
        MinNumber=Array[i];
    }
    return MinNumber;
}
int main()
{
    srand((unsigned)time(NULL));
    int Array[100], Arrlength;
    FillArrayWithRandomNumbers(Array, Arrlength);
    cout << "Array elements: ";
    printArray(Array, Arrlength);
    cout<<"The Min number is "<<MinNumberInArray(Array, Arrlength);
}