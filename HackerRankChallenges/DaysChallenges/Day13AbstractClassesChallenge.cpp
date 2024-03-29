/*
Hackerrank::Challenges::Day12:Inheritance
description:https://www.hackerrank.com/challenges/30-abstract-classes/
or below this page
Solution Copyright (c) 2021 Officefish / Techies Team.
*/

//#include <cmath>
//#include <cstdio>
#include <algorithm>
#include ".././Challenges.h"
using std::string;

class Book {
protected:
    string title;
    string author;
public:
    Book(string t, string a) : title(t), author(a) {};
    virtual void display() = 0;
};

class MyBook : Book {
protected:
    int16_t price;
public:
    MyBook(string t, string a, int16_t p) : Book(t, a), price(p) {};
    using Book::display;
    void display();
};

void MyBook::display() {
    using std::cout, std::endl;
    cout << "Title: " << title << endl;
    cout << "Author: " << author << endl;
    cout << "Price: " << price << endl;
}

int day13AbstrClassChallenge() {
    string title, author;
    int price;
    getline(std::cin, title);
    getline(std::cin, author);
    std::cin >> price;
    MyBook novel(title, author, price);
    novel.display();
    return 0;
}

/*
Task
Given a Book class and a Solution class, write a MyBook class that does the following:

Inherits from Book
Has a parameterized constructor taking these 3 parameters:
string title
string author
int price

Implements the Book class' abstract display() method so it prints these 3 lines:
Title: a space, and then the current instance's title.
Author: a space, and then the current instance's author.
Price a space, and then the current instance's price.

Note: Because these classes are being written in the same file, you must not use an access modifier (e.g.: public)
when declaring MyBook or your code will not execute.

Input Format

You are not responsible for reading any input from stdin. The Solution class creates a Book object and calls
the MyBook class constructor (passing it the necessary arguments).
It then calls the display method on the Book object.

Output Format

The void display() method should print and label the respective title, author, and price
of the MyBook object's instance (with each value on its own line) like so:

Title: $title
Author: $author
Price: $price
Note: The $ is prepended to variable names to indicate they are placeholders for variables.

Sample Input

The following input from stdin is handled by the locked stub code in your editor:

The Alchemist
Paulo Coelho
248
Sample Output

The following output is printed by your display() method:

Title: The Alchemist
Author: Paulo Coelho
Price: 248
*/