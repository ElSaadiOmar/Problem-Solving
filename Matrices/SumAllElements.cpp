// Problem: Calculate the sum of every element in a matrix.
// Nested loop accumulating a single running total.

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
            printf(" %0*d    ",2,Arr[i][j]);
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
int main()
{

    srand((unsigned)time(NULL));
    int Arr[3][3];
    RandomMatrix(Arr, 3, 3);
    cout << "The Following is a 3x3 Random Matrix\n";
    PrintMatrix(Arr, 3, 3);
    cout << endl
         << SumNumberOfMatrix(Arr, 3, 3);
    return 0;
}
