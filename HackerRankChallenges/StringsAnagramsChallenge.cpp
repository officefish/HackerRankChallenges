/*
Hackerrank::Challenges:Strings: Making Anagrams
description: https://www.hackerrank.com/challenges/ctci-making-anagrams/
*/


#include "Challenges.h"

#include "HackerRankMiscellaneous.h"
using hr::output_str;
using hr::split_string;

#include <bits/stdc++.h>

using std::cout;
using std::endl;
using std::cin;
using std::ofstream;
using std::vector;
using std::sort;
using std::priority_queue;


#include <unordered_map>
using std::unordered_map;

struct CustomCompare
{
    bool operator()(const string& lhs, const string& rhs)
    {
        return lhs.length() < rhs.length();
    }
};

int intToAscii(int number) {
    return '0' + number;
}

int makeAnagram(string a, string b) {
	
    // Genious one! Frequency rocks!!
    
    
    auto count = 0;
    vector<int> freq(26, 0);
    for (auto c : a) { ++freq[c - 'a']; }
    for (auto c : b) { --freq[c - 'a']; }
    for (auto val : freq) { count += abs(val); }
    return count;
    
    /*

    int counter = { 0 };
    
    string shortStr, longStr, currentSubstr;
    size_t SHORT_SIZE, LONG_SIZE;

    if (a.size() < b.size()) {
        shortStr = a;
        longStr = b;
        SHORT_SIZE = a.size();
        LONG_SIZE = b.size();
    }
    else {
        shortStr = b;
        longStr = a;
        SHORT_SIZE = b.size();
        LONG_SIZE = a.size();
    }

    auto compare = [](string lhs, string rhs)
    {
        return lhs.length() > rhs.length();
    };
    
    unordered_map<string, bool> shortSubstrs;
    unordered_map<string, bool> longSubstrs;
    priority_queue<string, vector<string>, decltype(compare)> chunk(compare);

    for (size_t i = 0; i < SHORT_SIZE; ++i) {
        for (size_t j = 1; j <= SHORT_SIZE - i; ++j) {
            currentSubstr = shortStr.substr(i, j);
            sort(currentSubstr.begin(), currentSubstr.end());
            if (!shortSubstrs[currentSubstr]) {
                shortSubstrs[currentSubstr] = true;
            }
        }
    }

    
    
    for (size_t i = 0; i < LONG_SIZE; ++i) {
        for (size_t j = LONG_SIZE - i; j > 0; --j) {
            currentSubstr = longStr.substr(i, j);
            sort(currentSubstr.begin(), currentSubstr.end());
            if (!longSubstrs[currentSubstr]) {
                longSubstrs[currentSubstr] = true;
                chunk.push(currentSubstr);
            }
            
        }
    }
    

    while (!chunk.empty()) {
        currentSubstr = chunk.top();
        chunk.pop();
        if (longSubstrs[currentSubstr] && shortSubstrs[currentSubstr]) {
            
            //cout << currentSubstr << endl;
            //counter += longStr.length() - currentSubstr.length();
            //counter += shortStr.length() - currentSubstr.length();
            
            //return counter;
        }
    }
    

    return counter;
    */
    

            
    
}


int stringsAnagramsChallenge() {

    string hackerrank_output_str = output_str("HACKERRANK_OUTPUT_PATH");
    ofstream fout(hackerrank_output_str);

    string a;
    getline(cin, a);

    string b;
    getline(cin, b);

    int res = makeAnagram(a, b);

    fout << res << "\n";
    cout << res << endl;

    fout.close();

    return 0;
	return 0;
}