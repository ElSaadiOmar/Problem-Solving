// Problem: Count how many words are in a sentence.
// Same splitting approach as above, counting words instead of printing them.

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
short CountWordInString(string S1)
{
  short count = 0;
  string delim = " ";
  short pos = 0;
  string sWord;
  while ((pos = S1.find(delim)) != std::string::npos)
  {
    sWord = S1.substr(0, pos);
    if (sWord != "")
    {
      count++;
    }
    S1.erase(0, pos + delim.length());
  }
  if (S1 != "")
  {
    count++;
  }
  return count;
}
int main()
{
  string S1 = ReadString();
  cout << "\nThe Numberof your Word in string  is: " ;
  cout << CountWordInString(S1);
  return 0;
}