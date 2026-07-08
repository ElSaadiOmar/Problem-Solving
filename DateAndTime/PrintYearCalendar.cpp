// Problem: Print a full calendar for all 12 months of a year.
// Loops PrintMonthCalendar() for every month, month 1 through 12.

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
string MonthShortName(short NumOfMonth)
{
    string months[13] = {"",
                         "Jan", "Feb", "Mar", "Apr", "May", "Jun",
                         "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    return months[NumOfMonth];
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
short NumberOfDaysInAMonth(short Year, short Month)
{
    if (Month < 1 || Month > 12)
        return 0;
    int NumberOfDays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    return (Month == 2) ? (IsLeapYear(Year) ? 29 : 28) : NumberOfDays[Month - 1];
}
void PrintMonthCalendar(short Month, short Year)
{

    short current = DayOfWeekOrder(1, Month, Year);
    short NumberOfDays = NumberOfDaysInAMonth(Year, Month);
    cout << "\n_______________" << MonthShortName(Month) << "_______________";
    cout << "\n\nSun  Mon  Tue  Wed  Thu  Fri  Sat\n";
    int j;
    for (j = 0; j < current; j++)
        cout << "     ";
    for (int i = 1; i <= NumberOfDays; i++)
    {
        cout << setw(3) << i << "  ";
        if (++j == 7)
        {
            j = 0;
            cout << endl;
        }
    }
    cout << "\n_________________________________\n";
}
void PrintAllMonthCalendar(short Year)
{
    cout << "_________________________________\n\n";
    printf("\t Calendar - %d\n",Year);
    cout << "_________________________________\n";
    for(int i=1;i<=12;i++)
    {
        PrintMonthCalendar(i,Year);
    }
}
int main()
{
    short Year = ReadYear();
    PrintAllMonthCalendar(Year);
    system("pause>0");
    return 0;
} /**/
