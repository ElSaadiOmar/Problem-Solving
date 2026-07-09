// Problem: Replace a whole word inside a sentence (word-by-word, not substring).
// Splits into words, swaps any exact match, then rejoins the sentence.

#include <iostream>
#include <ctime>
#include <cmath>
#include <string>
#include <vector>
#include <iomanip>
#include <cstdlib>
using namespace std;
vector<string> SplitString(string S1, string Spliter)
{
    vector<string> veWorld;
    short pos = 0;
    string sWord;
    while ((pos = S1.find(Spliter)) != std::string::npos)
    {
        sWord = S1.substr(0, pos);
        if (sWord != "")
        {
            veWorld.push_back(sWord);
        }
        S1.erase(0, pos + Spliter.length());
    }
    if (S1 != "")
    {
        veWorld.push_back(S1);
    }
    return veWorld;
}
string JoinString(vector<string> vWord, string Delim)
{
    string S1 = "";
    for (string &W : vWord)
    {
        S1 = S1 + W + Delim;
    }
    return S1.substr(0, S1.length() - Delim.length());
}
string LowerAllString(string S)
{
    for (int i = 0; i < S.length(); i++)
    {
        S[i] = tolower(S[i]);
    }
    return S;
}
string ReplaceWordInString(string S1, string ToReplace, string ReplaceTo, bool MatchCase = true)
{
    vector<string> vstring = SplitString(S1, " ");

    for (string &s : vstring)
    {
        if (MatchCase)
        {
            if (s == ToReplace)
            {
                s = ReplaceTo;
            }
        }
        else
        {
            if (LowerAllString(s) == LowerAllString(ToReplace))
            {
                s = ReplaceTo;
            }
        }
    }
    return JoinString(vstring," ");
}
int main()
{
    string S1 = "Hello in Algeria , Algeria a nice country";
    string StringToReplace = "Algeria";
    string ReplaceTo = "USA";
    cout << "The Original string:\n"
         << S1 << endl;

    cout << "String After Replace:\n"
         << ReplaceWordInString(S1, StringToReplace, ReplaceTo);
    return 0;
}