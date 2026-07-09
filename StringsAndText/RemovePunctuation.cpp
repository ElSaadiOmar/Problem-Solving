// Problem: Remove all punctuation characters from a string.
// Uses ispunct() to detect and erase punctuation in place.

#include <iostream>
#include <ctime>
#include <cmath>
#include <string>
#include <vector>
#include <iomanip>
#include <cstdlib>
using namespace std;
string DeletePunct(string S1)
{
    for (int i = 0; i < S1.length(); i++)
    {
        if (ispunct(S1[i]))
        {
            S1.erase(i,1);
            i--;
        }
    }
    return S1;
}
int main()
{
    string S1 = "Hello in :Algeria , Algeria; a,,,,,,; ; ; ; ; nice country..";
    cout<<DeletePunct(S1);
    return 0;
}