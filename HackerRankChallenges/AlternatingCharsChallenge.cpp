/*
Hackerrank::Challenges:Alternating Characters
description: https://www.hackerrank.com/challenges/alternating-characters/
*/

#include "Challenges.h"

#include "HackerRankMiscellaneous.h"
using hr::output_str;
using hr::split_string;

#include <bits/stdc++.h>

using std::cout;
using std::endl;
using std::cin;
using std::ofstream;
using std::max;
using std::numeric_limits;
using std::streamsize;

int alternatingCharacters(string s) {

    int counter = { 0 };
    size_t size = s.size();

    for (size_t i = 1; i < size; ++i) {
        if (s[i] == s[i - 1])
        {
            ++counter;
        }

    }
    return counter;
}

int alternatingCharactersChallenge() {

    string hackerrank_output_str = output_str("HACKERRANK_OUTPUT_PATH");
    ofstream fout(hackerrank_output_str);

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);

        int result = alternatingCharacters(s);

        cout << result << endl;
        fout << result << "\n";
        
    }

    fout.close();

    return 0;
}
