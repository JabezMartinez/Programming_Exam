// Activity #8 Sorting Algorithms
#include <iostream>
using namespace std;

// shows the credits screen
void showCredits() {
    cout << "\n==============================\n";
    cout << "           CREDITS\n";
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
    cout << "     SORTING ALGORITHMS\n";
    cout << "==============================\n";
    cout << "1. Start\n";
    cout << "2. Credits\n";
    cout << "3. Quit\n";
    cout << "Enter choice: ";
}

// prints all the elements of the array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

// copies the original array so every sort starts with the same numbers
void copyArray(int from[], int to[], int size) {
    for (int i = 0; i < size; i++) {
        to[i] = from[i];
    }
}

// bubble sort: compares neighbors and swaps them if they are in the wrong order
void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// selection sort: finds the smallest number and puts it in front
void selectionSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}

// insertion sort: takes one number at a time and inserts it in the right spot
void insertionSort(int arr[], int size) {
    for (int i = 1; i < size; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// does one run of the sorting program
void runSorting() {
    int original[100], arr[100];
    int size;

    cout << "\nHow many numbers (max 100)? ";
    cin >> size;

    if (size <= 0 || size > 100) {
        cout << "Invalid size!\n";
        return;
    }

    for (int i = 0; i < size; i++) {
        cout << "Enter number " << i + 1 << ": ";
        cin >> original[i];
    }

    cout << "\nOriginal array: ";
    printArray(original, size);

    copyArray(original, arr, size);
    bubbleSort(arr, size);
    cout << "Bubble Sort: ";
    printArray(arr, size);

    copyArray(original, arr, size);
    selectionSort(arr, size);
    cout << "Selection Sort: ";
    printArray(arr, size);

    copyArray(original, arr, size);
    insertionSort(arr, size);
    cout << "Insertion Sort: ";
    printArray(arr, size);
}

int main() {
    int choice;

    do {
        showMenu();
        cin >> choice;

        if (choice == 1) {
            do {
                runSorting();
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
