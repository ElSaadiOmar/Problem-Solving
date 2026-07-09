// Problem: Split a string into words and store them in a vector.
// General-purpose SplitString() helper reused by many later string exercises.

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
int main()
{
    string S1 = ReadString();
    vector<string> veWorld = SplitString(S1, " ");
    cout << "Token: " << veWorld.size() << endl;
    for (string Word : veWorld)
    {
        cout << Word << endl;
    }
    return 0;
}