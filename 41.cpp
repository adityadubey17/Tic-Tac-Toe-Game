#include <iostream>
using namespace std;

char board[3][3] = { { '1', '2', '3' }, { '4', '5', '6' }, { '7', '8', '9' } };
char currentPlayer = 'X';

// Function to draw the Tic-Tac-Toe board
void drawBoard() {
    system("clear"); // Use "cls" on Windows
    cout << "Tic-Tac-Toe Game" << endl << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << board[i][j];
            if (j < 2) cout << " | ";
        }
        cout << endl;
        if (i < 2) cout << "---------" << endl;
    }
    cout << endl;
}

// Function to handle player's move
void makeMove() {
    int choice;
    cout << "Player " << currentPlayer << ", enter a number (1-9): ";
    cin >> choice;

    int row = (choice - 1) / 3;
    int col = (choice - 1) % 3;

    if (choice < 1 || choice > 9 || board[row][col] == 'X' || board[row][col] == 'O') {
        cout << "Invalid move. Try again." << endl;
        makeMove();
    } else {
        board[row][col] = currentPlayer;
    }
}

// Function to toggle players
void togglePlayer() {
    if (currentPlayer == 'X') {
        currentPlayer = 'O';
    } else {
        currentPlayer = 'X';
    }
}

// Function to check for a win
bool checkWin() {
    // Check rows
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer) {
            return true;
        }
    }

    // Check columns
    for (int j = 0; j < 3; j++) {
        if (board[0][j] == currentPlayer && board[1][j] == currentPlayer && board[2][j] == currentPlayer) {
            return true;
        }
    }

    // Check diagonals
    if (board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer) {
        return true;
    }
    if (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer) {
        return true;
    }

    return false;
}

int main() {
    int moves = 0;

    while (true) {
        drawBoard();
        makeMove();
        moves++;

        if (checkWin()) {
            drawBoard();
            cout << "Player " << currentPlayer << " wins!" << endl;
            break;
        } else if (moves == 9) {
            drawBoard();
            cout << "It's a draw!" << endl;
            break;
        }

        togglePlayer();
    }

    return 0;
}
