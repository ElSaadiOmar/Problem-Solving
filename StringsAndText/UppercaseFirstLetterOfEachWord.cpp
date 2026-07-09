// Problem: Convert the first letter of every word in a sentence to uppercase.
// Uses the same word-boundary tracking, applying toupper() at each word start.

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
// char toupper()
string UpperFirstLetter(string S1)
{
    bool IsFirstLetter = true;
    for (int i = 0; i < S1.length(); i++)
    {
        if (S1[i] != ' ' && IsFirstLetter)
        {
                S1[i] = toupper(S1[i]);
        }
        IsFirstLetter = (S1[i] == ' ' ? true : false);
    }
    return S1;
}
int main()
{
     string S1 = ReadString();
     cout << "\nString after conversion:" << endl;
     S1 = UpperFirstLetter(S1);
     cout<<S1;
     system ("pause>0");
}
/*string UpperFirstLetter(string S1)
{
    bool IsFirstLetter = true;
    for (int i = 0; i < S1.length(); i++)
    {
        if (S1[i] != ' ' && IsFirstLetter)
        {
            if ((char)S1[i] > 96 && (char)S1[i] < 123)
                S1[i] = S1[i] - 32;
        }
        IsFirstLetter = (S1[i] == ' ' ? true : false);
    }
    return S1;
}*/