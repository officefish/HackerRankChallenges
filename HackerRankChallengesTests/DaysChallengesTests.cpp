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