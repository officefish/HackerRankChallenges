/*
Hackerrank::Challenges::BubbleSort
description: https://www.hackerrank.com/challenges/30-sorting/problem
Solution Copyright(c) 2021 Officefish / Techies Team.
https://www.softwaretestinghelp.com/bubble-sort/
*/

#include <vector>
#include <algorithm>

#include ".././Challenges.h"

int day20BubbleSortChallenge() {
    using std::cin, std::cout, std::endl;
    using std::vector;
    using std::swap;

    int n;
    cin >> n;
    vector<int> a(n);
    for (int a_i = 0; a_i < n; a_i++) {
        cin >> a[a_i];
    }
    int counter{ 0 };
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (a[j] < a[i]) {
                swap(a[j], a[i]);
                ++counter;
            }
        }
    }
    cout << "Array is sorted in " << counter << " swaps." << endl;
    cout << "First Element: " << a[0] << endl;
    cout << "Last Element: " << a[a.size() - 1];
    return 0;
}