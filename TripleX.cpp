#include <iostream>
#include <ctime>

void PrintIntroduction(int Difficulty)
{
//This is the welcoming message
    std::cout;
    std::cout << "You're a anti-bomb agent defusing a bomb level " << Difficulty << ".\n";
    std::cout << "You need to enter the correct code to still alive and possibly defuse this bomb...\n\n";

}

//The term "VOID" means that this function will return no data, thats why we don't use "return 0" in the end.
bool PlayGame(int Difficulty) 
{
    PrintIntroduction(Difficulty);
    
    //Declare the constant code
    const int CodeA = rand() % Difficulty + Difficulty;
    const int CodeB = rand() % Difficulty + Difficulty;
    const int CodeC = rand() % Difficulty + Difficulty;

    //Declare three number code
    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;

    //Print CodeSum and CodeProduct to the terminal
    std::cout << "+ The are three numbers in the screen...\n";
    std::cout << "+ And the numbers are add-up to: " << CodeSum << "\n";
    std::cout << "+ Also, the product of these numbers is: " << CodeProduct << "\n\n";
    
    //Declare the player's guesses
    int GuessA, GuessB, GuessC;

    std::cout << "+ Which are these numbers?" << std::endl;
    std::cin  >> GuessA >> GuessB >> GuessC;
    
    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    std::cout << "\n+ The sum of these is: " << GuessSum; 
    std::cout << "\n+ The product of these is: " << GuessProduct; 

    //Feedback to the player
    if (GuessSum == CodeSum && GuessProduct == CodeProduct)
    {
        std::cout << "\n\n+++ Correct answer!! Be ready for the next code... +++\n\n";
        return true;
    }
    else 
    {
        std::cout << "\n\n+++ Wrong answer, the bomb detonates!! TRY AGAIN +++\n\n";
        return false;
    } 
}

int main()
{
    srand(time(NULL)); //Create new random sequence based on time of day

    int LevelDifficulty = 1;
    const int MaxLevel = 5;
    
    while (LevelDifficulty <= MaxLevel) //Loop the game until all levels are completed
    {
        bool bLevelComplete = PlayGame(LevelDifficulty);

        std::cin.clear();  //Clears any errors
        std::cin.ignore();  //Discards the buffer

        if (bLevelComplete)
        {
            ++LevelDifficulty;
        }
    }
        std::cout << "\n+++++++++++++++++++++++++++++++++++++++++++++++\n";
        std::cout << "Great job!! You have defused the bomb! Now get out of there.\n";
        std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++\n\n";

    return 0;
}