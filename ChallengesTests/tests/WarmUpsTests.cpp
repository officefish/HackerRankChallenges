#include ".././pch.h"
#include "./Challenges.h"

using std::vector;
using std::string;

TEST(WarnUpsChallengesTests, SocksMerchantTest_01) {

	vector<int> values = { 10, 20, 20, 10, 10, 30, 50, 10, 20 };

	EXPECT_EQ(3, hrs::socksMerchant(int(values.size()), values));
}


TEST(WarnUpsChallengesTests, SocksMerchantTest_02) {

	vector<int> values = { 1, 1, 3, 1, 2, 1, 3, 3, 3, 3 };

	EXPECT_EQ(4, hrs::socksMerchant(int(values.size()), values));
}


TEST(WarnUpsChallengesTests, CountingValleysTest_01) {

	string path = { "UDDDUDUU" };

	EXPECT_EQ(1, hrs::countingValleys(int(path.length()), path));
}

TEST(WarnUpsChallengesTests, CountingValleysTest_02) {

	string path = { "DDUUDDUDUUUD" };

	EXPECT_EQ(2, hrs::countingValleys(int(path.length()), path));
}



TEST(WarnUpsChallengesTests, JumpingOnCloudsTest_01) {

	vector<int> clouds = { 0, 0, 1, 0, 0, 1, 0 };

	EXPECT_EQ(4, hrs::jumpingOnClouds(clouds));
}

TEST(WarnUpsChallengesTests, JumpingOnCloudsTest_02) {

	vector<int> clouds = { 0, 0, 0, 1, 0, 0 };

	EXPECT_EQ(3, hrs::jumpingOnClouds(clouds));
}


TEST(WarnUpsChallengesTests, RepeatedStringTest_01) {

	string repeated = { "aba" };
	long segment = { 10 };

	EXPECT_EQ(7, hrs::repeatedString(repeated, segment));
}

TEST(WarnUpsChallengesTests, RepeatedStringTest_02) {

	string repeated = { "a" };
	long segment = { long(1000000000000) };

	EXPECT_EQ(segment, hrs::repeatedString(repeated, segment));
}


