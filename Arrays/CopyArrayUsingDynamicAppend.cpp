// Problem: Copy a randomly filled array into a second array.
// Uses an AddArrayElement() helper to append values one at a time.

#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;
int ReadNumber(string Message)
{
    int Number = 0;
    cout << Message << endl;
    cin >> Number;
    return Number;
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
}
void AddArrayElement(int Number, int arr[100], int &arrLength)
{
    arrLength++;
    arr[arrLength - 1] = Number;
}
void FillArray2(int Arr1[100], int Arr2[100], int Arrlength, int &Arrlength2)
{
    for (int i = 0; i < Arrlength; i++)
        AddArrayElement(Arr1[i], Arr2, Arrlength2);
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

    int arr[100], Arr2[100], arrLength = 0, arrLength2 = 0;
    arrLength = ReadNumber("enter the length");

    FillArrayWithRandomNumbers(arr, arrLength);

    cout << "\nArray 1 element : " << endl;
    PrintArray(arr, arrLength);

    FillArray2(arr, Arr2, arrLength, arrLength2);

    cout << "\nArray 2 elements: " << endl;
    PrintArray(Arr2, arrLength2);
    return 0;
}