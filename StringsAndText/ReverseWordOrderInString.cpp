// Problem: Reverse the order of the words in a sentence.
// Splits into a vector, then rebuilds the string walking backwards.

#include <iostream>
#include <ctime>
#include <cmath>
#include <string>
#include <vector>
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
string ReverseWordsInString(string S1)
{
    vector<string> vstring;
    string S2 = "";
    vstring = SplitString(S1, " ");
    vector<string>::iterator iter = vstring.end();
    while (iter != vstring.begin())
    {
        iter--;
        S2 += *iter + " ";
    }
    S2 = S2.substr(0, S2.length() - 1);
    return S2;
}
int main()
{
    string S1 = ReadString();
    cout << "\n\nString after reversing words: " << endl;
    cout << ReverseWordsInString(S1);
    return 0;
}