/*
	Hackerrank::Challenges::ConditionalStatements
	https://www.hackerrank.com/challenges/c-tutorial-conditional-if-else/
*/

#include ".././Challenges.h"

using std::cout;
using std::cin;
using std::numeric_limits;
using std::streamsize;
using std::string;

int conditionalStatementsChallenge() {

    string numbers[10] = {"Greater than 9","one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    string output = numbers[0];

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    if (1 <= n && n <= 9)
        output = numbers[n];

    cout << output;

    return 0;

}