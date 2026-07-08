// Problem: Given a date, calculate and print which day of the week it falls on.
// Uses Zeller's-congruence-style arithmetic to compute the day order.

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
bool IsLeapYear(short Year)
{
    return ((Year % 400 == 0) || (Year % 4 == 0 && Year % 100 != 0));
}
short DayOfWeekOrder(short Day, short Month, short Year)
{
    short a, y, m;
    a = (14 - Month) / 12;
    y = Year - a;
    m = Month + 12 * a - 2;
    return (Day + y + (y / 4) - (y / 100) + (y / 400) + (31 * m / 12)) % 7;
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
int main()
{
    short Year = ReadYear();
    short Month = ReadMonth();
    short Day = ReadDay();
    cout << "\nDate      : " << Day << "/" << Month << "/" << Year;
    cout << "\nDay Order : " << DayOfWeekOrder(Day, Month, Year);
    cout << "\nDay Name  : " << DayShortName(DayOfWeekOrder(Day, Month, Year));
    system("pause>0");
    return 0;
}