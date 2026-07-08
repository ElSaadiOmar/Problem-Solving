// Problem: Convert a given month/year into days, hours, minutes, and seconds.
// Looks up days-in-month, adjusting February for leap years.

#include <iostream>
#include <string>
using namespace std;
bool IsLeapYear(short Year)
{
    return ((Year % 400 == 0) || (Year % 4 == 0 && Year % 100 != 0));
}
short NumberOfDaysInAMonth(short Year, short Month)
{
    if (Month < 1 || Month > 12)
        return 0;
    int NumberOfDays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    return (Month == 2) ? (IsLeapYear(Year) ? 29 : 28) : NumberOfDays[Month - 1];

    /* return (Month == 2) ? IsLeapYear(Year) ? 29 : 28 : (Month <= 7) ? Month % 2 != 0 ? 31 : 30
                                                    : Month % 2 == 0 ? 31: 30;
     short Arr31Days[7] = {1, 3, 5, 7, 8, 10, 12};
      for (int i = 0; i < 7; i++)
      {
          if (Arr31Days[i] == Month)
              return 31;
      }
      return 30;*/
}
int NumberOfHoursInAMonth(short Year, short Month)
{
    return NumberOfDaysInAMonth(Year, Month) * 24;
}
int NumberOfMinutesInAMonth(short Year, short Month)
{
    return NumberOfHoursInAMonth(Year, Month) * 60;
}
long NumberOfSecondsInAMonth(short Year, short Month)
{
    return NumberOfMinutesInAMonth(Year, Month) * 60;
}
short ReadYear()
{
    short Year;
    cout << "\nPlease enter a year to check? ";
    cin >> Year;
    return Year;
}
short ReadMonth()
{
    short Month;
    cout << "\nPlease enter a Month to check? ";
    cin >> Month;
    return Month;
}
int main()
{
    short Year = ReadYear();
    short Month = ReadMonth();
    cout << "\nNumber of Days    in Month [" << Month << "] is " << NumberOfDaysInAMonth(Year, Month);
    cout << "\nNumber of Hours   in Month [" << Month << "] is " << NumberOfHoursInAMonth(Year, Month);
    cout << "\nNumber of Minutes in Month [" << Month << "] is " << NumberOfMinutesInAMonth(Year, Month);
    cout << "\nNumber of Seconds in Month [" << Month << "] is " << NumberOfSecondsInAMonth(Year, Month);
    system("pause>0");
    return 0;
}