#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Book{
public:
    string title;
    string author;
    string genre;
    int year;
    double rating;

    Book(string title, string author,string genre, int year) {
        this->title =title;
        this->author =author;
        this->genre=genre;
        this->year=year;
        this->rating = 0.0;
    }
};

class Library {
private:
    vector<Book>books;

public:
    void add_book(string title, string author, string genre, int year) {
        books.push_back(Book(title, author,genre,year));
    }

    void remove_book(string title) {
        for (auto it = books.begin(); it != books.end(); ++it) {
            if (it->title == title) {
                books.erase(it);
                break;
            }
        }
    }

    void rate_book(string title, double rating) {
        for (auto& book : books) {
            if (book.title == title) {
                book.rating = rating;
                break;
            }
        }
    }

    void display_books() {
        for (const auto& book : books) {
            cout << "Title: " << book.title << endl;
            cout << "Author: " << book.author << endl;
            cout<<"Genre:"<<book.genre<<endl;
            cout<<  "Year: "    <<book.year<<endl;
            cout << "Rating: " << book.rating << endl;
            cout << "-----------------------------------" << endl;
        }
    }
};

int main() {
    Library library;

    int choice,year;
    string title, author,genre;
    double rating;

    while (true) {
        cout << "Library Management System" << endl;
        cout << "1. Add Book Information" << endl;
        cout << "2. Remove Book" << endl;
        cout << "3. Rate Book" << endl;
        cout << "4. Display Book Information" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                cout << "Enter the title of the book: "<<endl;
                getline(cin, title);
                cout << "Enter the author of the book: "<<endl;
                getline(cin, author);
                cout<<"Enter the genre of the book: "<<endl;
                getline(cin, genre);
                cout<<"Enter the year: "<<endl;
                cin>>year;
                library.add_book(title, author, genre, year);
                cout << "Book added successfully!" << endl;
                break;
            case 2:
                cout << "Enter the title of the book to remove: ";
                getline(cin, title);
                library.remove_book(title);
                cout << "Book removed successfully!" << endl;
                break;
            case 3:
                cout << "Enter the title of the book to rate: ";
                getline(cin, title);
                cout << "Enter your rating (out of 5): ";
                cin >> rating;
                cin.ignore();
                library.rate_book(title, rating);
                cout << "Book rated successfully!" << endl;
                break;
            case 4:
                cout << "All Books:" << endl;
                library.display_books();
                break;
            case 5:
                cout << "Exiting..." << endl;
                exit(0);
            default:
                cout << "Invalid choice. Please try again." << endl;
        }

        cout << endl;
    }

    return 0;
}