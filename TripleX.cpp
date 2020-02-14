#include <iostream>

void PrintIntroduction()
{
//This is the welcoming message
    std::cout;
    std::cout << "+ You're a anti-bomb agent defusing a bomb.\n";
    std::cout << "+ You need to enter the correct code to still alive and possibly defuse this bomb...\n\n";

}

bool PlayGame() //The term "VOID" means that this function will return no data, thats why we don't use "return 0" in the end.
{
    PrintIntroduction();
    
    //Declare the constant code
    const int CodeA = 4;
    const int CodeB = 6;
    const int CodeC = 7;

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
        std::cout << "\n\n+++ Wrong answer, the bomb detonates. +++\n\n";
        return false;
    } 
}

int main()
{
    while(true)
    {
        bool bLevelComplete = PlayGame();

        std::cin.clear();  //Clears any errors
        std::cin.ignore();  //Discards the buffer
    }
    return 0;
}