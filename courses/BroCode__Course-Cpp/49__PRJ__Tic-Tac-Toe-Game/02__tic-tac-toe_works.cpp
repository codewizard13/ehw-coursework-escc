/* ************************************************************
    BRO CODE COURSE: C++ Full Course for free
    - https://www.youtube.com/watch?v=-TkoO8Z07hI

    - Direct Link: https://youtu.be/-TkoO8Z07hI?si=t7MNvD3lhFB3ta1V&t=16038

    **** PROJECT: Tic-Tac-Toe Game ****

    Student: Eric Hepperle
    Created: 2026-10-06

    VERSION: 1.0

    STATUS: WIP

    Purpose:
    -

    📝 Lessons Learned:
    -

    References:
    -

    GitHub: https://github.com/codewizard13
    email: codewizard13@gmail.com
 ************************************************************ */

#include <iostream>
using namespace std;

// spaces = one dimensional array that will track which spots taken or occupied
void drawBoard(char *spaces);
void playerMove(char *spaces, char player);
void computerMove(char *spaces, char computer);
bool checkWinner(char *spaces, char player, char computer);
bool checkTie(char *spaces);

int main()
{
    char spaces[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};

    // Uncomment to test the tie scenario - enter 9 as the player move
    // char spaces[9] = {
    //     'X', 'O', 'X',
    //     'X', 'O', 'O',
    //     'O', 'X', ' '};

    char player = 'X';
    char computer = 'O';
    bool running = true;

    drawBoard(spaces);

    while (running)
    {
        playerMove(spaces, player);
        drawBoard(spaces); // redraw board to reflect changes

        if (checkWinner(spaces, player, computer))
        {
            running = false;
            break;
        }
        else if (checkTie(spaces))
        {
            running = false;
            break;
        }

        computerMove(spaces, computer);
        drawBoard(spaces);

        if (checkWinner(spaces, player, computer))
        {
            running = false;
            break;
        }
        else if (checkTie(spaces))
        {
            running = false;
            break;
        }
    }

    cout << "Thanks for playing!\n";
    cout << "***************************\n";
    return 0;
}

void drawBoard(char *spaces)
{
    cout << '\n';
    cout << "     |     |     " << '\n';
    cout << "  " << spaces[0] << "  |  " << spaces[1] << "  |  " << spaces[2] << "  " << '\n';
    cout << "_____|_____|_____" << '\n';
    cout << "     |     |     " << '\n';
    cout << "  " << spaces[3] << "  |  " << spaces[4] << "  |  " << spaces[5] << "  " << '\n';
    cout << "_____|_____|_____" << '\n';
    cout << "     |     |     " << '\n';
    cout << "  " << spaces[6] << "  |  " << spaces[7] << "  |  " << spaces[8] << "  " << '\n';
    cout << "     |     |     " << '\n';
    cout << '\n';
}

void playerMove(char *spaces, char player)
{
    int number; // the space number (1-9)

    do
    {
        cout << "Enter a spot to place a marker (1-9): ";
        cin >> number;
        number--; // decrement by one to get the actual index

        if (spaces[number] == ' ')
        {
            spaces[number] = player;
            break;
        }

    } while (!number > 0 || !number < 8); // user can only enter number 0-8
}

void computerMove(char *spaces, char computer)
{
    int number;
    srand(time(0));

    while (true)
    {
        // generate random num between 0-8
        number = rand() % 9;

        if (spaces[number] == ' ')
        {
            spaces[number] = computer;
            break;
        }
    }
}

bool checkWinner(char *spaces, char player, char computer)
{

    /* CHECK ROWS */

    // CHECK ROW 1 for winner
    // When all spaces in first row are equal and not blank spaces,
    if ((spaces[0] != ' ') && (spaces[0] == spaces[1]) && (spaces[1] == spaces[2]))
    {
        spaces[0] == player ? cout << "YOU WIN!\n" : cout << "You LOSE!\n";
    }
    // CHECK ROW 2 for winner
    else if ((spaces[3] != ' ') && (spaces[3] == spaces[4]) && (spaces[4] == spaces[5]))
    {
        spaces[3] == player ? cout << "YOU WIN!\n" : cout << "You LOSE!\n";
    }
    // CHECK ROW 3 for winner
    else if ((spaces[6] != ' ') && (spaces[6] == spaces[7]) && (spaces[7] == spaces[8]))
    {
        spaces[6] == player ? cout << "YOU WIN!\n" : cout << "You LOSE!\n";
    }

    /* CHECK COLUMNS */

    else if ((spaces[0] != ' ') && (spaces[0] == spaces[3]) && (spaces[3] == spaces[6]))
    {
        spaces[0] == player ? cout << "YOU WIN!\n" : cout << "You LOSE!\n";
    }
    else if ((spaces[1] != ' ') && (spaces[1] == spaces[4]) && (spaces[4] == spaces[7]))
    {
        spaces[1] == player ? cout << "YOU WIN!\n" : cout << "You LOSE!\n";
    }
    else if ((spaces[2] != ' ') && (spaces[2] == spaces[5]) && (spaces[5] == spaces[8]))
    {
        spaces[2] == player ? cout << "YOU WIN!\n" : cout << "You LOSE!\n";
    }

    /* CHECK DIAGONALS */

    else if ((spaces[0] != ' ') && (spaces[0] == spaces[4]) && (spaces[4] == spaces[8]))
    {
        spaces[0] == player ? cout << "YOU WIN!\n" : cout << "You LOSE!\n";
    }
    else if ((spaces[2] != ' ') && (spaces[2] == spaces[4]) && (spaces[4] == spaces[6]))
    {
        spaces[2] == player ? cout << "YOU WIN!\n" : cout << "You LOSE!\n";
    }
    else
    {
        return false;
    }

    return true;
}

bool checkTie(char *spaces)
{
    // 9 because there are only 9 spaces on the board
    for (int i = 0; i < 9; i++)
    {
        if (spaces[i] == ' ')
        {
            // we can continue
            return false;
        }
    }

    cout << "IT'S A TIE!\n";

    return true;
}
