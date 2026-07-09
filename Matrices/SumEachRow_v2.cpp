// Problem: Calculate the sum of each row and store the results in an array.
// Refines the row-sum idea to fill a results array instead of printing directly.

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
int SumRows(int Array[3][3], int RowsNumber, int Cols)
{
    int Sum=0;
    for(int i=0;i<Cols;i++)
    {
        Sum+=Array[RowsNumber][i];
    }
   return Sum;
}
void SumRowsInArray(int Array[3][3], int ArrSum[3], int Rows,int Cols)
{
    for (int i = 0; i < Rows; i++)
    {
        ArrSum[i] = SumRows(Array,i,Cols);
    }
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
void PrintSumMatrix(int Arr[3], short Rows)
{

    for (int i = 0; i < Rows; i++)
    {
        cout << "Row " << i + 1 << "Sum = " << Arr[i] << endl;
    }
}
int main()
{

    srand((unsigned)time(NULL));
    int Arr[3][3];
    int SumArray[3];
    RandomMatrix(Arr, 3, 3);
    cout << "The Following is a 3x3 Random Matrix\n";
    PrintMatrix(Arr, 3, 3);

    cout << "The Following The sum Matrix\n";
    SumRowsInArray(Arr, SumArray, 3,3);
    PrintSumMatrix(SumArray, 3);
    return 0;
}