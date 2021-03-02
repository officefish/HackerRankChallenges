
/*
Hackerrank::Challenges:StringStreamChallenge
description: https://www.hackerrank.com/challenges/c-tutorial-stringstream/
*/


#include "Challenges.h"

#include <bits/stdc++.h>

using std::cout;
using std::endl;
using std::cin;
using std::ofstream;
using std::vector;
using std::string;
using std::stringstream; // https://en.cppreference.com/w/cpp/io/basic_stringstream

vector<int> parseInts(string str) {
    
    stringstream ss(str);
    int out;

    vector<int> integers;

    while (ss >> out) {
        integers.push_back(out);
        if (ss.peek() == ',') { // read next character without extracting it
            ss.ignore();        // extracts and discards characters until the given character is found
        }
    }

    return integers;
}

int stringSteamChallenge() {
    string str;
    cin >> str;
    vector<int> integers = parseInts(str);
    for (int i = 0; i < integers.size(); i++) {
        cout << integers[i] << "\n";
    }

    return 0;
}