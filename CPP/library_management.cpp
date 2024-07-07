#include <bits/stdc++.h>

using namespace std;

// Problem Statement:
// You're tasked with designing a system for managing a library's inventory.
//  The system should allow librarians to add new books, remove existing ones, update 
//  book information (such as title, author, and genre), and search for books by 
//  various criteria (title, author, genre, etc.). Additionally, the system should
// provide functionality for users to borrow and return books.

// 1 - add new books
// 2 - remove books
// 4 - search books by various criteria (title, author, genre, etc.)
int BookId = 1;
class Book {
    private:
    string id;
    string title;
    string author;

    public:
    Book(string title, string author){
        this->id = BookId;
        this->author = author;
        this->title = title;
        BookId++;
    }

    string GetTitle(){
        return this->title;
    }

    string GetAuthor(){
        return this->author;
    }
};

class BookStorage {
    
}

class BookFinder {
    private:
    map<string, set<Book*>> titleMap, authorMap;

    public:
    void AddBook(Book* book){
        titleMap[book->GetTitle()].insert(book);
        authorMap[book->GetAuthor()].insert(book);
    }

    set<Book*> FindByTitle(string title){
        return titleMap[title];
    }

    set<Book*> FindByAuthor(string author){
        return authorMap[author];
    }
};

class LibraryManager {
    private:
    BookFinder BookFinder;
    vector<Book*> books;

    public:
    void AddNewBook(string title, string author){
        Book* book = new Book(title, author);
        books.push_back(book);
        this->BookFinder.AddBook(book);
    }

    set<Book*> FindBookByAuthor(string author){
        return this->BookFinder.FindByAuthor(author);
    }

    set<Book*> FindBookByTitle(string title){
        return this->BookFinder.FindByTitle(title);
    }
};