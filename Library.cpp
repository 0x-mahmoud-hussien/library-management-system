#include <iostream>
#include <string>
#include <vector>
using namespace std;

// ===================== Book Class =====================
class Book
{
private:
    string bookTitle;
    string bookAuthor;
    int bookId;
    bool isBorrowed; // هل الكتاب مُستعار أم لا

public:
    Book(string bt, string ba, int bi)
    {
        bookTitle = bt;
        bookAuthor = ba;
        bookId = bi;
        isBorrowed = false;
    }

    string getTitle() { return bookTitle; }
    string getAuthor() { return bookAuthor; }
    int getId() { return bookId; }
    bool getStatus() { return isBorrowed; }

    void borrowBook()
    {
        if (isBorrowed)
        {
            cout << "This book is already borrowed!" << endl;
        }
        else
        {
            isBorrowed = true;
            cout << "Book borrowed successfully!" << endl;
        }
    }

    void returnBook()
    {
        if (!isBorrowed)
        {
            cout << "This book was not borrowed!" << endl;
        }
        else
        {
            isBorrowed = false;
            cout << "Book returned successfully!" << endl;
        }
    }

    void displayBookInfo()
    {
        cout << "Book Title: " << bookTitle << endl;
        cout << "Book Author: " << bookAuthor << endl;
        cout << "Book Id: " << bookId << endl;
        cout << "Status: " << (isBorrowed ? "Borrowed" : "Available") << endl;
        cout << "============================" << endl;
    }
};

// ===================== Member Class =====================
class Member
{
private:
    string name;
    int memberId;

public:
    Member(string n, int mi)
    {
        name = n;
        memberId = mi;
    }

    int getID() { return memberId; }
    string getName() { return name; }

    void displayMemberInfo()
    {
        cout << "Member Name = " << name << endl;
        cout << "Member ID = " << memberId << endl;
        cout << "=========================" << endl;
    }
};

// ===================== Library Class =====================
class LibrarySystem
{
private:
    vector<Book> Books;
    vector<Member> Members;

public:
    // إضافة عضو جديد
    void registerMember()
    {
        int newId;
        string newName;

        cout << "Enter New Member Id: ";
        cin >> newId;
        cin.ignore();

        cout << "Enter New Name: ";
        getline(cin, newName);

        for (const auto &m : Members)
        {
            if (m.getID() == newId)
            {
                cout << "Error: Member With This ID Already Exists!" << endl;
                return;
            }
        }

        Member m(newName, newId);
        Members.push_back(m);

        cout << "Member Registered Successfully!" << endl;
    }

    // عرض كل الأعضاء
    void showAllMembers()
    {
        if (Members.empty())
        {
            cout << "No Members Found." << endl;
            return;
        }

        cout << "----- Members List -----" << endl;
        for (const auto &m : Members)
        {
            m.displayMemberInfo();
        }
    }

    // إضافة كتاب
    void addBook()
    {
        int id;
        string title, author;

        cout << "Enter Book ID: ";
        cin >> id;
        cin.ignore();

        for (const auto &b : Books)
        {
            if (b.getId() == id)
            {
                cout << "Error: A Book With This ID Already Exists!" << endl;
                return;
            }
        }

        cout << "Enter Book Title: ";
        getline(cin, title);
        cout << "Enter Book Author: ";
        getline(cin, author);

        Book newBook(title, author, id);
        Books.push_back(newBook);

        cout << "Book Added Successfully!" << endl;
    }

    // عرض كل الكتب
    void showAllBooks()
    {
        if (Books.empty())
        {
            cout << "No Books Available in The Library." << endl;
            return;
        }

        cout << "----- Books In The Library -----" << endl;
        for (auto &b : Books)
        {
            b.displayBookInfo();
        }
    }

    // البحث عن كتاب بالعنوان
    void searchBook(string title)
    {
        bool found = false;
        for (auto &b : Books)
        {
            if (b.getTitle() == title)
            {
                b.displayBookInfo();
                found = true;
                break;
            }
        }
        if (!found)
            cout << "Book Not Found!" << endl;
    }

    // استعارة كتاب بالـ ID
    void borrowBook(int id)
    {
        for (auto &b : Books)
        {
            if (b.getId() == id)
            {
                b.borrowBook();
                return;
            }
        }
        cout << "Book With ID " << id << " Not Found!" << endl;
    }

    // إرجاع كتاب بالـ ID
    void returnBook(int id)
    {
        for (auto &b : Books)
        {
            if (b.getId() == id)
            {
                b.returnBook();
                return;
            }
        }
        cout << "Book With ID " << id << " Not Found!" << endl;
    }
};

// ===================== Main Function =====================
int main()
{
    LibrarySystem lib;
    int choice;

    do
    {
        cout << "\n===== Library Menu =====" << endl;
        cout << "1. Add Book" << endl;
        cout << "2. Show All Books" << endl;
        cout << "3. Register Member" << endl;
        cout << "4. Show All Members" << endl;
        cout << "5. Search Book" << endl;
        cout << "6. Borrow Book" << endl;
        cout << "7. Return Book" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter Choice: ";
        cin >> choice;
        cin.ignore();

        if (choice == 1)
            lib.addBook();
        else if (choice == 2)
            lib.showAllBooks();
        else if (choice == 3)
            lib.registerMember();
        else if (choice == 4)
            lib.showAllMembers();
        else if (choice == 5)
        {
            string title;
            cout << "Enter Book Title To Search: ";
            getline(cin, title);
            lib.searchBook(title);
        }
        else if (choice == 6)
        {
            int id;
            cout << "Enter Book ID To Borrow: ";
            cin >> id;
            lib.borrowBook(id);
        }
        else if (choice == 7)
        {
            int id;
            cout << "Enter Book ID To Return: ";
            cin >> id;
            lib.returnBook(id);
        }

    } while (choice != 0);

    return 0;
}
