// Mini Project: Full client management system with a menu (list/add/delete/update/find).
// Combines every operation above (P45-P51) into one complete program.

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
enum enMainMenuOptions
{
    eClientList = 1,
    eAddClient = 2,
    eDeleteCLient = 3,
    eUpdateClient = 4,
    eFindClient = 5,
    eExit = 6,
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
string ConvertRecordToLine(sClient Info, string Delim = "#//#")
{
    string stClientRecord = "";
    stClientRecord += Info.AccountNumber + Delim;
    stClientRecord += Info.PinCode + Delim;
    stClientRecord += Info.Name + Delim;
    stClientRecord += Info.Phon + Delim;
    stClientRecord += to_string(Info.AccountBalance);
    return stClientRecord;
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
bool ClientExistsByAccountNumber(string AccountNum)
{
    vector<sClient> vClient;
    fstream MyFile;
    MyFile.open(FileName, ios::in);
    if (MyFile.is_open())
    {
        string Line;
        sClient Client;
        while (getline(MyFile, Line))
        {
            Client = ConvertLinetoRecord(Line);
            if (Client.AccountNumber == AccountNum)
            {
                MyFile.close();
                return true;
            }
        }
        MyFile.close();
    }
    return false;
}
string ReadAccountNumber()
{
    string AccountNumber;
    cout << "\nEnter Account Number? ";
    cin >> AccountNumber;
    return AccountNumber;
}

vector<string> SplitFileToLine()
{
    vector<string> vLine;
    fstream MyFile;
    MyFile.open(FileName, ios::in);
    if (MyFile.is_open())
    {
        string Line;
        while (getline(MyFile, Line))
        {
            vLine.push_back(Line);
        }
        MyFile.close();
    }
    return vLine;
}
void PrintLine(sClient Client)
{
    cout << "| " << left << setw(16) << Client.AccountNumber;
    cout << "| " << left << setw(10) << Client.PinCode;
    cout << "| " << left << setw(26) << Client.Name;
    cout << "| " << left << setw(11) << Client.Phon;
    cout << "| " << left << Client.AccountBalance;
}
void PrintClientsRecord()
{
    vector<sClient> vClients = LoadClientDataFromFile(FileName);

    cout << "\t\t\tClient List (" << vClients.size() << ") Client(s)." << endl;
    cout << string(84, '_') << endl
         << endl;
    cout << "| Account Number  ";
    cout << "| Pin Code  ";
    cout << "| Name Client" << string(15, ' ');
    cout << "| Phon" << string(7, ' ');
    cout << "| Balance" << endl;
    cout << string(84, '_') << endl;
    if (vClients.size() == 0)
        cout << "\t\t\tNo Client Available In The System";
    else
    {
        for (sClient Client : vClients)
        {
            PrintLine(Client);
            cout << endl;
        }
    }
    cout << string(84, '_') << endl
         << endl;
}
void ShowClientScreen()
{
    
    cout << "\n-------------------------------------------" << endl;
    cout << "\tClient Screen";
    cout << "\n-------------------------------------------" << endl;
    PrintClientsRecord();
}

sClient ReadNewClient()
{

    sClient Info;
    cout << "Enter Account Number? ";
    getline(cin >> ws, Info.AccountNumber);
    while (ClientExistsByAccountNumber(Info.AccountNumber))
    {
        cout << "Client With [" << Info.AccountNumber << "] already exists,Enter another Account Number? ";
        getline(cin >> ws, Info.AccountNumber);
    }

    cout << "\nEnter Pin Code? ";
    getline(cin >> ws, Info.PinCode);

    cout << "\nEnter Name? ";
    getline(cin, Info.Name);

    cout << "\nEnter Phon Number? ";
    getline(cin, Info.Phon);

    cout << "\nEnter Account Balance? ";
    cin >> Info.AccountBalance;
    return Info;
}
void AddDataLineToFile(string FileName, string stClientLine)
{
    fstream MyFile;
    MyFile.open(FileName, ios::out | ios::app);
    if (MyFile.is_open())
    {
        MyFile << stClientLine << endl;
        MyFile.close();
    }
}
void AddNewClient()
{
    sClient Client;
    Client = ReadNewClient();
    AddDataLineToFile("ClientRecord.txt", ConvertRecordToLine(Client));
}
void AddNewClients()
{
    char AddMore = 'Y';
    do
    {
        cout << "Adding New Client:" << endl;
        AddNewClient();
        cout << "\n\nClient Added Successfully, do you want to add more client? Y/N? " << endl;
        cin >> AddMore;
    } while (toupper(AddMore) == 'Y');
}
void ShowAddClientsScreen()
{

    cout << "\n-------------------------------------------" << endl;
    cout << "\tAdding New Client";
    cout << "\n-------------------------------------------" << endl;
    AddNewClients();
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
            vClient = LoadClientDataFromFile(FileName);
            cout << "\nClient Deleted successfully" << endl;
            return true;
        }
    }
    else
    {
        cout << "\nClient with Account Number (" << AccountNumber << ") Not Found!" << endl;
        return false;
    }
}
void ShowDeleteClientScreen()
{
    cout << "\n-------------------------------------------" << endl;
    cout << "\tDelete Client";
    cout << "\n-------------------------------------------" << endl;

    vector<sClient> vClient = LoadClientDataFromFile(FileName);
    string AccountNumber = ReadAccountNumber();
    DeleteClientByAccountNumber(AccountNumber, vClient);
}

sClient ChangeClientRecord(string AccountNumber)
{
    sClient Client;
    Client.AccountNumber = AccountNumber;

    cout << "\nEnter Pin Code? ";
    getline(cin >> ws, Client.PinCode);

    cout << "\nEnter Name? ";
    getline(cin, Client.Name);

    cout << "\nEnter Phon Number? ";
    getline(cin, Client.Phon);

    cout << "\nEnter Account Balance? ";
    cin >> Client.AccountBalance;
    return Client;
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

            for (sClient &C : vClient)
            {
                if (C.AccountNumber == AccountNumber)
                {
                    C = ChangeClientRecord(AccountNumber);
                    break;
                }
            }
            SaveClientDataToFile(vClient, FileName);
            cout << "\nClient Update successfully" << endl;
            return true;
        }
    }
    else
    {
        cout << "\nClient with Account Number (" << AccountNumber << ") Not Found!" << endl;
        return false;
    }
}
void ShowUpdateClientScreen()
{
    cout << "\n-------------------------------------------" << endl;
    cout << "\tUpdate Client";
    cout << "\n-------------------------------------------" << endl;
    vector<sClient> vClient = LoadClientDataFromFile(FileName);
    string AccountNumber = ReadAccountNumber();
    UpdateClientByAccountNumber(AccountNumber, vClient);
}

void ShowFindClientScreen()
{
    cout << "\n-------------------------------------------" << endl;
    cout << "\tFind Client";
    cout << "\n-------------------------------------------" << endl;
    vector<sClient> vClient = LoadClientDataFromFile(FileName);
    string AccountNumber = ReadAccountNumber();
    sClient Client;
    if (FindClientByAccountNumber(AccountNumber, vClient,Client))
        PrintClientCard(Client);
    else
        cout << "\nClient with Account Number (" << AccountNumber << ") Not Found!" << endl;
}

void ShowEndScreen()
{

    cout << "\n-------------------------------------------" << endl;
    cout << "\tEnd Program";
    cout << "\n-------------------------------------------" << endl;
}
void ShowMainMenuScreen();
void GoBackToMainMenu()
{
    cout << "\n\nPress any key to back Main Menu...";
    system("pause>0");
    ShowMainMenuScreen();
}
short ReadMainMenuOption()
{
    short Choose = 0;
    cout << "Choose What do you went to do? [1 to 6]? ";
    cin >> Choose;
    return Choose;
}

void PerfromMainMenuOption(enMainMenuOptions MainMenuOptions)
{

    switch (MainMenuOptions)
    {
    case enMainMenuOptions::eClientList:
        system("cls");
        ShowClientScreen();
        GoBackToMainMenu();
        break;

    case enMainMenuOptions::eAddClient:
        system("cls");
        ShowAddClientsScreen();
        GoBackToMainMenu();
        break;
    case enMainMenuOptions::eDeleteCLient:
        system("cls");
        ShowDeleteClientScreen();
        GoBackToMainMenu();
        break;
    case enMainMenuOptions::eUpdateClient:
        system("cls");
        ShowUpdateClientScreen();
        GoBackToMainMenu();
        break;
    case enMainMenuOptions::eFindClient:
        system("cls");
        ShowFindClientScreen();
        GoBackToMainMenu();
        break;
    case enMainMenuOptions::eExit:
        system("cls");
        ShowEndScreen();
        break;
    }
}
void ShowMainMenuScreen()
{
    system("cls");
    cout << "======================================" << endl;
    cout << "\t\tMain Menu Screen" << endl;
    cout << "======================================" << endl;
    cout << "\t[1] Show Client List." << endl;
    cout << "\t[2] Add New Client." << endl;
    cout << "\t[3] Delete Client." << endl;
    cout << "\t[4] Update Client Info." << endl;
    cout << "\t[5] Find Clinet." << endl;
    cout << "\t[6] Exit." << endl;
    cout << "======================================" << endl;
    PerfromMainMenuOption((enMainMenuOptions)ReadMainMenuOption());
}
int main()
{
    ShowMainMenuScreen();
    return 0;
}
