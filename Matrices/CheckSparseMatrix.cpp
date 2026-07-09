// Problem: Check whether a matrix is a sparse matrix (mostly zeros).
// Counts zero-value cells and compares against half the matrix size.

#include <iostream>
#include <ctime>
#include <cmath>
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
short CountNumberInMatrix(int Matrix1[3][3], int Number, short Rows, short Cols)
{
    short NumberCount = 0;
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            if (Matrix1[i][j] == Number)
            {
                NumberCount++;
            };
        }
    }
    return NumberCount;
}
bool IsSparceMatrix(int Arr[3][3], int Rows, int Cols)
{
    short MatrixSize = Rows * Cols;
    return CountNumberInMatrix(Arr, 0, 3, 3) >= ceil((float)(MatrixSize / 2));
}
/*bool IsSparceMatrix(int Arr[3][3], int Rows, int Cols)
{
    short NumberOfZero = 0, NumberOfAnotherNum = 0;
    for (int i = 0; i < Rows; i++)
    {
        for (int j = 0; j < Cols; j++)
        {
            if (Arr[i][j] == 0)
                NumberOfZero++;
            else
                NumberOfAnotherNum++;
        }
    }
    return NumberOfZero > NumberOfAnotherNum;
}*/
int main()
{

    srand((unsigned)time(NULL));
    int Arr[3][3];
    RandomMatrix(Arr, 3, 3);
    cout << "Matrix:\n";
    PrintMatrix(Arr, 3, 3);
    if (IsSparceMatrix(Arr, 3, 3))
        cout << "Is a Sparce Matrix\n";
    else
        cout << "Is NOT a Sparce Matrix\n";
    return 0;
}
