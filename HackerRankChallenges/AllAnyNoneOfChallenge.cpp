/*
BestPractice using STD Library / Algorithm
Copyright (c) 2021 Officefish / Techies Team.
*/

#include <Algorithm>
#include "./Challenges.h"

using std::vector;
using std::cout;
using std::endl;
using std::cin;
using std::numeric_limits;
using std::streamsize;

bool hrs::isEven(int32_t input) {
    return input % 2 == 0;
}
bool hrs::isOdd(int32_t input) {
    return input % 2 != 0;
}

namespace allof {
    enum MODE {
        ALL_OF_IS_EVEN = 1, 
        ALL_OF_IS_ODD = 2,
        ANY_OF_IS_EVEN = 3,
        ANY_OF_IS_ODD = 4,
        NONE_OF_IS_EVEN = 5,
        NONE_OF_IS_ODD = 6,
        CLEAR = 7
    };
    int32_t mode = ALL_OF_IS_EVEN;
    vector<int32_t> inputs;

    void changeMode(int32_t mode);
    void commander();
    void allOfIsEvenCommander();
    void allOfIsOddCommander();
    void anyOfIsEvenCommander();
    void anyOfIsOddCommander();
    void noneOfIsEvenCommander();
    void noneOfIsOddCommander();
    bool allOfIsEven(vector<int> inputs);
    bool allOfIsOdd(vector<int> inputs);
    bool anyOfIsEven(vector<int> inputs);
    bool anyOfIsOdd(vector<int> inputs);
    bool noneOfIsEven(vector<int> inputs);
    bool noneOfIsOdd(vector<int> inputs);
}

int allAnyNoneOfChallenge() {
    int32_t input;
    cout << "Allof Challenge. CurrentMode::" << allof::mode << endl;
    while (cin >> input) {
        if (!input) break;
        if (input >= allof::ALL_OF_IS_EVEN && input <= allof::CLEAR) {
            allof::changeMode(input);
        } else {
            allof::inputs.push_back(input);
        }
        allof::commander();
    }
    return 0;
}

void allof::changeMode(int32_t mode) {
    if (mode == allof::mode) return;
    allof::mode = mode;
    if (mode != CLEAR) {
        cout << "CurrentMode::" << allof::mode << endl;
    }
    else {
        cout << "container is empty" << endl;
    }
}

void allof::commander() {
    switch (allof::mode) {
    case ALL_OF_IS_EVEN: {
        allOfIsEvenCommander();
        break;
    }
    case ALL_OF_IS_ODD: {
        allOfIsOddCommander();
        break;
    }
    case ANY_OF_IS_EVEN: {
        anyOfIsEvenCommander();
        break;
    }
    case ANY_OF_IS_ODD: {
        anyOfIsOddCommander();
        break;
    }
    case NONE_OF_IS_EVEN: {
        noneOfIsEvenCommander();
        break;
    }
    case NONE_OF_IS_ODD: {
        noneOfIsOddCommander();
        break;
    }
    case CLEAR: {
        inputs.clear();
        break;
    }
    }
}

void inline allof::allOfIsEvenCommander() {
    cout << "inputs(" << inputs.size() << ") contains only even numbers: ";
    cout << std::boolalpha << allOfIsEven(allof::inputs) << endl;
}
void inline allof::allOfIsOddCommander() {
    cout << "inputs(" << inputs.size() <<") contains only odd numbers: ";
    cout << std::boolalpha << allOfIsOdd(allof::inputs) << endl;
}
void inline allof::anyOfIsEvenCommander() {
    cout << "inputs(" << inputs.size() << ") contains some even numbers: ";
    cout << std::boolalpha << anyOfIsEven(allof::inputs) << endl;
}
void inline allof::anyOfIsOddCommander() {
    cout << "inputs(" << inputs.size() << ") contains some odd numbers: ";
    cout << std::boolalpha << anyOfIsOdd(allof::inputs) << endl;
}
void inline allof::noneOfIsEvenCommander() {
    cout << "inputs(" << inputs.size() << ") contains none of even numbers: ";
    cout << std::boolalpha << noneOfIsEven(allof::inputs) << endl;
}
void inline allof::noneOfIsOddCommander() {
    cout << "inputs(" << inputs.size() << ") contains none of odd numbers: ";
    cout << std::boolalpha << noneOfIsOdd(allof::inputs) << endl;
}

bool inline allof::allOfIsEven(vector<int> inputs) {
    return std::all_of(inputs.begin(), inputs.end(), hrs::isEven);
}
bool inline allof::allOfIsOdd(vector<int> inputs) {
    return std::all_of(inputs.begin(), inputs.end(), hrs::isOdd);
}
bool inline allof::anyOfIsEven(vector<int> inputs) {
    return std::any_of(inputs.begin(), inputs.end(), hrs::isEven);
}
bool inline allof::anyOfIsOdd(vector<int> inputs) {
    return std::any_of(inputs.begin(), inputs.end(), hrs::isOdd);
}
bool inline allof::noneOfIsEven(vector<int> inputs) {
    return std::none_of(inputs.begin(), inputs.end(), hrs::isEven);
}
bool inline allof::noneOfIsOdd(vector<int> inputs) {
    return std::none_of(inputs.begin(), inputs.end(), hrs::isOdd);
}
