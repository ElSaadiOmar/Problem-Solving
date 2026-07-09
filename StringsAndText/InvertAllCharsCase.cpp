// Problem: Flip the case of every letter in a string.
// Applies the single-character case inversion across the whole string.

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
char IvertLetter(char Lett)
{
    return isupper(Lett) ? tolower(Lett) : toupper(Lett);
}
string IvertAllLetter(string S1)
{
    for (short i = 0; i < S1.length(); i++)
    {
        S1[i] = IvertLetter(S1[i]);
    }
    return S1;
}
int main()
{
    string S1 = ReadString();
    cout << "\nString after Iverting All letter:" << endl;
    S1 = IvertAllLetter(S1);
    cout << S1 << endl;
    system("pause>0");
}