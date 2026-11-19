// Activity #4: Temperature Converter
#include <iostream>
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
    cout << "   TEMPERATURE CONVERTER\n";
    cout << "==============================\n";
    cout << "1. Start\n";
    cout << "2. Credits\n";
    cout << "3. Quit\n";
    cout << "Enter choice: ";
}

// converts Celsius to Fahrenheit using F = (C * 9/5) + 32
double celsiusToFahrenheit(double c) {
    return (c * 9.0 / 5.0) + 32;
}

// converts Fahrenheit to Celsius using C = (F - 32) * 5/9
double fahrenheitToCelsius(double f) {
    return (f - 32) * 5.0 / 9.0;
}

// does one conversion
void runConverter() {
    int choice;
    double temp, result;

    cout << "\n1. Celsius to Fahrenheit\n";
    cout << "2. Fahrenheit to Celsius\n";
    cout << "Enter your choice (1 or 2): ";
    cin >> choice;

    if (choice == 1) {
        cout << "Enter temperature in Celsius: ";
        cin >> temp;
        result = celsiusToFahrenheit(temp);
        cout << temp << "C = " << result << "F\n";
    }
    else if (choice == 2) {
        cout << "Enter temperature in Fahrenheit: ";
        cin >> temp;
        result = fahrenheitToCelsius(temp);
        cout << temp << "F = " << result << "C\n";
    }
    else {
        cout << "Invalid choice!\n";
    }
}

int main() {
    int choice;

    do {
        showMenu();
        cin >> choice;

        if (choice == 1) {
            do {
                runConverter();
            } while (askAgain("Convert again?"));
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
