/*
Hackerrank::Challenges::Day12:Inheritance
description: https://www.hackerrank.com/challenges/cpp-lower-bound/
Solution Copyright (c) 2021 Officefish / Techies Team.
*/
#include "./Challenges.h"
#include <algorithm>

int lowerBoundChallenge() {
    std::vector<int32_t> stack;
    int32_t n, v, q;
    std::cin >> n;
    for (int32_t i = 0; i < n; ++i) {
        std::cin >> v;
        stack.push_back(v);
    }
    std::sort(stack.begin(), stack.end());
    std::cin >> n;
    for (int32_t i = 0; i < n; ++i) {
        std::cin >> q;
        std::vector<int32_t>::iterator low;
        low = std::lower_bound(stack.begin(), stack.end(), q);
        std::string s;
        s = stack[low - stack.begin()] == q ? "Yes " : "No ";
        std::cout << s << low - stack.begin() + 1 << std::endl;
    }
    return 0;
}

