// Mini Project: Extended bank system with client and user management (base version).
// Covers client CRUD, user accounts, and transactions, before permission checks were added.

#include <iostream>
#include <ctime>
#include <cmath>
#include <vector>
#include <fstream>
#include <string>
#include <iomanip>
#include <limits>
using namespace std;
const string ClientFile = "ClientRecord.txt";
const string UserFile = "User.txt";
const int FULLAccess = -1;
struct sClient
{
    string AccountNumber;
    string PinCode;
    string Name;
    string Phon;
    double AccountBalance;
    bool MarkForDelete = false;
};
struct sUser
{
    string UserName;
    string Password;
    short Access;
    bool MarkForDelete = false;
};
enum enMainMenuOptions
{
    eClientList = 1,
    eAddClient = 2,
    eDeleteCLient = 3,
    eUpdateClient = 4,
    eFindClient = 5,
    eTransaction = 6,
    eMangeUser = 7,
    eLogout = 8,
};
enum enTransactionMenuOption
{
    eDeposit = 1,
    eWithdraw = 2,
    eTotalBalance = 3,
    eMainMenu = 4,
};
enum enMangeUserMenuOption
{
    eUserList = 1,
    eAddUser = 2,
    eDeleteUser = 3,
    eUpdateUser = 4,
    eFindUser = 5,
    eMangeToMainMenu = 6,
};
enum enMainMenuPermission
{
    pListClients = 1,
    pAddNewClient = 2,
    pDeleteClient = 4,
    pUpdateClients = 8,
    pFindClient = 16,
    pTransactions = 32,
    pManageUsers = 64,
};
sUser CurrentUser;
void GoBackToMainMenu();
void ShowMainMenuScreen();
void ShowTransactionMenuScreen();
void ShowMangeUserMenuScreen();
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
sClient ConvertLinetoRecord(string Line, string Spliter = "#//#")
{
    sClient Info;
    vector<string> vInfo = SplitString(Line, Spliter);
    if (vInfo.size() != 5)
    {
        cout << "Error: Corrupted Client data in file.\n";
        exit(1);
    }
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

sUser ConvertLinetoRecordOfUser(string Line, string Spliter = "#//#")
{
    sUser UserInfo;
    vector<string> vInfo = SplitString(Line, Spliter);
    if (vInfo.size() != 3)
    {
        cout << "Error: Corrupted User data in file.\n";
        exit(1);
    }
    UserInfo.UserName = vInfo[0];
    UserInfo.Password = vInfo[1];
    UserInfo.Access = stoi(vInfo[2]);
    return UserInfo;
}
string ConvertRecordToLineOfUser(sUser User, string Delim = "#//#")
{
    string stUserRecord = "";
    stUserRecord += User.UserName + Delim;
    stUserRecord += User.Password + Delim;
    stUserRecord += to_string(User.Access);
    return stUserRecord;
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
bool ClientExistsByAccountNumber(string AccountNum, string FileName)
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

vector<string> SplitFileToLine(string FileName)
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
void PrintClientLine(sClient Client)
{
    cout << "| " << left << setw(16) << Client.AccountNumber;
    cout << "| " << left << setw(10) << Client.PinCode;
    cout << "| " << left << setw(26) << Client.Name;
    cout << "| " << left << setw(11) << Client.Phon;
    cout << "| " << left << Client.AccountBalance;
}
void PrintClientsRecord()
{
    vector<sClient> vClients = LoadClientDataFromFile(ClientFile);

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
            PrintClientLine(Client);
            cout << endl;
        }
    }
    cout << string(84, '_') << endl
         << endl;
}
void ShowClientScreen()
{
    cout << string(84, '_') << endl
         << endl;
    cout << "\t\t\t\tClient Screen\n";
    cout << string(84, '_') << endl
         << endl;
    PrintClientsRecord();
}

sClient ReadNewClient()
{

    sClient Info;
    cout << "Enter Account Number? ";
    getline(cin >> ws, Info.AccountNumber);
    while (ClientExistsByAccountNumber(Info.AccountNumber, ClientFile))
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
    cout << "\nThe following are the client details:\n";
    cout << "-------------------------------------\n";
    cout << "\nAcount Number : " << Info.AccountNumber;
    cout << "\nPin Code      : " << Info.PinCode;
    cout << "\nName          : " << Info.Name;
    cout << "\nPhon          : " << Info.Phon;
    cout << "\nAcount Balance: " << Info.AccountBalance;
    cout << "\n-------------------------------------\n";
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
bool DeleteClientByAccountNumber(string AccountNumber, vector<sClient> &vClient, string FileName)
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
            vClient = LoadClientDataFromFile(ClientFile);
            cout << "\nClient Deleted successfully" << endl;
            return true;
        }
        else
            return false;
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

    vector<sClient> vClient = LoadClientDataFromFile(ClientFile);
    string AccountNumber = ReadAccountNumber();
    DeleteClientByAccountNumber(AccountNumber, vClient, ClientFile);
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
bool UpdateClientByAccountNumber(string AccountNumber, vector<sClient> &vClient, string FileName)
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
        else
            return false;
    }
    else
    {
        cout << "\nClient with Account Number (" << AccountNumber << ") Not Found!" << endl;
        return false;
    }
    return false;
}

void ShowUpdateClientScreen()
{
    cout << "\n-------------------------------------------" << endl;
    cout << "\tUpdate Client";
    cout << "\n-------------------------------------------" << endl;
    vector<sClient> vClient = LoadClientDataFromFile(ClientFile);
    string AccountNumber = ReadAccountNumber();
    UpdateClientByAccountNumber(AccountNumber, vClient, ClientFile);
}

void ShowFindClientScreen()
{
    cout << "\n-------------------------------------------" << endl;
    cout << "\tFind Client";
    cout << "\n-------------------------------------------" << endl;
    vector<sClient> vClient = LoadClientDataFromFile(ClientFile);
    string AccountNumber = ReadAccountNumber();
    sClient Client;
    if (FindClientByAccountNumber(AccountNumber, vClient, Client))
        PrintClientCard(Client);
    else
        cout << "\nClient with Account Number (" << AccountNumber << ") Not Found!" << endl;
}

void DepositToAccount(string AccountNumber, vector<sClient> &vClient, string FileName)
{
    sClient Client;
    int DepositAmount = 0;
    while (!(FindClientByAccountNumber(AccountNumber, vClient, Client)))
    {
        cout << "\nClient withe [" << AccountNumber << "] does not exist.";
        AccountNumber = ReadAccountNumber();
    }
    PrintClientCard(Client);
    cout << "Please enter deposit amount? ";
    cin >> DepositAmount;

    char AreSure = 'y';
    cout << "\n\nAre you sure want perform this transaction? y/n ? ";
    cin >> AreSure;
    if (towlower(AreSure) == 'y')
    {

        for (sClient &C : vClient)
        {
            if (C.AccountNumber == AccountNumber)
            {
                C.AccountBalance += DepositAmount;
                SaveClientDataToFile(vClient, FileName);
                cout << "\nClient Deposit successfully, New balance is:" << C.AccountBalance << endl;
                break;
            }
        }
    }
}
void ShowDepositScreen()
{
    cout << "\n-------------------------------------------" << endl;
    cout << "\tDeposit Screen";
    cout << "\n-------------------------------------------" << endl;
    vector<sClient> vClient = LoadClientDataFromFile(ClientFile);
    string AccountNumber = ReadAccountNumber();
    DepositToAccount(AccountNumber, vClient, ClientFile);
}

void WithdrawToAccount(string AccountNumber, vector<sClient> &vClient, string FileName)
{
    sClient Client;
    int WithdrawAmount = 0;
    char AreSure = 'y';
    while (!(FindClientByAccountNumber(AccountNumber, vClient, Client)))
    {
        cout << "\nClient withe [" << AccountNumber << "] does not exist.";
        AccountNumber = ReadAccountNumber();
    }
    PrintClientCard(Client);
    cout << "Please enter Withdraw amount? ";
    cin >> WithdrawAmount;
    while (WithdrawAmount > Client.AccountBalance)
    {
        cout << "Amount Exceeds the balance, you can withdraw up to : " << Client.AccountBalance;
        cout << "\nplease enter another amount?";
        cin >> WithdrawAmount;
    }
    cout << "\n\nAre you sure want perform this transaction? y/n ? ";
    cin >> AreSure;
    if (towlower(AreSure) == 'y')
    {

        for (sClient &C : vClient)
        {
            if (C.AccountNumber == AccountNumber)
            {
                C.AccountBalance -= WithdrawAmount;
                SaveClientDataToFile(vClient, FileName);
                cout << "\nClient Withdraw successfully, New Balance is :" << Client.AccountBalance << endl;
                break;
            }
        }
    }
}
void ShowWithdrawScreen()
{
    cout << "\n-------------------------------------------" << endl;
    cout << "\tWithdraw Screen";
    cout << "\n-------------------------------------------" << endl;
    vector<sClient> vClient = LoadClientDataFromFile(ClientFile);
    string AccountNumber = ReadAccountNumber();
    WithdrawToAccount(AccountNumber, vClient, ClientFile);
}

void ShowTotalBalancesScreen()
{
    vector<sClient> vClient = LoadClientDataFromFile(ClientFile);
    double TotalBalance = 0;
    cout << "\t\t\t\tBalances List (" << vClient.size() << ") Client(s)." << endl;
    cout << string(90, '_') << endl
         << endl;
    cout << "| " << left << setw(16) << "Account Number";
    cout << "| " << left << setw(35) << "Client Name";
    cout << "| Balance" << endl;
    cout << string(90, '_') << endl
         << endl;
    if (vClient.size() == 0)
        cout << "\t\t\t\tNo Clients Available In the System!";
    else
    {
        for (sClient &C : vClient)
        {
            cout << "| " << left << setw(16) << C.AccountNumber;
            cout << "| " << left << setw(35) << C.Name;
            cout << "| " << C.AccountBalance << endl;
            TotalBalance += C.AccountBalance;
        }
        cout << string(90, '_') << endl;
        cout << "\n\t\t\t\tTotal Balance = " << TotalBalance;
    }
}

short ReadTransactionMenuOption()
{
    short Choose = 0;
    cout << "Choose What do you went to do? [1 to 4]? ";
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    cin >> Choose;
    while (cin.fail() || Choose <= 0 || Choose > 4)
    {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Invalid Choice.";
        cout << "\nPlease enter a number between 1 and 4. ";
        cin >> Choose;
    }
    return Choose;
}
void GoBackToTransactionMenu()
{
    cout << "\n\nPress any key to go back to Transaction Menu...";
    system("pause>0");
    ShowTransactionMenuScreen();
}
void PerfromTransactionMenuOption(enTransactionMenuOption TransactionMenuOptions)
{
    switch (TransactionMenuOptions)
    {
    case enTransactionMenuOption::eDeposit:
        system("cls");
        ShowDepositScreen();
        GoBackToTransactionMenu();
        break;
    case enTransactionMenuOption::eWithdraw:
        system("cls");
        ShowWithdrawScreen();
        GoBackToTransactionMenu();
        break;
    case enTransactionMenuOption::eTotalBalance:
        system("cls");
        ShowTotalBalancesScreen();
        GoBackToTransactionMenu();
        break;
    case enTransactionMenuOption::eMainMenu:
        system("cls");
        ShowMainMenuScreen();
        break;
    }
}
void ShowTransactionMenuScreen()
{
    system("cls");
    cout << "========================================================" << endl;
    cout << "\t\tTransaction Menu Screen" << endl;
    cout << "========================================================" << endl;
    cout << "\t[1] Deposit." << endl;
    cout << "\t[2] Withdraw." << endl;
    cout << "\t[3] Total Balance." << endl;
    cout << "\t[4] Main Menu." << endl;
    cout << "========================================================" << endl;
    PerfromTransactionMenuOption((enTransactionMenuOption)ReadTransactionMenuOption());
}

bool FindUserByUserName(string UserName, vector<sUser> vUser, sUser &User)
{
    for (sUser &U : vUser)
    {
        if (U.UserName == UserName)
        {
            User = U;
            return true;
        }
    }
    return false;
}
bool UserExistsByUserName(string UserName, string NameOfFile)
{
    vector<sUser> vUser;
    fstream MyFile;
    MyFile.open(NameOfFile, ios::in);
    if (MyFile.is_open())
    {
        string Line;
        sUser UserOfFile;
        while (getline(MyFile, Line))
        {
            UserOfFile = ConvertLinetoRecordOfUser(Line);
            if (UserOfFile.UserName == UserName)
            {
                MyFile.close();
                return true;
            }
        }
        MyFile.close();
    }
    return false;
}
vector<sUser> LoadUserDataFromUserFile(string FileName)
{
    vector<sUser> vUsers;
    fstream MyFile;
    MyFile.open(FileName, ios::in);
    if (MyFile.is_open())
    {
        string Line;
        sUser User;
        while (getline(MyFile, Line))
        {
            User = ConvertLinetoRecordOfUser(Line);
            vUsers.push_back(User);
        }
        MyFile.close();
    }
    return vUsers;
}

void PrintUserLine(sUser User)
{
    cout << "| " << left << setw(20) << User.UserName;
    cout << "| " << left << setw(20) << User.Password;
    cout << "| " << User.Access;
}
void PrintUsersRecord()
{
    vector<sUser> vUser = LoadUserDataFromUserFile(UserFile);

    cout << "\t\t\tUser List (" << vUser.size() << ") User(s)." << endl;

    cout << string(84, '_') << endl
         << endl;

    cout << "| " << left << setw(20) << "User Name  ";
    cout << "| " << left << setw(20) << "Passwrd  ";
    cout << "| Permissions" << endl;

    cout << string(84, '_') << endl;

    if (vUser.size() == 0)
        cout << "\t\t\tNo User Available In The System";
    else
    {
        for (sUser User : vUser)
        {
            PrintUserLine(User);
            cout << endl;
        }
    }
    cout << string(84, '_') << endl
         << endl;
}
void ShowUserScreen()
{

    cout << string(84, '_') << endl
         << endl;
    cout << "\t\t\t\tUser Screen\n";
    cout << string(84, '_') << endl
         << endl;
    PrintUsersRecord();
}

short ReadPermission()
{
    char answer = 'n';
    short Permissions = 0;
    cout << "\nDo you went to give full access? y/n? ";
    cin >> answer;
    if (tolower(answer) == 'y')
        return FULLAccess;
    else
    {
        cout << "\nDo you went give access to :\n\n";
        cout << "\nShow Client List? y/n? ";
        cin >> answer;
        if (tolower(answer) == 'y')
            Permissions = Permissions | enMainMenuPermission::pListClients;
        cout << "\nAdd New Client? y/n? ";
        cin >> answer;
        if (tolower(answer) == 'y')
            Permissions = Permissions | enMainMenuPermission::pAddNewClient;
        cout << "\nDelete Client? y/n? ";
        cin >> answer;
        if (tolower(answer) == 'y')
            Permissions = Permissions | enMainMenuPermission::pDeleteClient;
        cout << "\nUpdate Client? y/n? ";
        cin >> answer;
        if (tolower(answer) == 'y')
            Permissions = Permissions | enMainMenuPermission::pUpdateClients;
        cout << "\nFind Client? y/n? ";
        cin >> answer;
        if (tolower(answer) == 'y')
            Permissions = Permissions | enMainMenuPermission::pFindClient;
        cout << "\nTransactions? y/n? ";
        cin >> answer;
        if (tolower(answer) == 'y')
            Permissions = Permissions | enMainMenuPermission::pTransactions;
        cout << "\nMange Users? y/n? ";
        cin >> answer;
        if (tolower(answer) == 'y')
            Permissions = Permissions | enMainMenuPermission::pManageUsers;
    }
    return Permissions;
}
sUser ReadNewUser()
{
    sUser User;
    cout << "Enter UserName? ";
    getline(cin >> ws, User.UserName);
    while (UserExistsByUserName(User.UserName, UserFile))
    {
        cout << "User With [" << User.UserName << "] already exists,Enter another UserName? ";
        getline(cin >> ws, User.UserName);
    }
    cout << "Enter Password? ";
    getline(cin, User.Password);
    User.Access = ReadPermission();
    return User;
}
void AddNewUser()
{
    sUser User;
    User = ReadNewUser();
    AddDataLineToFile(UserFile, ConvertRecordToLineOfUser(User));
}
void AddNewUsers()
{
    char AddMore = 'Y';
    do
    {
        cout << "Adding New User:" << endl;
        AddNewUser();
        cout << "\n\nUser Added Successfully, do you want to add more User? Y/N? " << endl;
        cin >> AddMore;
    } while (toupper(AddMore) == 'Y');
}
void ShowAddUsersScreen()
{
    cout << string(84, '_') << endl
         << endl;
    cout << "\t\t\t\tAdd User Screen\n";
    cout << string(84, '_') << endl
         << endl;
    AddNewUsers();
}

void PrintUserCard(sUser UserInfo)
{
    cout << "\nThe following are the User details:\n";
    cout << "-------------------------------------\n";
    cout << "\nUser Name     : " << UserInfo.UserName;
    cout << "\nPassword      : " << UserInfo.Password;
    cout << "\nPermission    : " << UserInfo.Access;
    cout << "\n-------------------------------------\n";
}
bool MarkUserForDeleteByUserName(string UserName, vector<sUser> &vUser)
{
    for (sUser &U : vUser)
    {
        if (U.UserName == UserName)
        {
            U.MarkForDelete = true;
            return true;
        }
    }
    return false;
}
void SaveUserDataToFile(vector<sUser> &vUser, string FileName)
{
    fstream MyFile;
    MyFile.open(FileName, ios::out);

    if (MyFile.is_open())
    {
        string Line;
        for (sUser &U : vUser)
        {
            if (U.MarkForDelete == false)
                MyFile << ConvertRecordToLineOfUser(U) << endl;
        }
        MyFile.close();
    }
}
bool DeleteUserByUserName(string UserName, vector<sUser> &vUser, string FileName)
{
    char Chose;
    sUser User;
    if (FindUserByUserName(UserName, vUser, User))
    {
        PrintUserCard(User);
        if (User.UserName == "Admin")
        {
            cout << "\n\nYou cannot Delete This User.";
            return false;
        }
        else if(User.UserName==CurrentUser.UserName)
        {
            cout << "\n\nYou cannot Delete This User.";
            return false;
        }
        else
        {
            cout << "\n\nAre you sure you want delete this User? y/n ?";
            cin >> Chose;
            if (tolower(Chose) == 'y')
            {

                MarkUserForDeleteByUserName(UserName, vUser);
                SaveUserDataToFile(vUser, FileName);
                vUser = LoadUserDataFromUserFile(FileName);
                cout << "\n\nUser Deleted successfully" << endl;
                return true;
            }
            else
                return false;
        }
    }
    else
    {
        cout << "\nUser with User Name (" << UserName << ") Not Found!" << endl;
        return false;
    }
}
string ReadUserName()
{
    string UserName;
    cout << "Please Enter User Name? ";
    getline(cin >> ws, UserName);
    return UserName;
}
void ShowDeleteUserScreen()
{
    cout << "\n-------------------------------------------" << endl;
    cout << "\tDelete User";
    cout << "\n-------------------------------------------" << endl;

    vector<sUser> vUser = LoadUserDataFromUserFile(UserFile);
    string UserName = ReadUserName();
    DeleteUserByUserName(UserName, vUser, UserFile);
}
bool UpdateUserByUserName(string UserName, vector<sUser> &vUser, string FileName)
{
    sUser User;
    char Chose;
    if (FindUserByUserName(UserName, vUser, User))
    {
        PrintUserCard(User);
        cout << "\n\nAre you sure you want Update this User? y/n ?";
        cin >> Chose;
        if (tolower(Chose) == 'y')
        {
            for (sUser &U : vUser)
            {
                if (U.UserName == UserName)
                {
                    cout << "\n\nEnter Psswrd? ";
                    getline(cin >> ws, U.Password);
                    U.Access = ReadPermission();
                    break;
                }
            }
            SaveUserDataToFile(vUser, FileName);
            cout << "\n\nUser Update successfully" << endl;
            return true;
        }
        else
            return false;
    }
    else
    {
        cout << "\nUser with User Name (" << UserName << ") Not Found!" << endl;
        return false;
    }
}
void ShowUpdateUserScreen()
{
    cout << "\n-------------------------------------------" << endl;
    cout << "\tUpdate User";
    cout << "\n-------------------------------------------" << endl;

    vector<sUser> vUser = LoadUserDataFromUserFile(UserFile);
    string UserName = ReadUserName();
    UpdateUserByUserName(UserName, vUser, UserFile);
}

void ShowFindUserScreen()
{
    cout << "\n-------------------------------------------" << endl;
    cout << "\tFind User";
    cout << "\n-------------------------------------------" << endl;
    sUser User;
    vector<sUser> vUser = LoadUserDataFromUserFile(UserFile);
    string UserName = ReadUserName();
    if (FindUserByUserName(UserName, vUser, User))
        PrintUserCard(User);
    else
        cout << "\n\nUser with User Name (" << UserName << ") Not Found!" << endl;
}

short ReadMangeUserMenuOption()
{
    short Choose = 0;
    cout << "Choose What do you went to do? [1 to 6]? ";
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    cin >> Choose;
    while (cin.fail() || Choose <= 0 || Choose > 6)
    {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Invalid Choice.";
        cout << "\nPlease enter a numbaer between 1 and 6. ";
        cin >> Choose;
    }
    return Choose;
}
void GoBackToMangeUserMenu()
{
    cout << "\n\nPress any key to go back to Mange User Menu...";
    system("pause>0");
    ShowMangeUserMenuScreen();
}
void PerfromMangeUserMenuOption(enMangeUserMenuOption MangeUserMenuOptions)
{
    switch (MangeUserMenuOptions)
    {
    case enMangeUserMenuOption::eUserList:
        system("cls");
        ShowUserScreen();
        GoBackToMangeUserMenu();
        break;
    case enMangeUserMenuOption::eAddUser:
        system("cls");
        ShowAddUsersScreen();
        GoBackToMangeUserMenu();
        break;
    case enMangeUserMenuOption::eDeleteUser:
        system("cls");
        ShowDeleteUserScreen();
        GoBackToMangeUserMenu();
        break;
    case enMangeUserMenuOption::eUpdateUser:
        system("cls");
        ShowUpdateUserScreen();
        GoBackToMangeUserMenu();
        break;
    case enMangeUserMenuOption::eFindUser:
        system("cls");
        ShowFindUserScreen();
        GoBackToMangeUserMenu();
        break;
    case enMangeUserMenuOption::eMangeToMainMenu:
        system("cls");
        ShowMainMenuScreen();
        break;
    }
}
void ShowMangeUserMenuScreen()
{
    system("cls");
    cout << "========================================================" << endl;
    cout << "\t\tMange User Menu Screen" << endl;
    cout << "========================================================" << endl;
    cout << "\t[1] List Users." << endl;
    cout << "\t[2] Add New User." << endl;
    cout << "\t[3] Delete User." << endl;
    cout << "\t[4] Update User." << endl;
    cout << "\t[5] Find User." << endl;
    cout << "\t[6] Main Meneue." << endl;
    cout << "========================================================" << endl;
    PerfromMangeUserMenuOption((enMangeUserMenuOption)ReadMangeUserMenuOption());
}

void ShowAccessDeniedMessage()
{

    cout << "\n-------------------------------------------" << endl;
    cout << "Access Denied,";
    cout << "\nYou dont Have Permission To Do This,";
    cout << "\nPlease Conact Your Adin";
    cout << "\n-------------------------------------------" << endl;
}
void GoBackToMainMenu()
{
    cout << "\n\nPress any key to back Main Menu...";
    system("pause>0");
    ShowMainMenuScreen();
}
short ReadMainMenuOption()
{
    short Choose = 0;
    cout << "Choose What do you want to do? [1 to 8]? ";
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    cin >> Choose;
    while (cin.fail() || Choose <= 0 || Choose > 8)
    {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Invalid Choice.";
        cout << "\nPlease enter a numbaer between 1 and 8. ";
        cin >> ws, Choose;
    }
    return Choose;
}
bool CheckAccessPermission(int Permission, enMainMenuPermission Access)
{
    return Permission == FULLAccess || (Permission & Access) == Access;
}
void PerfromMainMenuOption(enMainMenuOptions MainMenuOptions, int Permission = CurrentUser.Access)
{

    switch (MainMenuOptions)
    {
    case enMainMenuOptions::eClientList:
        system("cls");
        if (CheckAccessPermission(Permission, enMainMenuPermission::pListClients))
            ShowClientScreen();
        else
            ShowAccessDeniedMessage();
        GoBackToMainMenu();
        break;

    case enMainMenuOptions::eAddClient:
        system("cls");
        if (CheckAccessPermission(Permission, enMainMenuPermission::pAddNewClient))
            ShowAddClientsScreen();
        else
            ShowAccessDeniedMessage();
        GoBackToMainMenu();
        break;
    case enMainMenuOptions::eDeleteCLient:
        system("cls");
        if (CheckAccessPermission(Permission, enMainMenuPermission::pDeleteClient))
            ShowDeleteClientScreen();
        else
            ShowAccessDeniedMessage();
        GoBackToMainMenu();
        break;
    case enMainMenuOptions::eUpdateClient:
        system("cls");
        if (CheckAccessPermission(Permission, enMainMenuPermission::pUpdateClients))
            ShowUpdateClientScreen();
        else
            ShowAccessDeniedMessage();
        GoBackToMainMenu();
        break;
    case enMainMenuOptions::eFindClient:
        system("cls");
        if (CheckAccessPermission(Permission, enMainMenuPermission::pFindClient))
            ShowFindClientScreen();
        else
            ShowAccessDeniedMessage();
        GoBackToMainMenu();
        break;
    case enMainMenuOptions::eTransaction:
        system("cls");
        if (CheckAccessPermission(Permission, enMainMenuPermission::pTransactions))
        {
            ShowTransactionMenuScreen();
            GoBackToTransactionMenu();
        }
        else
        {
            ShowAccessDeniedMessage();
            GoBackToMainMenu();
        }

        break;
    case enMainMenuOptions::eMangeUser:
        system("cls");
        if (CheckAccessPermission(Permission, enMainMenuPermission::pManageUsers))
        {
            ShowMangeUserMenuScreen();
            GoBackToMangeUserMenu();
        }
        else
        {
            ShowAccessDeniedMessage();
            GoBackToMainMenu();
        }
        break;
    case enMainMenuOptions::eLogout:
        system("cls");
        Login();
        break;
    }
}
void ShowMainMenuScreen()
{
    system("cls");
    cout << "========================================================" << endl;
    cout << "\t\tMain Menu Screen" << endl;
    cout << "========================================================" << endl;
    cout << "\t[1] Show Client List." << endl;
    cout << "\t[2] Add New Client." << endl;
    cout << "\t[3] Delete Client." << endl;
    cout << "\t[4] Update Client Info." << endl;
    cout << "\t[5] Find Clinet." << endl;
    cout << "\t[6] Transaction." << endl;
    cout << "\t[7] Manage User." << endl;
    cout << "\t[8] Logout." << endl;
    cout << "========================================================" << endl;
    PerfromMainMenuOption((enMainMenuOptions)ReadMainMenuOption());
}
bool FindUserByUserNameAndPassword(sUser &User)
{
    fstream MyFile;
    MyFile.open(UserFile, ios::in);
    if (MyFile.is_open())
    {
        string Line;
        sUser UserOfFile;
        while (getline(MyFile, Line))
        {
            UserOfFile = ConvertLinetoRecordOfUser(Line);
            if (UserOfFile.UserName == User.UserName && UserOfFile.Password == User.Password)
            {
                User.Access = UserOfFile.Access;
                MyFile.close();
                return true;
            }
        }
        MyFile.close();
    }
    return false;
}
void ShowLoginScreen()
{
    system("cls");
    cout << "========================================================" << endl;
    cout << "\t\tLogin Screen" << endl;
    cout << "========================================================" << endl;
}
sUser ReadUserNameAndPassword()
{

    sUser User;
    cout << "Enter UserName? ";
    getline(cin >> ws, User.UserName);
    cout << "Enter Password? ";
    getline(cin >> ws, User.Password);
    return User;
}
void Login()
{
    bool Find = true;
    sUser User;
    do
    {
        ShowLoginScreen();
        if (!Find)
        {
            cout << "Invalid UserName/Password\n";
        }
        User = ReadUserNameAndPassword();
        Find = FindUserByUserNameAndPassword(User);
    } while (!Find);
    CurrentUser = User;
    ShowMainMenuScreen();
}
int main()
{
    Login();
    // g++ PrBankExtension2.cpp -o BankSystem -static -static-libgcc -static-libstdc++
    return 0;
}