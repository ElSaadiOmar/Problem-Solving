// Problem: Add one day to a date, rolling over into the next month/year.
// Completes the logic sketched out in v1 using a compact ternary expression.

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
bool IsLeapYear(short Year)
{
    return ((Year % 400 == 0) || (Year % 4 == 0 && Year % 100 != 0));
}
short ReadYear()
{
    short Year;
    cout << "\nPlease enter a year? ";
    cin >> Year;
    return Year;
}
short ReadMonth()
{
    short Month;
    cout << "\nPlease enter a Month? ";
    cin >> Month;
    return Month;
}
short ReadDay()
{
    short Day;
    cout << "\nPlease enter a Day? ";
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
short NumberOfDaysInAMonth(short Year, short Month)
{
    if (Month < 1 || Month > 12)
        return 0;
    int NumberOfDays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    return (Month == 2) ? (IsLeapYear(Year) ? 29 : 28) : NumberOfDays[Month - 1];
}
bool IsLastDayInMonth(sDate Date)
{
    return Date.Day == NumberOfDaysInAMonth(Date.Year, Date.Month);
}
bool IsLastMonthInYear(short Month)
{
    return Month == 12;
}
sDate IncreaseDateByOneDay(sDate Date)
{
    IsLastDayInMonth(Date) ? Date.Day = 1, (IsLastMonthInYear(Date.Month) ? Date.Month = 1, Date.Year++ : Date.Month++) : Date.Day++;
    return Date;
}
int main()
{
    sDate Date1 = ReadFullDate();
    Date1 = IncreaseDateByOneDay(Date1);
    cout << "\nDate after adding one day is:" << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;
    system("pause>0");
    return 0;
}
