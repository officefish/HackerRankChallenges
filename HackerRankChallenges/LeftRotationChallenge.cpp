/*
Hackerrank::Challenges::JumpingOnTheClouds
description: https://www.hackerrank.com/challenges/ctci-array-left-rotation/
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

vector<int> RotationLeft(vector<int> a, int d) {
    
    const int SRC_SIZE = a.size();
    vector<int> output(SRC_SIZE);

    int srcIndex;

    for (int i = 0; i < SRC_SIZE; ++i) {
        srcIndex = i + d;
        if (srcIndex >= SRC_SIZE) srcIndex -= SRC_SIZE;
        output[i] = a[srcIndex];
    }
    return output;
   
}

int LeftRotationChallenge() {

    string hackerrank_output_str = output_str("HACKERRANK_OUTPUT_PATH");
    ofstream fout(hackerrank_output_str);

    string nd_temp;
    getline(cin, nd_temp);

    vector<string> nd = split_string(nd_temp);

    int n = stoi(nd[0]);

    int d = stoi(nd[1]);

    string a_temp_temp;
    getline(cin, a_temp_temp);

    vector<string> a_temp = split_string(a_temp_temp);

    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        int a_item = stoi(a_temp[i]);

        a[i] = a_item;
    }

    vector<int> result = RotationLeft(a, d);

    for (int i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << " ";
        }
    }

    for (auto x : result)
        cout << x << " ";
    cout << "\n";

    fout << "\n";
    fout.close();

    return 0;
}