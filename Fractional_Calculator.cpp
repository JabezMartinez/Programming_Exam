// Activity #5: Factorial Calculator
#include <iostream>
using namespace std;

// shows the credits screen
void showCredits() {
    cout << "\n==============================\n";
    cout << "           CREDITS\n";
    cout << "==============================\n";
    cout << "  Made By: Jabez A. Martinez\n";
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
    cout << "     FACTORIAL CALCULATOR\n";
    cout << "==============================\n";
    cout << "1. Start\n";
    cout << "2. Credits\n";
    cout << "3. Quit\n";
    cout << "Enter choice: ";
}

// computes n! using a for loop (n * (n-1) * ... * 1)
long long factorial(int n) {
    long long result = 1;
    for (int i = 1; i <= n; i++) {
        result = result * i;
    }
    return result;
}

// does one factorial calculation
void runFactorial() {
    int num;

    cout << "\nEnter a number: ";
    cin >> num;

    if (num < 0) {
        cout << "Factorial is not defined for negative numbers!\n";
    }
    else if (num > 20) {
        // 21! is too big for long long
        cout << "Number is too big! Please enter 20 or lower.\n";
    }
    else {
        cout << num << "! = " << factorial(num) << "\n";
    }
}

int main() {
    int choice;

    do {
        showMenu();
        cin >> choice;

        if (choice == 1) {
            do {
                runFactorial();
            } while (askAgain("Try another number?"));
        }
        else if (choice == 2) {
            showCredits();
        }
        else if (choice == 3) {
            cout << "Goodbye!\n";
        }
        else {
            cout << "Invalid choice!\n";
        }
    } while (choice != 3);

    return 0;
}
