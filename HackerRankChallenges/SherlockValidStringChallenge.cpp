/*
Hackerrank::Challenges:Strings:SherlockAndTheValidString
description: https://www.hackerrank.com/challenges/sherlock-and-valid-string/
*/


#include "Challenges.h"

#include "HackerRankMiscellaneous.h"
using hr::output_str;
using hr::split_string;

using std::cout;
using std::endl;
using std::cin;
using std::vector;
using std::ofstream;
using std::max_element;
using std::string;

#include <unordered_map>
using std::unordered_map;

string hrs::isValidSherlockString(string s) {

    const string YES = { "YES" };
    const string NO = { "NO" };

    if (!s.size()) return NO;
    
    string status;
  
    vector<int> frequency(26, 0);
    unordered_map<int, int> frequencyGroup;
    typedef  unordered_map<int, int>::const_iterator frequencyGroupIterator;

    int current;

    for (auto c : s) { ++frequency[c - 'a']; }

    for (size_t i = 0; i < frequency.size(); ++i) {
        current = frequency[i];
        if (current != 0) {
            !frequencyGroup[current] ? frequencyGroup[current] = 1 : ++frequencyGroup[current];
        }
    }

    if (frequencyGroup.size() == 1) {
        status = YES;
    }
    else if (frequencyGroup.size() >= 3) {
        status = NO;
    }
    else {

        int p1F, p1S, p2F, p2S; // pair1, pair2 : first, second  
        
        p1S = frequencyGroup.begin()->first;
        p1F = frequencyGroup.begin()->second;
        
        frequencyGroupIterator pIterTwo = std::next(frequencyGroup.begin(), 1);
        p2F = pIterTwo->first;
        p2S = pIterTwo->second;
        
        //cout << "pair 1. First: " << p1F << ", Second: " << p1S << endl;
        //cout << "pair 2. First: " << p2F << ", Second: " << p2S << endl;

        status = ( (p1F == 1 || p1F == 3) && (p1S == 1 || p1S == 3)) ||
                 ( (p2F == 1 || p2F == 3) && (p2S == 1 || p2S == 3)) ? YES : NO;
            
    }

    return status;

}

int sherlockValidStrChallenge() {


    //string hackerrank_output_str = output_str("HACKERRANK_OUTPUT_PATH");
    //ofstream fout(hackerrank_output_str);

    string s;
    getline(cin, s);

    string result = hrs::isValidSherlockString(s);

    cout << result << "\n";
    //fout << result << "\n";

    //fout.close();

    return 0;
}

/* Solution with find maximum repeating
string isValid(string s)
{
  map<char, int> mp;
  map<int, int> freq;  //frequency of same sized strings
  for(char c : s)
    mp[c]++;
  for(auto it=mp.begin(); it!=mp.end(); it++)
    freq[it->second]++;  //count of frequency of each group
  int bal=0, maxf=0;
  for(auto it = freq.begin(); it != freq.end(); ++it) {
     //Maximum repeating group size
     if(it->second > maxf) {
     maxf=it->second;
     bal =it->first;  //Balance Factor of all string groups
     }
  }
  int count=0, del=0;
  for(auto it=mp.begin(); it!=mp.end(); it++) {
     //count of character 1 more or less than balance factor
     if(it->second==1||it->second==bal-1||it->second==bal+1)
        del++;
     //count of character that can't be balanced
     else if(abs(it->second-bal) > 0)
        count++;
  }
  if(del<=1 && count==0)
     return "YES";
  else
     return "NO";
}

*/