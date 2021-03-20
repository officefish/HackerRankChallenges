#include ".././pch.h"
#include "./Challenges.h"

using std::vector;
using std::string;

TEST(HashTablesChallengesTests, RansomNoteTest_01) {

	vector<string> str1 = { "give", "me", "one", "grand", "today", "night" };
	vector<string> str2 = { "give", "one", "grand", "today" };

	EXPECT_EQ(true, hrs::checkMagazine(str1, str2));
}

TEST(HashTablesChallengesTests, RansomNoteTest_02) {

	vector<string> str1 = { "two", "times", "three", "is", "not", "four" };
	vector<string> str2 = { "two", "times", "two", "is", "four" };

	EXPECT_EQ(false, hrs::checkMagazine(str1, str2));
}
TEST(HashTablesChallengesTests, RansomNoteTest_03) {

	vector<string> str1 = { "ive", "got", "a", "lovely", "bunch", "of", "coconuts" };
	vector<string> str2 = { "ive", "got", "some", "coconuts" };

	EXPECT_EQ(false, hrs::checkMagazine(str1, str2));
}

TEST(HashTablesChallengesTests, TwoStringsTest_01) {

	string str1 = { "hello" };
	string str2 = { "world" };

	EXPECT_EQ("YES", hrs::twoStrings(str1, str2));

	str1 = { "hi" };
	EXPECT_EQ("NO", hrs::twoStrings(str1, str2));
}
TEST(HashTablesChallengesTests, TwoStringsTest_02) {

	string str1 = { "wouldyoulikefries" };
	string str2 = { "abcabcabcabcabcabc" };

	EXPECT_EQ("NO", hrs::twoStrings(str1, str2));

	str1 = { "hackerrankcommunity" };
	str2 = { "cdecdecdecde" };

	EXPECT_EQ("YES", hrs::twoStrings(str1, str2));

	str1 = { "jackandjill" };
	str2 = { "wentupthehill" };

	EXPECT_EQ("YES", hrs::twoStrings(str1, str2));

	str1 = { "writetoyourparents" };
	str2 = { "fghmqzldbc" };

	EXPECT_EQ("NO", hrs::twoStrings(str1, str2));
}
TEST(HashTablesChallengesTests, TwoStringsTest_03) {

	string str1 = { "aardvark" };
	string str2 = { "apple" };

	EXPECT_EQ("YES", hrs::twoStrings(str1, str2));

	str1 = { "beetroot" };
	str2 = { "sandals" };

	EXPECT_EQ("NO", hrs::twoStrings(str1, str2));
}

TEST(HashTablesChallengesTests, SherlockAndAnagramsTest_01) {

	string str1 = { "abba" };
	string str2 = { "abcd" };

	EXPECT_EQ(4, hrs::sherlockAndAnagrams(str1));
	EXPECT_EQ(0, hrs::sherlockAndAnagrams(str2));
}
TEST(HashTablesChallengesTests, SherlockAndAnagramsTest_02) {

	string str1 = { "ifailuhkqq" };
	string str2 = { "kkkk" };

	EXPECT_EQ(3, hrs::sherlockAndAnagrams(str1));
	EXPECT_EQ(10, hrs::sherlockAndAnagrams(str2));
}
TEST(HashTablesChallengesTests, SherlockAndAnagramsTest_03) {

	string str = { "cdcd" };

	EXPECT_EQ(5, hrs::sherlockAndAnagrams(str));
}


TEST(HashTablesChallengesTests, CountRatioTripletsTest_01) {

	vector<long> input = { 1, 2, 2, 4 };
	long ratio = { 2 };

	EXPECT_EQ(2, hrs::countTriplets(input, ratio));
}
TEST(HashTablesChallengesTests, CountRatioTripletsTest_02) {

	vector<long> input = { 1, 3, 9, 9, 27, 81 };
	long ratio = { 3 };

	EXPECT_EQ(6, hrs::countTriplets(input, ratio));
}
TEST(HashTablesChallengesTests, CountRatioTripletsTest_03) {

	vector<long> input = { 1, 5, 5, 25, 125 };
	long ratio = { 5 };

	EXPECT_EQ(4, hrs::countTriplets(input, ratio));
}

TEST(HashTablesChallengesTests, FrequencyQueriesTest_01) {

	vector<vector<int>> queries =
	{
		{ 1, 5 },
		{ 1, 6 },
		{ 3, 2 },
		{ 1, 10 },
		{ 1, 10 },
		{ 1, 6 },
		{ 2, 5 },
		{ 3, 2 }
	};

	vector<int> output = { 0, 1 };

	EXPECT_EQ(output, hrs::frequencyQuery(queries));
}

TEST(HashTablesChallengesTests, FrequencyQueriesTest_02) {

	vector<vector<int>> queries =
	{
		{ 3, 4 },
		{ 2, 1003 },
		{ 1, 16 },
		{ 3, 1 }

	};

	vector<int> output = { 0, 1 };

	EXPECT_EQ(output, hrs::frequencyQuery(queries));
}

TEST(HashTablesChallengesTests, FrequencyQueriesTest_03) {

	vector<vector<int>> queries =
	{
		{ 1, 3 },
		{ 2, 3 },
		{ 3, 2 },
		{ 1, 4 },
		{ 1, 5 },
		{ 1, 5 },
		{ 1, 4 },
		{ 3, 2 },
		{ 2, 4 },
		{ 3, 2 }
	};

	vector<int> output = { 0, 1, 1 };

	EXPECT_EQ(output, hrs::frequencyQuery(queries));
}