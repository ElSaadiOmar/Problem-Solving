// Problem: Brute-force guess a 3-letter capital password by trying all combos.
// Reuses the AAA-ZZZ generation idea and stops once a match is found.

#include <iostream>
#include <string>
using namespace std;
string readPassword(string Message)
{
    string Password = "";
    cout << Message << endl;
    cin >> Password;
    return Password;
}
bool GuessPassword(string Password)
{
    string word = "";
    int counter = 0;
    for (int i = 65; i < 91; i++)
    {
        for (int x = 65; x < 91; x++)
        {
            for (int j = 65; j < 91; j++) // number+(i-64-number)
            {
                counter++;
                word = word + (char)i;
                word = word + (char)x;
                word = word + (char)j;
                cout << "The trail number [" << counter << "] : " << word << endl;
                if (Password==word)
                {
                    cout <<"The password is "<<word<<endl;
                    cout<<"Found after "<<counter<<" trails"<<endl;
                    return true;
                }
                 word = "";
            }
        }
    }
    return false;
}
int main()
{
    GuessPassword(readPassword("Enter the password in capital later "));
    return 0;
}