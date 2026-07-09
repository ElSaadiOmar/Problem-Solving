// Problem: Delete a client record from the file by account number.
// Marks the matching record for deletion, then rewrites the file without it.

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
bool MarkClientForDeleteByAccountNumber(string AccountNumber, vector<sClient> &vClient)
{
    for (sClient &C : vClient)
    {
        if (C.AccountNumber == AccountNumber)
        {
            C.MarkForDelete = true;
            return true;
        }
    }
    return false;
}
void SaveClientDataToFile(vector<sClient> &vClient, string FileName)
{
    fstream MyFile;
    MyFile.open(FileName, ios::out);

    if (MyFile.is_open())
    {
        string Line;
        for (sClient &C : vClient)
        {
            if (C.MarkForDelete == false)
                MyFile << ConvertRecordToLine(C) << endl;
        }
        MyFile.close();
    }
}
bool DeleteClientByAccountNumber(string AccountNumber, vector<sClient> &vClient)
{
    char Chose;
    sClient Client;
    if (FindClientByAccountNumber(AccountNumber, vClient, Client))
    {
        PrintClientCard(Client);
        cout << "\n\nAre you sure you want delete this client? y/n ?";
        cin >> Chose;
        if (tolower(Chose) == 'y')
        {

            MarkClientForDeleteByAccountNumber(AccountNumber, vClient);
            SaveClientDataToFile(vClient, FileName);
            /* vector<sClient>::iterator iter;
             for (iter = vClient.begin(); iter != vClient.end();)
             {
                 if (iter->AccountNumber == AccountNumber)
                 {
                     iter = vClient.erase(iter);
                     SaveClientDataToFile(vClient, FileName);
                     return true;
                 }
                 else
                     iter++;
             }
             return false;*/
            vClient = LoadClientDataFromFile(FileName);
            cout << "\nClient Deleted successfully";
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
    DeleteClientByAccountNumber(AccountNumber, vClient);
    return 0;
}
