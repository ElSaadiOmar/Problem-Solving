// Problem: Check whether an array reads the same forwards and backwards.
// Compares elements from both ends moving toward the middle.

#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;
void FillArray(int Array[100], int &Arrlength)
{
    Arrlength = 6;
    Array[0] = 10;
    Array[1] = 20;
    Array[2] = 30;
    Array[3] = 30;
    Array[4] = 20;
    Array[5] = 10;
}
bool IsPalindromeArray(int Array[100], int Arrlength)
{
    for (int i = 0; i < Arrlength; i++)
    {
        if(Array[i]!=Array[Arrlength - i -1])
        return false;
    }
    return true;
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
    int arr[100], arrLength = 0;

    FillArray(arr, arrLength);

    cout << "\nArray  elements : " << endl;
    PrintArray(arr, arrLength);
    if(IsPalindromeArray(arr,arrLength))
    cout<<"yes, this array is a palindrome Array\n";
    else
    cout<<"No, this array is not a palindrome Array\n";
    return 0;
}