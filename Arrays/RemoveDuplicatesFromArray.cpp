// Problem: Remove duplicate values from an array, keeping only distinct numbers.
// Checks each number against what's already been copied before appending.

#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;
void FillArray(int Array[100], int &Arrlength)
{
    Arrlength = 10;
    Array[0] = 10;
    Array[1] = 10;
    Array[2] = 10;
    Array[3] = 50;
    Array[4] = 50;
    Array[5] = 70;
    Array[6] = 70;
    Array[7] = 70;
    Array[8] = 70;
    Array[9] = 90;
}
void AddArrayElement(int Number, int arr[100], int &arrLength)
{
    arrLength++;
    arr[arrLength - 1] = Number;
}
bool CheckNumberInArray(int number, int array[100], int Arrlength)
{
    for (int i = 0; i < Arrlength; i++)
    {
        if (number == array[i])
            return true;
    }
    return false;
}
void CopyNumber(int Arr1[100], int Arr2[100], int Arrlength, int &Arrlength2)
{
    for (int i = 0; i < Arrlength; i++)
    {
        if (!CheckNumberInArray(Arr1[i], Arr2, Arrlength2))
            AddArrayElement(Arr1[i], Arr2, Arrlength2);
    }
}
void PrintArray(int arr[100], int arrLength)
{
    for (int i = 0; i < arrLength; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
}
int main()
{
    srand((unsigned)time(NULL));

    int arr[100], Arr2[100], arrLength = 10, arrLength2 = 0;

    FillArray(arr, arrLength);

    cout << "\nArray 1 element : " << endl;
    PrintArray(arr, arrLength);

    CopyNumber(arr, Arr2, arrLength, arrLength2);

    cout << "\nArray 2 distinct elements: " << endl;
    PrintArray(Arr2, arrLength2);
    return 0;
}