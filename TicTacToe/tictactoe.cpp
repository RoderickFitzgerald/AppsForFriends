//Replicated TicTacToe / Knots and Crosses game that people play.
#include <iostream>
#include <stdlib.h> 

class Screen {
    char Position[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
    char SuggestedMove;
    unsigned int acceptedMoveCounter;

    //Super Secret AI algorithm I swear. Basically machine learning here.
    private:

    char UsedMoves[9];
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
        for (unsigned int i = 0; i < 9; i++)
        {
            if (UsedMoves[i] == move)
            {
                MoveIsUsed = true;
            }
        }

        if (MoveIsUsed)
        {
            RejectMove(true);
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


int main()
{
    Screen Output;
    //Output.InitializeVariables();
    Output.display();
    Output.playerMoveInitalise();
    std::cin.get();
}