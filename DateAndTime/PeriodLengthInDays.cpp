// Problem: Calculate the total length of a date period, in days.
// Reuses the date-difference logic between a period's start and end.

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
struct sPeriod
{
    sDate StartDate;
    sDate EndDate;
};
sDate ReadFullDate()
{
    sDate Date;
    Date.Day = ReadDay();
    Date.Month = ReadMonth();
    Date.Year = ReadYear();
    return Date;
}
enum enDateCompare
{
    Befor = -1,
    Equal = 0,
    After = 1,
};
bool IsDate1BeforeDate2(sDate Date1, sDate Date2)
{
    return (Date1.Year < Date2.Year)    ? true
           : (Date1.Year == Date2.Year) ? (Date1.Month < Date2.Month)    ? true
                                          : (Date1.Month == Date2.Month) ? Date1.Day < Date2.Day
                                                                         : false
                                        : false;
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
int GetDifferenceInDays(sDate Date1, sDate Date2, bool IncludeEndDay = false)
{
    int Days = 0;
    while (IsDate1BeforeDate2(Date1, Date2))
    {
        Days++;
        Date1 = IncreaseDateByOneDay(Date1);
    }
    return IncludeEndDay ? ++Days : Days;
}
int PeriodLengthInDay(sPeriod Period, bool IncludeEndDay = false)
{
    return GetDifferenceInDays(Period.StartDate, Period.EndDate, IncludeEndDay);
}
sPeriod ReadPeriod()
{
    sPeriod Period;
    cout << "\nEnter Start Date:\n";
    Period.StartDate = ReadFullDate();
    cout << "\nEnter End Date\n";
    Period.EndDate = ReadFullDate();
    return Period;
}
int main()
{
    cout << "Enter Period 1:";
    sPeriod Period = ReadPeriod();
    cout << "Period Length is: " << PeriodLengthInDay(Period) << endl;
    cout << "Period Length (Including End Date) is: " << PeriodLengthInDay(Period, true) << endl;
    system("pause>0");
    return 0;
}
