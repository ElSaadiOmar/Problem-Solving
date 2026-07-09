// Problem: Calculate and print the sum of each row in a matrix.
// First version: sums one row at a time via a helper function.

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
void PrintSumMatrix(int Arr[3][3], short Rows,short Cols)
{
    for (int i = 0; i < Rows; i++)
    {
        cout << "Row " << i + 1 << "Sum : " << SumRows(Arr,i,Cols)<< endl;
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
    PrintSumMatrix(Arr, 3,3);
    return 0;
}
/*#include <iostream>
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
void SumRows(int Array[3][3], int Arr[3], int Rows)
{
    for (int i = 0; i < Rows; i++)
    {
        Arr[i] = Array[i][0] + Array[i][1] + Array[i][2];
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
        cout << "Row " << i + 1 << "Sum : " << Arr[i] << endl;
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
    SumRows(Arr, SumArray, 3);
    PrintSumMatrix(SumArray, 3);
    return 0;
}*/