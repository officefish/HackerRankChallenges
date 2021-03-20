/*
    Hackerrank::Challenges::SherlockAnagrams
    description: https://www.hackerrank.com/challenges/sherlock-and-anagrams/
*/
#include <algorithm>
#include ".././Challenges.h"

using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::vector;
using std::max;
using std::numeric_limits;
using std::streamsize;

#include <unordered_map>
using std::unordered_map;
// https://en.cppreference.com/w/cpp/container/unordered_map


bool areAnagram(string str1, string str2)
{
    size_t n1 = str1.length();
    size_t n2 = str2.length();

    if (n1 != n2)
        return false;

    sort(str1.begin(), str1.end());
    sort(str2.begin(), str2.end());

    for (int i = 0; i < n1; i++)
        if (str1[i] != str2[i])
            return false;

    return true;
}

int substrSum(string s) {

    int sum = 0;

    const size_t STR_SIZE = s.size();
    for (char& c : s) {
        sum += int(c);
    }

    return sum;
}

int findAnagrams(unordered_map<int, vector<string>*> *substrs, string s) {

    bool m_areAnagram = false;
    int anagramCounter = 0;

    int m_substrSum = substrSum(s);

    vector<string>* pBufferSubs;

    unordered_map<int, vector<string>*>::const_iterator got = substrs->find(m_substrSum);

    if (got != substrs->end()) {
        pBufferSubs = got->second;

        m_areAnagram = false;
        for (auto& str : *pBufferSubs) {
            m_areAnagram = areAnagram(s, str);
            if (m_areAnagram) {
                ++anagramCounter;
            }
        }

        pBufferSubs->push_back(s);
    }
    else {
        pBufferSubs = new vector<string>();
        pBufferSubs->push_back(s);
        substrs->insert({ {m_substrSum, pBufferSubs} });
    }

    return anagramCounter;

}

int hrs::sherlockAndAnagrams(string s) {

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


int sherlockAnagramsChallenge() {

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);

        int result = hrs::sherlockAndAnagrams(s);

        cout << result << "\n";
    }

    return 0;
}
