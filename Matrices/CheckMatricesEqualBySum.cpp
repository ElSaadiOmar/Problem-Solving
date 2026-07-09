// Problem: Check whether two matrices are 'equal' by comparing their total sums.
// Note: this checks equal sums, not that every element matches.

#include <iostream>
#include <ctime>
#include <string>
#include <iomanip>
#include <cstdlib>
using namespace std;
int RandomNumber(int From, int To)
{

    int randNum = rand() % (To - From + 1) + From;
    return randNum;
}
void RandomMatrix(int Arr[3][3], short Rows, short Cols)
{
    for (int i = 0; i < Rows; i++)
    {
        for (int j = 0; j < Cols; j++)
        {
            Arr[i][j] = RandomNumber(1, 99);
        }
    }
}
void PrintMatrix(int Arr[3][3], short Rows, short Cols)
{

    for (int i = 0; i < Rows; i++)
    {
        for (int j = 0; j < Cols; j++)
        {
            printf(" %0*d    ", 2, Arr[i][j]);
        }
        cout << endl;
    }
}
int SumNumberOfMatrix(int Matrix[3][3], int Rows, int Cols)
{
    int Result = 0;
    for (int i = 0; i < Rows; i++)
    {
        for (int j = 0; j < Cols; j++)
        {
            Result += Matrix[i][j];
        }
    }
    return Result;
}
void TheMatrixEqual(int Arr1[3][3], int Arr2[3][3])
{
    if (SumNumberOfMatrix(Arr1, 3, 3) == SumNumberOfMatrix(Arr2, 3, 3))
        cout << "\nYes, matrix are equal\n";
    else
        cout << "\nNo, matrix are NOT equal\n";
}
int main()
{

    srand((unsigned)time(NULL));
    int Arr1[3][3];
    int Arr2[3][3];
    RandomMatrix(Arr1, 3, 3);
    cout << "Matrix1:\n";
    PrintMatrix(Arr1, 3, 3);
    RandomMatrix(Arr2, 3, 3);
    cout << "\nMatrix2:\n";
    PrintMatrix(Arr2, 3, 3);
    TheMatrixEqual(Arr1,Arr2);
    return 0;
}
