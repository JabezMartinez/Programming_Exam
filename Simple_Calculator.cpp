//Activity #1: Simple Calculator
#include <iostream>
using namespace std;

// shows the credits screen
void showCredits() {
    cout << "\n==============================\n";
    cout << "            CREDITS\n";
    cout << "==============================\n";
    cout << " Made By: Jabez A. Martinez\n";
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
    cout << "          CALCULATOR\n";
    cout << "==============================\n";
    cout << "1. Start\n";
    cout << "2. Credits\n";
    cout << "3. Quit\n";
    cout << "Enter choice: ";
}

//function to add two numbers
double add(double a, double b) {
    return a + b;
}

//function to subtract b from a
double subtract(double a, double b) {
    return a - b;
}

//function to multiply two numbers
double multiply(double a, double b) {
    return a * b;
}

//function to divide a by b
double divide(double a, double b) {
    return a / b;
}

// does one calculation
void runCalculator() {
    double num1, num2, result;
    char op;

    cout << "\nEnter First Number: ";
    cin >> num1;
    cout << "Enter Operator (+, -, *, /): ";
    cin >> op;
    cout << "Enter Second Number: ";
    cin >> num2;

    if (op == '+') {
        result = add(num1, num2);
        cout << "Result: " << num1 << " + " << num2 << " = " << result << "\n";
    }
    else if (op == '-') {
        result = subtract(num1, num2);
        cout << "Result: " << num1 << " - " << num2 << " = " << result << "\n";
    }
    else if (op == '*') {
        result = multiply(num1, num2);
        cout << "Result: " << num1 << " * " << num2 << " = " << result << "\n";
    }
    else if (op == '/') {
        //cant be divided by zero
        if (num2 == 0) {
            cout << "Error: cannot divide by zero!\n";
        } else {
            result = divide(num1, num2);
            cout << "Result: " << num1 << " / " << num2 << " = " << result << "\n";
        }
    }
    else {
        cout << "Invalid Operator!\n";
    }
}

int main() {
    int choice;

    do {
        showMenu();
        cin >> choice;

        if (choice == 1) {
            do {
                runCalculator();
            } while (askAgain("Calculate again?"));
        }
        else if (choice == 2) {
            showCredits();
        }
        else if (choice == 3) {
            cout << "Thank you for using this calculator!\n";
        }
        else {
            cout << "Invalid choice!\n";
        }
    } while (choice != 3);

    return 0;
}
