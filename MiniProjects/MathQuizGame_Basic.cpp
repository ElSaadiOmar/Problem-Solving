// Mini Project: Math quiz game (basic version).
// Generates arithmetic questions at different difficulty levels.

#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>
using namespace std;
enum enQuestionsLevel
{
    Easy = 1,
    Med = 2,
    Hard = 3,
    Mix = 4,
};
enum enOperationType
{
    Add = 1,
    Sub = 2,
    Mul = 3,
    Div = 4,
    Mex = 5,
};
struct stQuestionInfo
{
    short Number1 = 0;
    short Number2 = 0;
    char OperationType = ' ';
    int Answer = 0;
    int TrueAnswer = 0;
};
struct stGameResult
{
    short NumberOfQuestion = 0;
    enQuestionsLevel QuestionsLevel;
    enOperationType OperationType;
    short RightAnswersNumber = 0;
    short WrongAnswerNumber = 0;
};
int RandomNumber(int From, int To)
{
    int randNum = rand() % (To - From + 1) + From;
    return randNum;
}
short ReadNumberOfQuestion()
{
    short number = 0;
    do
    {
        cout << "How many question do you went to answer ? ";
        cin >> number;
    } while (number <= 0);
}
enQuestionsLevel QuestionsLevel()
{
    short Level = 1;
    do
    {
        cout << "Enter Question level : Easy [1], Med [2], Hard [3], or Mix [4] ? ";
        cin >> Level;

    } while (Level > 4 || Level < 1);
    return (enQuestionsLevel)Level;
}
enOperationType OperationType()
{
    short OpType = 0;
    do
    {
        cout << "Enter Operation type : Add [1], Sub [2], Mul [3], Div [4], or Mix [5] ? ";
        cin >> OpType;
    } while (OpType < 1 || OpType > 5);
    return (enOperationType)OpType;
}
stQuestionInfo CreatQuestion(enQuestionsLevel QuestionsLevel, enOperationType OperationType)
{
    stQuestionInfo QuestionInfo;
    if (QuestionsLevel == enQuestionsLevel::Mix)
        QuestionsLevel = (enQuestionsLevel)RandomNumber(1, 3);
    switch (QuestionsLevel)
    {
    case enQuestionsLevel::Easy:
        QuestionInfo.Number1 = RandomNumber(0, 9);
        QuestionInfo.Number2 = RandomNumber(0, 9);
        break;
    case enQuestionsLevel::Med:
        QuestionInfo.Number1 = RandomNumber(10, 99);
        QuestionInfo.Number2 = RandomNumber(10, 99);
        break;
    case enQuestionsLevel::Hard:
        QuestionInfo.Number1 = RandomNumber(100, 999);
        QuestionInfo.Number2 = RandomNumber(100, 999);
        break;
    }
    if (OperationType == enOperationType::Mex)
        OperationType = (enOperationType)RandomNumber(1, 4);
    switch (OperationType)
    {
    case enOperationType::Add:
        QuestionInfo.OperationType = '+';
        QuestionInfo.TrueAnswer = QuestionInfo.Number1 + QuestionInfo.Number2;
        break;
    case enOperationType::Sub:
        QuestionInfo.OperationType = '-';
        QuestionInfo.TrueAnswer = QuestionInfo.Number1 - QuestionInfo.Number2;
        break;
    case enOperationType::Mul:
        QuestionInfo.OperationType = 'x';
        QuestionInfo.TrueAnswer = QuestionInfo.Number1 * QuestionInfo.Number2;
        break;
    case enOperationType::Div:
        QuestionInfo.OperationType = '/';
        QuestionInfo.TrueAnswer = QuestionInfo.Number1 / QuestionInfo.Number2;
        break;
    }
    return QuestionInfo;
}
void ShowQuestion(stQuestionInfo QuestionInfo)
{
    cout << QuestionInfo.Number1 << endl;
    cout << QuestionInfo.OperationType << endl;
    cout << QuestionInfo.Number2 << endl;
    cout << "_______" << endl;
}
bool CheckAnswer(stQuestionInfo Info)
{
    if (Info.Answer == Info.TrueAnswer)
    {
        cout << "Right answer" << endl;
        system("color 2F");
        return true;
    }
    else
    {
        cout << "Wrong answer" << endl;
        cout << "The Right answer is : " << Info.TrueAnswer<<endl;
        system("color 4F");
        return false;
    }
}
stGameResult PlayGame(short NumbersOfQuestion)
{
    stGameResult GameResult;
    short RightAnswer = 0, WrongAnswer = 0;
    GameResult.NumberOfQuestion = NumbersOfQuestion;
    GameResult.QuestionsLevel = QuestionsLevel();
    GameResult.OperationType = OperationType();
    for (short CurrentQuestion = 0; CurrentQuestion < NumbersOfQuestion; CurrentQuestion++)
    {
        cout << "\nQuestion [" << CurrentQuestion + 1 << "/" << NumbersOfQuestion << "]" << endl;
        stQuestionInfo QuestionInfo = CreatQuestion(GameResult.QuestionsLevel, GameResult.OperationType);
        ShowQuestion(QuestionInfo);
        cin >> QuestionInfo.Answer;
        if (CheckAnswer(QuestionInfo))
            RightAnswer++;
        else
            WrongAnswer++;
    }
    GameResult.RightAnswersNumber = RightAnswer;
    GameResult.WrongAnswerNumber = WrongAnswer;
    return GameResult;
}
string LevelChoiceName(enQuestionsLevel Choice)
{
    string arrGameChoices[4] = {"Easy", "Med", "Hard", "Mix"};
    return arrGameChoices[Choice - 1];
}
string OpChoiceName(enOperationType Choice)
{
    string arrGameChoices[5] = {"Add", "Sub", "Mult", "Div", "Mix"};
    return arrGameChoices[Choice - 1];
}
string FinalResult(stGameResult GameResult)
{
    if (GameResult.RightAnswersNumber >= GameResult.WrongAnswerNumber)
    {
        system("color 2F");
        return "Sucsid";
    }
    else if (GameResult.RightAnswersNumber < GameResult.WrongAnswerNumber)
    {
        system("color 4F");
        return "Field";
    }
}
void ShowFinalResult(stGameResult GameResult)
{
    cout << "____________________________\n"
         << endl;
    cout << "The Final Result is " << FinalResult(GameResult) << endl;
    cout << "____________________________\n"
         << endl;
    cout << "____________________________\n\n";
    cout << "The Number of question : " << GameResult.NumberOfQuestion << endl;
    cout << "The Questions Level : " << LevelChoiceName(GameResult.QuestionsLevel) << endl;
    cout << "The Operation Type : " << OpChoiceName(GameResult.OperationType) << endl;
    cout << "The Right answer : " << GameResult.RightAnswersNumber << endl;
    cout << "The wrong answer : " << GameResult.WrongAnswerNumber << endl;
    cout << "____________________________\n\n";
}
void ResetScreen()
{
    system("cls");
    system("color 0F");
}
void StartGame()
{
    char PlayAgain = 'Y';
    do
    {
        ResetScreen();
        stGameResult GameResult = PlayGame(ReadNumberOfQuestion());
        ShowFinalResult(GameResult);

        cout << "Do you want to play again? Y/N? ";
        cin >> PlayAgain;
    } while (PlayAgain == 'Y' || PlayAgain == 'y');
}
int main()
{
    srand((unsigned)time(NULL));
    StartGame();
    return 0;
}