// Problem: Convert a year into its total days, hours, minutes, and seconds.
// Accounts for leap years when calculating the number of days.

#include <iostream>
#include <string>
using namespace std;
bool IsLeapYear(short Year)
{
    /*if (Year % 400 == 0 || Year % 4 == 0 && Year % 100 != 0)
        return true;
    else
        return false;*/
    return ((Year % 400 == 0) || (Year % 4 == 0 && Year % 100 != 0));
}
short NumberOfDaysInAYear(short Year)
{
    return IsLeapYear(Year) ? 366 : 365;
}
int NumberOfHoursInAYear(short Year)
{
    return NumberOfDaysInAYear(Year) * 24;
}
int NumberOfMinutesInAYear(short Year)
{
    return NumberOfHoursInAYear(Year) * 60;
}
long NumberOfSecondsInAYear(short Year)
{
    return NumberOfMinutesInAYear(Year) * 60;
}
short ReadYear()
{
    short Year;
    cout << "\nPlease enter a year to check? ";
    cin >> Year;
    return Year;
}
int main()
{
    short Year = ReadYear();
    cout << "\nNumber of Days    in Year [" << Year << "] is " << NumberOfDaysInAYear(Year);
    cout << "\nNumber of Hours   in Year [" << Year << "] is " << NumberOfHoursInAYear(Year);
    cout << "\nNumber of Minutes in Year [" << Year << "] is " << NumberOfMinutesInAYear(Year);
    cout << "\nNumber of Seconds in Year [" << Year << "] is " << NumberOfSecondsInAYear(Year);
    system("pause>0");
    return 0;
}