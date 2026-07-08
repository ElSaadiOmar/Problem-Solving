// Problem: Check whether two date periods (start-end ranges) overlap.
// Uses the enum date comparison to test for any shared days.

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
    /*return (IsDate1AfterDate2(Periode1.EndDate, Periode2.StartDate) && IsDate1BeforeDate2(Periode1.StartDate, Periode2.StartDate)
    //|| IsDate1AfterDate2(Periode1.StartDate, Periode2.EndDate) && IsDate1BeforeDate2(Periode1.EndDate, Periode2.EndDate));*/ 
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
    sPeriod Period1 = ReadPeriod();

    cout << "\nEnter Period 2:";
    sPeriod Period2 = ReadPeriod();

    if (IsOverlap(Period1, Period2))
        cout << "\nYes, Periods Overlap";
    else
        cout << "\nNo, Periods NOT Overlap";
    system("pause>0");
    return 0;
}
