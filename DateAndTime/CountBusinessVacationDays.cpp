// Problem: Count how many actual business (working) days fall within a vacation.
// Skips weekends while counting from the start date to the end date.

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
bool IsLastDayInMonth(sDate Date)
{
    return Date.Day == NumberOfDaysInAMonth(Date.Year, Date.Month);
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
sDate IncreaseDateByOneDay(sDate Date)
{
    IsLastDayInMonth(Date) ? Date.Day = 1, (IsLastMonthInYear(Date.Month) ? Date.Month = 1, Date.Year++ : Date.Month++) : Date.Day++;
    return Date;
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
bool IsDate1BeforeDate2(sDate Date1, sDate Date2)
{
    return (Date1.Year < Date2.Year)    ? true
           : (Date1.Year == Date2.Year) ? (Date1.Month < Date2.Month)    ? true
                                          : (Date1.Month == Date2.Month) ? Date1.Day < Date2.Day
                                                                         : false
                                        : false;
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
short ActcalVacationDays(sDate Date1, sDate Date2)
{
    short Count = 0;
    while (IsDate1BeforeDate2(Date1, Date2))
    {
        if (IsBusinessDay(Date1))
            Count++;
        Date1 = IncreaseDateByOneDay(Date1);
    }
    return Count;
}
int main()
{
    cout << "Vacation Starts:\n";
    sDate Date1 = ReadFullDate();
    //--------------------
    cout << "\nVacation Ends:\n";
    sDate Date2 = ReadFullDate();
    //--------------------
    cout << "\nVacation From: " << DayShortName(DayOfWeekOrder(Date1));
    printf(" , %d/%d/%d\n", Date1.Day, Date1.Month, Date1.Year);
    //--------------------
    cout << "Vacation To: " << DayShortName(DayOfWeekOrder(Date2));
    printf(" , %d/%d/%d\n", Date2.Day, Date2.Month, Date2.Year);
    //---------------------
    cout << "\n\nActucal Vacation Days is: " << ActcalVacationDays(Date1, Date2);

    system("pause>0");
    return 0;
}
