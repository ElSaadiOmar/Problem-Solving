// Problem: Calculate the return date after a vacation of N working days.
// Advances day by day, only counting business days toward the total.

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
sDate CalculateVacationReturnDate(sDate StartVacation, short VacationDays)
{
    while (VacationDays > 0)
    {
        if (IsBusinessDay(StartVacation))
            VacationDays--;
        StartVacation = IncreaseDateByOneDay(StartVacation);
    }
    return StartVacation;
}
int main()
{
    cout << "Vacation Starts:\n";
    sDate Date1 = ReadFullDate();
    short VacationDays = 0;
    cout << "\nPlease enter vacation days? ";
    cin >> VacationDays;
    //--------------------
    sDate EndVacation = CalculateVacationReturnDate(Date1, VacationDays);
    cout << "\nReturn Date: " << DayShortName(DayOfWeekOrder(EndVacation));
    printf(" , %d/%d/%d\n", EndVacation.Day, EndVacation.Month, EndVacation.Year);

    system("pause>0");
    return 0;
}
