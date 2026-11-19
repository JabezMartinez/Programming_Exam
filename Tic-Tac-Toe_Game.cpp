// Activity #6 Tic-Tac-Toe Game
#include <iostream>
#include <iomanip> // for setw()
using namespace std;

char board[5][5]; // the game board (biggest boardSize is 5x5)
int boardSize; // boardSize of the board (3, 4 or 5)
int winLen; // how many in a row are needed to win

// shows the credits screen
void showCredits() {
    cout << "\n==============================\n";
    cout << "          CREDITS\n";
    cout << "==============================\n";
    cout << "Made By: Jabez A. Martinez\n";
    cout << "==============================\n";
}

// asks yes or no, keeps asking until the answer is y or n
bool askAgain(string message) {
    char answer;
    while (true) {
        cout << "\n" << message << " (y/n): ";
        cin >> answer;
        if (answer == 'y' || answer == 'Y') {
            return true;
        }
        if (answer == 'n' || answer == 'N') {
            return false;
        }
        cout << "Please enter y or n only.\n";
    }
}

// shows the main menu
void showMenu() {
    cout << "\n==============================\n";
    cout << "         TIC-TAC-TOE\n";
    cout << "==============================\n";
    cout << "1. Start\n";
    cout << "2. Credits\n";
    cout << "3. Quit\n";
    cout << "Enter choice: ";
}

// lets the players choose the difficulty (the harder, the bigger the board)
void chooseDifficulty() {
    int level;
    cout << "\nSelect Difficulty:\n";
    cout << "1. Easy (3x3 board, 3 in a row)\n";
    cout << "2. Normal (4x4 board, 4 in a row)\n";
    cout << "3. Hard (5x5 board, 4 in a row)\n";
    cout << "Enter choice: ";
    cin >> level;

    if (level == 2) {
        boardSize = 4;
        winLen = 4;
    }
    else if (level == 3) {
        boardSize = 5;
        winLen = 4;
    }
    else {
        boardSize = 3; // easy is also the default
        winLen = 3;
    }
}

// makes all the spots empty
void resetBoard() {
    for (int i = 0; i < boardSize; i++) {
        for (int j = 0; j < boardSize; j++) {
            board[i][j] = ' ';
        }
    }
}

// prints the board, empty spots show their number so players know what to type
void displayBoard() {
    cout << "\n";
    for (int i = 0; i < boardSize; i++) {
        for (int j = 0; j < boardSize; j++) {
            if (board[i][j] == ' ') {
                cout << " " << setw(2) << (i * boardSize + j + 1) << " ";
            } else {
                cout << " " << setw(2) << board[i][j] << " ";
            }
            if (j < boardSize - 1) {
                cout << "|";
            }
        }
        cout << "\n";
        if (i < boardSize - 1) {
            for (int k = 0; k < boardSize; k++) {
                cout << "----";
                if (k < boardSize - 1) {
                    cout << "+";
                }
            }
            cout << "\n";
        }
    }
    cout << "\n";
}

// puts the player's mark on the chosen spot, returns false if the move is not allowed
bool placeMove(int spot, char mark) {
    if (spot < 1 || spot > boardSize * boardSize) {
        return false;
    }
    int row = (spot - 1) / boardSize;
    int col = (spot - 1) % boardSize;

    // spot is already taken if it is not empty
    if (board[row][col] != ' ') {
        return false;
    }
    board[row][col] = mark;
    return true;
}

// checks every spot in 4 directions (right, down, and the two diagonals)
// to see if the player has winLen marks in a row
bool checkWinner(char mark) {
    int dr[4] = {0, 1, 1, 1};
    int dc[4] = {1, 0, 1, -1};

    for (int i = 0; i < boardSize; i++) {
        for (int j = 0; j < boardSize; j++) {
            for (int d = 0; d < 4; d++) {
                int count = 0;
                for (int k = 0; k < winLen; k++) {
                    int r = i + dr[d] * k;
                    int c = j + dc[d] * k;
                    // stop if we go outside the board
                    if (r < 0 || r >= boardSize || c < 0 || c >= boardSize) {
                        break;
                    }
                    if (board[r][c] == mark) {
                        count++;
                    } else {
                        break;
                    }
                }
                if (count == winLen) {
                    return true;
                }
            }
        }
    }
    return false;
}

// plays one full game
void runGame() {
    int spot;
    int moves = 0;
    char current = 'X';
    bool gameOver = false;

    cout << "\nPlayer 1 = X, Player 2 = O\n";

    chooseDifficulty();
    resetBoard();

    while (!gameOver) {
        displayBoard();
        cout << "Player " << current << ", choose a spot (1-" << boardSize * boardSize << "): ";
        cin >> spot;

        if (placeMove(spot, current) == false) {
            cout << "Invalid move! Try again.\n";
            continue;
        }

        moves++;

        if (checkWinner(current)) {
            displayBoard();
            cout << "Player " << current << " wins! Congratulations!\n";
            gameOver = true;
        }
        else if (moves == boardSize * boardSize) {
            displayBoard();
            cout << "It's a draw!\n";
            gameOver = true;
        }
        else {
            // switch turn
            if (current == 'X') {
                current = 'O';
            } else {
                current = 'X';
            }
        }
    }
}

int main() {
    int choice;

    do {
        showMenu();
        cin >> choice;

        if (choice == 1) {
            do {
                runGame();
            } while (askAgain("Play again?"));
        }
        else if (choice == 2) {
            showCredits();
        }
        else if (choice == 3) {
            cout << "Thanks for playing!\n";
        }
        else {
            cout << "Invalid choice!\n";
        }
    } while (choice != 3);

    return 0;
}
