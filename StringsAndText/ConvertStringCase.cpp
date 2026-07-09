// Problem: Convert an entire string to all-uppercase and all-lowercase.
// Simple loop applying toupper()/tolower() to every character.

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
    cout << "enter your string: " << endl;
    getline(cin, String);
    return String;
}
string UpperAllLetter(string S1)
{
    for (short i = 0; i < S1.length(); i++)
    {
        S1[i] = toupper(S1[i]);
    }
    return S1;
}
string LowerAllLetter(string S1)
{
    for (short i = 0; i < S1.length(); i++)
    {
        S1[i] = tolower(S1[i]);
    }
    return S1;
}
int main()
{
    string S1 = ReadString();
    cout << "\nString after Upper:" << endl;
    cout << UpperAllLetter(S1);
    cout << "\n\nString after conversion:" << endl;
    cout << LowerAllLetter(S1);
    system("pause>0");
}