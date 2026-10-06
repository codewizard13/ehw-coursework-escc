/* ************************************************************
    BRO CODE COURSE: C++ Full Course for free
    - https://www.youtube.com/watch?v=-TkoO8Z07hI

    - Direct Link: https://youtu.be/-TkoO8Z07hI?si=t7MNvD3lhFB3ta1V&t=16038

    **** PROJECT: Tic-Tac-Toe Game ****

    Student: Eric Hepperle
    Created: 2026-10-06

    VERSION: 1.0

    STATUS: Fully Working

    Purpose:
    - Portfolio Project : Create console-based Tic-Tac-Toe Game
    - Demonstrates a working game with a flaw in checkWinner() (see below)
    - NOTE: checkWinner() and checkTie() are incomplete — all other functions are fully working
    - NOTE: May or may-not need to include <ctime>

    📝 Lessons Learned:
    - #TIP: When we pass an array to a function it decays to a pointer

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
    char player = 'X';
    char computer = 'O';
    bool running = true;

    drawBoard(spaces);

    while (running)
    {
        playerMove(spaces, player);
        drawBoard(spaces); // redraw board to reflect changes

        if (checkWinner(spaces, player, computer)) {
            running = false;
            break;
        }

        computerMove(spaces, computer);
        drawBoard(spaces);
                
        if (checkWinner(spaces, player, computer)) {
            running = false;
            break;
        }
    }

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

    while(true){
        // generate random num between 0-8
        number = rand() % 9;

        if (spaces[number] == ' ') {
            spaces[number] = computer;
            break;
        }
    }

}

bool checkWinner(char *spaces, char player, char computer)
{
    // #TIP: Normally he'd use a switch for this, but using ifs is easier
    //  for beginners.
    if (spaces[0] == spaces[1] && spaces[1] == spaces[2]){
        spaces[0] == player ? cout << "YOU WIN!\n" : cout << "You LOSE!\n";
    }


    return 0;
}

bool checkTie(char *spaces)
{

    return 0;
}

/*

#GOTCHA: After entering a number (eg, 9) as the player, the game says 'You LOSE!'

The reason that we lost is because we are checking to see if the first row all has the same characters. Theyre technically all empty spaces, so our program thinks that somebody won

*/