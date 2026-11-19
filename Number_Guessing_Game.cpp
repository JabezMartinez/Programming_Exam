// Activity #3 Number Guessing Game
#include <iostream>
#include <cstdlib> // for rand() and srand()
#include <ctime> // for time()
using namespace std;

// shows the credits screen
void showCredits() {
    cout << "\n==============================\n";
    cout << "           CREDITS\n";
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
    cout << "    NUMBER GUESSING GAME\n";
    cout << "==============================\n";
    cout << "1. Start\n";
    cout << "2. Credits\n";
    cout << "3. Quit\n";
    cout << "Enter choice: ";
}

// gives the computer's secret number from 1 up to the max number
int pickNumber(int maxNumber) {
    return rand() % maxNumber + 1;
}

// plays one round of the game, returns true if the player guessed it
bool playGame(int secret, int maxTries) {
    int guess;
    int tries = 0;

    while (tries < maxTries) {
        cout << "Guess #" << tries + 1 << " of " << maxTries << ": ";
        cin >> guess;
        tries++;
        if (guess > secret) {
            cout << "Too high! Try again.\n";
        }
        else if (guess < secret) {
            cout << "Too low! Try again.\n";
        }
        else {
            cout << "Correct! You got it in " << tries << " tries!\n";
            return true;
        }
    }

    // ran out of tries
    cout << "Game over! The number was " << secret << ".\n";
    return false;
}

// chooses the difficulty and plays one round
void runGame() {
    int level, maxNumber, maxTries;

    cout << "\nSelect Difficulty:\n";
    cout << "1. Easy (1-20, 10 tries)\n";
    cout << "2. Normal (1-50, 7 tries)\n";
    cout << "3. Hard (1-100, 5 tries)\n";
    cout << "Enter choice: ";
    cin >> level;

    if (level == 2) {
        maxNumber = 50;
        maxTries = 7;
    }
    else if (level == 3) {
        maxNumber = 100;
        maxTries = 5;
    }
    else {
        maxNumber = 20; // easy is also the default
        maxTries = 10;
    }

    cout << "\nI picked a number from 1 to " << maxNumber << ". Can you guess it?\n";
    int secret = pickNumber(maxNumber);
    playGame(secret, maxTries);
}

int main() {
    srand(time(0)); // makes the random number different every run
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
