#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

class LilawatLibrary
{
    string Book_id;
    string Book_Name;
    string Book_Author_Name;
    string Status;
    string Search_Book;
    fstream file;

public:
    // Existing Functions (Your Code Will Not Change)
    void AddToBooks()
    {
        cin.ignore();
        cout << "Please Enter Book ID Number: ";
        getline(cin, Book_id);
        cout << "Please Enter Book Name: ";
        getline(cin, Book_Name);
        cout << "Enter Book Author Name: ";
        getline(cin, Book_Author_Name);
        cout << "Enter Book Status (Available/Issued): ";
        getline(cin, Status);

        // Get Current Date and Time
        time_t now = time(0);
        char *dt = ctime(&now);

        file.open("BookData.txt", ios::out | ios::app);
        if (file.is_open())
        {
            file << Book_id << "|" << Book_Name << "|" << Book_Author_Name << "|" << Status << "|" << dt;
            cout << "Book Added Successfully!\n";
        }
        else
        {
            cout << "Error opening file for writing!\n";
        }
        file.close();
    }

    void ShowAllBooks()
    {
        file.open("BookData.txt", ios::in);
        if (!file)
        {
            cout << "No Books Found or File Cannot Be Opened!\n";
            return;
        }

        cout << "\nBook ID\t\tBook Name\t\tAuthor Name\t\tStatus\t\tDate Added\n";
        cout << "----------------------------------------------------------------------------\n";

        string line;
        while (getline(file, line))
        {
            vector<string> bookData = split(line, '|');
            if (bookData.size() >= 5)
            {
                cout << bookData[0] << "\t\t" << bookData[1] << "\t\t" << bookData[2] << "\t\t" 
                     << bookData[3] << "\t" << bookData[4];
            }
        }
        file.close();
    }

    // New Feature: Delete Book
    void DeleteBook()
    {
        string deleteID;
        cout << "Enter Book ID to Delete: ";
        cin.ignore();
        getline(cin, deleteID);

        fstream tempFile;
        file.open("BookData.txt", ios::in);
        tempFile.open("Temp.txt", ios::out);

        string line;
        bool found = false;

        while (getline(file, line))
        {
            if (line.find(deleteID + "|") != 0)
            {
                tempFile << line << endl;
            }
            else
            {
                found = true;
            }
        }
        file.close();
        tempFile.close();

        remove("BookData.txt");
        rename("Temp.txt", "BookData.txt");

        if (found)
            cout << "Book Deleted Successfully!\n";
        else
            cout << "Book ID Not Found!\n";
    }

    // New Feature: Search Books by Author Name
    void SearchByAuthor()
    {
        string authorName;
        cout << "Enter Author Name to Search: ";
        cin.ignore();
        getline(cin, authorName);

        file.open("BookData.txt", ios::in);
        string line;
        bool found = false;

        cout << "\nBooks by Author: " << authorName << "\n";
        cout << "Book ID\t\tBook Name\t\tStatus\t\tDate Added\n";
        cout << "--------------------------------------------------------------\n";

        while (getline(file, line))
        {
            vector<string> bookData = split(line, '|');
            if (bookData.size() >= 5 && bookData[2] == authorName)
            {
                cout << bookData[0] << "\t\t" << bookData[1] << "\t\t" 
                     << bookData[3] << "\t" << bookData[4];
                found = true;
            }
        }
        if (!found)
            cout << "No Books Found for Author: " << authorName << endl;

        file.close();
    }

    // New Feature: Count Total Books
    void CountBooks()
    {
        file.open("BookData.txt", ios::in);
        int count = 0;
        string line;

        while (getline(file, line))
            count++;

        cout << "Total Number of Books: " << count << endl;
        file.close();
    }

private:
    // Utility Function: Split a String
    vector<string> split(const string &str, char delimiter)
    {
        vector<string> result;
        stringstream ss(str);
        string token;

        while (getline(ss, token, delimiter))
        {
            result.push_back(token);
        }
        return result;
    }
};

int main()
{
    LilawatLibrary book;
    int choice;

    while (true)
    {
        cout << "\n------- Welcome To Lilawat Library --------\n";
        cout << "1 - Show All Books\n";
        cout << "2 - Add New Book\n";
        cout << "3 - Delete Book\n";
        cout << "4 - Search Book by Author Name\n";
        cout << "5 - Count Total Books\n";
        cout << "6 - Exit\n";
        cout << "-------------------------------------------\n";
        cout << "Enter Your Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            book.ShowAllBooks();
            break;
        case 2:
            book.AddToBooks();
            break;
        case 3:
            book.DeleteBook();
            break;
        case 4:
            book.SearchByAuthor();
            break;
        case 5:
            book.CountBooks();
            break;
        case 6:
            cout << "Exiting... Thank You!\n";
            return 0;
        default:
            cout << "Invalid Choice! Please Try Again.\n";
        }
    }

    return 0;
}
