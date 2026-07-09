// Problem: Count how many times a specific character appears in a string.
// Straightforward scan comparing each character to the target.

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
char ReadChar()
{
    char Char;
    cout << "Please Enter Your Char: " << endl;
    cin >> Char;
    return Char;
}
short CountNumOfChar(string S1, char Charactare)
{
    short count = 0;
    for (int i = 0; i < S1.length(); i++)
    {
        if (S1[i] == Charactare)
            count++;
    }
    return count;
}
int main()
{
    string S1 = ReadString();
    char Char = ReadChar();
    cout << "Letter '" << Char << "'count = " << CountNumOfChar(S1, Char)<<endl ;
    return 0;
}