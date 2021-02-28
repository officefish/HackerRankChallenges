/*
Hackerrank::Challenges:RectangleArea
description: https://www.hackerrank.com/challenges/rectangle-area
*/


#include "Challenges.h"

#include <bits/stdc++.h>

using std::cout;
using std::endl;
using std::cin;


class Rectangle {
protected:
    int width{ 0 };
    int height{ 0 };

public:
    virtual void display() {
        cout << width << " " << height << endl;
    };
};

class RectangleArea : public Rectangle {
public:
    void display() {
        cout << width * height << endl;
    };
    void read_input() {
        cin >> width >> height;
    }
};

int rectangleAreaChallenge() {
    
    // Declare a RectangleArea object
    RectangleArea r_area;

    //Read the width and height
    r_area.read_input();

    //Print the width and height
    
    r_area.Rectangle::display();

    // Print the area
    r_area.display();

    return 0;
}