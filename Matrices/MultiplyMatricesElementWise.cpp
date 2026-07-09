// Problem: Multiply two matrices element-by-element into a result matrix.
// Not true matrix multiplication - each cell is Arr1[i][j] * Arr2[i][j].

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
            Arr[i][j] = RandomNumber(1, 9);
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
void FillMultMatrix(int Arr1[3][3], int Arr2[3][3],
                    int MultArr[3][3], short Rows, short Cols)
{
    for (int i = 0; i < Rows; i++)
    {
        for (int j = 0; j < Cols; j++)
        {
            MultArr[i][j] = Arr1[i][j] * Arr2[i][j];
        }
    }
}
int main()
{

    srand((unsigned)time(NULL));
    int Arr1[3][3], Arr2[3][3], MultArr[3][3];
    RandomMatrix(Arr1, 3, 3);
    RandomMatrix(Arr2, 3, 3);
    cout << "Random Matrix1\n";
    PrintMatrix(Arr1, 3, 3);
    cout << "Random Matrix2\n";
    PrintMatrix(Arr2, 3, 3);
    FillMultMatrix(Arr1, Arr2, MultArr, 3, 3);
    cout << "Mult Matrix\n";
    PrintMatrix(MultArr, 3, 3);
    return 0;
}