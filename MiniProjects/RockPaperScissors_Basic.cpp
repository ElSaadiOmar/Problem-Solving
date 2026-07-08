// Mini Project: Rock-Paper-Scissors game (basic version).
// Reads the player's choice, generates a random computer choice, and compares them.

#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;
enum enGameChoice
{
    Stone = 1,
    Paper = 2,
    Scissors = 3,
};
int RandomNumber(int From, int To)
{
    int RanNum = rand() % (To - From + 1) + From;

    return RanNum;
}
short ReadeRoundNumber()
{
    int number = 0;
    do
    {
        cout << "How many Round 1 to 10 ?" << endl;
        cin >> number;
    } while (number < 1 || number > 10);
}
enGameChoice UserChoice()
{
    short Choice = 0;
    do
    {
        cout << "Select your choice: [1]Stone, [2]Paper, [3]Scissors ? ";
        cin >> Choice;
        switch (Choice)
        {
        case 1:
            return enGameChoice::Stone;
        case 2:
            return enGameChoice::Paper;
        case 3:
            return enGameChoice::Scissors;
        }
    } while (Choice < 1 || Choice > 3);
}
enGameChoice ComputerChoice()
{
    short Choice = RandomNumber(1, 3);
    switch (Choice)
    {
    case 1:
        return enGameChoice::Stone;
    case 2:
        return enGameChoice::Paper;
    case 3:
        return enGameChoice::Scissors;
    }
}
short IfPlayerWin(enGameChoice UserChoice, enGameChoice ComputerChoice)
{
    if (UserChoice == ComputerChoice)
        return -1;

    switch (ComputerChoice)
    {
    case enGameChoice::Stone:
        switch (UserChoice)
        {
        case enGameChoice::Paper:
            return 1;
        case enGameChoice::Scissors:
            return 0;
        }
    case enGameChoice::Paper:
        switch (UserChoice)
        {
        case enGameChoice::Stone:
            return 0;
        case enGameChoice::Scissors:
            return 1;
        }
    case enGameChoice::Scissors:
        switch (UserChoice)
        {
        case enGameChoice::Paper:
            return 0;
        case enGameChoice::Stone:
            return 1;
        }
    }
}
string ChoiceName(enGameChoice Choice)
{
    switch (Choice)
    {
    case 1:
        return "Stone";
    case 2:
        return "Paper";
    case 3:
        return "Scissors";
    }
}
void printRound(short RoundNumber, short &PlayerWon, short &ComputerWon, short &Draw)
{
    cout << "\nRound [" << RoundNumber << "] begins:\n\n";

    enGameChoice userChoice = UserChoice();
    enGameChoice computerChoice = ComputerChoice();

    cout << "\n_____________Round["
         << RoundNumber
         << "]______________\n"
         << endl;

    cout << "Your choice : " << ChoiceName(userChoice) << endl;
    cout << "Computer choice : " << ChoiceName(computerChoice) << endl;

    cout << "The winner : ";
    if (IfPlayerWin(userChoice, computerChoice) == 1)
    {
        system("color 2A");
        cout << "You win\n";
        PlayerWon++;
    }
    else if (IfPlayerWin(userChoice, computerChoice) == 0)
    {
        system("color 4A");
        cout << "Computer Win\n";
        ComputerWon++;
    }
    else
    {
        system("color 6A");
        cout << "[No Winner]\n";
        Draw++;
    }
    cout << "___________________________________\n\n";
}
void printResult(short number, short PlayerWon, short ComputerWon, short Draw)
{
    cout << "\t\t\t______________________________________________\n\n";
    cout << "\t\t\t\t     +++ G a m e  O v e r +++\n";
    cout << "\t\t\t______________________________________________\n\n";
    cout << "\t\t\t_______________ [Game Result ] _______________\n\n"
         << "\t\t\tGame Round\t: " << number << endl;
    cout << "\t\t\tPlayer won times : " << PlayerWon << endl;
    cout << "\t\t\tComputer won times : " << ComputerWon << endl;
    cout << "\t\t\tDraw times : " << Draw << endl;
    cout << "\t\t\tFinal Winner : ";
    if (PlayerWon > ComputerWon)
    {
        cout << "Player win" << endl;
        system("color 2A");
    }
    else if (PlayerWon < ComputerWon)
    {
        cout << "Computer win" << endl;
        system("color 4A");
    }
    else
    {
        cout << "No Winner" << endl;
        system("color 6A");
    }
    cout << "\t\t\t______________________________________________\n";
}
int main()
{
    char NewGame = ' ';
    srand((unsigned)time(NULL));
    do
    {
        system("cls");
        system("color 0F");
        short RoundNumber = ReadeRoundNumber();
        short PlayerWon = 0, ComputerWon = 0, Draw = 0;
        for (int i = 1; i <= RoundNumber; i++)
            printRound(i, PlayerWon, ComputerWon, Draw);
        printResult(RoundNumber, PlayerWon, ComputerWon, Draw);

        cout << "Do you want play a new game Y/N\n";
        cin >> NewGame;
    } while (NewGame == 'Y' || NewGame == 'y');
    return 0;
}