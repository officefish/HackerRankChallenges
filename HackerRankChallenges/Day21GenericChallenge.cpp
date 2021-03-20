/*
Hackerrank::Challenges::BubbleSort
description: https://www.hackerrank.com/challenges/30-generics/problem
Solution Copyright(c) 2021 Officefish / Techies Team.
https://www.geeksforgeeks.org/generics-in-c/
*/
#include "./Challenges.h"
#include <vector>
#include <string>

namespace {
	template<typename T> void printArray(std::vector<T> a) {
		for (T i : a)
			std::cout << i << std::endl;
	}
}
int day21GenericChallenge() {
	using std::cin, std::cout, std::endl;
	using std::vector, std::string;
	int n;
	cin >> n;
	vector<int> int_vector(n);
	for (int i = 0; i < n; i++) {
		int value;
		cin >> value;
		int_vector[i] = value;
	}
	cin >> n;
	vector<string> string_vector(n);
	for (int i = 0; i < n; i++) {
		string value;
		cin >> value;
		string_vector[i] = value;
	}
	printArray<int>(int_vector);
	printArray<string>(string_vector);
	return 0;
}

