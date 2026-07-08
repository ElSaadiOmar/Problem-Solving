// Problem: Validate whether a given day/month/year combination is a real date.
// Checks the month range and that the day fits within that month's length.

#include <iostream>
#include <string>
#include <iomanip>
#include <ctime>
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
bool IsValiDate(sDate Date)
{
    if (Date.Month >= 13 || Date.Month <= 0)
        return false;
    return !(Date.Day > NumberOfDaysInAMonth(Date.Year, Date.Month) || Date.Day <= 0);
}
int main()
{
    system("pause>0");
    return 0;
}
