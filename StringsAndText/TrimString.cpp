// Problem: Trim leading and trailing spaces from a string.
// Separate TrimLeft()/TrimRight() helpers combined into a full trim.

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
string TramLeft(string S1)
{
    for (int i = 0; i < S1.length(); i++)
    {
        if (S1[i] != ' ')
            return S1.substr(i, S1.length() - i);
    }
    return "";
}
string TramRight(string S1)
{
    for (int i = (S1.length() - 1); i >= 0; i--)
    {
        if (S1[i] != ' ')
            return S1.substr(0, i + 1);
    }
}
string TramAll(string &S1)
{
    return (TramLeft(TramRight(S1)));
}
int main()
{
    string S1 = ReadString();
    cout << "Tram Left:" << TramAll(S1);
    return 0;
}