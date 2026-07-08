// Mini Project: Math quiz game (full solution).
// Tracks every question asked plus right/wrong counts and a pass/fail result.

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
    enOperationType OpType;
    enQuestionsLevel QuestionsLevel;
    int Answer = 0;
    int TrueAnswer = 0;
    bool AnswerResult = false;
};
struct stGameResult
{
    stQuestionInfo QuestionsList[100];
    short NumberOfQuestion = 0;
    enQuestionsLevel QuestionsLevel;
    enOperationType OperationType;
    short RightAnswersNumber = 0;
    short WrongAnswerNumber = 0;
    bool isPass = false;
};
int SimpleCalculator(short Number1, short Number2, enOperationType OpType)
{
    switch (OpType)
    {
    case enOperationType::Add:
        return Number1 + Number2;
    case enOperationType::Sub:
        return Number1 - Number2;
    case enOperationType::Mul:
        return Number1 * Number2;
    case enOperationType::Div:
        return Number1 / Number2;
    }
}
int RandomNumber(int From, int To)
{
    int randNum = rand() % (To - From + 1) + From;
    return randNum;
}
short ReadNumberOfQuestion()
{
    short numberOfQuestion = 0;
    do
    {
        cout << "How many question do you went to answer ? ";
        cin >> numberOfQuestion;
    } while (numberOfQuestion <= 0);
    return numberOfQuestion;
}
enQuestionsLevel ReadQuestionsLevel()
{
    short Level = 1;
    do
    {
        cout << "Enter Question level : Easy [1], Med [2], Hard [3], or Mix [4] ? ";
        cin >> Level;

    } while (Level > 4 || Level < 1);
    return (enQuestionsLevel)Level;
}
enOperationType ReadOperationType()
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
    {
        QuestionsLevel = (enQuestionsLevel)RandomNumber(1, 3);
    }
    if (OperationType == enOperationType::Mex)
    {
        OperationType = (enOperationType)RandomNumber(1, 4);
    }

    switch (QuestionsLevel)
    {
    case enQuestionsLevel::Easy:
        QuestionInfo.Number1 = RandomNumber(0, 9);
        QuestionInfo.Number2 = RandomNumber(0, 9);
        QuestionInfo.TrueAnswer = SimpleCalculator(QuestionInfo.Number1, QuestionInfo.Number2,OperationType);
        QuestionInfo.QuestionsLevel = QuestionsLevel;
        return QuestionInfo;
    case enQuestionsLevel::Med:
        QuestionInfo.Number1 = RandomNumber(10, 99);
        QuestionInfo.Number2 = RandomNumber(10, 99);
        QuestionInfo.TrueAnswer = SimpleCalculator(QuestionInfo.Number1, QuestionInfo.Number2,OperationType);
        QuestionInfo.QuestionsLevel = QuestionsLevel;
        return QuestionInfo;
    case enQuestionsLevel::Hard:
        QuestionInfo.Number1 = RandomNumber(100, 999);
        QuestionInfo.Number2 = RandomNumber(100, 999);
        QuestionInfo.TrueAnswer = SimpleCalculator(QuestionInfo.Number1, QuestionInfo.Number2,OperationType);
        QuestionInfo.QuestionsLevel = QuestionsLevel;
        return QuestionInfo;
    }
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
int ReadPlayerAnswer()
{
    int Answer = 0;
    cin >> Answer;
    return Answer;
}
void CorrectAnswer(stGameResult GameResult, short NumberOfQuestion)
{
    if (GameResult.QuestionsList[NumberOfQuestion].Answer == GameResult.QuestionsList[NumberOfQuestion].TrueAnswer)
    {
        GameResult.QuestionsList[NumberOfQuestion].AnswerResult = true;
        GameResult.RightAnswersNumber++;
        cout << "Right answer" << endl;
    }
    else
    {
        GameResult.QuestionsList[NumberOfQuestion].AnswerResult = false;
        GameResult.WrongAnswerNumber++;
        cout << "Wrong answer" << endl;
        cout << "The Right answer is : " << GameResult.QuestionsList[NumberOfQuestion].TrueAnswer << endl;
    }
}
void GenerateAllQuestions(stGameResult &GameResult)
{
    for (short CurrentQuestion = 0; CurrentQuestion < GameResult.NumberOfQuestion; CurrentQuestion++)
    {
        GameResult.QuestionsList[CurrentQuestion] = CreatQuestion(GameResult.QuestionsLevel, GameResult.OperationType);
    }
}
void ShowQuestion(stGameResult GameResult, short NumberQuestion)
{
    cout << "\n";
    cout << "\nQuestion [" << NumberQuestion + 1 << "/" << GameResult.NumberOfQuestion << "]\n"
         << endl;
    cout << GameResult.QuestionsList[NumberQuestion].Number1 << endl;
    cout << OpChoiceName(GameResult.OperationType) << endl;
    cout << GameResult.QuestionsList[NumberQuestion].Number2 << endl;
    cout << "_______" << endl;
}
void AskAndCorrectQuestionListAnswer(stGameResult &GameResult)
{
    for (short i = 0; i < GameResult.NumberOfQuestion; i++)
    {
        ShowQuestion(GameResult, i);
        GameResult.QuestionsList[i].Answer = ReadPlayerAnswer();
        CorrectAnswer(GameResult, i);
    }
    GameResult.isPass = (GameResult.RightAnswersNumber >= GameResult.WrongAnswerNumber);
}
string FinalResult(bool Pass)
{
    if (Pass)
        return "Sucsid";
    else
        return "Field";
}
void ShowFinalResult(stGameResult GameResult)
{
    cout << "____________________________\n"
         << endl;
    cout << "The Final Result is " << FinalResult(GameResult.isPass) << endl;
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
void PlayGame()
{
    stGameResult GameResult;
    GameResult.NumberOfQuestion = ReadNumberOfQuestion();
    GameResult.QuestionsLevel = ReadQuestionsLevel();
    GameResult.OperationType = ReadOperationType();
    GenerateAllQuestions(GameResult);
    AskAndCorrectQuestionListAnswer(GameResult);
    ShowFinalResult(GameResult);
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
        PlayGame();
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