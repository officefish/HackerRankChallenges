/*
Hackerrank::Challenges::Day2DataTypes
description: see below the code
*/
#include <string>
#include <limits>

#include "./Challenges.h"

int day2DataTypesChallenge() {
	using std::cout;
	using std::endl;
	using std::cin;
	using std::string;
	using std::numeric_limits;
	using std::streamsize;
	using std::fixed;
	using std::setprecision;

	int i1{ 4 };
	uint64_t d1 = { 4 };
	string s1 { "HackerRank " };
	int i2; uint64_t d2; string s2;
	
	cin >> i2 >> d2;
	//(1)
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	getline(cin, s2);
	
	cout << i1 + i2 << endl;
	cout << fixed << setprecision(1) << d1 + d2 << endl;
	cout << s1 + s2 << endl;
	return 0;
}

/*
	(1)	People starting to learn C++ might suffer if they aren't familiar with cin >> and getline() and what happens 
		if you use both of them together. Using cin leaves an end of line character which is then read by your getline(); 
		It is best not to mix different types of input.

		The solution one could use to overcome this problem is to use a different input method. On the other hand, 
		it is always nice to get familiar with problems one might come across while coding, so take a look. 
		It is possible to overcome this problem while keeping all of your code and just adding a single line.

		Here is an excerpt from the input code:

		cin >> doubleNumber;
		cin.ignore();  //ignores an end of line character 
		getline(cin, stringName);
		
		This will read you string correctly, it will also read the whole line. It will just ignore a character and continue from that.

		I could be wrong, I'm still a complete novice myself but this is the way I understand it. Cheers. 

*/

/*
	Objective
	Today, we're discussing data types. Check out the Tutorial tab for learning materials and an instructional video!

	Task
	Complete the code in the editor below. The variables i, d, and s are already declared and initialized for you. You must:

	1. Declare 3 variables: one of type int, one of type double, and one of type String.
	2. Read 3 lines of input from stdin (according to the sequence given in the Input Format section below) and initialize your 3 variables.
	3.Use the  operator to perform the following operations:
		1. Print the sum of i plus your int variable on a new line.
		2. Print the sum of d plus your double variable to a scale of one decimal place on a new line.
		3. Concatenate  with the string you read as input and print the result on a new line.

	Note: If you are using a language that doesn't support using  for string concatenation (e.g.: C), 
	you can just print one variable immediately following the other on the same line. 
	The string provided in your editor must be printed first, immediately followed by the string you read as input.

	Input Format

	The first line contains an integer that you must sum with i.
	The second line contains a double that you must sum with d.
	The third line contains a string that you must concatenate with s.

	Output Format

	Print the sum of both integers on the first line, the sum of both doubles (scaled to 1 decimal place) on the second line, 
	and then the two concatenated strings on the third line.

	Sample Input

	12
	4.0
	is the best place to learn and practice coding!

	Sample Output

	16
	8.0
	HackerRank is the best place to learn and practice coding!

	Explanation

	When we sum the integers 4 and 12, we get the integer 16.
	When we sum the floating-point numbers 4.0 and 4.0, we get 8.0.
	When we concatenate HackerRank with is the best place to learn and practice coding!, 
	we get HackerRank is the best place to learn and practice coding!.

	You will not pass this challenge if you attempt to assign the Sample Case values to your variables instead of following 
	the instructions above and reading input from stdin.
*/