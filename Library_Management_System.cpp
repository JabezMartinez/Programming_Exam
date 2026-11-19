// Activity #9 Library Management System
#include <iostream>
#include <string>
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
    cout << " LIBRARY MANAGEMENT SYSTEM\n";
    cout << "==============================\n";
    cout << "1. Start\n";
    cout << "2. Credits\n";
    cout << "3. Quit\n";
    cout << "Enter choice: ";
}

// ---------- Book class ----------
class Book {
public:
    int id;
    string title;
    string author;
    bool isBorrowed;

    Book() {
        id = 0;
        title = "";
        author = "";
        isBorrowed = false;
    }

    // sets the details of the book
    void setBook(int bookId, string bookTitle, string bookAuthor) {
        id = bookId;
        title = bookTitle;
        author = bookAuthor;
        isBorrowed = false;
    }

    // prints the book info
    void display() {
        cout << "ID: " << id << " | " << title << " by " << author << " | ";
        if (isBorrowed) {
            cout << "Borrowed\n";
        } else {
            cout << "Available\n";
        }
    }
};

// ---------- Member class ----------
class Member {
public:
    int id;
    string name;
    int borrowedCount; // how many books the member has now

    Member() {
        id = 0;
        name = "";
        borrowedCount = 0;
    }

    // sets the details of the member
    void setMember(int memberId, string memberName) {
        id = memberId;
        name = memberName;
        borrowedCount = 0;
    }

    // prints the member info
    void display() {
        cout << "ID: " << id << " | " << name << " | Books borrowed: " << borrowedCount << "\n";
    }
};

// ---------- Library class ----------
class Library {
private:
    Book books[50];
    Member members[50];
    int bookCount;
    int memberCount;

public:
    Library() {
        bookCount = 0;
        memberCount = 0;
    }

    // adds a new book to the library
    void addBook(int id, string title, string author) {
        if (bookCount < 50) {
            books[bookCount].setBook(id, title, author);
            bookCount++;
            cout << "Book added successfully!\n";
        } else {
            cout << "Library is full!\n";
        }
    }

    // adds a new member
    void addMember(int id, string name) {
        if (memberCount < 50) {
            members[memberCount].setMember(id, name);
            memberCount++;
            cout << "Member added successfully!\n";
        } else {
            cout << "Member list is full!\n";
        }
    }

    // shows all the books
    void displayBooks() {
        if (bookCount == 0) {
            cout << "No books yet.\n";
            return;
        }
        for (int i = 0; i < bookCount; i++) {
            books[i].display();
        }
    }

    // shows all the members
    void displayMembers() {
        if (memberCount == 0) {
            cout << "No members yet.\n";
            return;
        }
        for (int i = 0; i < memberCount; i++) {
            members[i].display();
        }
    }

    // searches the book list and returns its position (-1 if not found)
    int findBook(int id) {
        for (int i = 0; i < bookCount; i++) {
            if (books[i].id == id) {
                return i;
            }
        }
        return -1;
    }

    // searches the member list and returns its position (-1 if not found)
    int findMember(int id) {
        for (int i = 0; i < memberCount; i++) {
            if (members[i].id == id) {
                return i;
            }
        }
        return -1;
    }

    // lets a member borrow a book (max 3 books per member)
    void borrowBook(int memberId, int bookId) {
        int m = findMember(memberId);
        int b = findBook(bookId);

        if (m == -1) {
            cout << "Member not found!\n";
        }
        else if (b == -1) {
            cout << "Book not found!\n";
        }
        else if (books[b].isBorrowed) {
            cout << "Sorry, that book is already borrowed.\n";
        }
        else if (members[m].borrowedCount >= 3) {
            cout << "Member already has 3 books. Return one first.\n";
        }
        else {
            books[b].isBorrowed = true;
            members[m].borrowedCount++;
            cout << members[m].name << " borrowed \"" << books[b].title << "\".\n";
        }
    }

    // lets a member return a book
    void returnBook(int memberId, int bookId) {
        int m = findMember(memberId);
        int b = findBook(bookId);

        if (m == -1) {
            cout << "Member not found!\n";
        }
        else if (b == -1) {
            cout << "Book not found!\n";
        }
        else if (books[b].isBorrowed == false) {
            cout << "That book was not borrowed.\n";
        }
        else {
            books[b].isBorrowed = false;
            members[m].borrowedCount--;
            cout << members[m].name << " returned \"" << books[b].title << "\".\n";
        }
    }
};

// runs the library system until the user picks Back (a fresh library every time)
void runLibrary() {
    Library lib;
    int choice;
    int id, id2;
    string text, text2;

    do {
        cout << "\n1. Add Book\n";
        cout << "2. Add Member\n";
        cout << "3. Display Books\n";
        cout << "4. Display Members\n";
        cout << "5. Borrow Book\n";
        cout << "6. Return Book\n";
        cout << "7. Back\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Book ID: ";
            cin >> id;
            cin.ignore(); // removes the leftover enter key
            cout << "Title: ";
            getline(cin, text);
            cout << "Author: ";
            getline(cin, text2);
            lib.addBook(id, text, text2);
        }
        else if (choice == 2) {
            cout << "Member ID: ";
            cin >> id;
            cin.ignore();
            cout << "Name: ";
            getline(cin, text);
            lib.addMember(id, text);
        }
        else if (choice == 3) {
            lib.displayBooks();
        }
        else if (choice == 4) {
            lib.displayMembers();
        }
        else if (choice == 5) {
            cout << "Member ID: ";
            cin >> id;
            cout << "Book ID: ";
            cin >> id2;
            lib.borrowBook(id, id2);
        }
        else if (choice == 6) {
            cout << "Member ID: ";
            cin >> id;
            cout << "Book ID: ";
            cin >> id2;
            lib.returnBook(id, id2);
        }
        else if (choice == 7) {
            cout << "Closing the library system...\n";
        }
        else {
            cout << "Invalid choice!\n";
        }
    } while (choice != 7);
}

int main() {
    int choice;

    do {
        showMenu();
        cin >> choice;

        if (choice == 1) {
            do {
                runLibrary();
            } while (askAgain("Play again? (starts a new library)"));
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
