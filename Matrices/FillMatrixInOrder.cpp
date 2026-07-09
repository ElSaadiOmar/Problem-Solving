// Problem: Fill a matrix with sequential numbers (1, 2, 3, ...) and print it.
// Simple counter-based fill, used as a base for the transpose exercise.

#include <iostream>
#include <iomanip>
using namespace std;
void FillMatrixByOrderNumber(int Arr[3][3], short Rows, short Cols)
{
    int Counter = 1;
    for (int i = 0; i < Rows; i++)
    {
        for (int j = 0; j < Cols; j++)
        {
            Arr[i][j] = Counter;
            Counter++;
        }
    }
}
void PrintMatrix(int Arr[3][3], short Rows, short Cols)
{

    for (int i = 0; i < Rows; i++)
    {
        for (int j = 0; j < Cols; j++)
        {
            cout << Arr[i][j] << setw(3) << "\t";
        }
        cout << endl;
    }
}
int main()
{
    int Arr[3][3];
    FillMatrixByOrderNumber(Arr, 3, 3);
    cout << "The following is 3x3 order matrix \n";
    PrintMatrix(Arr, 3, 3);
}