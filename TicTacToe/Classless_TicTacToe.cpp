#include <iostream>
using namespace std;

//Variables
bool KeepAlive = true;
int TempPosition;
char Positions[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
char UsedPositions[9];
int PlayerPositions[9];
int AiPositions[9];
int WinConditions[9][3] =  {{1, 2, 3},
                            {1, 5, 9},
                            {1, 4, 7},
                            {2, 5, 8},
                            {3, 6, 9},
                            {3, 5, 7},
                            {4, 5, 6},
                            {7, 8, 9}};

//Functions
void Display()
{
    int size = 9;
    for (int i = 0; i < size; i++)
    {
        
        if ( i == 2 || i == 5 || i == 8)
        {
            printf(" %c ", Positions[i]);
            cout << endl;
        }
        else {
            printf(" %c |", Positions[i]);
        }
    }
}

void PlayerInput()
{
    printf("Where do you want to put the knott?: ");
    cin >> TempPosition;
}

void InputFailed(bool Player=true)
{
    if (Player)
    {
        Display();
        printf("That positions already looks like it's been taken, please pick again!\n");
        PlayerInput();
    }
}

void UpdateBoard()
{
    UsedPositions[TempPosition-1] = (char) TempPosition;
    PlayerPositions[TempPosition-1] = TempPosition;
    Positions[TempPosition-1] = 'x';
}

void PositonCheck(bool Player=true)
{
    int size = 9;
    for (int i = 0; i < size; i++ )
    {
        if (UsedPositions[i-1] == (int) TempPosition)
        {
            InputFailed(Player);
        }
    }
    UpdateBoard();
}

void WinCheck()
{
    bool win[3] = {false, false, false};
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 3; i++)
        {
            for (int t = 0; t < 9; t++)
            {
                if (WinConditions[i][j] == PlayerPositions[])
                {
                    win[j] = true;
                }
            }
        }
    }
    if (win[0] == true && win[1] == true && win[2])
    {
        printf("Player wins! Hurray!");
        KeepAlive = false;
    }
}

int main()
{
    while (KeepAlive)
    {
        Display();
        PlayerInput();
        PositonCheck(true);
        WinCheck();
    }
    return 0;
}