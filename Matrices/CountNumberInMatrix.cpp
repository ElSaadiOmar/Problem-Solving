// Problem: Count how many times a chosen number appears in a matrix.
// Scans every cell and increments a counter on a match.

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
short CounterNumber(int Arr[3][3], int Rows, int Cols,int CountNumber)
{
    short Counter=0;
    for (int i = 0; i < Rows; i++)
    {
        for (int j = 0; j < Cols; j++)
        {
            if(Arr[i][j]==CountNumber)
            {
                Counter++;
            }
        }
    }
    return Counter;
}
int main()
{

    srand((unsigned)time(NULL));
    int Arr[3][3];
    short CountNumber=0;
    RandomMatrix(Arr, 3, 3);
    cout << "Matrix:\n";
    PrintMatrix(Arr, 3, 3);
    cout<<"\nenter your number went to count "<<endl;
    cin>>CountNumber;
    cout<<"The number rebid in matrix "<<CounterNumber(Arr,3,3,CountNumber)<<" Time";
    return 0;
}
