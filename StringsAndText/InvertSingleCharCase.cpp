// Problem: Flip the case of a single character (upper becomes lower, and vice versa).
// Small building block reused by the whole-string version below.

#include <iostream>
#include <ctime>
#include <cmath>
#include <string>
#include <iomanip>
#include <cstdlib>
using namespace std;
char ReadChar()
{
    char Lett;
    cout << "enter your char: " << endl;
    cin >> Lett;
    return Lett;
}
char IvertLetter(char Lett)
{
    return isupper(Lett) ? tolower(Lett) : toupper(Lett);
}
int main()
{
    char n = ReadChar();
    cout << "\nChar after inverting case:" << endl;
    n = IvertLetter(n);
    cout << n << endl;
    system("pause>0");
}