// Problem: Calculate the number of days between two dates.
// Repeatedly increases the earlier date by one day until it reaches the other.

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
bool IsDate1BeforeDate2(sDate Date1, sDate Date2)
{

    return (Date1.Year != Date2.Year)     ? (Date1.Year < Date2.Year)
           : (Date1.Month != Date2.Month) ? Date1.Month < Date2.Month
                                          : Date1.Day < Date2.Day;
}
short CalculateNumOfDayInYear(sDate Date)
{
    int NumOfDay = 0;
    for (int i = 1; i < Date.Month; i++)
    {
        NumOfDay += NumberOfDaysInAMonth(Date.Year, i);
    }
    NumOfDay += Date.Day;
    return NumOfDay;
}

int GetDifferenceInDays(sDate Date1, sDate Date2, bool IncludingEndDay = false)
{
    /*int Days = 0;
    while (IsDate1BeforeDate2(Date1, Date2))
    {
        if (Date1.Year != Date2.Year)
        {
            for (int i = Date1.Year; i < Date2.Year; i++)
            {
                Days += NumberOfDaysInAYear(i);
                if (Date1.Month != Date2.Month)
                {
                    for (int j = Date1.Month; j < Date2.Month; j++)
                    {
                        Days += NumberOfDaysInAMonth(j, i);
                    }
                }
            }
        }

        else
        {
            Days++;
            IncreaseDateByOneDay(Date1);
        }
    }
    return IncludingEndDay ? ++Days : Days;*/
    int Days = 0;
    while (IsDate1BeforeDate2(Date1, Date2))
    {
        Days++;
        Date1 = IncreaseDateByOneDay(Date1);
    }
    return IncludingEndDay ? ++Days : Days;
    /*short DifferenceDays = 0;
    if (!IsDate1BeforeDate2(Date1, Date2))
        return -1;
    if (IncludingEndDay)
    {
        for (int i = Date1.Year; i < Date2.Year; i++)
        {
            DifferenceDays += NumberOfDaysInAYear(i);
        }
        DifferenceDays += (CalculateNumOfDayInYear(Date2) - CalculateNumOfDayInYear(Date1)) + 1;
        return DifferenceDays;
    }
    else
    {
        return GetDifferenceInDays(IncreaseDateByOneDay(Date1), Date2, true);
    }
    */
}
int main()
{
    sDate Date1 = ReadFullDate();
    sDate Date2 = ReadFullDate();
    cout << "Difference is: " << GetDifferenceInDays(Date1, Date2);
    cout << "\nDifference is (Including End Day): " << GetDifferenceInDays(Date1, Date2, true);
    system("pause>0");
    return 0;
}
