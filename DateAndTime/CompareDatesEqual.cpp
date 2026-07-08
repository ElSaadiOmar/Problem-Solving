// Problem: Check whether two dates are exactly equal.
// Compares year, month, and day fields for an exact match.

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
bool IsDate1EqualDate2(sDate Date1, sDate Date2)
{
    /*return (Date1.Year != Date2.Year) ? false
                                        : (Date1.Month != Date2.Month) ? false
                                                                       : Date1.Day == Date2.Day;*/
    return (Date1.Year == Date2.Year) ? ((Date1.Month == Date2.Month) ? (Date1.Day == Date2.Day): false) : false;
      /* if (Date1.Year != Date2.Year)
           return Date1.Year < Date2.Year;
       if(Date1.Month!=Date2.Month)
           return Date1.Month < Date2.Month;
       return  Date1.Day < Date2.Day;*/
}
int main()
{
    sDate Date1 = ReadFullDate();
    sDate Date2 = ReadFullDate();
    if (IsDate1EqualDate2(Date1, Date2))
        cout << "\nYes, Date1 is Equal than Date2.";
    else
        cout << "\nNo, Date1 is NOT Equal than Date2.";
    system("pause>0");
    return 0;
}
