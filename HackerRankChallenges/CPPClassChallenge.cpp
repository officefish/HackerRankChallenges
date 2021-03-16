/*
Hackerrank::Challenges::Day12:Inheritance
description:https://www.hackerrank.com/challenges/c-tutorial-class/
Solution Copyright (c) 2021 Officefish / Techies Team.
habr::Inheritance https://habr.com/ru/post/445948/
*/
#include <iostream>
#include <sstream>
#include "./Challenges.h"
using std::string;

class Student {

private:
    int8_t _age, _standard;
    string _first_name, _last_name;
public:
    void set_age(int8_t age) { _age = age; }
    void set_standard(int8_t standard) { _standard = standard; }
    void set_first_name(string name) { _first_name = name; }
    void set_last_name(string name) { _last_name = name; }
    string to_string();

    int8_t get_age() { return unsigned(_age); }
    int8_t get_standard() { return unsigned(_standard); }
    string get_first_name() { return _first_name; }
    string get_last_name() { return _last_name; }
};

string Student::to_string() {
    std::stringstream ss;
    ss << +this->get_age() << ", ";
    ss << this->get_first_name() << ", ";
    ss << this->get_last_name() << ", ";
    ss << +this->get_standard() << std::endl;
    ss << std::noskipws;
    return ss.str();
}

int classChallenge () {
    using std::cin, std::cout;
    int age, standard;
    string first_name, last_name;

    cin >> age >> first_name >> last_name >> standard;

    Student st;
    st.set_age(age);
    st.set_standard(standard);
    st.set_first_name(first_name);
    st.set_last_name(last_name);

    cout << +st.get_age() << "\n";
    cout << st.get_last_name() << ", " << st.get_first_name() << "\n";
    cout << +st.get_standard() << "\n";
    cout << "\n";
    cout << st.to_string();

    return 0;
}