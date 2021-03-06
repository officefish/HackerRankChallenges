#pragma once
#include <bits/stdc++.h>

/* 30 days coding Challenge */
int day1IfStatementsChallenge();// day1
int day2DataTypesChallenge();	// day2
int day3OperatorsChallenge();	// day3
int day4ClassVsInstance();		// day4
int day5LoopsChallenge();		// day5
int day6LetsReviewChallenge();	// day6
int day7ArraysChallange();		// day7


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

//HashTables
int ransomNoteChallenge();
int twoStringsChallenge();
int sherlockAnagramsChallenge();
int countRatioTripletsChallenge();
int frequencyQueriesChallenge();

//Sorting
int bubbleSortChallenge();
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

// hackerrank solutions
namespace hrs {

	using std::string;
	using std::vector;

	// Warm Up Challenges
	int socksMerchant(int, vector<int>);
	int countingValleys(int, string);
	int jumpingOnClouds(vector<int>);
	long repeatedString(string, long);

	// Arrays
	int hourglassSum(vector<vector<int>>);
	vector<int> rotationLeft(vector<int>, int);
	int minimumBribes(vector<int>);
	int minimumSwaps(vector<int>);
	long arrayManipulation(int, vector<vector<int>>);
	
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

	//DayChallenges
	vector<int> reverseRange(char, const vector<int>& input);
	vector<int16_t> getCompositeNumbers(int16_t n);
	vector<int16_t> getPrimeNumbers(int16_t n);
}









