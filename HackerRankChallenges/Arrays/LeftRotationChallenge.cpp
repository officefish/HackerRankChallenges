/*
Hackerrank::Challenges::JumpingOnTheClouds
description: https://www.hackerrank.com/challenges/ctci-array-left-rotation/
*/

#include ".././Challenges.h"

#include ".././HackerRankMiscellaneous.h"
using hr::split_string;

using std::cout;
using std::endl;
using std::cin;
using std::ofstream;

std::vector<int> hrs::rotationLeft(vector<int> a, int d) {
    const size_t SRC_SIZE = a.size();
    std::vector<int> output(SRC_SIZE);
    size_t srcIndex;
    for (size_t i = 0; i < SRC_SIZE; ++i) {
        srcIndex = i + size_t(d);
        if (srcIndex >= SRC_SIZE) srcIndex -= SRC_SIZE;
        output[i] = std::move(a[srcIndex]);
    }
    return output;
}

int leftRotationChallenge() {
    using std::string, std::vector;
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
    vector<int> result = hrs::rotationLeft(a, d);
    for (auto x : result)
        cout << x << " ";
    cout << "\n";
    return 0;
}