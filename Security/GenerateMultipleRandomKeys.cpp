// Problem: Generate multiple random license keys and store them in an array.
// Extends the single-key generator to fill and print a whole array of keys.

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
int readnumber(string Message)
{
    int number = 0;
    do
    {
        cout << Message << endl;
        cin >> number;
    } while (number <= 0);
    return number;
}
int RandomNumber(int From, int To)
{
    int RanNum = rand() % (To - From + 1) + From;
    return RanNum;
}
char RandomCharType(enCharType CharType)
{
    switch (CharType)
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
string RandomWord(enCharType charType, short length)
{
    string word;
    for (int i = 1; i <= length; i++)
    {
        word = word + RandomCharType(charType);
    }
    return word;
}
string GenerateKey()
{
    string key = "";
    for (int i = 1; i <= 4; i++)
    {
        key = key + RandomWord(enCharType::CapitalLetter, 4) + '-';
    }
    key.pop_back();
    return key;
}
/*void printKey(int number)
{
    for (int i = 1; i <= number; i++)
    {
        cout << "Key [" << i << "] : " << GenerateKey() << endl;
    }
}*/
void FillArrayWithkeys(string Array[100], int Arrlength)
{
    for (int i = 0; i < Arrlength; i++)
        Array[i] = GenerateKey();
}
void printStringArray(string Array[100], int Arrlength)
{
    for (int i = 0; i < Arrlength; i++)
    {
        cout << "Array[" << i + 1 << "] : " << Array[i] << endl;
    }
    cout << "\n\n";
}
int main()
{
    srand((unsigned)time(NULL));
    int Arrlength = 0;
    string Array[100];
    Arrlength = readnumber("Enter the number of keys to generate:");
    FillArrayWithkeys(Array, Arrlength);
    printStringArray(Array, Arrlength);
    return 0;
}