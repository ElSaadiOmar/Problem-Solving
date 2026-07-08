// Problem set: Check if a date is the end of the week, a weekend, or a
// business day, and calculate days remaining until week/month/year end.

#include <iostream>
#include <string>
#include <iomanip>
#include <ctime>
using namespace std;
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
struct sDate
{
    short Year;
    short Month;
    short Day;
};
sDate ReadFullDate()
{
    sDate Date;
    Date.Day = ReadDay();
    Date.Month = ReadMonth();
    Date.Year = ReadYear();
    return Date;
}
short NumberOfDaysInAYear(short Year)
{
    return IsLeapYear(Year) ? 366 : 365;
}
short NumberOfDaysInAMonth(short Year, short Month)
{
    if (Month < 1 || Month > 12)
        return 0;
    int NumberOfDays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    return (Month == 2) ? (IsLeapYear(Year) ? 29 : 28) : NumberOfDays[Month - 1];
}
bool IsLastMonthInYear(short Month)
{
    return Month == 12;
}
short DayOfWeekOrder(short Day, short Month, short Year)
{
    short a, y, m;
    a = (14 - Month) / 12;
    y = Year - a;
    m = Month + 12 * a - 2;
    return (Day + y + (y / 4) - (y / 100) + (y / 400) + (31 * m / 12)) % 7;
}
short DayOfWeekOrder(sDate Date)
{
    return DayOfWeekOrder(Date.Day, Date.Month, Date.Year);
}
string DayShortName(short DayOfWeekOrder)
{
    string DayOfWeek[7] = {"Sun",
                           "Mon",
                           "Tue",
                           "Wed",
                           "Thu",
                           "Fri",
                           "Sat"};
    return DayOfWeek[DayOfWeekOrder];
}
bool IsEndOfWeek(sDate Date)
{
    return DayOfWeekOrder(Date) == 6;
}
bool IsWeekEnd(sDate Date)
{
    short nDayOfWeekOrder = DayOfWeekOrder(Date);
    return nDayOfWeekOrder == 5 || nDayOfWeekOrder == 6;
}
bool IsBusinessDay(sDate Date)
{
    return !IsWeekEnd(Date);
}
int DaysUntilTheEndOfWeek(sDate Date)
{
    return 6 - DayOfWeekOrder(Date);
}
int DaysUntilTheEndOfMonth(sDate Date)
{
    return NumberOfDaysInAMonth(Date.Year, Date.Month) - Date.Day;
}
int DaysUntilTheEndOfYear(sDate Date)
{
    int Until = 0;
    for (int i = Date.Month + 1; i <= 12; i++)
    {
        Until += NumberOfDaysInAMonth(Date.Year, Date.Month);
    }
    Until += DaysUntilTheEndOfMonth(Date);
    return Until;
}
int main()
{
    sDate Date1 = ReadFullDate();
    //---------------------
    cout << "\nIs it End of Week?\n";
    if (IsEndOfWeek(Date1))
        cout << "Yes it is Saturday, it's of Week.";
    else
        cout << "No it's Not end of week.";
    //---------------------
    cout << "\n\nIs it Weekend?\n";
    if (IsWeekEnd(Date1))
        cout << "Yes it is a week end.";
    else
        cout << "No today is "
             << DayShortName(DayOfWeekOrder(Date1)) << ", Not a weekend.";
    //---------------------
    cout << "\n\nIs it Business Day?\n";
    if (IsBusinessDay(Date1))
        cout << "Yes it is a business day.";
    else
        cout << "No it is NOT a business day.";
    //---------------------
    cout << "\n\nDays until end of week : "
         << DaysUntilTheEndOfWeek(Date1) << " Day(s).";
    //---------------------
    cout << "\nDays until end of month : "
         << DaysUntilTheEndOfMonth(Date1) << " Day(s).";
    cout << "\nDays until end of year : "
         << DaysUntilTheEndOfYear(Date1) << " Day(s).";
    system("pause>0");
    return 0;
}
