// Problem: Check whether one date comes before another.
// Compares year, then month, then day using nested ternaries.

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
bool IsDate1BeforeDate2(sDate Date1, sDate Date2)
{
    return (Date1.Year < Date2.Year) ? true 
                                     : (Date1.Year == Date2.Year) ?
                                                                    (Date1.Month < Date2.Month) ?  true
                                                                                                : (Date1.Month == Date2.Month) ?
                                                                                                                               Date1.Day < Date2.Day
                                                                                                                               : false
                                                                  : false;
    /*return (Date1.Year != Date2.Year) ? (Date1.Year < Date2.Year)
                                        : (Date1.Month != Date2.Month) ? Date1.Month < Date2.Month
                                                                       : Date1.Day < Date2.Day;
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
    if (IsDate1BeforeDate2(Date1, Date2))
        cout << "\nYes, Date1 is Less than Date2.";
    else
        cout << "\nNo, Date1 is NOT Less than Date2.";
    system("pause>0");
    return 0;
}
