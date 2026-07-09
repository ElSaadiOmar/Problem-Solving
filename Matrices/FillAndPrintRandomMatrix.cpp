// Problem: Fill a 3x3 matrix with random numbers and print it.
// Foundation helper reused by most of the other matrix exercises.

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
            cout <<setw(3)<< Arr[i][j] << "\t";
        }
        cout << endl;
    }
}
int main()
{

    srand((unsigned)time(NULL));
    int Arr[3][3];
    RandomMatrix(Arr,3,3);
    cout << "The Following is a 3x3 Random Matrix\n";
    PrintMatrix(Arr,3,3);
    return 0;
}
