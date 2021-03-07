/*
Hackerrank::Challenges::Day9:Recursion
description:https://www.hackerrank.com/challenges/30-recursion/
or below this page
Solution Copyright (c) 2021 Officefish / Techies Team.
*/

#include <string>
#include <map>
#include <stdexcept>
#include <unordered_map>
#include <variant>

#include "./Challenges.h"

// Complete the factorial function below.
int32_t hrs::factorial(int32_t n) {
    if (!n) return 1;
    return n * factorial(n - 1);
}

int day9RecursionChallenge()
{
    using std::cout;
    using std::endl;
    using std::cin;
    using std::numeric_limits;
    using std::streamsize;

    int32_t n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    int32_t result = hrs::factorial(n);
    cout << result;
    return 0;
}


/*
Objective
Today, we are learning about an algorithmic concept called recursion. 
Check out the Tutorial tab for learning materials and an instructional video.
https://www.hackerrank.com/challenges/30-recursion/tutorial

Recursive Method for Calculating Factorial

factorial(N) {
	doSomething;
	if (N >= 1) {
		return factorial(N-1);
	} else {
		return output;
	}
} 

Function Description
Complete the factorial function in the editor below. Be sure to use recursion.

factorial has the following paramter:
int n: an integer

Returns
int: the factorial of n

Note: If you fail to use recursion or fail to name your recursive function factorial
or Factorial, you will get a score of 0.

Input Format
A single integer, n (the argument to pass to factorial).

Constraints
2 <= n <= 12

Your submission must contain a recursive function named factorial.

Sample Input
3

Sample Output
6

Explanation
Consider the following steps. After the recursive calls from step 1 to 3, 
results are accumulated from step 3 to 1.
factorial(3) = 3 * factorial(2) = 3 * 2 = 6;
factorial(3) = 2 * factorial(1) = 2 * 1 = 2;
factorial(1) = 1;
*/