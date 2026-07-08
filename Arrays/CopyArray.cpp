// Problem: Copy the contents of one array into another.
// Straightforward element-by-element copy loop.

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
void copyArray(int ArraySource[100],int arrDestination[100] ,int Arrlength)
{
    for (int i = 0; i < Arrlength; i++)
    {
       arrDestination[i]=ArraySource[i];
    }
}
int main()
{
    srand((unsigned)time(NULL));
    int Array[100], Arrlength;

    FillArrayWithRandomNumbers(Array, Arrlength);

    int Array2[100];
    copyArray(Array,Array2,Arrlength);

    cout << "First Array elements: ";
    printArray(Array, Arrlength);
    cout << "Second Array elements: ";
    printArray(Array2, Arrlength);
}