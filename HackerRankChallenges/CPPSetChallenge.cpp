/*
Hackerrank::Challenges::SetChallenge
description:https://www.hackerrank.com/challenges/cpp-sets/
Solution Copyright (c) 2021 Officefish / Techies Team.
*/
#include "./Challenges.h"
#include <algorithm>
#include <set>

inline void Add(std::set<int32_t>* set, const int32_t value) {
    set->insert(value);
}
inline void Delete(std::set<int32_t>* set, const int32_t value) {
    set->erase(value);
}
inline void Print(std::set<int32_t>* set, const int32_t value) {
    std::string s = set->find(value) == set->end() ? "No" : "Yes";
    std::cout << s << std::endl;
}

int setChallenge() {
    std::set<int32_t> set;
    int32_t n, c, v; // numQueues, command, value;
    std::cin >> n;
    for (int32_t i = 0; i < n; i++) {
        std::cin >> c >> v;
        switch (c) {
        case 1:
            Add(&set, v);
            break;
        case 2:
            Delete(&set, v);
            break;
        case 3:
            Print(&set, v);
            break;
        }
    }
    return 0;
}
