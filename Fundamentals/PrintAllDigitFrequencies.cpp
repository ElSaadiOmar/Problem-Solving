// Problem: Print how many times each digit (1-9) appears in a number.
// Calls CountDigitFrequency() once per digit and prints non-zero results.

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
int CountDigitFrequency(int Number, short DigitToCheck)
{
    int remainder = 0, frequencyNumber = 0;
    while (Number > 0)
    {
        remainder = Number % 10;
        Number = Number / 10;
        if (remainder == DigitToCheck)
            frequencyNumber++;
    }
    return frequencyNumber;
}
void printAllDigitsFrequency(int Number)
{
    for (int i = 1; i < 10; i++)
    {
        short DigitFrequency = 0;
        DigitFrequency = CountDigitFrequency(Number, i);
        if (DigitFrequency > 0)
        {
            cout << "Digit " << i << " Frequency is "
                 << DigitFrequency << " Time(s).\n";
        }
    }
}
int main()
{
   printAllDigitsFrequency(readnumber("enter number"));
}

/*#include <iostream>
#include <string>
#include <cmath>
using namespace std;
struct stNumbers
{
    int number0 = 0,
        number1 = 0, number2 = 0, number3 = 0,
        number4 = 0, number5 = 0, number6 = 0,
        number7 = 0, number8 = 0, number9 = 0;
};
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
stNumbers theNumberLoop(int number)
{
    stNumbers Numbers;
    int remainder = 0;
    while (number > 0)
    {
        remainder = number % 10;
        number = number / 10;
        if (remainder == 1)
            Numbers.number1 += 1;
        else if (remainder == 2)
            Numbers.number2 += 1;
        else if (remainder == 3)
            Numbers.number3 += 1;
        else if (remainder == 4)
            Numbers.number4 += 1;
        else if (remainder == 5)
            Numbers.number5 += 1;
        else if (remainder == 6)
            Numbers.number6 += 1;
        else if (remainder == 7)
            Numbers.number7 += 1;
        else if (remainder == 8)
            Numbers.number8 += 1;
        else if (remainder == 9)
            Numbers.number9 += 1;
        else
            Numbers.number0 += 1;
    }
    return Numbers;
}
void printResult(stNumbers Numbers)
{
    if (Numbers.number1 > 0)
        cout << "The number 1 digits " << Numbers.number1 << " time\n";
    if (Numbers.number2 > 0)
        cout << "The number 2 digits " << Numbers.number2 << " time\n";
    if (Numbers.number3 > 0)
        cout << "The number 3 digits " << Numbers.number3 << " time\n";
    if (Numbers.number4 > 0)
        cout << "The number 4 digits " << Numbers.number4 << " time\n";
    if (Numbers.number5 > 0)
        cout << "The number 5 digits " << Numbers.number5 << " time\n";
    if (Numbers.number6 > 0)
        cout << "The number 6 digits " << Numbers.number6 << " time\n";
    if (Numbers.number7 > 0)
        cout << "The number 7 digits " << Numbers.number7 << " time\n";
    if (Numbers.number8 > 0)
        cout << "The number 8 digits " << Numbers.number8 << " time\n";
    if (Numbers.number9 > 0)
        cout << "The number 9 digits " << Numbers.number9 << " time\n";
    if (Numbers.number0 > 0)
        cout << "The number 0 digits " << Numbers.number0 << " time\n";
}
int main()
{
    printResult(theNumberLoop(readnumber("enter number")));
    return 0;
}*/