/*
	Hackerrank::Challenges::ForLoop
	https://www.hackerrank.com/challenges/c-tutorial-for-loop
*/

#include "Challenges.h"

#include<bits/stdc++.h>
using std::cout;
using std::cin;
using std::endl;
using std::numeric_limits;
using std::streamsize;
using std::string;



int forLoopChallenge() {
	
    string numbers[12] = { "I am Moon Hacker","one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "even", "odd"};
    string output;
    int n1, n2;

    cin >> n1 >> n2;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
       

    for (int i = n1; i <= n2; ++i) {
        output = (i <= 9) ? numbers[i] : numbers[10 + (i % 2)];
        cout << output << endl;
    }
         
    return 0;
}