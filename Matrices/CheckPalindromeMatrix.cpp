// Problem: Check whether each row of a matrix reads the same forwards and backwards.
// Compares elements from both ends of every row toward the middle.

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
bool MatrixIsPalindrome(int Arr[3][3], short Rows, short Cols)
{
    for (int i = 0; i < Rows; i++)
    {
        for (int j = 0; j < Cols/2; j++)
        {
            if (Arr[i][j] != Arr[i][Cols - 1 - j])
                return false;
        }
    }
    return true;
}
int main()
{
    srand((unsigned)time(NULL));
    int Arr[3][3]={{2,2,1},{2,1,2},{1,9,1}};
    //RandomMatrix(Arr, 3, 3);
    cout << "Matrix:\n";
    PrintMatrix(Arr, 3, 3);
    if (MatrixIsPalindrome(Arr, 3, 3))
        cout << "\nThe matrix is palindrome " << endl;
    else
        cout << "\nThe matrix is NOT palindrome " << endl;
    return 0;
}