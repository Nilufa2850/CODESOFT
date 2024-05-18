/*                  Task 3 
                TIC-TAC-TOE GAME

Build a simple console-based Tic-Tac-Toe game that
allows two players to play against each other
Game Board: Create a 3x3 grid as the game board.
Players: Assign "X" and "O" to two players.
Display Board: Show the current state of the board.
Player Input: Prompt the current player to enter their move.
Update Board: Update the game board with the player's move.
Check for Win: Check if the current player has won.
Check for Draw: Determine if the game is a draw.
Switch Players: Alternate turns between "X" and "O" players.
Display Result: Show the result of the game (win, draw, or ongoing).
Play Again: Ask if the players want to play another game.*/

#include <iostream>
#include <stdlib.h>
using namespace std;

char square[3][3] = {
    {'1', '2', '3'},
    {'4', '5', '6'},
    {'7', '8', '9'}
};

int player = 0, i, choice;
char mark;

int isPlaceEmpty(int row, int col) {
    return (square[row][col] != 'X' && square[row][col] != 'O');
}

void enterChoice() {
    cout << "Player " << player + 1 << ", Enter Marking Place: ";
    cin >> choice;
}

void selectPlayer() {
    player = (player + 1) % 2;
}

void selectMark() {
    mark = (player == 1) ? 'O' : 'X';
}

void gameStatus() {
    if (i == 1) {
        cout << "Player " << player + 1 << " won\n";
    } else {
        cout << "Game draw\n";
    }
    cout << "\n\n#####################################################\n\n";
}

int checkWinner() {
    for (int row = 0; row < 3; row++) {
        if (square[row][0] == square[row][1] && square[row][1] == square[row][2])
            return 1;
    }

    for (int col = 0; col < 3; col++) {
        if (square[0][col] == square[1][col] && square[1][col] == square[2][col])
            return 1;
    }

    if (square[0][0] == square[1][1] && square[1][1] == square[2][2])
        return 1;
    else if (square[0][2] == square[1][1] && square[1][1] == square[2][0])
        return 1;

    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            if (isPlaceEmpty(row, col))
                return -1;
        }
    }

    return 0;
}

void drawBoard() {
    system("cls");
    cout << "\n\n#################### Tic Tac Toe ####################\n\n";
    cout << "First Player X \nSecond Player O \n\n\n";

    for (int row = 0; row < 3; row++) {
        cout << "     |     |     \n";
        cout << "  " << square[row][0] << "  |  " << square[row][1] << "  |  " << square[row][2] << "  \n";
        if (row != 2)
            cout << "_____|_____|_____\n";
    }
    cout << "\n\n#####################################################\n\n";
}

void fillMark() {
    int row = 0, col = 0;
    int place = 0;
    int flag = 0;
    for (row = 0; row < 3; row++) {
        for (col = 0; col < 3; col++) {
            place = ((row * 3) + (col + 1));

            if ((choice == place) && isPlaceEmpty(row, col)) {
                square[row][col] = mark;
                flag = 1;
                break;
            }
        }
        if (flag == 1) break;
    }

    if (flag == 0) {
        cout << "\n\n#####################################################\n\n";
        cout << "Place is either already used or incorrect!";
        getchar();
        player--;
    } else {
        i = checkWinner();
    }
}

void resetBoard() {
    char a = '1';
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            square[row][col] = a++;
        }
    }
    player = 0;
}

int main() {
    int playAgain = 1;
    while (playAgain == 1) {
        resetBoard();
        do {
            drawBoard();
            selectPlayer();
            selectMark();
            enterChoice();
            fillMark();
        } while (i == -1);

        drawBoard();
        gameStatus();
        cout << "Do you want to play again? (1 for Yes / 0 for No): ";
        cin >> playAgain;
    }

    return 0;
}
