// Problem: Join words back into a string, from either a vector or a plain array.
// Adds an overload of JoinString() that accepts a C-style string array.

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
        // S1.append(W);
        // S1.append(Delim);
    }
    return S1.substr(0, S1.length() - Delim.length());
}
string JoinString(string Arr[], int lengthArr, string Delim)
{
    string S1 = "";
    for (int i = 0; i < lengthArr; i++)
    {
        S1 = S1 + Arr[i] + Delim;
    }
    return S1.substr(0, S1.length() - Delim.length());
}
int main()
{
    vector<string> vString = {"Omar", "Ahmad", "Ali", "Abodi"};
    string Arr[4] = {"Omar", "Ahmad", "Ali", "Abodi"};
    cout << "Vector after join" << endl;
    cout << JoinString(vString, ",");
    cout << "\nArray after join" << endl;
    cout << JoinString(Arr, 4, ",");
    return 0;
}