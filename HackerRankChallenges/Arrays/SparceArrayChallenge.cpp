/*
Hackerrank::Challenges::Arrays::SparceArray
description: https://www.hackerrank.com/challenges/sparse-arrays/problem
*/

#include <algorithm>
#include ".././Challenges.h"
#include <set>

std::vector<int> hrs::matchingStrings(std::vector<std::string> s, std::vector<std::string> q) {
    std::multiset<std::string> strings(s.begin(), s.end());
    std::set<std::string> queues(q.begin(), q.end());
    std::vector<int> output;
    for (auto& key : queues) {
        output.push_back(static_cast<int>(strings.count(key)));
    }
    return output;
}

int sparseArraysChallenge() {
    using std::cin, std::cout, std::endl;
    using std::streamsize, std::numeric_limits;
    using std::vector, std::string;

    int strings_count;
    cin >> strings_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<string> strings(strings_count);
    for (int i = 0; i < strings_count; i++) {
        string strings_item;
        getline(cin, strings_item);

        strings[i] = strings_item;
    }
    int queries_count;
    cin >> queries_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<string> queries(queries_count);

    for (int i = 0; i < queries_count; i++) {
        string queries_item;
        getline(cin, queries_item);
        queries[i] = queries_item;
    }

    vector<int> res = hrs::matchingStrings(strings, queries);

    for (int i = 0; i < res.size(); i++) {
        cout << res[i];
        if (i != res.size() - 1)
            cout << "\n";

    }
    cout << "\n";
    return 0;
}