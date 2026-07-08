// Problem: Reverse the order of elements in an array into a second array.
// Copies elements from the end of the source into the start of the result.

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
void ReverseArray(int Array[100], int Array2[100], int Arrlength)
{
    for (int i = 0; i < Arrlength; i++)
        Array2[i]=Array[Arrlength - 1 - i];
}
void printArray(int Array[100], int Arrlength)
{
    for (int i = 0; i < Arrlength; i++)
    {
        cout << Array[i] << " ";
    }
    cout << "\n\n";
}
int main()
{
    srand((unsigned)time(NULL));

    int Array[100], Array2[100];
    int Arrlength = Readnumber("enter the length of array");

    FillArrayWithRandomNumbers(Array, Arrlength);

    cout << "Array 1 elements: " << endl;
    printArray(Array, Arrlength);
    ReverseArray(Array, Array2, Arrlength);

    cout << "The 2 array after reverse 1 Array: " << endl;
    printArray(Array2, Arrlength);
    return 0;
}