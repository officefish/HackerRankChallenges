/*
Hackerrank::Challenges::CPPStringsChallenge
description:https://www.hackerrank.com/challenges/c-tutorial-strings/
Solution Copyright (c) 2021 Officefish / Techies Team.
theory string: http://www.cplusplus.com/reference/string/string/string/
swap: https://en.cppreference.com/w/cpp/algorithm/swap
*/

#include <string>
#include <algorithm>

#include "./Challenges.h"
#include "./HackerRankMiscellaneous.h"

int stringsSTLChallenge() {
	using std::cout;
	using std::endl;
	using std::cin;
	using std::swap;
	using std::string;

	string str1;
	getline(cin, str1);
	string str2;
	getline(cin, str2);

	cout << str1.size() << " " << str2.size() << endl;
	cout << str1 + str2 << endl;
	std::swap(str1[0], str2[0]);
	cout << str1 << " " << str2 << endl;
	return 0;
}