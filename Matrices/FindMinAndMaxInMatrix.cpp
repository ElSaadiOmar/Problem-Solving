// Problem: Find both the minimum and maximum values in a matrix.
// Two independent scans, each tracking the best value seen so far.

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
int MaxNumberInMatrix(int Arr[3][3], short Rows, short Cols)
{
    int MaxNumber = Arr[0][0];
    for (int i = 0; i < Rows; i++)
    {
        for (int j = 0; j < Cols; j++)
        {

            if (Arr[i][j] > MaxNumber)
                MaxNumber = Arr[i][j];
        }
    }
    return MaxNumber;
}
int MinNumberInMatrix(int Arr[3][3], short Rows, short Cols)
{
    int MinNumber = Arr[0][0];
    for (int i = 0; i < Rows; i++)
    {
        for (int j = 0; j < Cols; j++)
        {

            if (Arr[i][j] < MinNumber)
                MinNumber = Arr[i][j];
        }
    }
    return MinNumber;
}
int main()
{

    srand((unsigned)time(NULL));
    int Arr[3][3];
    int Number = 0;
    RandomMatrix(Arr, 3, 3);
    cout << "Matrix:\n";
    PrintMatrix(Arr, 3, 3);
    cout << "\nThe max number is : " << MaxNumberInMatrix(Arr, 3, 3);
    cout << "\n\nThe mix number is : " << MinNumberInMatrix(Arr, 3, 3);
    return 0;
}