// Problem: Print the middle row and middle column of a matrix.
// Uses integer division to find the middle index for rows and columns.

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
void printMidleRow(int Arr[3][3], int Rows, int Cols)
{
    short MidleRow = Rows / 2;
    for (int i = 0; i < Cols; i++)
    {
        printf(" %0*d   ", 2, Arr[MidleRow][i]);
    }
    cout << endl;
}
void printMidleCols(int Arr[3][3], int Rows, int Cols)
{
    short MidleCols = Cols / 2;
    for (int i = 0; i < Cols; i++)
    {
        printf(" %0*d   ", 2, Arr[i][MidleCols]);
    }
    cout << endl;
}
int main()
{
    srand((unsigned)time(NULL));
    int Arr[3][3];
    RandomMatrix(Arr, 3, 3);
    cout << "The Following is a 3x3 Random Matrix\n";
    PrintMatrix(Arr, 3, 3);
    cout << "\nMidleRows is\n";
    printMidleRow(Arr,3,3);
    cout << "\nMidleCols is\n";
    printMidleCols(Arr,3,3);
    return 0;
}
