// Problem: Print the first letter of every word in a sentence.
// Tracks word boundaries using spaces to detect the start of each word.

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
void printFirstLetter(string S1)
{
    bool IsFirstLetter = true;
    for (int i = 0; i < S1.length(); i++)
    {
        if (S1[i] != ' ' && IsFirstLetter)
        {
            cout << S1[i] << endl;
        }
        IsFirstLetter=(S1[i] == ' ' ?true : false);
    }
}
int main()
{

    printFirstLetter(ReadString());
}
/*void printFirstLetter(string String)
{
    int Length = String.length();
    if (Length == 0)
        return;
    if (String[0] != ' ')
        cout << String[0] << endl;
    for (int i = 1; i < Length; i++)
    {
        if (String[i - 1] == ' ' && String[i] != ' ')
        {
            cout << String[i] << endl;
        }
    }
}*/