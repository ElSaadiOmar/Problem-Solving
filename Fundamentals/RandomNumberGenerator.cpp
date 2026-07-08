// Problem: Generate a random number within a given range [From, To].
// Seeds the RNG with the current time and uses rand() % range.


#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <ctime> // Include ctime for time function
using namespace std;
int RandomNumber(int From, int To)
{
    int RanNum = rand() % (To - From + 1) + From;
    return RanNum;
}
int main()
{
    srand((unsigned)time(NULL));
    cout<<RandomNumber(2,38);
    return 0;
}
