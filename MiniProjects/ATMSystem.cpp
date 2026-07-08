// Mini Project: ATM simulation system.
// Supports login, quick/normal withdraw, deposit, and balance check, backed by a text file.

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;
const string ClientFile = "ClientRecord.txt";
struct stClient
{
    string AccountNumber;
    string PinCode;
    string Name;
    string Phon;
    double AccountBalance;
    bool MarkForDelete = false;
};
enum enATMMainMenu
{
    eQuickWithdraw = 1,
    eNormalWithdraw = 2,
    eDeposit = 3,
    eCheckBalance = 4,
    eLogout = 5,
};
enum enQuickWithdraw
{
    e20 = 1,
    e50 = 2,
    e100 = 3,
    e200 = 4,
    e400 = 5,
    e600 = 6,
    e800 = 7,
    e1000 = 8,
    eExit = 9,
};
stClient CurrentClient;
void ShowATMMenuScreen();
void GoBackToATMMainMenu();
void ShowQuickWithdrawScreen();
void ShowNormalWithdrawScreen();
void Login();
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
stClient ConvertLineToRecord(string Line, string Spliter = "#//#")
{
    stClient ClientInfo;
    vector<string> vInfo = SplitString(Line, Spliter);
    if (vInfo.size() != 5)
    {
        cout << "Error: Corrupted Client data in file.\n";
        exit(1);
    }
    ClientInfo.AccountNumber = vInfo[0];
    ClientInfo.PinCode = vInfo[1];
    ClientInfo.Name = vInfo[2];
    ClientInfo.Phon = vInfo[3];
    ClientInfo.AccountBalance = stod(vInfo[4]);
    return ClientInfo;
}
string ConvertRecordToLine(stClient Info, string Delim = "#//#")
{
    string stClientRecord = "";
    stClientRecord += Info.AccountNumber + Delim;
    stClientRecord += Info.PinCode + Delim;
    stClientRecord += Info.Name + Delim;
    stClientRecord += Info.Phon + Delim;
    stClientRecord += to_string(Info.AccountBalance);
    return stClientRecord;
}
vector<stClient> LoadClientDataFromFile(string FileName)
{
    vector<stClient> vClients;
    fstream MyFile;
    MyFile.open(FileName, ios::in);
    if (MyFile.is_open())
    {
        string Line;
        stClient Client;
        while (getline(MyFile, Line))
        {
            Client = ConvertLineToRecord(Line);
            vClients.push_back(Client);
        }
        MyFile.close();
    }
    return vClients;
}
vector<stClient> SaveClientsDataToFile(string FileName, vector<stClient> vClients)
{
    fstream MyFile;
    MyFile.open(FileName, ios::out); // overwrite
    string DataLine;
    if (MyFile.is_open())
    {
        for (stClient C : vClients)
        {
            if (C.MarkForDelete == false)
            {
                DataLine = ConvertRecordToLine(C);
                MyFile << DataLine << endl;
            }
        }
        MyFile.close();
    }
    return vClients;
}
bool DepositBalanceToClientByAccountNumber(string AccountNumber, double Amount, vector<stClient> &vClients)
{
    char Answer = 'n';
    cout << "\n\nAre you sure you want perfrom this transaction? y/n? ";
    cin >> Answer;
    if (Answer == 'y' || Answer == 'Y')
    {
        for (stClient &C : vClients)
        {
            if (C.AccountNumber == AccountNumber)
            {
                C.AccountBalance += Amount;
                SaveClientsDataToFile(ClientFile, vClients);
                cout << "\n\nDone Successfully. New balance is: "
                     << C.AccountBalance;
                return true;
            }
        }

    }
    return false;
}

bool FindClientByAccountNumberAndPinCode(string AccountNumber, string PINCode, stClient &Client)
{
    vector<stClient> vClients = LoadClientDataFromFile(ClientFile);
    for (stClient &C : vClients)
    {
        if (C.AccountNumber == AccountNumber && C.PinCode == PINCode)
        {
            Client = C;
            return true;
        }
    }
    return false;
}
void ShowBalance()
{
    cout << "You Balance is " << CurrentClient.AccountBalance << endl;
}
void GoBackToATMMainMenu()
{
    cout << "\n\nPress any key to go back to ATM Main Menu...";
    system("pause>0");
    ShowATMMenuScreen();
}
short ReadATMMenuOption()
{
    short Choose = 0;
    cout << "Choose What do you want to do? [1 to 5]? ";
    cin >> Choose;
    while (Choose > 5 || Choose < 1)
    {
        cout << "Invalid Choose\nChoose What do you want to do? [1 to 5]? ";
        cin >> Choose;
    }
    return Choose;
}

short getQuickWithDrawAmount(short QuickWithDrawOption)
{
    switch (QuickWithDrawOption)
    {
    case 1:
        return 20;
    case 2:
        return 50;
    case 3:
        return 100;
    case 4:
        return 200;
    case 5:
        return 400;
    case 6:
        return 600;
    case 7:
        return 800;
    case 8:
        return 1000;
    default:
        return 0;
    }
}
void PerfromQuickWithdrawOption(short QuickWithDrawOption)
{
    if (QuickWithDrawOption == 9) // exit
        return;
    short WithDrawBalance = getQuickWithDrawAmount(QuickWithDrawOption);
    if (WithDrawBalance > CurrentClient.AccountBalance)
    {
        cout << "\nThe amount exceeds your balance, make another choice.\n ";
        cout << "Press Anykey to continue...";
        system("pause>0");
        ShowQuickWithdrawScreen();
        return;
    }
    vector<stClient> vClients = LoadClientDataFromFile(ClientFile);
    DepositBalanceToClientByAccountNumber(CurrentClient.AccountNumber, WithDrawBalance * -1, vClients);
    CurrentClient.AccountBalance -= WithDrawBalance;
}
short ReadQuickWithdrawOption()
{
    short Choose = 0;
    cout << "Choose What to withdraw from[1] to [9]] ? ";
    cin >> Choose;
    while (Choose > 9 || Choose < 1)
    {
        cout << "Invalid Choose\nChoose What to withdraw from[1] to [9]] ? ";
        cin >> Choose;
    }
    return Choose;
}
void ShowQuickWithdrawChoose()
{
    cout << "\t[1] 20 \t[2] 50\n";
    cout << "\t[3] 100\t[4] 200\n";
    cout << "\t[5] 400\t[6] 600\n";
    cout << "\t[7] 800\t[8] 1000\n";
    cout << "\t[9] Exit\n";
}
void ShowQuickWithdrawScreen()
{
    cout << "========================================================" << endl;
    cout << "\t\tQuick Withdraw" << endl;
    cout << "========================================================" << endl;
    ShowQuickWithdrawChoose();
    cout << "========================================================" << endl;
    ShowBalance();
    PerfromQuickWithdrawOption(ReadQuickWithdrawOption());
}

bool IsMultipleOfXNumber(int Number, int XNumber)
{
    return (Number % XNumber == 0);
}
void NormalWithdrawToAccount()
{
    int WithdrawAmount = 0;
    do
    {
        cout << "\nEnter an amount multiple of 5's ? ";
        cin >> WithdrawAmount;
    } while (!IsMultipleOfXNumber(WithdrawAmount, 5));

    char AreSure = 'y';
    if (WithdrawAmount > CurrentClient.AccountBalance)
    {
        cout << "\nThe Amount Exceeds your balance, make another choice.\n";
        cout << "Press anykey to continue.....";
        system("pause>0");
        ShowNormalWithdrawScreen();
        return;
    }
    vector<stClient> vClients = LoadClientDataFromFile(ClientFile);
    DepositBalanceToClientByAccountNumber(CurrentClient.AccountNumber, WithdrawAmount * -1, vClients);
    CurrentClient.AccountBalance -= WithdrawAmount;
}
void ShowNormalWithdrawScreen()
{

    cout << "========================================================" << endl;
    cout << "\t\tNormal Withdraw Screen" << endl;
    cout << "========================================================" << endl;
    NormalWithdrawToAccount();
}

void DepositToAccount()
{
    double DepositAmount = 0;
    do
    {
        cout << "Enter a positive Deposit Amount? ";
        cin >> DepositAmount;
    } while (DepositAmount <= 0);
    vector<stClient> vClients = LoadClientDataFromFile(ClientFile);
    DepositBalanceToClientByAccountNumber(CurrentClient.AccountNumber, DepositAmount, vClients);
    CurrentClient.AccountBalance += DepositAmount;
}
void ShowDepositScreen()
{

    cout << "========================================================" << endl;
    cout << "\t\tDeposit Screen" << endl;
    cout << "========================================================" << endl;
    DepositToAccount();
}

void ShowCheckBalanceScreen()
{
    cout << "========================================================" << endl;
    cout << "\t\tCheck Balance Screen" << endl;
    cout << "========================================================" << endl;
    ShowBalance();
}
void PerfromATMMainMenuOption(enATMMainMenu ATMMainMenuOption)
{
    switch (ATMMainMenuOption)
    {
    case (enATMMainMenu::eQuickWithdraw):
        system("cls");
        ShowQuickWithdrawScreen();
        GoBackToATMMainMenu();
        break;
    case (enATMMainMenu::eNormalWithdraw):
        system("cls");
        ShowNormalWithdrawScreen();
        GoBackToATMMainMenu();
        break;
    case (enATMMainMenu::eDeposit):
        system("cls");
        ShowDepositScreen();
        GoBackToATMMainMenu();
        break;
    case (enATMMainMenu::eCheckBalance):
        system("cls");
        ShowCheckBalanceScreen();
        GoBackToATMMainMenu();
        break;
    case (enATMMainMenu::eLogout):
        system("cls");
        Login();
        break;
    }
}
void ShowATMMenuScreen()
{
    system("cls");
    cout << "========================================================" << endl;
    cout << "\t\tATM Main Menu Screen\n";
    cout << "========================================================" << endl;
    cout << "\t[1] Quick Withdraw.\n";
    cout << "\t[2] Normal Withdraw.\n";
    cout << "\t[3] Deposit.\n";
    cout << "\t[4] Check Balance.\n";
    cout << "\t[5] Logout.\n";
    cout << "========================================================" << endl;
    PerfromATMMainMenuOption((enATMMainMenu)ReadATMMenuOption());
}
void ShowLoginScreen()
{
    system("cls");
    cout << "========================================================" << endl;
    cout << "\t\tLogin Screen" << endl;
    cout << "========================================================" << endl;
}
void Login()
{
    bool LoginFailed = false;
    stClient Client;
    do
    {
        ShowLoginScreen();
        if (LoginFailed)
        {
            cout << "Invalid Account Number/PinCode!\n";
        }
        cout << "Enter Account Number? ";
        getline(cin >> ws, Client.AccountNumber);
        cout << "Enter Pin Code? ";
        getline(cin >> ws, Client.PinCode);
        LoginFailed = !FindClientByAccountNumberAndPinCode(Client.AccountNumber, Client.PinCode, Client);
    } while (LoginFailed);
    CurrentClient = Client;
    ShowATMMenuScreen();
}
int main()
{
    Login();
    return 0;
}