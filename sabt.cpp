#include <iostream>
using namespace std;

char board[3][3]; // 3x3 game board

void initializeBoard() {
    char num = '1';
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = num++;
        }
    }
}

void printBoard() {
    cout << endl;
    for (int i = 0; i < 3; i++) {
        cout << " ";
        for (int j = 0; j < 3; j++) {
            cout << board[i][j];
            if (j < 2) cout << " | ";
        }
        cout << endl;
        if (i < 2) cout << "---|---|---" << endl;
    }
    cout << endl;
}

bool placeMark(int choice, char mark) {
    int row = (choice - 1) / 3;
    int col = (choice - 1) % 3;
    
    if (choice < 1 || choice > 9 || board[row][col] == 'X' || board[row][col] == 'O') {
        return false;
    } else {
        board[row][col] = mark;
        return true;
    }
}

bool checkWin(char mark) {
    // Check rows, columns, and diagonals
    for (int i = 0; i < 3; i++) {
        if ((board[i][0] == mark && board[i][1] == mark && board[i][2] == mark) ||
            (board[0][i] == mark && board[1][i] == mark && board[2][i] == mark))
            return true;
    }
    if ((board[0][0] == mark && board[1][1] == mark && board[2][2] == mark) ||
        (board[0][2] == mark && board[1][1] == mark && board[2][0] == mark))
        return true;
    return false;
}

bool checkDraw() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] != 'X' && board[i][j] != 'O')
                return false;
    return true;
}

int main() {
    initializeBoard();
    char player = 'X';
    int choice;
    bool game_over = false;

    cout << "Tic Tac Toe Game (2 Players)\n";

    while (!game_over) {
        printBoard();
        cout << "Player " << player << ", enter your move (1-9): ";
        cin >> choice;

        if (!placeMark(choice, player)) {
            cout << "Invalid move! Try again.\n";
            continue;
        }

        if (checkWin(player)) {
            printBoard();
            cout << "Player " << player << " wins!\n";
            game_over = true;
        } else if (checkDraw()) {
            printBoard();
            cout << "It's a draw!\n";
            game_over = true;
        } else {
            player = (player == 'X') ? 'O' : 'X';
        }
    }
    return 0;
}
