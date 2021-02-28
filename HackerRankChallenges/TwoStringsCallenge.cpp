/*
    Hackerrank::Challenges::TwoStrings
    description: https://www.hackerrank.com/challenges/two-strings
*/

#include "Challenges.h"

#include "HackerRankMiscellaneous.h"
using hr::output_str;

#include <bits/stdc++.h>

using std::cout;
using std::endl;
using std::cin;
using std::ofstream;
using std::max;
using std::numeric_limits;
using std::streamsize;

#include <unordered_map>
using std::unordered_map;
// https://en.cppreference.com/w/cpp/container/unordered_map

string twoStrings(string s1, string s2) {
    
    string largeStr;
    string shortStr;
    string ans;

    bool status = false;
    unordered_map<char, bool> chars;

    if (s1.size() >= s2.size()) {
        largeStr = s1;
        shortStr = s2;
    }
    else {
        largeStr = s2;
        shortStr = s1;
    }

    for (auto& it : shortStr)
        chars[it] = true;

    for (auto& it : largeStr) {
        if (chars[it]) {
            status = true; break;
        }
    }

    return ans =  status ? "YES" : "NO";
}

int twoStringsChallenge() {
    
    string hackerrank_output_str = output_str("HACKERRANK_OUTPUT_PATH");
    ofstream fout(hackerrank_output_str);

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s1;
        getline(cin, s1);

        string s2;
        getline(cin, s2);

        string result = twoStrings(s1, s2);
        cout << result << '\n';
        fout << result << "\n";
    }

    fout.close();

    return 0;
}