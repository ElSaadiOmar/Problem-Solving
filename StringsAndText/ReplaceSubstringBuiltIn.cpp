// Problem: Replace every occurrence of a word inside a string.
// Uses the built-in string::replace() function to swap the text directly.

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
string ReplaceWordInStringUsingBuiltInFunction(string S1, string StringToReplace, string sRepalceTo)
{
    short pos = S1.find(StringToReplace);
    while (pos != std::string::npos)
    {
        S1 = S1.replace(pos, StringToReplace.length(),
                        sRepalceTo);
        pos = S1.find(StringToReplace); // find next
    }
    return S1;
}
/*string ReplaceWordInString(vector<string> S1, string ToReplace, string ReplaceTo, bool MatchCase = true)
{
    if (MatchCase)
    {
        short pos = 0;
        string S2 = "";
        while ((pos = S1.find(ToReplace)) != std::string::npos)
        {
            S2 = S2 + S1.substr(0, pos) + ReplaceTo;
            S1.erase(0, pos + ToReplace.length());
        }
        S2 = S2 + S1;
        return S2;
    }
    else
    {
        short pos = 0;
        string S2 = "";
        string LS=tolower('t');
        string LToReplace;
        while ((pos = S1.find(ToReplace)) != std::string::npos)
        {
            S2 = S2 + S1.substr(0, pos) + ReplaceTo;
            S1.erase(0, pos + ToReplace.length());
        }
        S2 = S2 + S1;
        return S2;
    }
}*/
int main()
{
    string S1 = "Hello in Algeria , Algeria a nice country";
    string StringToReplace = "Algeria";
    string ReplaceTo = "USA";
    cout << "The Original string:\n"
         << S1 << endl;

    cout << "String After Replace:\n";
    // ReplaceWordInString(S1, StringToReplace, ReplaceTo);
    return 0;
}