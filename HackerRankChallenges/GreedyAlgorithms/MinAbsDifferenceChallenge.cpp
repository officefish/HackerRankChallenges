/*
Hackerrank::Challenges::GreedyAlgorithm::MinimumAbsoluteDifferenceInAnArray
description: https://www.hackerrank.com/challenges/minimum-absolute-difference-in-an-array
Solution Copyright (c) 2021 Officefish / Techies Team.
std::iterator https://en.cppreference.com/w/cpp/iterator/iterator
std::adjacment_difference https://en.cppreference.com/w/cpp/algorithm/adjacent_difference

*/

#include <string>
#include <vector>
#include <numeric>
#include <iterator>
#include <algorithm>

#include ".././Challenges.h"
#include ".././HackerRankMiscellaneous.h"

// std library optomization
int hrs::minAbsDifference_uSTD(vector<int> arr) {
    vector<int> sortArr;
    sort(begin(arr), end(arr));
    adjacent_difference
        (begin(arr), end(arr),back_inserter(sortArr));
    return *min_element(begin(sortArr) + 1, end(sortArr));
}

int hrs::minAbsDifference(vector<int> arr) {
    // first sort
    sort(arr.begin(), arr.end());
    int minDifference = INT_MAX, absDifference;
    // goes through vector and save current closest option element
    for (size_t i = 0, s = arr.size() - 1; i < s; ++i) {
        absDifference = abs(arr[i + 1] - arr[i]);
        if (!minDifference || absDifference < minDifference) {
            minDifference = absDifference;
        }
        if (minDifference == 0) {
            return 0;
        }
    }
    return minDifference;
}

int minAbsDifferenceChallenge() {
    using hr::split_string;
    using std::cout;
    using std::endl;
    using std::cin;
    using std::numeric_limits;
    using std::streamsize;
    using std::string;
    using std::vector;
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    string arr_temp_temp;
    getline(cin, arr_temp_temp);
    vector<string> arr_temp = split_string(arr_temp_temp);
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);
        arr[i] = arr_item;
    }
    int result = hrs::minAbsDifference(arr);
    cout << result;
    return 0;
}