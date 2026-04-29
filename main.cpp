#include <iostream>
#include <string>
using namespace std;

// =====================
// Book Class
// =====================
class Book {
private:
    string title;
    string author;
    string isbn;
    bool isAvailable;

public:
    // Set book details
    void setBookDetails(string t, string a, string i) {
        title = t;
        author = a;
        isbn = i;
        isAvailable = true;
    }

    // Display book details
    void displayBookDetails() {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "ISBN: " << isbn << endl;
        cout << "Status: " << (isAvailable ? "Available" : "Borrowed") << endl;
        cout << "-------------------------" << endl;
    }

    // Borrow book
    bool borrowBook() {
        if (isAvailable) {
            isAvailable = false;
            return true;
        }
        return false;
    }

    // Return book
    void returnBook() {
        isAvailable = true;
    }

    // Get ISBN
    string getISBN() {
        return isbn;
    }

    // Get availability
    bool getAvailability() {
        return isAvailable;
    }
};

// =====================
// Library Class (Dependency Class)
// =====================
class Library {
private:
    Book books[5];
    int bookCount;

public:
    Library() {
        bookCount = 0;
    }

    // Add book
    void addBook(Book book) {
        if (bookCount < 5) {
            books[bookCount] = book;
            bookCount++;
        }
    }

    // Display all books
    void displayAllBooks() {
        for (int i = 0; i < bookCount; i++) {
            books[i].displayBookDetails();
        }
    }

    // Find book by ISBN
    int findBookByISBN(string isbn) {
        for (int i = 0; i < bookCount; i++) {
            if (books[i].getISBN() == isbn) {
                return i;
            }
        }
        return -1;
    }

    // Borrow book by ISBN
    void borrowBookByISBN(string isbn) {
        int index = findBookByISBN(isbn);

        if (index == -1) {
            cout << "Book not found!" << endl;
        } else {
            if (books[index].borrowBook()) {
                cout << "Book borrowed successfully!" << endl;
            } else {
                cout << "Book is already borrowed!" << endl;
            }
        }
    }

    // Get book count
    int getBookCount() {
        return bookCount;
    }
};

// =====================
// Main Function
// =====================
int main() {
    Library library;

    // Create books
    Book b1, b2, b3, b4, b5;

    b1.setBookDetails("C++ Basics", "John Smith", "111");
    b2.setBookDetails("Data Structures", "Alice Brown", "222");
    b3.setBookDetails("Programming Logic", "David Lee", "333");
    b4.setBookDetails("OOP Concepts", "Emma White", "444");
    b5.setBookDetails("Algorithms", "Michael Green", "555");

    // Add books to library
    library.addBook(b1);
    library.addBook(b2);
    library.addBook(b3);
    library.addBook(b4);
    library.addBook(b5);

    // Display books
    cout << "Library Books:" << endl;
    library.displayAllBooks();

    string inputISBN;

    while (true) {
        cout << "\nEnter ISBN to borrow (0 to exit): ";
        cin >> inputISBN;

        if (inputISBN == "0") {
            cout << "Program ended." << endl;
            break;
        }

        library.borrowBookByISBN(inputISBN);
    }

    return 0;
}
