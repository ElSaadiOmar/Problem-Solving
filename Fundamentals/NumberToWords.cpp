// Problem: Convert a number into its English word representation.
// Recursively breaks the number into billions/millions/thousands/hundreds.

#include <iostream>
#include <string>
using namespace std;
long long ReadNumber()
{
    long long Number = 0;
    cout << "Please enter Number" << endl;
    cin >> Number;
    return Number;
}
string NumberToText(long long Number)
{
    string TextNumber = "";
    if (Number == 0)
    {
        return "";
    }
    if (Number < 0)
    {
        TextNumber += "negative " + NumberToText(-Number);
        return TextNumber;
    }
    if (Number <= 19)
    {
        string arr[] = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten",
                        "eleven", "twelve", "thirteen", "fourteen", "fifteen",
                        "sixteen", "seventeen", "eighteen", "nineteen"};
        return arr[Number] + " ";
    }
    if (Number <= 100)
    {
        string arr[] = {"", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
        return arr[Number / 10] + " " + NumberToText(Number % 10);
    }
    if (Number <= 999)
        return NumberToText(Number / 100) + "hundred " + NumberToText(Number % 100);
    if (Number <= 999999)
        return NumberToText(Number / 1000) + "thousand " + NumberToText(Number % 1000);
    if (Number <= 999999999)
        return NumberToText(Number / 1000000) + "million " + NumberToText(Number % 1000000);
    if (Number <= 999999999999)
        return NumberToText(Number / 1000000000) + "billion " + NumberToText(Number % 1000000000);
}
void WriteNumberByWords(long long Number)
{
    if (Number == 0 )
    {
        return;
    }
    if (Number < 0)
    {
        cout << "negative ";
        WriteNumberByWords(-Number);
        return;
    }
    if (Number > 999999999999)
    {
        cout << "The number is big";
        return;
    }
    else
    {
        if (Number >= 1000000000)
        {
            WriteNumberByWords(Number / 1000000000);
            cout << "billion ";
            Number = Number % 1000000000;
        }
        if (Number >= 1000000)
        {
            WriteNumberByWords(Number / 1000000);
            cout << "million ";
            Number = Number % 1000000;
        }
        if (Number >= 1000)
        {
            WriteNumberByWords(Number / 1000);
            cout << "thousand ";
            Number = Number % 1000;
        }
        if (Number >= 100)
        {
            WriteNumberByWords(Number / 100);
            cout << "hundred ";
            Number = Number % 100;
        }
        if (Number >= 20)
        {
            string arr[] = {"", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
            cout << arr[Number / 10] << " ";
            Number = Number % 10;
        }
        if (Number <= 19)
        {
            string arr[] = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten",
                            "eleven", "twelve", "thirteen", "fourteen", "fifteen",
                            "sixteen", "seventeen", "eighteen", "nineteen"};
            cout << arr[Number] << " ";
        }
    }
}
int main()
{
    long long Number = ReadNumber();
    cout << "Yor number is :" << endl;
    WriteNumberByWords(Number);
    return 0;
}