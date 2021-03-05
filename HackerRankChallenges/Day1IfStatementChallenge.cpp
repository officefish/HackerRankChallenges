/*
Hackerrank::Challenges::CppConditionalStatement
https://www.hackerrank.com/challenges/30-conditional-statements/problem
*/

#include <string>
#include <limits>

#include "./Challenges.h"

using std::cout;
using std::cin;
using std::endl;
using std::numeric_limits;
using std::streamsize;
using std::string;
using std::ios_base;

int day1IfStatementsChallenge() {

	ios_base::sync_with_stdio(0);

	const string WEIRD = { "Weird" };
	const string NOT_WEIRD = { "Not Weird" };

	int N;
	cin >> N;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	if (N % 2 != 0 || (N > 5 && N <= 20)) {
		cout << WEIRD;
	} else {
		cout << NOT_WEIRD;
	}
	
	return 0;
}