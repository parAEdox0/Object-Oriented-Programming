/*Imagine a publishing company which does marketing for book and audio cassette versions. Create a class publication that stores the title (a string) and price (type float) of publications. From this class derive two classes: book which adds a page count (type int) and tape which adds a playing time in minutes (type float). Write a program that instantiates the book and tape class, allows user to enter data and displays the data members. If an exception is caught, replace all the data member values with zero values.*/

#include <iostream>
#include <string>
using namespace std;

class Publication
{

private:
    string title;
    float price;

public:
    void getdata();
    void display();
};

void Publication ::getdata()
{
    cout << "Enter Title(use '_' (under_score) instead of ' ' (space)): ";
    cin >> title;

    if (title.find(' '))
    {
        throw "Error! Using space is not allowed";
    }

    cout << "Enter Price : ";
    cin >> price;

    if (price < 0)
    {
        throw "Invalid Price! can't be negative";
    }
}

void Publication ::display()
{
    cout << "Title : " << title << endl;
    cout << "Price : " << price << endl;
}

class Book : public Publication
{
private:
    int page_count;

public:
    void input_pages()
    {
        cout << "Enter number of pages : ";
        cin >> page_count;

        if (page_count < 0)
        {
            throw "Invalid number of pages! can't be negative";
        }
    }
    void print_pages()
    {
        cout << "The number of pages : " << page_count << endl;
    }
};

class Tape : public Publication
{
private:
    float play_time;

public:
    void input_play_time()
    {
        cout << "Enter playing time in minutes : ";
        cin >> play_time;
        if (play_time < 0)
        {
            throw "Invalid play time! can't be negative";
        }
    }
    void print_play_time()
    {
        cout << "The play time in minutes: " << play_time << endl;
    }
};

int main()
{
    try
    {
        Book b1;
        Tape t1;
        cout << "\nEnter Book Details : " << endl
             << endl;
        b1.getdata();
        b1.input_pages();
        cout << endl;
        cout << "\nEnter Tape Details : " << endl
             << endl;
        t1.getdata();
        t1.input_play_time();
        cout << endl;
        cout << "********************Book********************" << endl
             << endl;
        b1.display();
        b1.print_pages();
        cout << endl;
        cout << "********************Tape********************" << endl
             << endl;
        t1.display();
        t1.print_play_time();
        cout << endl;
    }
    catch (const char *errors)
    {
        cerr << "Exception caught! " << errors << endl;
    }
    return 0;
}
