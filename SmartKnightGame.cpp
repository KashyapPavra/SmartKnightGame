#include <iostream>
#include <ctime>
#include <string>

using namespace std;

int GameMenu()
{
    int Selected;
    cout << "\nWelcome to the SmartKnight Game!\n";
    cout << "\n*============ Menu ============*!\n";
    cout << "\n1. Play Game\n";
    cout << "2. Exit\n";
    cout << "Enter your option below (1 or 2)\n";
    if (Selected <= 1 || Selected >= 2)
    {
        while (Selected < 1 || Selected > 2)
        {
            cout << "Please enter 1 or 2\n";
            cin >> Selected;
        }
    }

    if (Selected == 1)
    {
        return 1;
    }
    else if (Selected == 2)
    {
        return 2;
    }
}
int GameDifficulty()
{
    system("clear");
    int Selected;
    cout << "\n*============ Select Difficulty for your Game ============*!\n";
    cout << "\n1. Easy\n";
    cout << "2. Medium\n";
    cout << "3. Hard\n";
    cout << "Enter your option below (1, 2 or 3)\n";
    cin >> Selected;
    if (Selected <= 1 || Selected >= 3)
    {
        while (Selected < 1 || Selected > 3)
        {
            cout << "Please enter 1,2 or 3\n";
            cin >> Selected;
        }
    }
    if (Selected == 1)
    {
        return 1;
    }
    else if (Selected == 2)
    {
        return 2;
    }
    else if (Selected == 3)
    {
        return 3;
    }
}
void PrintIntroduction(int Lives, int RequiredPowerups)
{
    system("clear");
    cout << "\nHello there Knight! You want to defeat the dragon?\n";
    cout << "\n****** You need " << RequiredPowerups << " Powerups to defeat the dragon ******\n";
    cout << "\n****** You have " << Lives << " chances to start with ******\n";
    cout << "\nSolve these puzzles and get the Power ups to defeat the dragon....\n \n";
}
void StartGame(int Difficulty, int &Lives, int RequiredPowerups)
{
    srand(time(NULL));
    const int CodeA = rand() % Difficulty + Difficulty,
              CodeB = rand() % Difficulty + Difficulty,
              CodeC = rand() % Difficulty + Difficulty;
    int PlayerPowerUp = 0;
    int CodeSum = CodeA + CodeB + CodeC;
    int CodeProd = CodeA * CodeB * CodeC;
    int PlayerGuessA;
    int PlayerGuessB;
    int PlayerGuessC;
    int GuessSum, GuessProd;
    while (PlayerPowerUp != RequiredPowerups && Lives != 0)
    {

        cout << "\n**** Guess the 3 Numbers in the puzzle to get a Power up\n";
        cout << "**** Numbers add up to " << CodeSum << endl;
        cout << "**** Numbers multiply to give " << CodeProd << endl;
        cout << "\nWhat's your answer?" << endl;
        cin >> PlayerGuessA >> PlayerGuessB >> PlayerGuessC;

        GuessSum = PlayerGuessA + PlayerGuessB + PlayerGuessC;
        GuessProd = PlayerGuessA * PlayerGuessB * PlayerGuessC;
        cout << "\nSo the sum will be add up to " << GuessSum << endl;
        cout << "and the multiplication is " << GuessProd << endl;

        //Result with Life
        if (GuessSum == CodeSum && GuessProd == CodeProd)
        {
            cout << "\nWell Done Knight, here is your Power up!\n";
            ++PlayerPowerUp;
            cout << "You have " << PlayerPowerUp << " Power ups, " << RequiredPowerups - PlayerPowerUp << " more Power ups to go!\n";
            cout << "\nYou still have " << Lives << " Lives\n";
        }
        else
        {
            cout << "\nYou FAILED Knight! You loose a life!\n";
            --Lives;
            cout << "You only have " << Lives << " Lives\n";
            cout << "You have " << PlayerPowerUp << " Power ups, " << RequiredPowerups - PlayerPowerUp << " more Power ups to go!\n";
        }
    }
    //If Life lost then game over
    if (Lives == 0)
    {
        cout << "\nXXXXXXXXXXX XXXXXXXXXXX XXXXXXXXXXX XXXXXXXXXXX\n\nYou could not get enough Power up so you DIED!\n\nXXXXXXXXXXX XXXXXXXXXXX XXXXXXXXXXX XXXXXXXXXXX\n";
    }
    if (RequiredPowerups == PlayerPowerUp)
    {
        cout << "\n+++++++ +++++++ +++++++ +++++++ \n\nYou did it!\nYou have killed the Dragon and Saved the Town from it's wrath!\n\n+++++++ +++++++ +++++++ +++++++ \n";
    }
}
void PlayGame()
{
    //PlayGame Difficulty
    int Difficulty = GameDifficulty();

    //Introduction with Lives
    int Lives = 10 - (Difficulty * 2);
    int RequiredPowerups = Difficulty * 2;
    PrintIntroduction(Lives, RequiredPowerups);

    //Game Starts
    StartGame(Difficulty, Lives, RequiredPowerups);
}
void GameOn()
{
    int MenuSelection;
    //Game Menu 1.PlayGame 2.Exit
    MenuSelection = GameMenu();
    if (MenuSelection == 1)
    {
        PlayGame();
    }
    else if (MenuSelection == 2)
    {
        exit(0);
    }
}

int main()
{
    system("clear");
    GameOn();
    return 0;
}