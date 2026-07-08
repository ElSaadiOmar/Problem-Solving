// Problem: Demonstrate how a C++ union shares memory between members.
// Shows how writing to one member (int/float/char) affects the others.

#include <iostream>
using namespace std;
union Myunion
{
    int IntegerValue;
    float FloatValue;
    char CharValue;
};
int main()
{
    Myunion myunion;
    myunion.IntegerValue = 89;
    cout << myunion.IntegerValue << endl;
    myunion.FloatValue = 9.99f;

    cout << myunion.FloatValue << endl;
    cout << myunion.IntegerValue << endl;
    myunion.CharValue='A';
  
    cout << myunion.CharValue << endl;
    cout << myunion.FloatValue << endl;
}