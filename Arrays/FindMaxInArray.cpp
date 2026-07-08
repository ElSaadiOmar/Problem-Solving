// Problem: Find the maximum value inside an array.
// Scans all elements, keeping track of the largest value seen so far.

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
int MaxNumberInArray(int Array[100], int Arrlength)
{
    int greatNumber=0;
    for (int i = 0; i < Arrlength; i++)
    {
        if(greatNumber<Array[i])
        greatNumber=Array[i];
    }
    return greatNumber;
}
int main()
{
    srand((unsigned)time(NULL));
    int Array[100], Arrlength;
    FillArrayWithRandomNumbers(Array, Arrlength);
    cout << "Array elements: ";
    printArray(Array, Arrlength);
    cout<<"The great number is "<<MaxNumberInArray(Array, Arrlength);
}