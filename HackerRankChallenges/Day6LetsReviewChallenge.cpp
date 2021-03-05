/*
Hackerrank::Challenges:Day 6: Let's Review
description: https://www.hackerrank.com/challenges/30-review-loop/problem
or below the code int this page
*/

#include "Challenges.h"

using std::vector;
using std::string;
using std::cin;
using std::cout;
using std::endl;

int day6LetsReviewChallenge() {
	
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {

        string str, evens, odds;
        cin >> str;

        for (int j = 0; j < str.size(); ++j) {
            j % 2 == 0 ? evens += str[j] : odds += str[j];
        }
        cout << evens << " " << odds << endl;
    }

    return 0;
}


/*
Objective
Today we will expand our knowledge of strings, combining it with what we have already learned about loops. 
Check out the Tutorial tab for learning materials and an instructional video.

Task
Given a string S, of length N that is indexed from 0 to N -1 , print its even-indexed and odd-indexed characters 
as 2 space-separated strings on a single line (see the Sample below for more detail).

Note: 0 is considered to be an even index.

Example

s = adbecf

Print abc def

Input Format

The first line contains an integer, T (the number of test cases).
Each line i of the T subsequent lines contain a string, S.

Constraints

1 <= T <= 10
2 <= length of S 10000

Output Format

For each String Sj (where 0 <= j <= T -1), print Sj's even-indexed characters, followed by a space, 
followed by Sj's odd-indexed characters.

Sample Input

2
Hacker
Rank

Sample Output

Hce akr
Rn ak
*/