#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;

class login
{
private:
    string password = "root";

public:
    string getpassword()
    {
        return password;
    }
};

class book
{
private:
    char *author, *title, *publisher;
    float *price;
    int *stock;

public:
    book()
    {
        author = new char[30]; // why?
        title = new char[30];
        publisher = new char[30];
        price = new float;
        stock = new int;
    }
    int getStock()
    {
        return *stock;
    }
    void feeddata();
    void editdata();
    void showdata();
    bool search(char[], char[]);
    void buybook();
};

void book ::feeddata()
{
    cin.ignore(); // why?

    cout << "\n Enter the Author Name : ";
    cin.getline(author, 30);

    cout << "Enter the Title name : ";
    cin.getline(title, 30);

    cout << "Enter the Publisher Name : ";
    cin.getline(publisher, 30);

    cout << "Enter Price : ";
    cin >> *price;

    cout << "Enter Stock : ";
    cin >> *stock;
}

void book ::editdata()
{
    cout << "\n Enter the new name of author ";
    cin.getline(author, 30);

    cout << "Enter the new book title : ";
    cin.getline(title, 30);

    cout << "Enter the new name of publisher : ";
    cin.getline(publisher, 30);

    cout << "Enter new price of the book : ";
    cin >> *price;

    cout << "Enter new stock of the book : ";
    cin >> *stock;
}

void book ::showdata()
{
    cout << "\n Author Name : " << author;
    cout << "\n Book Name : " << title;
    cout << "\n Publisher Name : " << publisher;
    cout << "\n Book Price : " << *price;
    cout << "\n Current Stock : " << *stock;
}

bool book ::search(char titlebuy[30], char authorbuy[30])
{
    if (strcmp(title, titlebuy) && strcmp(author, authorbuy))
        return 1;
    else
        return 0;
}

void book ::buybook()
{
    int count;
    cout << "\nEnter the number of books to buy : ";
    cin >> count;
    if (count <= *stock)
    {
        stock -= count;
        cout << "\n Books bought successfully";
        cout << "\n Amount: Rs. " << *price;
    }
    else
        cout << "\n Required Copies not in Stock";
}

int main()
{

    login l;
    string password = l.getpassword();
    while (1)
    {
        string userpassword;
        cout << "\nPlease Enter Password to login : ";
        cin >> userpassword;
        if (password == userpassword)
        {
            cout << "\nCongratulations you are logged in";

            book *B[20]; // storing the data of any book in this array
            int i = 0;   // index to traverse the books
            char titlebuy[20], authorbuy[20];
            int choice;
            int t;
            while (1)
            {
                cout << "\n\n\t\tMENU"
                     << "\n1. Entry of New Book"
                     << "\n2. Buy Book"
                     << "\n3. Search For Book"
                     << "\n4. Edit Details Of Book"
                     << "\n5. Number of books in stock currently"
                     << "\n6. Show data of all books"
                     << "\n7. Exit"
                     << "\n\nEnter your Choice: ";
                cin >> choice;
                int sum = 0;
                switch (choice)
                {
                case 1:
                    B[i] = new book;
                    B[i]->feeddata();
                    i++;
                    break;
                case 2:
                    cin.ignore();
                    cout << "\nEnter the title of the book want to buy : ";
                    cin.getline(titlebuy, 20);
                    cout << "\nEnter the name of author of the book : ";
                    cin.getline(authorbuy, 20);
                    for (t = 0; i < i; t++)
                    {
                        if (B[t]->search(titlebuy, authorbuy))
                        {
                            B[t]->buybook();
                            break;
                        }
                    }
                    if (t == i)
                        cout << "\nThis Book is Not in Stock";
                    break;
                case 3:
                    cin.ignore();
                    cout << "\nEnter the title of the book want to search : ";
                    cin.getline(titlebuy, 20);
                    cout << "\nEnter the name of author of the book : ";
                    cin.getline(authorbuy, 20);
                    for (t = 0; t < i; t++)
                    {
                        if (B[t]->search(titlebuy, authorbuy))
                        {
                            cout << "\n Book found successfully";
                            B[t]->showdata();
                            break;
                        }
                    }
                    if (t == i)
                        cout << "\nThis Book is Not in Stock";
                    break;
                case 4:
                    cin.ignore();
                    cout << "\nEnter the title of the book want to update : ";
                    cin.getline(titlebuy, 20);
                    cout << "\nEnter the name of author of the book : ";
                    cin.getline(authorbuy, 20);
                    for (int t = 0; t < i; t++)
                    {
                        if (B[t]->search(titlebuy, authorbuy))
                        {
                            cout << "\n Book found successfully";
                            B[t]->editdata();
                            break;
                        }
                    }
                    if (t == i)
                        cout << "\nThis Book is Not in Stock";
                    break;
                case 5:
                    for (t = 0; t < i; t++)
                    {
                        sum += B[t]->getStock();
                    }
                    cout << "\n Currently we have " << sum << " number of books in our store";
                    sum = 0;
                    break;
                case 6:
                    for (t = 0; t < i; t++)
                    {
                        cout << t + 1 << endl;
                        B[t]->showdata();
                        cout << "\n\n";
                    }
                case 7:
                    exit(0);
                default:
                    cout << "\nInvalid Choice Entered";
                }
            }
        }
        else
            cout << "Wrong Password";
    }
}