#include "pch.h"





TEST(StringChallengesTests, AlternatingCharactersTest_01) {

	std::string strs[5] = { "AAAA", "BBBBB", "ABABABAB", "BABABA", "AAABBB" };
	
	EXPECT_EQ(3, hrs::alternatingCharacters(strs[0]));
	EXPECT_EQ(4, hrs::alternatingCharacters(strs[1]));
	EXPECT_EQ(0, hrs::alternatingCharacters(strs[2]));
	EXPECT_EQ(0, hrs::alternatingCharacters(strs[3]));
	EXPECT_EQ(4, hrs::alternatingCharacters(strs[4]));
}

TEST(StringChallengesTests, AlternatingCharactersTest_02) {

	std::string strs[3] = { "AAABBBAABB", "AABBAABB", "ABABABAA" };

	EXPECT_EQ(6, hrs::alternatingCharacters(strs[0]));
	EXPECT_EQ(4, hrs::alternatingCharacters(strs[1]));
	EXPECT_EQ(1, hrs::alternatingCharacters(strs[2]));
}

TEST(StringChallengesTests, AlternatingCharactersTest_03) {

	std::string str = { "ABBABBAA" };

	EXPECT_EQ(3, hrs::alternatingCharacters(str));
	
}



TEST(StringChallengesTests, StringAnagramsTest_01) {

	std::string s1 = { "cde" };
	std::string	s2 = { "abc" };

	EXPECT_EQ(4, hrs::makeAnagramFromStings(s1, s2));
}

TEST(StringChallengesTests, StringAnagramsTest_02) {

	std::string s1 = { "fcrxzwscanmligyxyvym" };
	std::string	s2 = { "jxwtrhvujlmrpdoqbisbwhmgpmeoke" };

	EXPECT_EQ(30, hrs::makeAnagramFromStings(s1, s2));
}

TEST(StringChallengesTests, StringAnagramsTest_03) {

	std::string s1 = { "showman" };
	std::string	s2 = { "woman" };

	EXPECT_EQ(2, hrs::makeAnagramFromStings(s1, s2));
}


const std::string YES = { "YES" };
const std::string NO = { "NO" };


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








