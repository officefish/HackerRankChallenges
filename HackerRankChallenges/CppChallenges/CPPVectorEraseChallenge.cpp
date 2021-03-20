/*
Hackerrank::Challenges::VectorEraseChallenge
description: https://www.hackerrank.com/challenges/vector-erase/
Solution Copyright(c) 2021 Officefish / Techies Team.
*/
#include ".././Challenges.h"
#include <vector>

inline void DeleteRange(std::vector<int32_t>* stack, const int32_t begin, const int32_t end) {
    stack->erase(stack->begin() + begin, stack->begin() + end);
}

inline void Delete(std::vector<int32_t>* stack, const int32_t index) {
    stack->erase(stack->begin() + index);
}

inline void Print(std::vector<int32_t>* stack) {
    std::cout << stack->size() << std::endl;
    for (int32_t x : *stack) {
        std::cout << x << " ";
    }
}

int vectorEraseChallenge() {
    using std::cin;
    using std::vector;
    int32_t n, x, a, b;
    vector<int32_t> stack;
    cin >> n;
    for (int32_t i = 0; i < n; ++i) {
        cin >> x;
        stack.push_back(x);
    }
    cin >> x;
    Delete(&stack, x - 1);
    cin >> a >> b;
    DeleteRange(&stack, a - 1, b - 1);
    Print(&stack);
    return 0;
}
