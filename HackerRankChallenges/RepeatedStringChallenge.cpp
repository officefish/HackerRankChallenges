/*
Hackerrank::Chalenges::RepeatedString
description: https://www.hackerrank.com/challenges/repeated-string/problem
*/

#include "Challenges.h"

#include "HackerRankMiscellaneous.h"
using hr::output_str;

#include <bits/stdc++.h>

using std::cout;
using std::endl;
using std::cin;
using std::ofstream;
using std::streamsize;

using std::max;
using std::numeric_limits;

int hrs::repeatedString(string s, long n) {
    const char symbol = 'a';
    char currentSymbol;
    string::size_type stringSize = s.size();
    
    long repeatedCounter = 0;

    for (std::string::size_type i = 0; i < stringSize; ++i) {
        currentSymbol = s[i];
        if (currentSymbol == symbol) {
            ++repeatedCounter;
        }
    }
    
    long relations = n / long(stringSize);
    repeatedCounter *= relations;
    size_t remainder = n % stringSize;

    if (remainder) {
        string remainderString = s.substr(0, remainder);

        for (std::string::size_type y = 0; y < remainder; ++y) {
            currentSymbol = remainderString[y];
            if (currentSymbol == symbol) {
                ++repeatedCounter;
            }
        }
    }
    
    return repeatedCounter;
}

int repeatedStringChallenge() {

    string s;
    getline(cin, s);

    long n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    long result = hrs::repeatedString(s, n);

    cout << "\n" << result << "\n";
   
    return 0;
}