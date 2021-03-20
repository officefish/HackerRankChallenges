/*
MIPT::Challenges::CompositeNumbersSearch
description: below
Solution Copyright (c) 2021 Officefish / Techies Team.
theory:https://en.wikipedia.org/wiki/Composite_number
*/

#include <vector>
#include ".././Challenges.h"

std::vector<bool> getPrineCompositeMatrix(int16_t n) {
	int32_t len = static_cast<int32_t>(n) + 1;
	std::vector<bool> sieve(len, true);
	int16_t x = 2;

	while (x * x < len) {
		if (sieve[x]) {
			for (int32_t y = x * x; y <= n; y += x) {
				sieve[y] = false;
			}
		}
		x += 1;
	}
	return sieve;
}

std::vector<int16_t> hrs::getPrimeNumbers(int16_t n) {
	std::vector<int16_t> output;
	if (n < 2) return output;
	vector<bool> matrix = getPrineCompositeMatrix(n);

	for (size_t x = 2, len = matrix.size(); x < len; ++x) {
		if (matrix[x]) output.push_back(uint16_t(x));
	}
	return output;
}

std::vector<int16_t> hrs::getCompositeNumbers(int16_t n) {
	std::vector<int16_t> output;
	if (n < 2) return output;
	vector<bool> matrix = getPrineCompositeMatrix(n);

	for (size_t x = 0, len = matrix.size(); x < len; ++x) {
		if (!matrix[x]) output.push_back(uint16_t(x));
	}
	return output;
}

int compositeNumbersChallenge() {
	using std::cout;
	using std::endl;
	using std::cin;
	using std::streamsize;
	using std::numeric_limits;
	int16_t n;
	cin >> n;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	std::vector<int16_t> output = hrs::getCompositeNumbers(n);
	cout << output.size() << endl;
	for (int16_t v : output) {
		cout << v << " ";
	}
	return 0;
}