// Problem: Find and print the numbers that appear in both of two matrices.
// For each element of Matrix1, checks whether it also exists in Matrix2.

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
bool IsInMatrix(int Arr[3][3], int Number, int Rows, int Cols)
{
    for (int i = 0; i < Rows; i++)
    {
        for (int j = 0; j < Cols; j++)
        {
            if (Arr[i][j] == Number)
                return true;
        }
    }
    return false;
}
void NumberInTowMatrix(int Matrix1[3][3], int Matrix2[3][3], int Rows, int Cols)
{
    int number = 0;
    for (int i = 0; i < Rows; i++)
    {
        for (int j = 0; j < Cols; j++)
        {
            number = Matrix1[i][j];
            if (IsInMatrix(Matrix2, number, Rows, Cols))
            {
                cout << setw(3) << number << "     ";
            }
        }
    }
}
/*void NumberInTowMatrix(int Matrix1[3][3], int Matrix2[3][3], vector<int> &number, int Rows, int Cols)
{
    for (int i = 0; i < Rows; i++)
    {
        for (int j = 0; j < Cols; j++)
        {
            for (int i2 = 0; i2 < Rows;i2++)
            {
                for (int j2 = 0; j2 < Cols; j2++)
                {
                    if (IsInMatrix(Matrix2, Rows, Cols, Matrix1[i][j]))
                    {

                        number.push_back(Matrix1[i][j]);
                    }
                }
            }
        }
    }
}*/
int main()
{

    srand((unsigned)time(NULL));
    int Arr1[3][3], Arr2[3][3];
    RandomMatrix(Arr1, 3, 3);
    cout << "Matrix1:\n";
    PrintMatrix(Arr1, 3, 3);
    RandomMatrix(Arr2, 3, 3);
    cout << "Matrix2:\n";
    PrintMatrix(Arr2, 3, 3);
    cout << "The number in tow matrix: \n";
    NumberInTowMatrix(Arr1, Arr2, 3, 3);
}
