// Problem: Count exactly how many days two date periods overlap by.
// Extends the overlap check to return a day count instead of true/false.

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
bool IsLastDayInMonth(sDate Date)
{
    return Date.Day == NumberOfDaysInAMonth(Date.Year, Date.Month);
}
bool IsLastMonthInYear(short Month)
{
    return Month == 12;
}
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
bool IsDate1EqualDate2(sDate Date1, sDate Date2)
{
    return (Date1.Year == Date2.Year) ? ((Date1.Month == Date2.Month) ? (Date1.Day == Date2.Day) : false) : false;
}
bool IsDate1AfterDate2(sDate Date1, sDate Date2)
{
    return (!IsDate1EqualDate2(Date1, Date2) && !IsDate1BeforeDate2(Date1, Date2));
}
enDateCompare CompareDates(sDate Date1, sDate Date2)
{
    if (IsDate1AfterDate2(Date1, Date2))
        return enDateCompare::After;
    if (IsDate1EqualDate2(Date1, Date2))
        return enDateCompare::Equal;
    return enDateCompare::Befor;
}
bool IsOverlap(sPeriod Periode1, sPeriod Periode2)
{
    return !(CompareDates(Periode1.StartDate, Periode2.EndDate) == After || CompareDates(Periode1.EndDate, Periode2.StartDate) == Befor);
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
bool IsDateWithinPeriod(sPeriod Period1, sDate Date)
{
    sPeriod Period2;
    Period2.StartDate = Date;
    Period2.EndDate = Date;
    return IsOverlap(Period1, Period2);
}
int CountOverlapDays(sPeriod Periode1, sPeriod Periode2)
{
    int Period1Length = PeriodLengthInDay(Periode1);
    int Period2Length = PeriodLengthInDay(Periode2);
    int CountDays = 0;

    if (!IsOverlap(Periode1, Periode2))
        return 0;

    if (Period1Length < Period2Length)
    {
        while (IsDate1BeforeDate2(Periode1.StartDate,Periode1.EndDate))
        {
            if (IsDateWithinPeriod(Periode2, Periode1.StartDate))
                CountDays++;
            Periode1.StartDate = IncreaseDateByOneDay(Periode1.StartDate);
        }
    }
    else
    {
        while (IsDate1BeforeDate2(Periode2.StartDate,Periode2.EndDate))
        {
            if (IsDateWithinPeriod(Periode1, Periode2.StartDate))
                CountDays++;
            Periode2.StartDate = IncreaseDateByOneDay(Periode2.StartDate);
        }
    }
    return CountDays;
}
int main()
{
    cout << "Enter Period 1:";
    sPeriod Period1 = ReadPeriod();

    cout << "\nEnter Period 2:\n";
    sPeriod Period2 = ReadPeriod();

    cout << "\nOverlap Days Count Is: " << CountOverlapDays(Period1, Period2);
    system("pause>0");
    return 0;
}
