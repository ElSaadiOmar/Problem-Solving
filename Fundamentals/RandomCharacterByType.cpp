// Problem: Generate a random character of a chosen type.
// Supports small letters, capital letters, symbols, and digits via an enum.

#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;
enum enCharType
{
    SmallLetter = 1,
    CapitalLetter = 2,
    SpecialCharacter = 3,
    number = 4,
};
int RandomNumber(int From, int To)
{
    int RanNum = rand() % (To - From + 1) + From;
    return RanNum;
}
char RandomCharType(enCharType RandomCharType)
{
    switch (RandomCharType)
    {
    case enCharType::SmallLetter:
        return RandomNumber(97, 122);
        break;
    case enCharType::CapitalLetter:
        return RandomNumber(65, 90);
        break;
    case enCharType::SpecialCharacter:
        return RandomNumber(33, 47);
        break;
    case enCharType::number:
        return RandomNumber(48, 57);
        break;
    default:
        break;
    }
}
int main()
{
    srand((unsigned)time(NULL));
    cout << RandomCharType(enCharType::SmallLetter)<<endl;
    cout << RandomCharType(enCharType::CapitalLetter)<<endl;
    cout << RandomCharType(enCharType::SpecialCharacter)<<endl;
    cout << RandomCharType(enCharType::number)<<endl;
    return 0;
}
