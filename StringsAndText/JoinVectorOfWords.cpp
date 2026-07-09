// Problem: Join a vector of words back into a single delimited string.
// The reverse operation of splitting a string into a vector.

#include <iostream>
#include <ctime>
#include <cmath>
#include <string>
#include <vector>
#include <iomanip>
#include <cstdlib>
using namespace std;
string JoinString(vector<string> vWord, string Delim)
{
    string S1 = "";
    for (string &W : vWord)
    {
        S1 = S1 + W + Delim;
        //S1.append(W);
       // S1.append(Delim);
    }
    return S1.substr(0, S1.length() - Delim.length());
}
int main()
{
    vector<string> vString = {"Omar", "Ahmad", "Ali", "Abodi"};
    cout << JoinString(vString, ",");
    return 0;
}