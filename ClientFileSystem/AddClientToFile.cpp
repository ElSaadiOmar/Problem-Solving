// Problem: Read a new client's details and append them to a text file.
// Combines record-to-line conversion with file writing, plus an 'add more?' loop.

#include <iostream>
#include <ctime>
#include <cmath>
#include <fstream>
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
sClient ReadInfo()
{
    sClient Info;
    cout << "\nEnter Account Number? ";
    getline(cin>>ws, Info.AccountNumber);

    cout << "\nEnter Pin Code? ";
    getline(cin, Info.PinCode);

    cout << "\nEnter Name? ";
    getline(cin, Info.Name);

    cout << "\nEnter Phon Number? ";
    getline(cin, Info.Phon);

    cout << "\nEnter Account Balance? ";
    cin >> Info.AccountBalance;
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
void AddNewClients()
{
    sClient Client;
    Client = ReadInfo();
    AddDataLineToFile("ClientRecord.txt", ConvertRecordToLine(Client));
}
void AddClient()
{
    char AddMore = 'Y';
    do
    {
        system("cls");
        cout<<"\n-------------------------------------------"<<endl;
        cout << "Adding New Client";
        cout<<"\n-------------------------------------------"<<endl;
        cout << "Adding New Client:"<<endl;
        AddNewClients();
        cout << "\n\nClient Added Successfully, do you want to add more client? Y/N? " << endl;
        cin >> AddMore;
    } while (toupper(AddMore) == 'Y');
}
int main()
{
    AddClient();
    return 0;
}