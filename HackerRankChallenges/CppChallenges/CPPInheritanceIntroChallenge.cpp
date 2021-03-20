/*
Hackerrank::Challenges::Day12:Inheritance
description: https://www.hackerrank.com/challenges/inheritance-introduction
Solution Copyright (c) 2021 Officefish / Techies Team.
*/
#include ".././Challenges.h"
using std::cout;

class Triangle {
public:
    void triangle() {
        cout << "I am a triangle\n";
    }
};

class Isosceles : public Triangle {
public:
    void isosceles() {
        cout << "I am an isosceles triangle\n";
    }
    // that is quiz, lol
    void description() {
        cout << "In an isosceles triangle two sides are equal\n";
    }
};

int inheritanceIntroChallenge() {
    Isosceles isc;
    isc.isosceles();
    isc.description();
    isc.triangle();
    return 0;
}