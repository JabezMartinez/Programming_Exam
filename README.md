# Programming_Exam
A list of simle programs written in C++ for my IT College Course

# C++ Console Programs

A collection of 10 beginner-friendly console programs written in C++ by **Jabez A. Martinez**. Every program shares the same flow: a main menu, a play-again prompt after each round, and a credits screen.

## Table of Contents

- [Programs](#programs)
- [Project Structure](#project-structure)
- [Getting Started](#getting-started)
- [How the Programs Work](#how-the-programs-work)
- [Program Notes](#program-notes)
- [Known Limitations](#known-limitations)
- [Author](#author)

## Programs

| # | File | Description |
|---|------|-------------|
| 1 | [`Simple_Calculator.cpp`](Simple_Calculator.cpp) | Adds, subtracts, multiplies and divides two numbers. Guards against division by zero. |
| 2 | [`Array_Operations.cpp`](Array_Operations.cpp) | Reads up to 100 numbers and shows the minimum, maximum and average. |
| 3 | [`Number_Guessing_Game.cpp`](Number_Guessing_Game.cpp) | Guess the secret number with higher/lower hints. Three difficulty levels. |
| 4 | [`Temperature_Converter.cpp`](Temperature_Converter.cpp) | Converts Celsius to Fahrenheit and Fahrenheit to Celsius. |
| 5 | [`Fractional_Calculator.cpp`](Fractional_Calculator.cpp) | Factorial calculator for 0 to 20 (the largest `n!` that fits in `long long`). |
| 6 | [`Tic-Tac-Toe_Game.cpp`](Tic-Tac-Toe_Game.cpp) | Two-player game with 3x3, 4x4 and 5x5 boards. |
| 7 | [`Matrix_Operations.cpp`](Matrix_Operations.cpp) | Adds, multiplies and transposes matrices up to 10x10. |
| 8 | [`Sorting_Algorithms.cpp`](Sorting_Algorithms.cpp) | Sorts the same input with bubble, selection and insertion sort. |
| 9 | [`Library_Management_System.cpp`](Library_Management_System.cpp) | Manages books and members, with borrowing and returning (max 3 books per member). |
| 10 | [`Quiz_Game.cpp`](Quiz_Game.cpp) | Five-question multiple-choice quiz with three difficulty levels and a final score. |

## Project Structure

```
.
├── Simple_Calculator.cpp
├── Array_Operations.cpp
├── Number_Guessing_Game.cpp
├── Temperature_Converter.cpp
├── Fractional_Calculator.cpp
├── Tic-Tac-Toe_Game.cpp
├── Matrix_Operations.cpp
├── Sorting_Algorithms.cpp
├── Library_Management_System.cpp
├── Quiz_Game.cpp
├── .gitignore
└── README.md
```

## Getting Started

### Requirements

A C++ compiler such as `g++` (GCC or MinGW) or any IDE that builds C++ (Code::Blocks, Dev-C++, Visual Studio). The programs use only the standard library.

### Clone the repository

```
git clone https://github.com/<your-username>/<repository-name>.git
cd <repository-name>
```

### Compile and run one program

```
mkdir -p build
g++ Simple_Calculator.cpp -o build/Simple_Calculator
./build/Simple_Calculator
```

On Windows the executable is `build\Simple_Calculator.exe`. Replace the file name to build a different program.

### Compile all programs

Linux / macOS / Git Bash:

```
mkdir -p build
for f in *.cpp; do g++ "$f" -o "build/${f%.cpp}"; done
```

Windows PowerShell:

```
mkdir build -Force
Get-ChildItem *.cpp | ForEach-Object { g++ $_.Name -o "build\$($_.BaseName)" }
```

The `build/` folder is listed in `.gitignore`, so compiled files are not committed.

## How the Programs Work

Each program opens on this menu:

```
1. Start
2. Credits
3. Quit
```

- **Start** runs the program once, then asks `Play again? (y/n)`. Answer `y` to run it again, or `n` to return to the main menu. The wording of the question changes to fit the program (for example `Calculate again?`).
- **Credits** shows the credits screen.
- **Quit** exits the program.

## Program Notes

- **Number Guessing Game**
  - Easy: 1-20, 10 tries
  - Normal: 1-50, 7 tries
  - Hard: 1-100, 5 tries
- **Tic-Tac-Toe**
  - Easy: 3x3 board, 3 in a row to win
  - Normal: 4x4 board, 4 in a row
  - Hard: 5x5 board, 4 in a row
  - Player 1 is X and Player 2 is O. Type the number shown on an empty spot to place a mark.
- **Matrix Operations**
  - Addition needs both matrices to be the same size.
  - Multiplication needs the columns of A to equal the rows of B.
  - Transpose is applied to Matrix A.
- **Library Management System**
  - Add books and members, display them, and borrow or return books.
  - Option 7 (Back) leaves the system. Data is not saved between runs, so each new run starts with an empty library.
  - Holds up to 50 books and 50 members.
- **Quiz Game**
  - Answer with A, B, C or D (lowercase also works).
  - The final screen shows the score and percentage.

## Known Limitations

- Input is not fully validated. Typing letters where a number is expected can cause unexpected behavior.
- Nothing is saved to disk. All data lives in memory while the program runs.

## Author

Made by **Jabez A. Martinez**
