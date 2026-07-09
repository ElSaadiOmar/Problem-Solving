// Problem: Count how many uppercase and lowercase letters are in a string.
// Uses an enum to select what to count, plus standalone counter functions.

#include <iostream>
#include <ctime>
#include <cmath>
#include <string>
#include <iomanip>
#include <cstdlib>
using namespace std;
string ReadString()
{
    string String;
    cout << "Please Enter Your String: " << endl;
    getline(cin, String);
    return String;
}
enum enWhatToCount
{
    SmallLetters = 0,
    CapitalLetters = 1,
    All = 2,
};
short CountLetters(string S1, enWhatToCount WhatToCount)
{
    if (WhatToCount == enWhatToCount::All)
    {
        return S1.length();
    }
    short Counter = 0;
    for (short i = 0; i < S1.length(); i++)
    {
        if (WhatToCount == enWhatToCount::CapitalLetters && isupper(S1[i]))
            Counter++;
        if (WhatToCount == enWhatToCount::SmallLetters && islower(S1[i]))
            Counter++;
    }
    return Counter;
}
int CountUpperLetter(string S1)
{
    int Counter = 0;
    for (int i = 0; i < S1.length(); i++)
    {
        if (isupper(S1[i]))
            Counter++;
    }
    return Counter;
}
int CountSmallLetter(string S1)
{
    int Counter = 0;
    for (int i = 0; i < S1.length(); i++)
    {
        if (islower(S1[i]))
            Counter++;
    }
    return Counter;
}
int main()
{
    enWhatToCount WhatToCount;
    string S1 = ReadString();
    cout << endl<<CountLetters(S1,enWhatToCount::CapitalLetters);
    cout << "String length = " << S1.length() << endl;
    cout << "Capital Letter Count = " << CountUpperLetter(S1) << endl;
    cout << "Small Letter Count = " << CountSmallLetter(S1) << endl;
    return 0;
}
