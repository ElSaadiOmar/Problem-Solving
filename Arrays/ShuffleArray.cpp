// Problem: Randomly shuffle the elements of an array.
// Repeatedly swaps random pairs of elements to mix the array.

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
void swap(int &A, int &B)
{
    int temp;
    temp = A;
    A = B;
    B = temp;
}
void FillArrayWith1ToNumbers(int Array[100], int Arrlength)
{
    for (int i = 0; i < Arrlength; i++)
        Array[i] = i + 1;
}
void shuffleArray(int Array[100], int Arrlength)
{
    for (int i = 0; i < Arrlength; i++)
    {
        swap(Array[RandomNumber(1, Arrlength) - 1], Array[RandomNumber(1, Arrlength) - 1]);
    }
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

    int Array[100];
    int Arrlength = Readnumber("enter the length of array");

    FillArrayWith1ToNumbers(Array, Arrlength);

    cout << "Array 1 elements: " << endl;
    printArray(Array, Arrlength);
    shuffleArray(Array, Arrlength);
    cout << "The random array: " << endl;
    printArray(Array, Arrlength);
    return 0;
}