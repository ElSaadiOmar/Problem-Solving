// Problem: Update an existing client's details by account number.
// Finds the client, re-reads their new details, then rewrites the file.

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
    bool MarkForDelete = false;
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
bool FindClientByAccountNumber(string AccountNum, vector<sClient> vClient, sClient &Client)
{
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
    cout << "\nAcount Number : " << Info.AccountNumber;
    cout << "\nPin Code      : " << Info.PinCode;
    cout << "\nName          : " << Info.Name;
    cout << "\nPhon          : " << Info.Phon;
    cout << "\nAcount Balance: " << Info.AccountBalance;
}
string ConvertRecordToLine(sClient Client, string Delim = "#//#")
{
    string stClientRecord = "";
    stClientRecord += Client.AccountNumber + Delim;
    stClientRecord += Client.PinCode + Delim;
    stClientRecord += Client.Name + Delim;
    stClientRecord += Client.Phon + Delim;
    stClientRecord += to_string(Client.AccountBalance);
    return stClientRecord;
}
sClient ChangeClientRecord(string AccountNumber)
{
    sClient Client;
    Client.AccountNumber = AccountNumber;

    cout << "\nEnter Pin Code? ";
    getline(cin>>ws, Client.PinCode);

    cout << "\nEnter Name? ";
    getline(cin, Client.Name);

    cout << "\nEnter Phon Number? ";
    getline(cin, Client.Phon);

    cout << "\nEnter Account Balance? ";
    cin >> Client.AccountBalance;
    return Client;
}
void SaveClientDataToFile(vector<sClient> &vClient, string FileName)
{
    fstream MyFile;
    MyFile.open(FileName, ios::out);

    if (MyFile.is_open())
    {
        for (sClient &C : vClient)
        {
            if(C.MarkForDelete==false)
                MyFile << ConvertRecordToLine(C) << endl; 
        }
        MyFile.close();
    }
}
bool UpdateClientByAccountNumber(string AccountNumber, vector<sClient> &vClient)
{
    char Chose;
    sClient Client;
    if (FindClientByAccountNumber(AccountNumber, vClient, Client))
    {
        PrintClientCard(Client);
        cout << "\n\nAre you sure you want Update this client? y/n ?";
        cin >> Chose;
        if (tolower(Chose) == 'y')
        {

            for(sClient &C:vClient)
            {
                if(C.AccountNumber==AccountNumber)
                {
                    C=ChangeClientRecord(AccountNumber);
                    break;
                }
            }
            SaveClientDataToFile(vClient, FileName);
            cout << "\nClient Update successfully";
            return true;
        }
    }
    else
    {
        cout << "\nClient with Account Number (" << AccountNumber << ") Not Found!";
        return false;
    }
}
int main()
{
    system("cls");
    vector<sClient> vClient = LoadClientDataFromFile(FileName);
    string AccountNumber = ReadString();
    UpdateClientByAccountNumber(AccountNumber, vClient);
    return 0;
}
