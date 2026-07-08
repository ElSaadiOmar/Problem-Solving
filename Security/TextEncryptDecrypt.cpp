// Problem: Encrypt and decrypt text using a simple Caesar-cipher shift.
// Shifts each character's ASCII code by a fixed key, then reverses it.

#include <iostream>
#include <string>
using namespace std;
string readText(string Message)
{
    string Text = "";
    cout << Message << endl;
    getline(cin, Text);
    return Text;
}
string EncryptText(string Text, short EncryptionKey)
{
    for (int i = 0; i < Text.length(); i++)
    {
        // if (Text[i] != ' ')
        //{
        Text[i] = char((int)Text[i] + EncryptionKey);
        //}
        // else
        //{
        //    NewText = NewText + ' ';
        //}
    }
    return Text;
}
string Decryption(string textAfterEncryption, short EncryptionKey)
{
    for (int i = 0; i < textAfterEncryption.length(); i++)
    {
        // if (textAfterEncryption[counter] != ' ')
        //{
        textAfterEncryption[i] = char((int)textAfterEncryption[i] - EncryptionKey);
        //
        //}
        // else
        //{
        //    OldText=OldText+ ' ';
        //
        //}
    }
    return textAfterEncryption;
}
int main()
{
    const short EncryptionKey = 5;
    string Text = readText("enter The text you need to encryption");
    string encryptText = EncryptText(Text, EncryptionKey);
    string decryption = Decryption(encryptText, EncryptionKey);
    cout << "the encryption text is " << encryptText << endl;
    cout << "The old text is " << decryption << endl;
}