// Problem: Parse a delimited text line back into a client record (struct).
// The reverse of the previous exercise: string -> struct.

#include <iostream>
#include <ctime>
#include <cmath>
#include <string>
#include <vector>
#include <iomanip>
#include <cstdlib>
using namespace std;
struct sClient
{
    string AccountNumber;
    string PinCode;
    string Name;
    string Phon;
    double AccountBalance;
};
vector<string> SplitString(string S1, string Spliter)
{
    vector<string> veWorld;
    short pos = 0;
    string sWord;
    while ((pos = S1.find(Spliter)) != std::string::npos)
    {
        sWord = S1.substr(0, pos);
        if (sWord != "")
        {
            veWorld.push_back(sWord);
        }
        S1.erase(0, pos + Spliter.length());
    }
    if (S1 != "")
    {
        veWorld.push_back(S1);
    }
    return veWorld;
}
sClient ConvertLinetoRecord(string Line, string Spliter = "#//#")
{
    sClient Info;
    vector<string> vInfo = SplitString(Line, Spliter);
    Info.AccountNumber = vInfo[0];
    Info.PinCode = vInfo[1];
    Info.Name = vInfo[2];
    Info.Phon = vInfo[3];
    Info.AccountBalance = stod(vInfo[4]);
    return Info;
}
void PrintRecord(sClient Info)
{
    cout << "Acount Number : " << Info.AccountNumber << endl;
    cout << "Pin Code      : " << Info.PinCode << endl;
    cout << "Name          : " << Info.Name << endl;
    cout << "Phon          : " << Info.Phon << endl;
    cout << "Acount Balance: " << Info.AccountBalance << endl;
}
int main()
{
    string ClientInfo = "57Au#//#6888#//#Omar#//#5778867#//#3242";
    cout << "Line Record is:" << endl;
    cout << ClientInfo << endl
         << endl;
    cout << "The following is the extracted client record" << endl<< endl;

    sClient Info = ConvertLinetoRecord(ClientInfo);

    PrintRecord(Info);
    return 0;}
/*
sClient SplitStringToStruct(string S1, string delim = "#//#")
{
    sClient Info;
    short pos = 0;
    short count = 1;
    string sWord;
    while ((pos = S1.find(delim)) != std::string::npos)
    {
        sWord = S1.substr(0, pos);
        switch (count)
        {
        case 1:
            Info.AccountNumber = sWord;
            count++;
            break;
        case 2:
            Info.PinCode = sWord;
            count++;
            break;
        case 3:
            Info.Name = sWord;
            count++;
            break;
        case 4:
            Info.Phon = sWord;
            count++;
            break;
        default:
            break;
        }
        S1.erase(0, pos + delim.length());
    }
    if (S1 != "")
    {
        Info.AccountBalance = stod(S1);
    }
    return Info;
}
void PrintRecord(sClient Info)
{
    cout << "Acount Number : " << Info.AccountNumber << endl;
    cout << "Pin Code      : " << Info.PinCode << endl;
    cout << "Name          : " << Info.Name << endl;
    cout << "Phon          : " << Info.Phon << endl;
    cout << "Acount Balance: " << Info.AccountBalance << endl;
}
int main()
{
    string ClientInfo = "57Au#//#6888#//#Omar#//#5778867#//#3242";
    cout << "Line Record is:" << endl;
    cout << ClientInfo << endl
         << endl;
    cout << "The following is the extracted client record" << endl<< endl;

    sClient Info = SplitStringToStruct(ClientInfo);

    PrintRecord(Info);
    return 0;}
}*/