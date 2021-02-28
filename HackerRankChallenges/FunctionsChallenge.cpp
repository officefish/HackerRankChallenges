/*
    Hackerrank::Challenges::Functions
    https://www.hackerrank.com/challenges/c-tutorial-functions
*/

#include "Challenges.h"

#include<bits/stdc++.h>
using std::cout;
using std::cin;
using std::endl;
using std::numeric_limits;
using std::streamsize;
using std::sort;

int max_of_four(int a, int b, int c, int d);

int functionsChallenge() {

    
    int n1, n2, n3, n4;
    int max;

    cin >> n1 >> n2 >> n3 >> n4;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    
    max = max_of_four(n1, n2, n3, n4);
    cout << max << endl;

    return 0;
}

int max_of_four(int a, int b, int c, int d) {

    int numbers[4] = { a,b,c,d };
    int n = sizeof(numbers) / sizeof(numbers[0]);
    sort(numbers, numbers + n);

    return numbers[3];
}



