/*
    Hackerrank::Challenges::ArrayIntroductionChallenge
    https://www.hackerrank.com/challenges/arrays-introduction
*/

#include "Challenges.h"

using std::cout;
using std::cin;
using std::endl;

int arrayIntroductionChallenge() {

    int length;
    cin >> length;

    int* numbers = new int[length];

    for (int i = 0; i < length; ++i) {
        cin >> numbers[i];
    }

    for (int i = length - 1; i >= 0; --i) {
        cout << numbers[i] << " ";
    }

    cout << endl;

    delete[] numbers;

    return 0;

}