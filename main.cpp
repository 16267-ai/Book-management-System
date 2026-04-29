#include <iostream>
#include <string>
using namespace std;

class Book {
protected:
    string title;
    string author;
    string isbn;
    bool isAvailable;

public:
    Book() {
        isAvailable = true;
    }

    virtual void setBookDetails(string t, string a, string i) {
        title = t;
        author = a;
        isbn = i;
        isAvailable = true;
    }

    virtual void displayBookDetails() {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "ISBN: " << isbn << endl;
        cout << "Status: " << (isAvailable ? "Available" : "Borrowed") << endl;
    }

    bool borrowBook() {
        if (isAvailable) {
            isAvailable = false;
            return true;
        }
        return false;
    }

    void returnBook() {
        isAvailable = true;
    }

    string getISBN() {
        return isbn;
    }

    virtual ~Book() {}
};

class HardcopyBook : public Book {
private:
    string shelfNumber;

public:
    void setBookDetails(string t, string a, string i, string shelf) {
        Book::setBookDetails(t, a, i);
        shelfNumber = shelf;
    }

    void displayBookDetails() override {
        Book::displayBookDetails();
        cout << "Book Type: Hardcopy Book" << endl;
        cout << "Shelf Number: " << shelfNumber << endl;
        cout << "-------------------------" << endl;
    }
};

class EBook : public Book {
private:
    double fileSizeMB;
    string licenseExpiryDate;

public:
    void setBookDetails(string t, string a, string i, double size, string expiry) {
        Book::setBookDetails(t, a, i);
        fileSizeMB = size;
        licenseExpiryDate = expiry;
    }

    void displayBookDetails() override {
        Book::displayBookDetails();
        cout << "Book Type: EBook" << endl;
        cout << "File Size: " << fileSizeMB << " MB" << endl;
        cout << "License Expiry Date: " << licenseExpiryDate << endl;
        cout << "-------------------------" << endl;
    }
};

class LibrarySystem {
private:
    Book* books[5];
    int bookCount;

public:
    LibrarySystem() {
        bookCount = 0;
    }

    void addBook(Book* book) {
        if (bookCount < 5) {
            books[bookCount] = book;
            bookCount++;
        }
    }

    Book* findBookByISBN(string isbn) {
        for (int i = 0; i < bookCount; i++) {
            if (books[i]->getISBN() == isbn) {
                return books[i];
            }
        }
        return nullptr;
    }

    void displayAllBooks() {
        for (int i = 0; i < bookCount; i++) {
            books[i]->displayBookDetails();
        }
    }

    void borrowBookByISBN(string isbn) {
        Book* book = findBookByISBN(isbn);

        if (book == nullptr) {
            cout << "Book not found!" << endl;
        } else if (book->borrowBook()) {
            cout << "Book borrowed successfully!" << endl;
        } else {
            cout << "This book is already borrowed." << endl;
        }
    }
};

int main() {
    LibrarySystem library;

    HardcopyBook book1, book2, book3;
    EBook ebook1, ebook2;

    book1.setBookDetails("C++ Basics", "John Smith", "111", "A1");
    book2.setBookDetails("Data Structures", "Alice Brown", "222", "B2");
    book3.setBookDetails("OOP Concepts", "David Lee", "333", "C3");

    ebook1.setBookDetails("Digital Programming", "Emma White", "444", 12.5, "2026-12-31");
    ebook2.setBookDetails("Algorithms Online", "Michael Green", "555", 8.2, "2027-06-30");

    library.addBook(&book1);
    library.addBook(&book2);
    library.addBook(&book3);
    library.addBook(&ebook1);
    library.addBook(&ebook2);

    cout << "Library Book Management System - Phase 2" << endl;
    cout << "----------------------------------------" << endl;

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
