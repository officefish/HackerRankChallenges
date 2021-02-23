/*
	Hackerrank::Challenges::InputOutput
	description: https://www.hackerrank.com/challenges/cpp-input-and-output
*/

#include "Challenges.h"

#include"HackerRankMiscellaneous.h"
using hr::split_string;


#include <bits/stdc++.h>

using std::cout;
using std::endl;
using std::cin;
using std::ofstream;



int InputOutputChallenge() {

	string nd_temp;
	getline(cin, nd_temp);

	vector<string> nd = split_string(nd_temp);
	int sum = 0;

	for (string value : nd) {
		sum += atoi(value.c_str());
	}

	cout << sum << endl;
	
	return 0;
}