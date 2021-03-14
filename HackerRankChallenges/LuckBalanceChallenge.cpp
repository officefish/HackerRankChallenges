/*
Hackerrank::Challenges::GreedyAlgorithm::LuckBalance
description: https://www.hackerrank.com/challenges/luck-balance/
Solution Copyright (c) 2021 Officefish / Techies Team.
stuff:
std::multimap https://en.cppreference.com/w/cpp/container/multimap
*/
#include <string>
#include <vector>
#include <numeric>
#include <iterator>
#include <map>
#include <limits>

#include "./Challenges.h"
#include "./HackerRankMiscellaneous.h"

// The wrapper type that does reversal
template <typename Range>
class Reverser {
    Range& r_;
public:
    using iterator_type = std::reverse_iterator<decltype(std::begin(r_))>;

    Reverser(Range& r) : r_(r) {}

    iterator_type begin() { return iterator_type(std::end(r_)); }
    iterator_type end() { return iterator_type(std::begin(r_)); }
};
// Helper creation function
template <typename Range>
Reverser<Range> reverse(Range& r){
    return Reverser<Range>(r);
}

int32_t hrs::luckBalance(int32_t k, vector<vector<int32_t>> contests) {
    // rebuild a two-dimensional array into a multimap
    std::multimap<int32_t, int32_t> mpContests;
    int key, value;
    for (int32_t i = 0; i < contests.size(); ++i) {
        for (int32_t j = 0; j < contests[i].size(); ++j) {
            if (j == 0) key = contests[i][j];
            else
                value = contests[i][j];
        }
        mpContests.insert({ key, value });
    }
    // we benefit as long as we are lucky
    int32_t maxProfit = 0, currentLuck = k;
    // p.s. need some custom stuff for reverse ranging, so using template
    for (auto&& [profit, luck] : reverse(mpContests)) {
        if (luck == 1 && currentLuck > 0) {
            --currentLuck;
            maxProfit += profit;
        }
        else if (luck == 1) maxProfit -= profit;
        else if (luck == 0) maxProfit += profit;
    }
    return maxProfit;
}

int luckBalanceChallenge() {
    using hr::split_string;
    using std::cout;
    using std::endl;
    using std::cin;
    using std::numeric_limits;
    using std::streamsize;
    using std::string, std::vector;
    string nk_temp;
    getline(cin, nk_temp);
    vector<string> nk = split_string(nk_temp);
    int32_t n = stoi(nk[0]);
    int32_t k = stoi(nk[1]);
    vector<vector<int32_t>> contests(n);
    for (int32_t i = 0; i < n; i++) {
        contests[i].resize(2);
        for (int32_t j = 0; j < 2; j++) {
            cin >> contests[i][j];
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    int32_t result = hrs::luckBalance(k, contests);
    cout << result << "\n";
    return 0;
}
