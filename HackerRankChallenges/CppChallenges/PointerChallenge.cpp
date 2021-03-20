/*
    Hackerrank::Challenges::PointerChallenge
    https://www.hackerrank.com/challenges/c-tutorial-pointer
*/

#include ".././Challenges.h"

using std::cout;
using std::cin;
using std::endl;
using std::numeric_limits;
using std::streamsize;

void update(int* a, int* b);

int pointerChallenge() {
    int a, b;
    int* pa = &a, * pb = &b;

    cin >> a >> b;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    update(pa, pb);

    cout << "a: " << a << ", b:" << b << endl;

    return 0;
}

void update(int* a, int* b) {

    int aValue = *a;
    int bValue = *b;

    *a = aValue + bValue;
    *b = abs(aValue - bValue);

    /*
        int sum = *a + *b;
        int absDifference = *a - *b > 0 ? *a - *b : -(*a - *b);
    */
}