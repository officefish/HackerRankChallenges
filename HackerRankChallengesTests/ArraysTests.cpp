#include "pch.h"



using std::vector;
using std::string;

TEST(ArraysChallengesTests, HourglassSumTest_01) {
		
	vector<vector<int>> matrix =
	{ 
		{1, 1, 1, 0, 0, 0},
		{0, 1, 0, 0, 0, 0},
		{1, 1, 1, 0, 0, 0},
		{0, 0, 2, 4, 4, 0},
		{0, 0, 0, 2, 0, 0},
		{0, 0, 1, 2, 4, 0}
	};

	EXPECT_EQ(19, hrs::hourglassSum(matrix));
}

TEST(ArraysChallengesTests, HourglassSumTest_02) {

	vector<vector<int>> matrix =
	{
		{1, 1, 1, 0, 0, 0},
		{0, 1, 0, 0, 0, 0},
		{1, 1, 1, 0, 0, 0},
		{0, 9, 2, -4, -4, 0},
		{0, 0, 0, -2, 0, 0},
		{0, 0, -1, -2, -4, 0}
	};

	EXPECT_EQ(13, hrs::hourglassSum(matrix));
}


TEST(ArraysChallengesTests, HourglassSumTest_03) {

	vector<vector<int>> matrix =
	{
		{-9,-9, -9, 1, 1, 1},
		{0, -9, 0, 4, 3, 2},
		{-9, -9, -9, 1, 2, 3},
		{0, 0, 8, 6, 6, 0},
		{0, 0, 0, -2, 0, 0},
		{0, 0, 1, 2, 4, 0}
	};

	EXPECT_EQ(28, hrs::hourglassSum(matrix));
}

TEST(ArraysChallengesTests, RotationLeftTest_01) {

	vector<int> input = { 1, 2, 3, 4, 5 };
	int countRotations = { 4 };
	
	vector<int> output = { 5, 1, 2, 3, 4 };

	EXPECT_EQ(output, hrs::rotationLeft(input, countRotations));
}

TEST(ArraysChallengesTests, RotationLeftTest_02) {

	vector<int> input = { 41, 73, 89, 7, 10, 1, 59, 58, 84, 77, 77, 97, 58, 1, 86, 58, 26, 10, 86, 51 };
	int countRotations = { 10 };

	vector<int> output = { 77, 97, 58, 1, 86, 58, 26, 10, 86, 51, 41, 73, 89, 7, 10, 1, 59, 58, 84, 77 };

	EXPECT_EQ(output, hrs::rotationLeft(input, countRotations));
}

TEST(ArraysChallengesTests, RotationLeftTest_03) {

	vector<int> input = { 33, 47, 70, 37, 8, 53, 13, 93, 71, 72, 51, 100, 60, 87, 97 };
	int countRotations = { 13 };

	vector<int> output = { 87, 97, 33, 47, 70, 37, 8, 53, 13, 93, 71, 72, 51, 100, 60 };

	EXPECT_EQ(output, hrs::rotationLeft(input, countRotations));
}

TEST(ArraysChallengesTests, NewYearChaosTest_01) {

	vector<int> input1 = { 2, 1, 5, 3, 4 };
	vector<int> input2 = { 2, 5, 1, 3, 4 };
	
	EXPECT_EQ(3, hrs::minimumBribes(input1));
	EXPECT_EQ(-1, hrs::minimumBribes(input2));
}

TEST(ArraysChallengesTests, NewYearChaosTest_02) {

	vector<int> input1 = { 5, 1, 2, 3, 7, 8, 6, 4 };
	vector<int> input2 = { 1, 2, 5, 3, 7, 8, 6, 4 };

	EXPECT_EQ(-1, hrs::minimumBribes(input1));
	EXPECT_EQ(7, hrs::minimumBribes(input2));
}

TEST(ArraysChallengesTests, NewYearChaosTest_03) {

	vector<int> input1 = { 1, 2, 5, 3, 4, 7, 8, 6 };
	
	EXPECT_EQ(4, hrs::minimumBribes(input1));
}


TEST(ArraysChallengesTests, MinimumSwapsTest_01) {

	vector<int> input = { 4, 3, 1, 2 };

	EXPECT_EQ(3, hrs::minimumSwaps(input));
}

TEST(ArraysChallengesTests, MinimumSwapsTest_02) {

	vector<int> input = { 2, 3, 4, 1, 5 };

	EXPECT_EQ(3, hrs::minimumSwaps(input));
}

TEST(ArraysChallengesTests, MinimumSwapsTest_03) {

	vector<int> input = { 1, 3, 5, 2, 4, 6, 7 };

	EXPECT_EQ(3, hrs::minimumSwaps(input));
}


TEST(ArraysChallengesTests, ArrayManipulationTest_01) {

	vector<vector<int>> matrix =
	{
		{1, 2, 100},
		{2, 5, 100},
		{3, 4, 100}
	};

	int count = { 5 };

	EXPECT_EQ(200, hrs::arrayManipulation(count, matrix));
}

TEST(ArraysChallengesTests, ArrayManipulationTest_02) {

	vector<vector<int>> matrix =
	{
		{1, 5, 3},
		{4, 8, 7},
		{6, 9, 1}
	};

	int count = { 10 };

	EXPECT_EQ(10, hrs::arrayManipulation(count, matrix));
}


TEST(ArraysChallengesTests, ArrayManipulationTest_03) {

	vector<vector<int>> matrix =
	{
		{2, 6, 8},
		{3, 5, 7},
		{1, 8, 1},
		{5, 9, 15}
	};

	int count = { 10 };

	EXPECT_EQ(31, hrs::arrayManipulation(count, matrix));
}




