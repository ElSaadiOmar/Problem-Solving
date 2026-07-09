// Problem: Calculate and print the sum of each column in a matrix.
// Mirrors the row-sum logic, iterating column-by-column instead.

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
            Arr[i][j] = RandomNumber(1, 100);
        }
    }
}
int SumCols(int Array[3][3], int Rows, int NumberCols)
{
    int Sum = 0;
    for (int i = 0; i < Rows; i++)
    {
        Sum += Array[i][NumberCols];
    }
    return Sum;
}
void PrintMatrix(int Arr[3][3], short Rows, short Cols)
{

    for (int i = 0; i < Rows; i++)
    {
        for (int j = 0; j < Cols; j++)
        {
            cout << setw(3) << Arr[i][j] << "\t";
        }
        cout << endl;
    }
}
void PrintSumMatrix(int Arr[3][3], short Rows, short Cols)
{
    for (int i = 0; i < Cols; i++)
    {
        cout << "Cols " << i + 1 << "Sum : " << SumCols(Arr, Rows, i) << endl;
    }
}
int main()
{

    srand((unsigned)time(NULL));
    int Arr[3][3];
    RandomMatrix(Arr, 3, 3);
    cout << "The Following is a 3x3 Random Matrix\n";
    PrintMatrix(Arr, 3, 3);

    cout << "The Following The sum Matrix\n";
    PrintSumMatrix(Arr, 3, 3);
    return 0;
}