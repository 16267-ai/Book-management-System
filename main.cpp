#include <iostream>
#include <string>
using namespace std;

class Book {
private:
    string title;
    string author;
    string isbn;
    bool isAvailable;

public:
    // set book details
    void setBookDetails(string t, string a, string i) {
        title = t;
        author = a;
        isbn = i;
        isAvailable = true; // default = available
    }

    // display book info
    void displayBookDetails() {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "ISBN: " << isbn << endl;
        cout << "Status: " << (isAvailable ? "Available" : "Borrowed") << endl;
        cout << "-------------------------" << endl;
    }

    // borrow book
    bool borrowBook() {
        if (isAvailable) {
            isAvailable = false;
            return true;
        }
        return false;
    }

    // return book
    void returnBook() {
        isAvailable = true;
    }

    // get ISBN
    string getISBN() {
        return isbn;
    }
};

int main() {
    Book books[5];

    // initialize books
    books[0].setBookDetails("C++ Basics", "John Smith", "111");
    books[1].setBookDetails("OOP Concepts", "Alice Brown", "222");
    books[2].setBookDetails("Data Structures", "David Lee", "333");
    books[3].setBookDetails("Algorithms", "Emma White", "444");
    books[4].setBookDetails("Programming Logic", "Chris Green", "555");

    string inputISBN;

    while (true) {
        cout << "\nEnter ISBN to borrow (0 to exit): ";
        cin >> inputISBN;

        if (inputISBN == "0") {
            cout << "Program ended." << endl;
            break;
        }

        bool found = false;

        for (int i = 0; i < 5; i++) {
            if (books[i].getISBN() == inputISBN) {
                found = true;

                if (books[i].borrowBook()) {
                    cout << "Book borrowed successfully!\n";
                    books[i].displayBookDetails();
                } else {
                    cout << "Error: Book is not available.\n";
                }
                break;
            }
        }

        if (!found) {
            cout << "Error: Book not found.\n";
        }
    }
// Add Task 3: Implement HardcopyBook and EBook class hierarchy
// update version
    
    return 0;
}
