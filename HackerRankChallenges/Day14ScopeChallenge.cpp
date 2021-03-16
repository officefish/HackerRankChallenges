/*
Hackerrank::Challenges::Day12:Inheritance
description:https://www.hackerrank.com/challenges/30-scope/
or below this page
Solution Copyright (c) 2021 Officefish / Techies Team.
linear time solution: https://www.geeksforgeeks.org/maximum-absolute-difference-value-index-sums/
*/
#include <algorithm>
#include <limits.h>

#include "./Challenges.h"
class Difference {
private:
    std::vector<int> elements;

public:
    explicit Difference(std::vector<int> __elements) : elements(__elements) {};
    int maximumDifference{ 0 };
    void computeDifference();
    // Add your code here

}; // End of Difference class

void Difference::computeDifference() {
    using std::max;
    using std::min;
    int m = INT_MIN, n = INT_MAX;
    for (int c : elements) {
        m = max(m, c);
        n = min(n, c);
    }
    /*
    std::vector<int>::iterator it;
    for (it = elements.begin(); it != elements.end(); ++it) {
        m = max(m, *it);
        n = min(n, *it);
    }*/
    maximumDifference = m - n;
}

int day14ScopeChallenge() {
    using std::cout, std::cin, std::vector;
    int8_t N;
    cin >> N;
    vector<int> a;
    for (int8_t i = 0; i < N; i++) {
        int e;
        cin >> e;
        a.push_back(e);
    }
    Difference d(a);
    d.computeDifference();
    cout << d.maximumDifference;
    return 0;
}



/*
he absolute difference between two integers, a and b, is written as |a - b|.
The maximum absolute difference between two integers in a set of positive integers, elements,
is the largest absolute difference between any two integers in __elements.

The Difference class is started for you in the editor.
It has a private integer array (elements) for storing N non-negative integers,
and a public integer (maximumDifference) for storing the maximum absolute difference.

Task
Complete the Difference class by writing the following:

A class constructor that takes an array of integers as a parameter and saves it to the __elements instance variable.
A computeDifference method that finds the maximum absolute difference between any 2 numbers in __elements and stores
it in the maximumDifference instance variable.

Input Format
You are not responsible for reading any input from stdin.
The locked Solution class in the editor reads in 2 lines of input.
The first line contains N, the size of the elements array.
The second line has N space-separated integers that describe the __elements array.

Constraints
1 <= N <= 10
1 <= __elements[i] <= 100, where 0 <= i <= N - 1

Output Format

You are not responsible for printing any output; the Solution class will print the valu
e of the maximimDifference instance variable.

Sample Input
STDIN   Function
-----   --------
3       __elements[] size N = 3
1 2 5   __elements = [1, 2, 5]

Sample Output
4

Explanation
The scope of the __elements array and maximumDifference integer is the entire class instance.
The class constructor saves the argument passed to the constructor as the __elements instance variable
(where the computeDifference method can access it).

To find the maximum difference, computeDifference checks each element in the array and finds
the maximum difference between any 2 elements:
|1 - 2| = 1
|1 - 5| = 4
|2 - 5| = 3

The maximum of these differences is 4, so it saves the value 4 as the maximumDifference instance variable.
The locked stub code in the editor then prints the value stored as maximDifference, which is 4.
*/