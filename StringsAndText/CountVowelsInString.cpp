// Problem: Count how many vowels appear in a string.
// Reuses the IsVowelLetter() check while scanning every character.

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
bool IsVowelLetter(char Char)
{
    Char = tolower(Char);
    return ((Char == 'a') || (Char == 'o') || (Char == 'i') || (Char == 'u') || (Char == 'e'));
}
short countVowel(string S1)
{
    short count = 0;
    for (int i = 0; i < S1.length(); i++)
    {
        if (IsVowelLetter(S1[i]))
            count++;
    }
    return count;
}
int main()
{
    string S1 = ReadString();
    cout << "\nNumber of Vowels is: " << countVowel(S1);
    return 0;
}