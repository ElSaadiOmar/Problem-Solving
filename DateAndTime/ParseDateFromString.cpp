// Problem: Parse a date typed as free-form text into day/month/year fields.
// Splits the string on '/' and converts each piece into numbers.

#include <iostream>
#include <string>
#include <iomanip>
#include <ctime>
#include <vector>
using namespace std;
struct sDate
{
    short Year;
    short Month;
    short Day;
};
bool IsLeapYear(short Year)
{
    return ((Year % 400 == 0) || (Year % 4 == 0 && Year % 100 != 0));
}
short ReadYear()
{
    short Year;
    cout << "Please enter a year? ";
    cin >> Year;
    return Year;
}
short ReadMonth()
{
    short Month;
    cout << "Please enter a Month? ";
    cin >> Month;
    return Month;
}
short ReadDay()
{
    short Day;
    cout << "Please enter a Day? ";
    cin >> Day;
    return Day;
}
short NumberOfDaysInAMonth(short Year, short Month)
{
    if (Month < 1 || Month > 12)
        return 0;
    int NumberOfDays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    return (Month == 2) ? (IsLeapYear(Year) ? 29 : 28) : NumberOfDays[Month - 1];
}
sDate ReadFullDate()
{
    sDate Date;
    Date.Day = ReadDay();
    Date.Month = ReadMonth();
    Date.Year = ReadYear();
    return Date;
}
vector<string> SplitString(string S1, string Delim)
{
    vector<string> vString;
    short pos = 0;
    string sWord; // define a string variable
    // use find() function to get the position of the delimiters
    while ((pos = S1.find(Delim)) != std::string::npos)
    {
        sWord = S1.substr(0, pos); // store the word
        if (sWord != "")
        {
            vString.push_back(sWord);
        }
        S1.erase(0, pos + Delim.length());
    }
    if (S1 != "")
    {
        vString.push_back(S1); // it adds last word of the string.
    }
    return vString;
}
bool IsValiDate(sDate Date)
{
    if (Date.Month >= 13 || Date.Month <= 0)
        return false;
    return !(Date.Day > NumberOfDaysInAMonth(Date.Year, Date.Month) || Date.Day <= 0);
}
sDate DateByStringToDateByStruct(string Date)
{
    sDate SDate;
    for (int i = 0; i < Date.length(); i++)
    {
        if (Date[i] >= 12 || Date[i] <= 12)
        {
            Date.erase(0, i);
            SDate.Day = stoi(Date.substr(0, Date.find('/')));
            Date.erase(0, Date.find('/') + 1);

            SDate.Month = stoi(Date.substr(0, Date.find('/')));
            Date.erase(0, Date.find('/') + 1);

            if (Date.find('/') != string::npos)
                SDate.Year = stoi(Date.substr(0, Date.find('/')));
            else
                SDate.Year = stoi(Date);
            return SDate;
        }
    }
}
string DateToString(sDate Date)
{
    return to_string(Date.Day) + "/" + to_string(Date.Month) +
           "/" + to_string(Date.Year);
}
sDate StringToDate(string DateString)
{
    sDate Date;
    vector<string> vDate;
    vDate = SplitString(DateString, "/");
    Date.Day = stoi(vDate[0]);
    Date.Month = stoi(vDate[1]);
    Date.Year = stoi(vDate[2]);
    return Date;
}
string ReadStringDate(string Message)
{
    string DateString;
    cout << Message;
    getline(cin >> ws, DateString);
    return DateString;
}
int main()
{
    sDate Date = DateByStringToDateByStruct("12 / 12 / 2002/");
    cout << Date.Day << "  ," << Date.Month << "  ," << Date.Year;
    cout << "Yes";
    system("pause>0");
    return 0;
}
