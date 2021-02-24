/*
    Hackerrank::Challenges::SherlockAnagrams
    description: https://www.hackerrank.com/challenges/sherlock-and-anagrams/
*/

#include "Challenges.h"

#include "HackerRankMiscellaneous.h"
using hr::output_str;

#include <bits/stdc++.h>

using std::cout;
using std::endl;
using std::cin;
using std::ofstream;
using std::max;
using std::numeric_limits;
using std::streamsize;

#include <unordered_map>
using std::unordered_map;
// https://en.cppreference.com/w/cpp/container/unordered_map


bool AreAnagram(string str1, string str2)
{
    int n1 = str1.length();
    int n2 = str2.length();
       
    if (n1 != n2)
        return false;

    sort(str1.begin(), str1.end());
    sort(str2.begin(), str2.end());

    for (int i = 0; i < n1; i++)
        if (str1[i] != str2[i])
            return false;

    return true;
}

int SubstrSum(string s) {

    int sum = 0;

    const size_t STR_SIZE = s.size();
    for (char& c : s) {
        sum += int(c);
    }

    return sum;
}

int FindAnagrams(unordered_map<int, vector<string>*> *substrs, string s) {
    
    bool areAnagram = false;
    int anagramCounter = 0;

    int substrSum = SubstrSum(s);
  
    vector<string>* pBufferSubs;
    
    unordered_map<int, vector<string>*>::const_iterator got = substrs->find(substrSum);

    if (got != substrs->end()) {
        pBufferSubs = got->second;
              
        areAnagram = false;
        for (auto& str : *pBufferSubs) {
            areAnagram = AreAnagram(s, str);
            if (areAnagram) {
                ++anagramCounter;
            }
        }
        
        pBufferSubs->push_back(s);
    }
    else {
        pBufferSubs = new vector<string>();
        pBufferSubs->push_back(s);
        substrs->insert({ {substrSum, pBufferSubs} });
    }
   
    return anagramCounter;

}

int SherlockAndAnagrams(string s) {
    
    /*
        Elegant
    */

    unordered_map<string, int> substrs;
    const size_t STR_SIZE = s.size();
    string currentSubstr;
    int pairs = 0;
    for (size_t i = 0; i < STR_SIZE; ++i) {
        for (size_t j = 1; j <= STR_SIZE - i; ++j) {

            currentSubstr = s.substr(i, j);
            sort(currentSubstr.begin(), currentSubstr.end());

            if (substrs[currentSubstr])
            {
                pairs += substrs[currentSubstr];
                ++substrs[currentSubstr];
            }
            else {
                substrs[currentSubstr] = 1;
            }
        }
    }


    /* Brutforce, calls 3 methods
    unordered_map<int, vector<string>*> substrs;
    const size_t STR_SIZE = s.size();
    string currentSubstr;
    int pairs = 0;

    for (size_t i = 0; i < STR_SIZE; ++i) {
        for (size_t j = 1; j <= STR_SIZE - i; ++j) {

            currentSubstr = s.substr(i, j);
            pairs += FindAnagrams(&substrs, currentSubstr);
                
        }
    }

    for (auto x : substrs) {
        delete x.second;
    }
    substrs.clear();
    */
    
    return pairs;

}


int SherlockAnagramsChallenge() {

    string hackerrank_output_str = output_str("HACKERRANK_OUTPUT_PATH");
    ofstream fout(hackerrank_output_str);

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);

        int result = SherlockAndAnagrams(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
