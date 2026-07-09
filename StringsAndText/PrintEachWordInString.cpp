// Problem: Split a sentence into words and print each word on its own line.
// Uses string::find() with a space delimiter to walk through the sentence.

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
void PrintEachwordInString(string S1)
{
    string delim = " ";
    cout << "\nYour string Word is: " << endl;
    short pos = 0;
    string sWord;
    while ((pos = S1.find(delim)) != std::string::npos)
    {
        sWord = S1.substr(0, pos);
        if (sWord != "")
        {
            cout << sWord << endl;
        }
        S1.erase(0, pos + delim.length());
    }
    if (S1 != "")
    {
        cout << S1 << endl;
    }
}
int main()
{
    string S1 = ReadString();
    PrintEachwordInString(S1);
    return 0;
}