/*
Hackerrank::Challenges::BubbleSort
description:https://www.hackerrank.com/challenges/ctci-bubble-sort
*/

#include ".././Challenges.h"
#include ".././HackerRankMiscellaneous.h"
using hr::split_string;

size_t hrs::countSwaps(vector<int> a) {
    size_t i, j;
    size_t n = a.size();
    size_t counter = 0;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n - 1; j++) {
            // Swap adjacent elements if they are in decreasing order
            if (a[j] > a[j + 1]) {
                std::swap(a[j], a[j + 1]);
                ++counter;
            }
        }
    }
    return counter;
}

int bubbleSortChallenge(){
    using std::cout;
    using std::endl;
    using std::cin;
    using std::streamsize;
    using std::numeric_limits;
    using std::string, std::vector;
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    string a_temp_temp;
    getline(cin, a_temp_temp);
    vector<string> a_temp = split_string(a_temp_temp);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        int a_item = stoi(a_temp[i]);
        a[i] = a_item;
    }
    cout << "Array is sorted in " << hrs::countSwaps(a) << " swaps." << endl;
    cout << "First Element: " << a[0] << endl;
    cout << "Last Element: " << a[n - 1] << endl;
    return 0;
}

// How to count Swaps without swaps see: