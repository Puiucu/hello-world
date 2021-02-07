#include <iostream>
#include "Book.h"
#include "Inventory.h"
#include <string>
using namespace std;

Inventory _inventory;
void DisplayMenu()
{
    cout << "Choose an option:" << endl;
    cout << "1. Add Book" << endl;
    cout << "2. List all books" << endl;
    cout << "3. Check out books" << endl;
    cout << "4. Check in books" << endl;
    cout << "5. Remove book from library" << endl;
    cout << "6. List all checked out books" << endl;


    cout << "0. Exit" << endl;
}

void AddNewBook()
{
    cout << "Tittle: ";
    string title;
    getline(cin, title);

    cout << "Author: ";
    string author;
    getline(cin, author);

    int id = _inventory.Books.size() + 1;

    Book newBook(id, title, author);

    _inventory.AddBook(newBook);
    return;
}

void ListAllBooks()
{

    cout << "\nID\tTitle\tAuthor" << endl;
    for (int i = 0; i < _inventory.Books.size(); i++)
    {
        cout << _inventory.Books[i].Id << "\t" << _inventory.Books[i].Title << "\t" << _inventory.Books[i].Author << endl;
    }
    cout << endl;
}

void CheckInOrOutBook(bool checkIn)
{
    string inOrOut;
    if (checkIn)
    {
        inOrOut = "out";
    }
    else
    {
        inOrOut = "in";
    }
    cout << "Enter book title to check out " + inOrOut + ":" ;
    string title;
    getline(cin, title);

    int foundBookIndex = _inventory.FindBookByTitle(title);
    if (foundBookIndex >= 0)
    {

        // if checkedOut == false, then we are checked in
        // if checkedOut == true, then we are checked out
        Book* foundBook = &_inventory.Books[foundBookIndex];
        if (foundBook->CheckedOut == checkIn)
        {
            cout << "Book already checked out!" + inOrOut << endl;
            return;
        }
        if (checkIn)
        {
            _inventory.CheckInBook(foundBook);
        }
        else
        {
            _inventory.CheckOutBook(foundBook);
        } 
        cout << "Book checked out" + inOrOut + "!" << endl;
    }
    else
    {
        cout << "Book not found" << endl;
    }
}

void RemoveBook()
{
    cout << "Tittle: ";
    string title;
    getline(cin, title);

    _inventory.RemoveBook(title);
}

void DisplayCheckedOutBooks()
{
    cout << "\nID\tTitle\tAuthor" << endl;
    for (int i = 0; i < _inventory.Books.size(); i++)
    {
        if (_inventory.Books[i].CheckedOut)
        {
            cout << _inventory.Books[i].Id << "\t" << _inventory.Books[i].Title << "\t" << _inventory.Books[i].Author << endl;
        }
    }
    cout << endl;
}

int main()
{
    while (true)
    {
        DisplayMenu();
        

        int input;
        cin >> input;
        cin.ignore();
        switch (input)
        {
        case 0:
            cout << "Thank you. Goodbye";
            return 0;
        case 1:
        {
            AddNewBook();
            break;
        }
        case 2:
        {
            ListAllBooks();
            break;
        }
        case 3:
        {
            CheckInOrOutBook(false);
            break;
        }
        case 4:
        {
            CheckInOrOutBook(true);
            break;
        }
        case 5: 
        {
            RemoveBook();
            break;
        }
        case 6:
        {
            DisplayCheckedOutBooks();
            break;
        }
        default:
            cout << "Invalid selection. Try again" << endl;
            break;
        }

    }
}





