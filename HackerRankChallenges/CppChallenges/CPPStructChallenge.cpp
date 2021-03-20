/*
Hackerrank::Challenges::CPPTutorialStruct
description:https://www.hackerrank.com/challenges/c-tutorial-struct
Solution Copyright (c) 2021 Officefish / Techies Team.
*/

#include <string>
#include <algorithm>

#include ".././Challenges.h"

struct Student {
    int16_t age;
    std::string first_name;
    std::string last_name;
    int16_t standard;
};

int structChallenge() {
    using std::cin;
    using std::cout;
    Student st;
    cin >> st.age >> st.first_name;
    cin >> st.last_name >> st.standard;
    std::transform(
        st.first_name.begin(), st.first_name.end(),
        st.first_name.begin(), ::tolower);
    std::transform(
        st.last_name.begin(), st.last_name.end(),
        st.last_name.begin(), ::tolower);
    cout << st.age << " ";
    cout << st.first_name << " ";
    cout << st.last_name << " ";
    cout << st.standard;
    return 0;
}
