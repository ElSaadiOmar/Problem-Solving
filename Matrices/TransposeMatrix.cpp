// Problem: Print the transpose of a matrix (swap rows and columns).
// Reuses the ordered-fill matrix and prints it with indices flipped.

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
void PrintTranslMatrix(int Arr[3][3], short Rows, short Cols)
{

    for (int i = 0; i < Rows; i++)
    {
        for (int j = 0; j < Cols; j++)
        {
            cout << Arr[j][i] << setw(3) << "\t";
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
    cout << "The following is 3x3 order matrix \n";
    PrintTranslMatrix(Arr, 3, 3);
}
/*#include <iostream>
#include <string>
using namespace std;
void FillMatrixWithOrderedNumbers(int arr[3][3], short Rows, short
Cols)
{
short Counter = 0;
for (short i = 0; i < Rows; i++)
{
for (short j = 0; j < Cols; j++)
{
Counter++;
arr[i][j] = Counter;
}
}
}
void PrintMatrix(int arr[3][3], short Rows, short Cols)
{
for (short i = 0; i < Rows; i++)
{
for (short j = 0; j < Cols; j++)
{
cout << " " << arr[i][j] << " ";
}
cout << "\n";
}
}
void TransposeMatrix(int arr[3][3], int arrTransposed[3][3], short
Rows, short Cols)
{
for (short i = 0; i < Rows; i++)
{
for (short j = 0; j < Cols; j++)
{
arrTransposed[i][j] = arr[j][i];
}
}
}
int main()
{
int arr[3][3], arrTransposed[3][3];
FillMatrixWithOrderedNumbers(arr, 3, 3);
cout << "\nThe following is a 3x3 ordered matrix:\n";
PrintMatrix(arr, 3, 3);
TransposeMatrix(arr, arrTransposed, 3, 3);
cout << "\n\nThe following is the transposed matrix:\n";
PrintMatrix(arrTransposed, 3, 3);
system("pause>0");*/