//Replicated TicTacToe / Knots and Crosses game that people play.
//I feel like I've done something cursed here by trying to use a class for everything.
//I might just make what I think is a standard way of doing this soon.


#include <iostream>
#include <stdlib.h>
#include "tictactoe.h" 

class Screen {

    //Super Secret AI algorithm I swear. Basically machine learning here.
    private:
    bool MoveIsUsed;

    void aiMove()
    {
        unsigned int move = std::rand() % 9 + 1;
        for (unsigned int i = 0; i < 9; i++)
        {
            if (UsedMoves[i] == move)
            {
                MoveIsUsed = true; 
            }
        }

        if (MoveIsUsed)
        {
            RejectMove(false);
        }

        else
        {
            UsedMoves[(int) move] = move;
            Position[(int) move] = 'o';
            playerMoveInitalise();
        }
    }
    
    void playerMove(char move)
    {
        //Checking if move has places has been used already.
        for (int i = 0; i < 9; i++)
        {
            if (UsedMoves[i] == move)
            {
                MoveIsUsed = true;
            }
        }

        if (MoveIsUsed)
        {
            RejectMove(MoveIsUsed);
        }

        else
        {
            UsedMoves[(int) move] = move;
            Position[(int) move] = 'x';
        }
    }

    void RejectMove(bool Player)
    {
        if (Player)
        {
            MoveIsUsed = false;
            printf("Sorry that position has already been taken.\n");
            display();
            playerMoveInitalise();

        }
        else
        {
            MoveIsUsed = true;
            aiMove();
        }
    }


    // Callable functions. 
    public:
    void display()
    {
        printf("%c | %c | %c\n%c | %c | %c\n%c | %c | %c\n", Position[0],Position[1],Position[2],Position[3],Position[4],Position[5],Position[6],Position[7],Position[8]);
    }
    
    void playerMoveInitalise()
    {
        char Input;
        printf("Where do you want to put knott?: ");
        std::cin >> Input;
        playerMove(Input);
    }
};

Screen Output;

bool GameStart()
{
    Output.display();
    Output.playerMoveInitalise();
    bool state = true;
    return state;
}


int main()
{
    bool KeepActive = true; 
    char Position[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
    char SuggestedMove;
    unsigned int acceptedMoveCounter;
    char UsedMoves[9];
    while (KeepActive == true)
    {
        GameStart();
    }

    return 0;
}