#include "pch.h"

using std::vector;
using std::string;

TEST(GreedyAlgorithmsTests, LuckyBalanceTest_01) {

	vector<vector<int32_t>> contests =
	{
		{ 5, 1 },
		{ 2, 1 },
		{ 1, 1 },
		{ 8, 1 },
		{10, 0 },
		{ 5, 0 }
	};
	int32_t luck = { 3 };
	
	EXPECT_EQ(29, hrs::luckBalance(luck, contests));
}
TEST(GreedyAlgorithmsTests, LuckyBalanceTest_02) {

	vector<vector<int32_t>> contests =
	{
		{ 8, 5 },
		{13, 1 },
		{10, 1 },
		{ 9, 1 },
		{ 8, 1 },
		{13, 1 },
		{12, 1 },
		{18, 1 },
		{13, 1 }
	};
	int32_t luck = { 5 };

	EXPECT_EQ(42, hrs::luckBalance(luck, contests));
}
TEST(GreedyAlgorithmsTests, LuckyBalanceTest_03) {

	vector<vector<int32_t>> contests =
	{
		{ 5, 1 },
		{ 4, 0 },
		{ 6, 1 },
		{ 2, 1 },
		{ 8, 0 }
	};
	int32_t luck = { 2 };

	EXPECT_EQ(21, hrs::luckBalance(luck, contests));
}
