// Problem: Convert a number between different numeral systems (bases).
// Converts X-base to decimal, then decimal to a target Y-base.

#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cstdlib>
using namespace std;
int XSystemToDecimalSystem(string Number, short XSystem)
{
    int NumberByDecimal = 0;
    int digit = 0;
    for (int i = 0; i < Number.length(); i++)
    {
        if (Number[Number.length() - 1 - i] >= '0' && Number[Number.length() - 1 - i] <= '9')
            digit = Number[Number.length() - 1 - i] - '0';
        else if (Number[Number.length() - 1 - i] >= 'A' && Number[Number.length() - 1 - i] <= 'Z')
            digit = Number[Number.length() - 1 - i] - 55;
        NumberByDecimal += digit * pow(XSystem, i);
    }

    return NumberByDecimal;
}
string DecimalSystemToXSystem(int Number, short XSystem)
{
    string NumberByXSystem = "";
    int Result = Number;
    do
    {
        int digit = Result % XSystem;
        if (digit < 10)
            NumberByXSystem = to_string(digit) + NumberByXSystem;
        else
            NumberByXSystem = char(digit + 55) + NumberByXSystem;
        Result = Result / XSystem;
    } while (Result != 0);
    return NumberByXSystem;
}
string XSystemToYSystem(string Number, short XSystem, short YSystem)
{
    int NumberByDecimal = XSystemToDecimalSystem(Number, XSystem);
    return DecimalSystemToXSystem(NumberByDecimal, YSystem);
}
string PointXSystemToDecimal(double Number, int XS)
{
    string Result = "";
    vector<float> vNumber;
    vNumber.push_back(Number);
    while (fabs(Number) > 1e-9 && find(vNumber.begin(), vNumber.end(), Number) == vNumber.end())
    {

        Number *= XS;
        int Digit = (int)Number;
        Result += to_string(Digit);
        Number -= Digit;
        vNumber.push_back(Number);
    }
    return Result;
}
string PointDecimalToXSystem(double)
{
}
int main()
{
    // cout << DecimalSystemToXSystem(302, 16);
    // cout<<XSystemToDecimalSystem("12E",16);
    cout << DecimalSystemToXSystem(72,2 ) << ".";
    //cout << PointXSystemToDecimal(0.1, 2);
}