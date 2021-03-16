/*
Hackerrank::Challenges::Day12:Inheritance
description: https://www.hackerrank.com/challenges/multi-level-inheritance-cpp
Solution Copyright (c) 2021 Officefish / Techies Team.
*/
#include "./Challenges.h"
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
};
class Equilateral : public Isosceles {
public:
    void equilateral() {
        cout << "I am an equilateral triangle\n";
    }
};
int multiInheritanceChallenge () {
    Equilateral eqr;
    eqr.equilateral();
    eqr.isosceles();
    eqr.triangle();
    return 0;
}
