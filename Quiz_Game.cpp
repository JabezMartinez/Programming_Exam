// Activity #10 Quiz Game
#include <iostream>
#include <string>
using namespace std;

// one quiz question
struct Question {
    string text;
    string choices[4];
    char answer; // correct letter (A, B, C or D)
};

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
    cout << "          QUIZ GAME\n";
    cout << "==============================\n";
    cout << "1. Start\n";
    cout << "2. Credits\n";
    cout << "3. Quit\n";
    cout << "Enter choice: ";
}

// puts one question in the array
void setQuestion(Question &q, string text, string a, string b, string c, string d, char answer) {
    q.text = text;
    q.choices[0] = a;
    q.choices[1] = b;
    q.choices[2] = c;
    q.choices[3] = d;
    q.answer = answer;
}

// loads the 5 questions depending on the difficulty
void loadQuestions(Question q[], int level) {
    if (level == 1) {
        setQuestion(q[0], "What is the capital of the Philippines?", "Cebu City", "Manila", "Davao City", "Baguio City", 'B');
        setQuestion(q[1], "Which of these is a programming language?", "Mouse", "Monitor", "C++", "Keyboard", 'C');
        setQuestion(q[2], "What is 5 + 7?", "10", "11", "12", "13", 'C');
        setQuestion(q[3], "Which device is used to type?", "Keyboard", "Speaker", "Printer", "Webcam", 'A');
        setQuestion(q[4], "Which symbol ends a statement in C++?", ":", ".", ",", ";", 'D');
    }
    else if (level == 2) {
        setQuestion(q[0], "What does CPU stand for?", "Central Processing Unit", "Computer Personal Unit", "Central Programming Unit", "Computer Processing Unit", 'A');
        setQuestion(q[1], "What is 8 x 7?", "54", "56", "58", "64", 'B');
        setQuestion(q[2], "Which loop runs at least once?", "for", "while", "do-while", "if", 'C');
        setQuestion(q[3], "Which header is needed for cout?", "<cmath>", "<iostream>", "<string>", "<ctime>", 'B');
        setQuestion(q[4], "What is the index of the first element in an array?", "1", "-1", "0", "10", 'C');
    }
    else {
        setQuestion(q[0], "What is the output of 7 % 3 in C++?", "2", "1", "0", "3", 'B');
        setQuestion(q[1], "Which of these is NOT a data type in C++?", "int", "double", "char", "real", 'D');
        setQuestion(q[2], "What does the break statement do inside a loop?", "Skips one turn", "Stops the loop", "Restarts the loop", "Ends the program", 'B');
        setQuestion(q[3], "What is the size of an int array declared as arr[8]?", "7 elements", "8 elements", "9 elements", "Depends on values", 'B');
        setQuestion(q[4], "Which sorting algorithm repeatedly swaps neighboring elements?", "Selection sort", "Insertion sort", "Bubble sort", "Merge sort", 'C');
    }
}

// shows one question and its choices
void displayQuestion(Question q, int number) {
    cout << "\nQuestion " << number << ": " << q.text << "\n";
    cout << "A. " << q.choices[0] << "\n";
    cout << "B. " << q.choices[1] << "\n";
    cout << "C. " << q.choices[2] << "\n";
    cout << "D. " << q.choices[3] << "\n";
}

// changes a small letter to a capital letter
char toUpperLetter(char c) {
    if (c >= 'a' && c <= 'z') {
        return c - 32;
    }
    return c;
}

// plays one full quiz
void runQuiz() {
    const int TOTAL = 5;
    Question quiz[TOTAL];
    char userAnswer;
    int score = 0;
    int level;

    cout << "\nSelect Difficulty:\n";
    cout << "1. Easy\n";
    cout << "2. Normal\n";
    cout << "3. Hard\n";
    cout << "Enter choice: ";
    cin >> level;

    loadQuestions(quiz, level);
    cout << "\nAnswer with A, B, C or D.\n";

    for (int i = 0; i < TOTAL; i++) {
        displayQuestion(quiz[i], i + 1);
        cout << "Your answer: ";
        cin >> userAnswer;
        userAnswer = toUpperLetter(userAnswer);

        if (userAnswer == quiz[i].answer) {
            cout << "Correct!\n";
            score++;
        } else {
            cout << "Wrong! The correct answer is " << quiz[i].answer << ".\n";
        }
        cout << "Current score: " << score << "/" << i + 1 << "\n";
    }

    cout << "\n==============================\n";
    cout << "         QUIZ FINISHED\n";
    cout << "==============================\n";
    cout << "Final score: " << score << " out of " << TOTAL << "\n";
    cout << "Percentage: " << (score * 100) / TOTAL << "%\n";

    if (score == TOTAL) {
        cout << "Perfect! Great job!\n";
    } else if (score >= 3) {
        cout << "Good job!\n";
    } else {
        cout << "Keep practicing!\n";
    }
}

int main() {
    int choice;

    do {
        showMenu();
        cin >> choice;

        if (choice == 1) {
            do {
                runQuiz();
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
