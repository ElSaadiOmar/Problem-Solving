// Problem: Check whether a specific number exists anywhere in a matrix.
// Simple nested-loop search returning true on the first match.

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
short CountNumberInMatrix(int Matrix1[3][3], int Number, short Rows, short Cols)
{
    short NumberCount = 0;
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            if (Matrix1[i][j] == Number)
            {
                NumberCount++;
            };
        }
    }
    return NumberCount;
}
/*bool IsInMatrix(int Arr[3][3], int Rows, int Cols, int Number)
{
    return (CountNumberInMatrix(Arr, Rows, Cols, Number) != 0);
}*/
bool IsInMatrix(int Arr[3][3], int Rows, int Cols, int Number)
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
int main()
{

    srand((unsigned)time(NULL));
    int Arr[3][3];
    int Number = 0;
    RandomMatrix(Arr, 3, 3);
    cout << "Matrix:\n";
    PrintMatrix(Arr, 3, 3);
    cout << "Enter the number you search it\n";
    cin >> Number;
    if (IsInMatrix(Arr, 3, 3, Number))
        cout << "Yes,Is in Matrix\n";
    else
        cout << "No,Is NOT in Matrix\n";
    return 0;
}