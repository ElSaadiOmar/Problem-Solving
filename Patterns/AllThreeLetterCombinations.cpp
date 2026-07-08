// Problem: Print every possible 3-letter combination from AAA to ZZZ.
// Triple nested loop over the alphabet (A-Z) using ASCII codes.

#include <iostream>
#include <string>
using namespace std;
void printWordFromAAA_TO_ZZZ()
{
    string word = "";
    for (int i = 65; i < 91; i++)
    {
        for (int x = 65; x < 91; x++)
        {
            for (int j = 65; j < 91; j++) // number+(i-64-number)
            {
                word = word + (char)i;
                word = word + (char)x;
                word = word + (char)j;

                cout << word << endl;
                word = "";
            }
        }
    }
}
int main()
{
    printWordFromAAA_TO_ZZZ();
    return 0;
}