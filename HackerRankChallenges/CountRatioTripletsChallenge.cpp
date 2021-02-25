/*
    Hackerrank::Challenges::CountRatioTriplets
    description: https://www.hackerrank.com/challenges/count-triplets-1
*/


#include "Challenges.h"

#include "HackerRankMiscellaneous.h"
using hr::output_str;
using hr::ltrim;
using hr::rtrim;
using hr::split;

#include <bits/stdc++.h>
#include <algorithm>

using std::ofstream;
using std::cin;
using std::cout;
using std::stoi;
using std::endl;


#include <unordered_map>
using std::unordered_map;
// https://en.cppreference.com/w/cpp/container/unordered_map

long CountTriplets(vector<long> arr, long r) {

    long triplets = 0;
    unordered_map<string, long> pairs;
    unordered_map<long, long> map;

    const long SIZE = arr.size();

    long x;
    long rx;
    long r2x;
    string pairWeWant;
    string pair;

    for (long i = SIZE - 1; i >= 0; --i) {
        x = arr[i];
        rx = x * r;
        r2x = rx * r;
        pairWeWant = std::to_string(rx) + std::to_string(r2x);
        if (pairs[pairWeWant]) {
            triplets += pairs[pairWeWant];
        }
        pair = std::to_string(x) + std::to_string(rx);
        pairs[pair] += map[rx];
        map[x] ? map[x]++ : map[x] = 1;
    }

    return triplets;
}

int CountRatioTripletsChallenge() {

    string hackerrank_output_str = output_str("HACKERRANK_OUTPUT_PATH");
    ofstream fout(hackerrank_output_str);

    string nr_temp;
    getline(cin, nr_temp);

    vector<string> nr = split(rtrim(nr_temp));

    int n = stoi(nr[0]);

    long r = stol(nr[1]);

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split(rtrim(arr_temp_temp));

    vector<long> arr(n);

    for (int i = 0; i < n; i++) {
        long arr_item = stol(arr_temp[i]);

        arr[i] = arr_item;
    }

    long ans = CountTriplets(arr, r);

    cout << ans << "\n";
    fout << ans << "\n";

    fout.close();

    return 0;
}