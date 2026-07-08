// Problem: Add a number of days to a date (revised implementation).
// Cleans up the rollover logic from the first attempt.

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
int ReadNumberOfDaysAdd()
{
    short NumDayAdd;
    cout << "\nPlease enter number of days to add?";
    cin >> NumDayAdd;
    return NumDayAdd;
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
            Date.Day = Number;
            break;
        }
    }

    return Date;
}
sDate ReadFullDate()
{
    sDate Date;
    Date.Day = ReadDay();
    Date.Month = ReadMonth();
    Date.Year = ReadYear();
    return Date;
}
sDate DateAddDays(int DaysAdd, sDate Date)
{
    int TotalNumber = DaysAdd + CalculateNumOfDayInYear(Date.Day, Date.Month, Date.Year);
    while (true)
    {
        Date.Month = 1;
        if (TotalNumber > NumberOfDaysInAMonth(Date.Month, Date.Year))
        {
            TotalNumber -= NumberOfDaysInAMonth(Date.Month, Date.Year);
            Date.Month++;
            if (Date.Month > 12)
            {
                Date.Month = 1;
                Date.Year++;
            }
        }
        else
        {
            Date.Day=TotalNumber;
            return Date;
        }
    }
   
}
int main()
{
    sDate Date = ReadFullDate();
    int DaysAdd = ReadNumberOfDaysAdd();
    DateAddDays(DaysAdd, Date);
    printf("\nThe date after adding [%d] is %d/%d/%d", DaysAdd, Date.Day, Date.Month, Date.Year);
    system("pause>0");
    return 0;
}
