/*
Hackerrank::Challenges::Day12:Inheritance
description: https://www.hackerrank.com/challenges/overload-operators/
Solution Copyright (c) 2021 Officefish / Techies Team.
*/
#include "./Challenges.h"
#include <sstream>
class Complex {
    double _RealVal{ 0 }, _ImagVal{ 0 };
public:
    Complex() {}
    Complex(double r, double i) : _RealVal(r), _ImagVal(i) {}
    void input(std::string);
    friend Complex operator+(const Complex& c1, const Complex& c2);
    friend std::ostream& operator<<(std::ostream& os, const Complex& c);
};

void Complex::input(std::string complexText) {
    //std::string parsed;
    //std::stringstream complexStream;
    std::string delimiter = "+i";
    std::string real = complexText.substr(0, complexText.find(delimiter));
    std::string imag = complexText.substr(real.length(), complexText.find(delimiter));
    _RealVal = atof(real.c_str());
    _ImagVal = atof(imag.c_str());
    //std::cout << _RealVal << " " << _ImagVal << std::endl;
}

inline std::ostream& operator<<(std::ostream& os, const Complex& c) {
    os << c._RealVal << (c._ImagVal > 0 ? '+' : '-') << c._ImagVal;
    return os;
}
Complex operator+(const Complex& c1, const Complex& c2) {
    Complex c3;
    c3._RealVal = c1._RealVal + c2._RealVal;
    c3._ImagVal = c1._ImagVal + c2._ImagVal;
    return c3;
}

int overloadOperatorChallenge()
{
    using std::cin, std::cout, std::endl, std::string;
    Complex x, y;
    string s1, s2;
    cin >> s1;
    cin >> s2;
    x.input(s1);
    y.input(s2);
    Complex z = x + y;
    cout << z << endl;
    return 0;
}
