// Problem: Demonstrate basic usage of the C++ STL queue container.
// Pushes values, then prints them using front()/pop() (FIFO order).

#include <iostream>
#include <queue>
using namespace std;
int main()
{
    queue<int> MyQueue;
    MyQueue.push(10);
    MyQueue.push(20);
    MyQueue.push(30);
    MyQueue.push(40);
    MyQueue.push(50);
    cout << MyQueue.back()<<endl;
    while (!MyQueue.empty())
    {
       cout<<MyQueue.front()<<endl;
       MyQueue.pop();
    }
    
}