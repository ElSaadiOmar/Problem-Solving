// Problem: Convert a day-of-year number back into a full date.
// Walks through months, subtracting days until the correct month is found.

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
struct sDate
{
    short Year;
    short Month;
    short Day;
};
sDate CalculateTheDateOfNum(short Number, short Year)
{
    sDate Date;
    Date.Year = Year;
    for (short i = 1; i <= 12; i++)
    {

        if (Number > NumberOfDaysInAMonth(Year, i))
            Number -= NumberOfDaysInAMonth(Year, i);
        else
        {
            Date.Month = i;
            Date.Day = Number + NumberOfDaysInAMonth(Year, i);
            break;
        }
    }

    return Date;
}
/*sDate GetDateFromDayOrderInYear(short DateOrderInYear, short Year)
{
    sDate Date;
    short RemainingDays = DateOrderInYear;
    short MonthDays = 0;
    Date.Year = Year;
    Date.Month = 1;
    while (true)
    {
        MonthDays = NumberOfDaysInAMonth(Date.Month, Year);
        if (RemainingDays > MonthDays)
        {
            RemainingDays -= MonthDays;
            Date.Month++;
        }
        else
        {
            Date.Day = RemainingDays;
            break;
        }
    }
    return Date;
}
*/
int main()
{
    short Day = ReadDay();
    short Month = ReadMonth();
    short Year = ReadYear();
    short Num = CalculateNumOfDayInYear(Day, Month, Year);
    sDate Date = CalculateTheDateOfNum(Num, Year);
    printf("\nNumber of Days from the begining of the year is %d\n", Num);
    printf("\nThe date of Number %d is %d/%d/%d", Num, Date.Day, Date.Month, Date.Year);
    system("pause>0");
    return 0;
} /**/
