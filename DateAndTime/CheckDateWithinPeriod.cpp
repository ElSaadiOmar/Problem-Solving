// Problem: Check whether a specific date falls within a given period.
// Treats the single date as a zero-length period and checks for overlap.

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
int main()
{
    cout << "Enter Period :";
    sPeriod Period1 = ReadPeriod();

    cout << "\nEnter Date:";
    sDate Date = ReadFullDate();

    if (IsDateWithinPeriod(Period1, Date))
        cout << "\nYes, Date is Within Period";
    else
        cout << "\nNo, Date NOTis  Within Period";
    system("pause>0");
    return 0;
}
