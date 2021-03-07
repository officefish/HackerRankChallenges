#include "pch.h"

using std::vector;
using std::string;

TEST(DaysChallengesTests, Day7ArraysTest_01) {

	vector<int> input { 1, 2, 3, 4, 5, 6, 7 };
	vector<int> output{ 7, 6, 5, 4, 3, 2, 1 };

	EXPECT_EQ(output, hrs::reverseRange(1, input));
	EXPECT_EQ(output, hrs::reverseRange(2, input));
	EXPECT_EQ(output, hrs::reverseRange(3, input));
	EXPECT_EQ(output, hrs::reverseRange(4, input));
}

TEST(DaysChallengesTests, Day9RecursionTest_01) {

	int32_t input1 = { 5 }, input2 = { 7 }, input3 = { 10 };
	int32_t output1 = { 120 }, output2 = { 5040 }, output3 = { 3628800 };

	EXPECT_EQ(output1, hrs::factorial(input1));
	EXPECT_EQ(output2, hrs::factorial(input2));
	EXPECT_EQ(output3, hrs::factorial(input3));
}