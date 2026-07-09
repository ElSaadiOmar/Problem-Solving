// Problem: Convert the first letter of every word in a sentence to lowercase.
// Mirror image of the uppercase version, using tolower() instead.

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

string LowerFirstLetter(string S1)
{
    bool IsFirstLetter = true;
    for (int i = 0; i < S1.length(); i++)
    {
        if (S1[i] != ' ' && IsFirstLetter)
        {
                S1[i] = tolower(S1[i]);
        }
        IsFirstLetter = (S1[i] == ' ' ? true : false);
    }
    return S1;
}
int main()
{
     string S1 = ReadString();
     cout << "\nString after conversion:" << endl;
     S1 = LowerFirstLetter(S1);
     cout<<S1;
     system ("pause>0");
}