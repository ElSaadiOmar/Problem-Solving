// Problem set: Increase a date by one day, week, month, year, decade,
// century, or millennium (a group of related date-arithmetic exercises).

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
sDate IncreaseDateByXDay(sDate Date, short XDay)
{
    for (int i = 0; i <XDay; i++)
    {
        Date = IncreaseDateByOneDay(Date);
    }
    return Date;
}
sDate IncreaseDateByOneWeek(sDate Date)
{
    return IncreaseDateByXDay(Date, 7);
}
sDate IncreaseDateByXWeeks(sDate Date, short Week)
{
    for (int i = 0; i < Week; i++)
    {
        Date = IncreaseDateByOneWeek(Date);
    }
    return Date;
}
sDate IncreaseDateByOneMonth(sDate Date)
{
    IsLastMonthInYear(Date.Month) ? Date.Month = 1 : Date.Month++;
    short Def = Date.Day - NumberOfDaysInAMonth(Date.Year, Date.Month);
    if (Def > 0)
    {
        Date.Day = Def;
        IsLastMonthInYear(Date.Month) ? Date.Month = 1 : Date.Month++;
    }
    return Date;
}
sDate IncreaseDateByXMonth(sDate Date, short Month)
{
    for (int i = 0; i < Month; i++)
    {
        Date = IncreaseDateByOneMonth(Date);
    }
    return Date;
}
sDate IncreaseDateByOneYear(sDate Date)
{
    Date.Year++;
    return Date;
}
sDate IncreaseDateByXYear(sDate Date, short Year)
{
    for (int i = 0; i < Year; i++)
    {
        Date = IncreaseDateByOneYear(Date);
    }
    return Date;
}
sDate IncreaseDateByXYearFaster(sDate Date, short Year)
{
    Date.Year += Year;
    return Date;
}
sDate IncreaseDateByOneDecade(sDate Date)
{
    Date.Year+=10;
    return Date;
}
sDate IncreaseDateByXDecades(sDate Date, short Decade)
{
    for (int i = 0; i < Decade; i++)
    {
        Date = IncreaseDateByOneDecade(Date);
    }
    return Date;
}
sDate IncreaseDateByXDecadesFaster(sDate Date, short Decade)
{
    Date.Year += (Decade * 10);
    return Date;
}
sDate IncreaseDateByOneCentury(sDate Date)
{
    Date.Year += 100;
    return Date;
}
sDate IncreaseDateByOneMillennium(sDate Date)
{
    Date.Year += 1000;
    return Date;
}
void PrintDate(sDate Date)
{
    printf("%d/%d/%d\n", Date.Day, Date.Month, Date.Year);
}
int main()
{
    sDate Date1 = ReadFullDate();
    PrintDate(IncreaseDateByOneDay(Date1));
    PrintDate(IncreaseDateByXDay(Date1,10));
    PrintDate(IncreaseDateByOneWeek(Date1));
    PrintDate(IncreaseDateByXWeeks(Date1,10));
    PrintDate(IncreaseDateByOneMonth(Date1));
    PrintDate(IncreaseDateByXMonth(Date1,5));
    PrintDate(IncreaseDateByOneYear(Date1));
    PrintDate(IncreaseDateByXYear(Date1,10));
    PrintDate(IncreaseDateByXYearFaster(Date1,10));
    PrintDate(IncreaseDateByOneDecade(Date1));
    PrintDate(IncreaseDateByXDecades(Date1,10));
    PrintDate(IncreaseDateByXDecadesFaster(Date1,10));
    PrintDate(IncreaseDateByOneCentury(Date1));
    PrintDate(IncreaseDateByOneMillennium(Date1));
    system("pause>0");
    return 0;
}
