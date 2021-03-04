#include "pch.h"


std::string YES = { "YES" };
std::string NO = { "NO" };


TEST(StringChallengesTests, SherlockValidStringTest_01) {
	std::string s = { "aabbcd" };
	EXPECT_TRUE(NO == hrs::isValidSherlockString(s));
}

TEST(StringChallengesTests, SherlockValidStringTest_02) {
	std::string s = { "aabbccddeefghi" };
	EXPECT_TRUE(NO == hrs::isValidSherlockString(s));

}

TEST(StringChallengesTests, SherlockValidStringTest_03) {
	std::string s = { "abcdefghhgfedecba" };
	EXPECT_EQ(YES, hrs::isValidSherlockString(s));
}

TEST(StringChallengesTests, StringAnagramsTest_01) {
	
	std::string s1 = { "abcdefghhgfedecba" };
	std::string	s2 = { "sdsdsd" };

	EXPECT_EQ(2, hrs::makeAnagramFromStings(s1,s2));
}





