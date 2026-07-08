// Problem: Count how many times a chosen number appears inside an array.
// Simple linear scan comparing each element to the target value.

#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;
int Readnumber(string Message)
{
    int number = 0;
    do
    {
        cout << Message << endl;
        cin >> number;
    } while (number <= 0);
    return number;
}
void ReadArray(int Array[100], int &Arrlength)
{
    cout << "\nenter number of element: \n";
    cin >> Arrlength;
    cout << "\nEnter array elements: \n";
    for (int i = 0; i < Arrlength; i++)
    {
        cout << "The element [" << i + 1 << "] : ";
        cin >> Array[i];
    }
    cout << endl;
}
void printArray(int Array[100], int Arrlength)
{
    for (int i = 0; i < Arrlength; i++)
    {
        cout << Array[i] << " ";
    }
    cout << "\n";
}
int TimeRepeated(int Number, int Array[100], int Arrlength )
{
    short counter = 0;
    for (int i = 0; i < Arrlength; i++)
    {
        if (Array[i]==Number)
        counter++;
    }
    return counter;
}
int main()
{
    int Array[100], Arrlength, numbercheck;

    ReadArray(Array, Arrlength);

    numbercheck = Readnumber("enter the number you went to check");


    cout << "\nOriginal array is: ";
    printArray(Array, Arrlength);

    cout <<"Number "<<numbercheck << " is repeated " 
    <<TimeRepeated(numbercheck,Array,Arrlength)<<" times";
}