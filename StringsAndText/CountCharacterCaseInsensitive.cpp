// Problem: Count a character's occurrences, with an option to ignore letter case.
// Extends the character counter with a MatchCase parameter.

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
/*short CountNumOfChar(string S1, char Charactare)
{
    short count = 0;
    for (int i = 0; i < S1.length(); i++)
    {
        if (S1[i] == Charactare)
            count++;
    }
    return count;
}*/
char IvertLetter(char Lett)
{
    return isupper(Lett) ? tolower(Lett) : toupper(Lett);
}
/*short CountAllNumOfChar(string S1, char Char)
{
    return (CountNumOfChar(S1,Char) + CountNumOfChar(S1,IvertLetter(Char)));
}*/
short CountLetter(string S1, char Letter, bool MatchCase = true)
{
    short Counter = 0;
    for (short i = 0; i < S1.length(); i++)
    {
        if (MatchCase)
        {
            if (S1[i] == Letter)
                Counter++;
        }
        else
        {
            if (tolower(S1[i]) == tolower(Letter))
                Counter++;
        }
    }
    return Counter;
}
int main()
{
    string S1 = ReadString();
    char Char = ReadChar();
    cout << "Letter '" << Char << "'count = " << CountLetter(S1, Char) << endl;
    cout << "Letter '" << Char << "' or '" << IvertLetter(Char) << "' count = " << CountLetter(S1, Char,false) << endl;
    return 0;
}