// Problem: Check whether two matrices are identical (every element matches).
// Compares each pair of elements at the same position.

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
bool TheMatrixIsTypical(int Arr1[3][3], int Arr2[3][3], int Rows, int Cols)
{
    for (int i = 0; i < Rows; i++)
    {
        for (int j = 0; j < Cols; j++)
        {
            if (Arr1[i][j] != Arr2[i][j])
                return false;
        }
    }
    return true;
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
    if (TheMatrixIsTypical(Arr1, Arr2, 3, 3))
        cout << "\nThe matrix is typical" << endl;
    else
        cout << "\nThe matrix is NOT typical" << endl;
    return 0;
}
