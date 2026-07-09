// Problem: Read all clients from the file and print them as a formatted table.
// First version: works directly with raw text lines, splitting each on demand.

#include <iostream>
#include <ctime>
#include <cmath>
#include <vector>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;
const string FileName = "ClientRecord.txt";
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
short NumberOfLineInFile(string FileName)
{
    fstream MyFile;
    short Counter = 0;
    MyFile.open(FileName, ios::in | ios::app);
    if (MyFile.is_open())
    {
        string Line;
        while (getline(MyFile, Line))
        {
            Counter++;
        }
        MyFile.close();
    }
    return Counter;
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
void PrintLine(string Line)
{
    vector<string> vWorldInLine;
    vWorldInLine = SplitString(Line, "#//#");
    cout << "| " << left << setw(16) << vWorldInLine[0];
    cout << "| " << left << setw(10) << vWorldInLine[1];
    cout << "| " << left << setw(26) << vWorldInLine[2];
    cout << "| " << left << setw(11) << vWorldInLine[3];
    cout << "| " << left << vWorldInLine[4] ;
}
void PrintClientsRecord(string FileName)
{
    vector<string> vLine = SplitFileToLine(FileName);
    cout << "\t\t\tClient List (" << NumberOfLineInFile(FileName) << ") Client(s)." << endl;
    cout << string(84, '_') << endl
         << endl;
    cout << "| Account Number  ";
    cout << "| Pin Code  ";
    cout << "| Name Client" << string(15, ' ');
    cout << "| Phon" << string(7, ' ');
    cout << "| Balance" << endl;
    cout << string(84, '_') << endl;
    for (string &Line : vLine)
    {
        PrintLine(Line);
        cout << endl;
    }
      cout << string(84, '_') << endl
         << endl;
}
int main()
{
    system("cls");
    PrintClientsRecord(FileName);
    return 0;
}
