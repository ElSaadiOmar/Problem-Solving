// Problem: Calculate which day-of-year number a date corresponds to.
// Sums the days in every prior month, then adds the day itself.

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
short NumberOfDaysInAMonth(short Year, short Month)
{
    if (Month < 1 || Month > 12)
        return 0;
    int NumberOfDays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    return (Month == 2) ? (IsLeapYear(Year) ? 29 : 28) : NumberOfDays[Month - 1];
}
short CalculateNumOfDayInYear(short Day, short Month, short Year)
{
    int NumOfDay = 0;
    for (int i = 1; i < Month; i++)
    {
        NumOfDay += NumberOfDaysInAMonth(Year, i);
    }
    NumOfDay += Day;
    return NumOfDay;
}
int main()
{
    short Day = ReadDay();
    short Month = ReadMonth();
    short Year = ReadYear();
    printf("Number of Days from the begining of the year is %d\n", CalculateNumOfDayInYear(Day, Month, Year));
    system("pause>0");
    return 0;
} /**/