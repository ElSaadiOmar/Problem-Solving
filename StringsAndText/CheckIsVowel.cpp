// Problem: Check whether a single character is a vowel (a, e, i, o, u).
// Converts to lowercase first so both cases are handled.

#include <iostream>
#include <ctime>
#include <cmath>
#include <string>
#include <iomanip>
#include <cstdlib>
using namespace std;
char ReadChar()
{
    char Char;
    cout << "Please Enter Your Char: " << endl;
    cin >> Char;
    return Char;
}
bool IsVowelLetter(char Char)
{
    Char = tolower(Char);
    return ((Char == 'a') || (Char == 'o') || (Char == 'i') || (Char == 'u') || (Char == 'e'));
}
int main()
{
    char Char = ReadChar();
    if (IsVowelLetter(Char))
        cout << "YES, Letter '" << Char << "' is vowel";
    else
        cout << "NO, Letter '" << Char << "' is not vowel";
    return 0;
}