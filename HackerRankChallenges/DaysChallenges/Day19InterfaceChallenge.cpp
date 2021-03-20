/*
Hackerrank::Challenges::PreprocessorChallenge
description: https://www.hackerrank.com/challenges/30-interfaces/problem
Solution Copyright(c) 2021 Officefish / Techies Team.
*/
#include ".././Challenges.h"

class AdvancedArithmetic {
public:
    virtual int divisorSum(int n) = 0;
};
class Calculator : public AdvancedArithmetic {
public:
    using AdvancedArithmetic::divisorSum;
    int divisorSum(int n) {
        int sum = 0;
        for (int i = 1; i <= n; ++i)
            if(n % i == 0) sum += i;
        return sum;
    }
};

int day19InterfaceChallenge() {
    int n;
    std::cin >> n;
    AdvancedArithmetic* myCalculator = new Calculator();
    int sum = myCalculator->divisorSum(n);
    std::cout << "I implemented: AdvancedArithmetic\n" << sum;
    return 0;
};