#include "pch.h"



using std::vector;
using std::string;

TEST(SortingChallengesTests, BubbleSortTest_01) {

	vector<int> input = { 1, 2, 3 };

	EXPECT_EQ(0, hrs::countSwaps(input));
}
TEST(SortingChallengesTests, BubbleSortTest_02) {

	vector<int> input = { 3, 2, 1 };

	EXPECT_EQ(3, hrs::countSwaps(input));
}
TEST(SortingChallengesTests, BubbleSortTest_03) {

	vector<int> input = { 4, 2, 3, 1 };

	EXPECT_EQ(5, hrs::countSwaps(input));
}

TEST(SortingChallengesTests, MergeSortTest_01) {

	vector<int> input1 = { 1, 1, 1, 2, 2 };
	vector<int> input2 = { 2, 1, 3, 1, 2 };

	EXPECT_EQ(0, hrs::countInversions(input1));
	EXPECT_EQ(4, hrs::countInversions(input2));
}
TEST(SortingChallengesTests, MergeSortTest_02) {

	vector<int> input1 = { 1, 5, 3, 7 };
	vector<int> input2 = { 7, 5, 3, 1 };

	EXPECT_EQ(1, hrs::countInversions(input1));
	EXPECT_EQ(6, hrs::countInversions(input2));
}
TEST(SortingChallengesTests, MergeSortTest_03) {

	vector<int> input1 = { 1, 3, 5, 7 };
	vector<int> input2 = { 3, 2, 1 };

	EXPECT_EQ(0, hrs::countInversions(input1));
	EXPECT_EQ(3, hrs::countInversions(input2));
}

TEST(SortingChallengesTests, MarkAndToysTest_01) {

	vector<int> prices = { 1, 12, 5, 111, 200, 1000, 10 };
	int budget = { 50 };

	EXPECT_EQ(4, hrs::maximumToys(prices, budget));
}
TEST(SortingChallengesTests, MarkAndToysTest_02) {

	vector<int> prices = { 1, 2, 3, 4 };
	int budget = { 7 };

	EXPECT_EQ(3, hrs::maximumToys(prices, budget));
}
TEST(SortingChallengesTests, MarkAndToysTest_03) {

	vector<int> prices = { 3, 7, 2, 9, 4 };
	int budget = { 15 };

	EXPECT_EQ(3, hrs::maximumToys(prices, budget));
}

TEST(SortingChallengesTests, FraudulentNotificationsTest_01) {

	vector<int> expenditure = { 2, 3, 4, 2, 3, 6, 8, 4, 5 };
	int median = { 5 };

	EXPECT_EQ(2, hrs::activityNotifications(expenditure, median));
}
TEST(SortingChallengesTests, FraudulentNotificationsTest_02) {

	vector<int> expenditure = { 1, 2, 3, 4, 4 };
	int median = { 4 };

	EXPECT_EQ(0, hrs::activityNotifications(expenditure, median));
}
TEST(SortingChallengesTests, FraudulentNotificationsTest_03) {

	vector<int> expenditure = { 10, 20, 30, 40, 50 };
	int median = { 3 };

	EXPECT_EQ(1, hrs::activityNotifications(expenditure, median));
}