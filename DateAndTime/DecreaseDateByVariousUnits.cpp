// Problem set: Decrease a date by one day, week, month, year, decade,
// century, or millennium (the mirror image of the Increase exercises).

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
bool IsFirstDayInMonth(sDate Date)
{
    return Date.Day == 1;
}
bool IsFirstMonthInYear(short Month)
{
    return Month == 1;
}
sDate DecreaseDateByOneDay(sDate Date)
{
    (Date.Day==1) ? ((Date.Month==1) ? (Date.Day = 31, Date.Month = 12, Date.Year--) : (Date.Month--, Date.Day = NumberOfDaysInAMonth(Date.Year, Date.Month))) : (Date.Day--);
    return Date;
}
sDate DecreaseDateByXDay(sDate Date, short XDay)
{
    for (int i = 0; i < XDay; i++)
    {
        Date = DecreaseDateByOneDay(Date);
    }
    return Date;
}
sDate DecreaseDateByOneWeek(sDate Date)
{
    return DecreaseDateByXDay(Date, 7);
}
sDate DecreaseDateByXWeeks(sDate Date, short Week)
{
    for (int i = 0; i < Week; i++)
    {
        Date = DecreaseDateByOneWeek(Date);
    }
    return Date;
}
sDate DecreaseDateByOneMonth(sDate Date)
{
    IsFirstMonthInYear(Date.Month) ? Date.Month = 12 : Date.Month--;
    if (Date.Day > NumberOfDaysInAMonth(Date.Year, Date.Month))
        Date.Day = NumberOfDaysInAMonth(Date.Year, Date.Month);
    return Date;
}
sDate DecreaseDateByXMonth(sDate Date, short Month)
{
    for (int i = 0; i < Month; i++)
    {
        Date = DecreaseDateByOneMonth(Date);
    }
    return Date;
}
sDate DecreaseDateByOneYear(sDate Date)
{
    Date.Year--;
    return Date;
}
sDate DecreaseDateByXYear(sDate Date, short Year)
{
    for (int i = 0; i < Year; i++)
    {
        Date = DecreaseDateByOneYear(Date);
    }
    return Date;
}
sDate DecreaseDateByXYearFaster(sDate Date, short Year)
{
    Date.Year -= Year;
    return Date;
}
sDate DecreaseDateByOneDecade(sDate Date)
{
    Date.Year -= 10;
    return Date;
}
sDate DecreaseDateByXDecades(sDate Date, short Decade)
{
    for (int i = 0; i < Decade; i++)
    {
        Date = DecreaseDateByOneDecade(Date);
    }
    return Date;
}
sDate DecreaseDateByXDecadesFaster(sDate Date, short Decade)
{
    Date.Year -= (Decade * 10);
    return Date;
}
sDate DecreaseDateByOneCentury(sDate Date)
{
    Date.Year -= 100;
    return Date;
}
sDate DecreaseDateByOneMillennium(sDate Date)
{
    Date.Year -= 1000;
    return Date;
}
void PrintDate(sDate Date)
{
    printf("%d/%d/%d\n", Date.Day, Date.Month, Date.Year);
}
int main()
{
    sDate Date1 = ReadFullDate();
    PrintDate(DecreaseDateByOneDay(Date1));
    PrintDate(DecreaseDateByXDay(Date1, 10));
    PrintDate(DecreaseDateByOneWeek(Date1));
    PrintDate(DecreaseDateByXWeeks(Date1, 10));
    PrintDate(DecreaseDateByOneMonth(Date1));
    PrintDate(DecreaseDateByXMonth(Date1, 5));
    PrintDate(DecreaseDateByOneYear(Date1));
    PrintDate(DecreaseDateByXYear(Date1, 10));
    PrintDate(DecreaseDateByXYearFaster(Date1, 10));
    PrintDate(DecreaseDateByOneDecade(Date1));
    PrintDate(DecreaseDateByXDecades(Date1, 10));
    PrintDate(DecreaseDateByXDecadesFaster(Date1, 10));
    PrintDate(DecreaseDateByOneCentury(Date1));
    PrintDate(DecreaseDateByOneMillennium(Date1));
    system("pause>0");
    return 0;
}
