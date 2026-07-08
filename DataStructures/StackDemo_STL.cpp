// Problem: Demonstrate basic usage of the C++ STL stack container.
// Pushes several values then pops and prints them (LIFO order).

#include <iostream>
#include <stack>
using namespace std;
int main()
{
    std::stack<int> stkNumbers;
    stkNumbers.push(10);
    stkNumbers.push(20);
    stkNumbers.push(30);
    stkNumbers.push(40);
    stkNumbers.push(50);
    while (!stkNumbers.empty())
    {
        cout << stkNumbers.top() << endl;

        stkNumbers.pop();
    }
}