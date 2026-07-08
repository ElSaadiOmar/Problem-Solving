// Problem: Calculate the average value of the elements in an array.
// Reuses the sum function and divides by the array length.

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
float SumNumberInArray(int Array[100], int Arrlength)
{
    float SumNumber = 0;
    for (int i = 0; i < Arrlength; i++)
    {
        SumNumber += Array[i];
    }
    return SumNumber;
}
float AvrNumberInArray(int Array[100], int Arrlength)
{
    return (float)SumNumberInArray(Array,Arrlength)/Arrlength;
}
int main()
{
    srand((unsigned)time(NULL));
    int Array[100], Arrlength;
    FillArrayWithRandomNumbers(Array, Arrlength);
    cout << "Array elements: ";
    printArray(Array, Arrlength);
    cout << "The Avr number is " << AvrNumberInArray(Array, Arrlength);
}