/*
Hackerrank::Challenges::CPPStringsChallenge
description:https://www.hackerrank.com/challenges/c-tutorial-strings/
Solution Copyright (c) 2021 Officefish / Techies Team.
theory string: http://www.cplusplus.com/reference/string/string/string/
swap: https://en.cppreference.com/w/cpp/algorithm/swap
xor swap: https://en.wikipedia.org/wiki/XOR_swap_algorithm
*/

#include <string>
#include <algorithm>

#include ".././Challenges.h"
#include ".././HackerRankMiscellaneous.h"

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
	//XOR Swapping *(1)
	//if (str1[0] != str2[0]) {
	//	str1[0] ^= str2[0];
	//	str2[0] ^= str1[0];
	//	str1[0] ^= str2[0];
	//}
	// Itterator swapping
	// Error: Expression: string iterators incompatible (e.g. point to different string instances)
	/*
	std::string::iterator pStr1 = str1.begin();
	std::string::iterator pStr2 = str2.begin();
	if (pStr1 != pStr2)	{
		*pStr1 = *pStr1 + *pStr2;
		*pStr2 = *pStr1 - *pStr2;
		*pStr1 = *pStr1 + *pStr2;
	}
	*/
	cout << str1 << " " << str2 << endl;

	/* true way
	char* cstr1 = new char[str1.length() + 1];
	char* cstr2 = new char[str2.length() + 1];
	char* pcstr1 = cstr1; // which is equivalent pctr1 = &(cstr1[0]);
	char* pcstr2 = cstr2;

	if (pcstr1 != pcstr2) {
		*pcstr1 = *pcstr1 + *pcstr2;
		*pcstr2 = *pcstr1 - *pcstr2;
		*pcstr1 = *pcstr1 + *pcstr2;
	}
#include <stdlib.h>
#include <locale.h>
	printf("%s1 %s2", cstr1, cstr2);
	delete[] cstr1;
	delete[] cstr2;
	*/
	return 0;
}
/*
(1) On modern CPU architectures, the XOR technique can be slower than using a temporary variable to do swapping.
At least on recent x86 CPUs, both by AMD and Intel, moving between registers regularly incurs zero latency.
(This is called MOV-elimination.) Even if there is not any architectural register available to use,
the XCHG instruction will be at least as fast as the three XORs taken together. Another reason is that modern CPUs
strive to execute instructions in parallel via instruction pipelines. In the XOR technique, the inputs to each
operation depend on the results of the previous operation, so they must be executed in strictly sequential order,
negating any benefits of instruction-level parallelism
*/