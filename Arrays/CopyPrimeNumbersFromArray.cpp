// Problem: Copy only the prime numbers from one array into a new array.
// Filters each element using the CheckPrime() helper before copying.

#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;
enum enPrimNotPrim
{
    Prim = 1,
    NotPrim = 2,
};
enPrimNotPrim CheckPrime(int number)
{
    int M = round(number / 2);
    for (int i = 2; i <= M; i++)
    {
        if (number % i == 0)
            return enPrimNotPrim::NotPrim;
    }
    return enPrimNotPrim::Prim;
}
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
void copyArray(int ArraySource[100], int arrDestination[100], int Arrlength, int &Arr2length)
{
    int counter = 0;
    for (int i = 0; i < Arrlength; i++)
    {
        if (CheckPrime(ArraySource[i]) == enPrimNotPrim::Prim)
        {
            arrDestination[counter] = ArraySource[i];
            counter++;
        }
    }
    Arr2length = --counter;
}
int main()
{
    srand((unsigned)time(NULL));
    int Array[100], Arrlength;

    FillArrayWithRandomNumbers(Array, Arrlength);

    int Array2[100], Arr2length = 0;
    copyArray(Array, Array2, Arrlength, Arr2length);

    cout << "Array 1 elements: ";
    printArray(Array, Arrlength);
    cout << "Prime number in Array 2 : ";
    printArray(Array2, Arr2length);
}