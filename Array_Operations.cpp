// Activity #2: Array Operations (min, max, average)
#include <iostream>
using namespace std;

// credits screen
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
    cout << "       ARRAY OPERATIONS\n";
    cout << "==============================\n";
    cout << "1. Start\n";
    cout << "2. Credits\n";
    cout << "3. Quit\n";
    cout << "Enter choice: ";
}

// finds the smallest number in the array
int findMin(int arr[], int size) {
    int min = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}

// finds the biggest number in the array
int findMax(int arr[], int size) {
    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

//adds all the elements then divides by the size
double findAverage(int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum = sum + arr[i];
    }
    return (double) sum / size;
}

// does one run of the array operations
void runArray() {
    int numbers[100];
    int size;

    cout << "\nHow many elements (max 100)? ";
    cin >> size;

    if (size <= 0 || size > 100) {
        cout << "Invalid size!\n";
        return;
    }

    //ask the user to fill the array
    for (int i = 0; i < size; i++) {
        cout << "Enter Element " << i + 1 << ": ";
        cin >> numbers[i];
    }

    //show the array
    cout << "\nArray: ";
    for (int i = 0; i < size; i++) {
        cout << numbers[i] << " ";
    }
    cout << "\n";

    cout << "Minimum: " << findMin(numbers, size) << "\n";
    cout << "Maximum: " << findMax(numbers, size) << "\n";
    cout << "Average: " << findAverage(numbers, size) << "\n";
}

int main() {
    int choice;

    do {
        showMenu();
        cin >> choice;

        if (choice == 1) {
            do {
                runArray();
            } while (askAgain("Play again?"));
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
