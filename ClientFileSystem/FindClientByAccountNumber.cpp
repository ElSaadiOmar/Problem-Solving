// Problem: Search the client file for one client by account number.
// Loads all clients, then searches the in-memory list for a match.

#include <iostream>
#include <ctime>
#include <cmath>
#include <vector>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;
const string FileName = "ClientRecord.txt";
struct sClient
{
    string AccountNumber;
    string PinCode;
    string Name;
    string Phon;
    double AccountBalance;
};
string ReadString()
{
    string String;
    cout << "Please enter account number? ";
    getline(cin, String);
    return String;
}
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
vector<sClient> LoadClientDataFromFile(string FileName)
{
    vector<sClient> vClients;
    fstream MyFile;
    MyFile.open(FileName, ios::in);
    if (MyFile.is_open())
    {
        string Line;
        sClient Client;
        while (getline(MyFile, Line))
        {
            Client = ConvertLinetoRecord(Line);
            vClients.push_back(Client);
        }
        MyFile.close();
    }
    return vClients;
}
bool FindClientByAccountNumber(string AccountNum, sClient &Client)
{
    vector<sClient> vClient = LoadClientDataFromFile(FileName);
    for (sClient &C : vClient)
    {
        if (C.AccountNumber == AccountNum)
        {
            Client = C;
            return true;
        }
    }
    return false;
}
void PrintClientCard(sClient Info)
{
    cout << "\nThe following are the client details\n";
    cout << "\nAcount Number : " << Info.AccountNumber ;
    cout << "\nPin Code      : " << Info.PinCode;
    cout << "\nName          : " << Info.Name;
    cout << "\nPhon          : " << Info.Phon;
    cout << "\nAcount Balance: " << Info.AccountBalance;
}
void PrintClientByAccountNumber(string AccountNumber)
{
    sClient Client;
    if (FindClientByAccountNumber(AccountNumber, Client))
    {
        PrintClientCard(Client);
    }
    else
    {
        cout << "\nClient with Account Number (" << AccountNumber << ") Not Found!";
    }
}
int main()
{
    system("cls");
    string AccountNumber = ReadString();
    PrintClientByAccountNumber(AccountNumber);
    return 0;
}
