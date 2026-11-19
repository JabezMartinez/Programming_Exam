// Activity #7 Matrix Operations
#include <iostream>
using namespace std;

const int MAX = 10;

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
    cout << "      MATRIX OPERATIONS\n";
    cout << "==============================\n";
    cout << "1. Start\n";
    cout << "2. Credits\n";
    cout << "3. Quit\n";
    cout << "Enter choice: ";
}

// asks the user to type in the values of a matrix
void inputMatrix(int m[MAX][MAX], int rows, int cols, char name) {
    cout << "\nEnter the elements of Matrix " << name << ":\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << name << "[" << i + 1 << "][" << j + 1 << "]: ";
            cin >> m[i][j];
        }
    }
}

// prints a matrix in rows and columns
void printMatrix(int m[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << m[i][j] << "\t";
        }
        cout << "\n";
    }
}

// adds A and B and stores the answer in result (same size only)
void addMatrix(int a[MAX][MAX], int b[MAX][MAX], int result[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = a[i][j] + b[i][j];
        }
    }
}

// multiplies A (r1 x c1) and B (c1 x c2), the answer is r1 x c2
void multiplyMatrix(int a[MAX][MAX], int b[MAX][MAX], int result[MAX][MAX], int r1, int c1, int c2) {
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < c1; k++) {
                result[i][j] = result[i][j] + a[i][k] * b[k][j];
            }
        }
    }
}

// switches the rows and columns of a matrix
void transposeMatrix(int a[MAX][MAX], int result[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[j][i] = a[i][j];
        }
    }
}

// does one run of the matrix operations
void runMatrix() {
    int A[MAX][MAX], B[MAX][MAX], R[MAX][MAX];
    int r1, c1, r2, c2;
    int choice;

    cout << "\nRows and columns of Matrix A (max 10): \n";
    cout << "Rows: ";
    cin >> r1;
    cout << "Columns: ";
    cin >> c1;
    cout << "\nRows and columns of Matrix B (max 10): \n";
    cout << "Rows: ";
    cin >> r2;
    cout << "Columns: ";
    cin >> c2;

    if (r1 < 1 || c1 < 1 || r2 < 1 || c2 < 1 ||
        r1 > MAX || c1 > MAX || r2 > MAX || c2 > MAX) {
        cout << "Invalid size!\n";
        return;
    }

    inputMatrix(A, r1, c1, 'A');
    inputMatrix(B, r2, c2, 'B');

    cout << "\nMatrix A:\n";
    printMatrix(A, r1, c1);
    cout << "\nMatrix B:\n";
    printMatrix(B, r2, c2);

    cout << "\n1. Add\n";
    cout << "2. Multiply\n";
    cout << "3. Transpose Matrix A\n";
    cout << "Choose an operation: ";
    cin >> choice;

    if (choice == 1) {
        if (r1 != r2 || c1 != c2) {
            cout << "\nWarning!: \n";
            cout << "\nCannot add! Matrices must be the same size.\n";
        } else {
            addMatrix(A, B, R, r1, c1);
            cout << "\nResult: \n";
            cout << "\nA + B = \n";
            printMatrix(R, r1, c1);
        }
    }
    else if (choice == 2) {
        if (c1 != r2) {
            cout << "\nWarning!: \n";
            cout << "\nCannot multiply! Columns of A must equal rows of B.\n";
        } else {
            multiplyMatrix(A, B, R, r1, c1, c2);
            cout << "\nResult: \n";
            cout << "\nA x B = \n";
            printMatrix(R, r1, c2);
        }
    }
    else if (choice == 3) {
        transposeMatrix(A, R, r1, c1);
        cout << "\nResult: \n";
        cout << "\nTranspose of A = \n";
        printMatrix(R, c1, r1);
    }
    else {
        cout << "\nWarning!:\n";
        cout << "\nInvalid choice!\n";
    }
}

int main() {
    int choice;

    do {
        showMenu();
        cin >> choice;

        if (choice == 1) {
            do {
                runMatrix();
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
