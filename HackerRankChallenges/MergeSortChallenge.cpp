/*
Hackerrank::Challenges::MergeSort:Counting Inversions
description: https://www.hackerrank.com/challenges/ctci-merge-sort/problem
*/

#include "Challenges.h"

#include "HackerRankMiscellaneous.h"
using hr::split_string;

using std::cout;
using std::endl;
using std::cin;
using std::streamsize;
using std::numeric_limits;
using std::vector;

long merge(vector<int>& arr, int first, int mid, int last)
{
    long invCount{ 0 };
    // copy first half vector in temporary vector
    vector<int> temp;
    copy(arr.begin() + first, arr.begin() + mid + 1, back_inserter(temp));
    // sweep both vectors simultaniously until one empty
    int i{ first }, i1{ 0 }, i2{ mid + 1 };
    int size{ static_cast<int>(temp.size()) };
    while (i1 < size && i2 < last + 1) {
        if (arr[i2] < temp[i1]) {
            arr[i] = arr[i2];
            ++i, ++i2;
            invCount += i2 - i;
            continue;
        }
        arr[i] = temp[i1];
        ++i; ++i1;
    }
    // if any left in first put to the end of second
    while (i1 < size) {
        arr[i] = temp[i1];
        ++i; ++i1;
    }
    return invCount;
}

long mergeSort(vector<int>& arr, int first, int last) {
    long invCount{ 0 };
    if (first == last) return invCount;
    int mid{ (first + last) / 2 };
    invCount += mergeSort(arr, first, mid);
    invCount += mergeSort(arr, mid + 1, last);
    invCount += merge(arr, first, mid, last);
    return invCount;
}

long hrs::countInversions(vector<int>& arr) {
    int first{ 0 };
    int last{ static_cast<int>(arr.size()) - 1 };
    return mergeSort(arr, first, last);
}

int mergeSortChallenge() {
    using std::string;
    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    for (int t_itr = 0; t_itr < t; t_itr++) {
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
        long result = hrs::countInversions(arr);
        cout << result << "\n";
    }
    return 0;
}

/*
    Explanation:

    Let's take: 2 1 3 1 2

    This splits to:
    2 1 3 / 1 2

    Left Side: 2 1 3
    Next: 2 1 / 3
    Next: 2 / 1. Recombining this is 1 2 (Now, INV is now 1).
    Next: 3 is 3.
    Back to: 1 2 / 3. Recombining this is 1 2 3

    Now, back to the Right side of 2 1 3 1 2:
    Right Side: 1 2
    Next: 1 / 2
    Next: 1 is 1.
    Next: 2 is 2.
    Back to: 1 / 2. Recombine for 1 2

    Back to the top. We have:
    1 2 3 / 1 2, INV = 1
    The key here is, "Whenever we pick a number from the right array because it is smaller than the left array,
    then we have to add to the inversions. How many? The length of the remainder of the left array."
    So for example, let us recombine these two arrays step by step by comparing the smallest elements of each:

    1 2 3 / 1 2
    1 <= 1 -> 2 3 / 1 2
    2 > 1 -> 2 3 / 2
    (1 is less than 2 and 3 from the left array remainder.
    We add 2 (the length of the left array remainder). INV += 2; INV is now 3)

    2 <= 2 - > 3 / 2
    3 < 2 -> 3
    (2 is less than 3 from the left array remainder.
    We add 1 (the length of the left array remainder). INV += 1; INV is now 4)

    3 -> done

    count += mid + 1 - i;
    This adds the length of the remainder of the left array to the count.
*/