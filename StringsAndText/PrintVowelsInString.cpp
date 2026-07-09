// Problem: Print every vowel found in a string.
// Same vowel check as above, but prints matches instead of counting them.

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
void PrintVowel(string S1)
{
    cout << "\nVowels in string are: ";
    for (int i = 0; i < S1.length(); i++)
    {
        if (IsVowelLetter(S1[i]))
            cout << S1[i] << "      ";
    }
}
int main()
{
    string S1 = ReadString();
    PrintVowel(S1);
    return 0;
}