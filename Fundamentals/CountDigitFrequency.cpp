// Problem: Count how many times a specific digit appears in a number.
// Compares each extracted digit against the target digit.

#include <iostream>
#include <string>
#include <cmath>
using namespace std;
float readnumber(string Message)
{
    int number = 0;
    do
    {
        cout << Message << endl;
        cin >> number;
    } while (number <= 0);
    return number;
}
int CountDigitFrequency(int tallNumber, short loopNumber)
{
    int remainder = 0, frequencyNumber = 0;
    while (tallNumber > 0)
    {
        remainder = tallNumber % 10;
        tallNumber = tallNumber / 10;
        if (remainder == loopNumber)
            frequencyNumber++;
    }
    return frequencyNumber;
}
int main()
{
    int tallNumber = readnumber("enter the tall number");
    short loopNumber = readnumber("enter the number you went to check how many loop");
    cout << endl
         << "the number " 
         << loopNumber 
         <<" is frequency " 
         << CountDigitFrequency(tallNumber, loopNumber) 
         << " Time.";
}