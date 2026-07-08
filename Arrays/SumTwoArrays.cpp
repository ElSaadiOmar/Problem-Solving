// Problem: Add two arrays element-by-element into a third result array.
// Assumes both arrays are the same length.

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
void SumOfArrays(int Array[100], int Array2[100], int SumArray[100], int Arrlength)
{
    for (int i = 0; i < Arrlength; i++)
    {
        SumArray[i] = (Array[i] + Array2[i]);
    }
}
int main()
{
    srand((unsigned)time(NULL));
    int Array[100], Array2[100], SumArray[100];
    int Arrlength = Readnumber("enter the length of array");
    FillArrayWithRandomNumbers(Array, Arrlength);
    FillArrayWithRandomNumbers(Array2, Arrlength);
    SumOfArrays(Array, Array2, SumArray, Arrlength);

    cout << "Array 1 elements: " << endl;
    printArray(Array, Arrlength);

    cout << "Array 1 elements: " << endl;
    printArray(Array2, Arrlength);
    
    cout << "Sum of array1 and array2 element: " << endl;
    printArray(SumArray, Arrlength);
    return 0;
}