// Problem: Check whether a matrix is an identity matrix.
// Diagonal elements must be 1, and every other element must be 0.

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
bool TheMatrixIsIdentity(int Arr[3][3], int Rows, int Cols)
{
    for (int i = 0; i < Rows; i++)
    {
        for (int j = 0; j < Cols; j++)
        {
            if (i == j && Arr[i][j] != 1)
                return false;
            else if (i != j && Arr[i][j] != 0)
                return false;
        }
    }
    return true;
}
int main()
{

    srand((unsigned)time(NULL));
    int Arr[3][3] = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
    // RandomMatrix(Arr, 3, 3);
    cout << "Matrix:\n";
    PrintMatrix(Arr, 3, 3);
    if (TheMatrixIsIdentity(Arr, 3, 3))
        cout << "\nThe matrix is Identity" << endl;
    else
        cout << "\nThe matrix is NOT Identity" << endl;
    return 0;
}
