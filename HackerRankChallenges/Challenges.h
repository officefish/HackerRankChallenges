#pragma once
#include <vector>
#include <string>
#include <iostream>

/* 30 days coding Challenge */
int day1IfStatementsChallenge();// day1
int day2DataTypesChallenge();	// day2
int day3OperatorsChallenge();	// day3
int day4ClassVsInstance();		// day4
int day5LoopsChallenge();		// day5
int day6LetsReviewChallenge();	// day6
int day7ArraysChallange();		// day7
int day8MapsChallenge();		// day8
int day9RecursionChallenge();	// day9
//int day10BinNumsChallenge();	// day10
//int day112DArrsChallenge();		// day11
int day12InheritanceChallenge();// day12
int day13AbstrClassChallenge(); // day13
int day14ScopeChallenge();		// day14
int day15LinkedListChallenge(); // day15
int day16ExceptionsChallenge();	// day16
int day17MoreExceptsChallenge();// day17
int day18QuAndStChallenge();	// day18
int day19InterfaceChallenge();	// day19
int day20BubbleSortChallenge(); // day20
int day21GenericChallenge(); // day21

/* Interview Preparation kit */

//Warm up Challenges
int socksMerchantChallenge();
int countingValleysChallenge();
int jumpingOnCloudsChallenge();
int repeatedStringChallenge();

//Arrays
int hourglassChallenge();
int leftRotationChallenge();
int newYearChaosChallenge();
int minimumSwap2Challenge();
int arrayManipulationChallenge();
int reverseArrayChallenge_c();
int reverseArrayChallenge();
int reverseArraySTDChallenge();
int sparseArraysChallenge();

//HashTables
int ransomNoteChallenge();
int twoStringsChallenge();
int sherlockAnagramsChallenge();
int countRatioTripletsChallenge();
int frequencyQueriesChallenge();

//Sorting
//int bubbleSortChallenge();
int markAndToysChallenge();
int mergeSortChallenge();
int comparatorSortChallenge();
int fraudNotChallenge();

//Strings
int stringsAnagramsChallenge();
int alternatingCharactersChallenge();
int sherlockValidStrChallenge();
int specialStrAgainChallenge();
int commonChildChallenge();

//Greedy Algorithms
int minAbsDifferenceChallenge();
int luckBalanceChallenge();

//Lists
// singly
int insertNodeAtHeadChallenge();
int instertNodeAtTailChallenge();
int insertNodeAtPositionChallenge();
int deleteNodeChallenge();
int reverseListChallenge();
int getNodeDataChallenge();
int printListChallenge();
int printReverseChallenge();
int compareListsChallenge();
int sortListChallenge();
int mergeSinglySortedChallenge();
int findMergePointChallenge();
int removeDuplicatesInSortedChallenge();
int listHasCycleChallenge();
int deleteNthNodeChallenge();
int countCommonNodesChallenge();
int splitMiddleChallenge();
int splitEvenOddChallenge();
int reorderChallenge();
// doubly
int sortedInsertChallenge();

/* C++ */
int inputOutputChallenge();
int dataTypesChallenge();
int conditionalStatementsChallenge();
int forLoopChallenge();
int functionsChallenge();
int pointerChallenge();
int vectorSortChallenge();
int arrayIntroductionChallenge();
int variableSizedArraysChallenge();
int dequeSTLChallenge();
int rectangleAreaChallenge();
int stringSteamChallenge();
int compositeNumbersChallenge();
int stringsSTLChallenge();
int structChallenge();
int classChallenge();
int classAndObjectChallenge();
int boxItChallenge();
int inheritanceIntroChallenge();
int multiInheritanceChallenge();
int overloadOperatorChallenge();
int lowerBoundChallenge();
int setChallenge();
int vectorEraseChallenge();
int mapChallenge();
int prettyPrintChallenge();
int classTemplateChallenge();
//int preprocessorChallenge();

/*C++ Standard Algorithm Challenge */
int allAnyNoneOfChallenge();

// hackerrank solutions
namespace hrs {

	using std::string;
	using std::vector;

	// Warm Up Challenges
	int socksMerchant(int, vector<int>);
	int countingValleys(int, string);
	int jumpingOnClouds(vector<int>);
	long repeatedString(string, long);
	std::pair<size_t, size_t> minMaxSum(std::vector<int32_t> row);
	size_t accumulate(std::vector<int32_t> row);
	std::pair<int8_t, int8_t>compareTheTriplets(vector<int16_t> a, vector<int16_t> b);
	int16_t diagonalDifference(vector<vector<int8_t>> arr);
	std::string plusMinus(std::vector<int16_t> arr);
	std::string staircase(int8_t n);
	int64_t birthdayCakeCandles(std::vector<int32_t> candles);
	std::string timeConversion(std::string s, std::string iPattern, std::string oPattern);

	// Arrays
	int hourglassSum(vector<vector<int>>);
	vector<int> rotationLeft(vector<int>, int);
	int minimumBribes(vector<int>);
	int minimumSwaps(vector<int>);
	long arrayManipulation(int, vector<vector<int>>);
	void reverseArray(vector<int32_t>*);
	void reverseArray_c(int*, int length);
	void reverseArray_std(vector<int32_t>*);
	vector<int> matchingStrings(vector<string> strings, vector<string> queries);

	//HashTables
	bool checkMagazine(vector<string>, vector<string>);
	string twoStrings(string, string);
	int sherlockAndAnagrams(string);
	long countTriplets(vector<long>, long);
	vector<int> frequencyQuery(vector<vector<int>>);

	//Sorting
	size_t countSwaps(vector<int>);
	int maximumToys(vector<int>, int);
	long countInversions(vector<int>&);
	int activityNotifications(vector<int>, int d);

	// Strings
	int makeAnagramFromStings(string a, string b);
	int alternatingCharacters(string s);
	string isValidSherlockString(string);
	int64_t substrCount(size_t, string);
	int commonChild(string s1, string s2);

	//Greedy Algs
	int minAbsDifference(vector<int>);
	int minAbsDifference_uSTD(vector<int>);
	int32_t luckBalance(int32_t, vector<vector<int32_t>>);


	//DayChallenges
	vector<int> reverseRange(char, const vector<int>& input);
	vector<int16_t> getCompositeNumbers(int16_t n);
	vector<int16_t> getPrimeNumbers(int16_t n);
	int32_t factorial(int32_t);

	//CPP Algorithm Library
	bool isEven(int32_t input);
	bool isOdd(int32_t input);

}








