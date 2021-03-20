#include ".././pch.h"
#include "./Challenges.h"


TEST(CPPChallengesTests, PrimeNumbersTest_01) {

	std::vector<int16_t> output = { 2, 3, 5, 7 };
	EXPECT_EQ(output, hrs::getPrimeNumbers(10));

	output = {  2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31,
				37, 41, 43, 47, 53, 59, 61, 67, 71,	73,
				79, 83, 89, 97, 101, 103, 107, 109,	113,
				127, 131, 137, 139, 149, 151, 157, 163,
				167, 173, 179, 181, 191, 193, 197, 199 };

	EXPECT_EQ(output, hrs::getPrimeNumbers(200));
	EXPECT_EQ(168, hrs::getPrimeNumbers(1000).size());

}

TEST(CPPChallengesTests, CompositeNumbersTest_01) {

	std::vector<int16_t> output = { 4, 6, 8, 9, 10 };

	EXPECT_EQ(output, hrs::getCompositeNumbers(10));
	EXPECT_EQ(153, hrs::getCompositeNumbers(200).size());
	EXPECT_EQ(831, hrs::getCompositeNumbers(1000).size());
}