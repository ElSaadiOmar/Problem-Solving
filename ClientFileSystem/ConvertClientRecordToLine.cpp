// Problem: Read client details from the user and convert them into one text line.
// First step of the file-based client system: struct -> delimited string.

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
sClient ReadInfo()
{
    sClient Info;
    cout << "\nEnter Account Number? ";
    getline(cin, Info.AccountNumber);

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
int main()
{
    cout << "Please Enter Client Data" << endl;
    sClient Info = ReadInfo();
    cout << "\n\nClient Record for Saving is:" << endl;
    cout << ConvertRecordToLine(Info);
    return 0;
}