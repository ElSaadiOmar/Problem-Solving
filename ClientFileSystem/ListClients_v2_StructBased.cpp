// Problem: Read all clients from the file and print them as a formatted table.
// Refined version: parses every line into a client struct before printing.

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

void PrintClientRecord(sClient Client)
{

    cout << "| " << left << setw(16) << Client.AccountNumber;
    cout << "| " << left << setw(10) << Client.PinCode;
    cout << "| " << left << setw(26) << Client.Name;
    cout << "| " << left << setw(11) << Client.Phon;
    cout << "| " << left << Client.AccountBalance;
}
void PrintAllClientsData(vector<sClient> &Client)
{
    cout << "\t\t\tClient List (" << Client.size() << ") Client(s)." << endl;
    cout << string(84, '_') << endl
         << endl;
    cout << "| Account Number  ";
    cout << "| Pin Code  ";
    cout << "| Name Client" << string(15, ' ');
    cout << "| Phon" << string(7, ' ');
    cout << "| Balance" << endl;
    cout << string(84, '_') << endl;
    for (sClient &RecRdClint : Client)
    {
        PrintClientRecord(RecRdClint);
        cout << endl;
    }
    cout << string(84, '_') << endl
         << endl;
}
int main()
{
    system("cls");
    vector<sClient> vClient = LoadClientDataFromFile(FileName);
    PrintAllClientsData(vClient);
    return 0;
}
