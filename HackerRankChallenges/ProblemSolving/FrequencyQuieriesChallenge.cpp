/*
    Hackerrank::Challenges::FrequencyQueries
    description: https://www.hackerrank.com/challenges/frequency-queries
*/

#include <algorithm>
#include <map>
#include <unordered_map>
using std::unordered_map;
// https://en.cppreference.com/w/cpp/container/unordered_map

#include ".././Challenges.h"

#include ".././HackerRankMiscellaneous.h"
using hr::ltrim;
using hr::rtrim;
using hr::split;

using std::cin;
using std::cout;
using std::stoi;
using std::endl;
using std::string;

std::vector<int> hrs::frequencyQuery(vector<vector<int>> queries) {
    //initialize two maps where :
    //freq has for key the frequence z and the value is the datas having this frequency
    //values has for key the data inserted and the key is it's frequency
    std::map<int, int> freq;
    std::map<int, int> datas;
    //vector of the final output
    std::vector<int> output;
    for (auto& q : queries) {
        switch (q[0]) {
        case 1:
            //incrementing the frequency of the data
            datas[q[1]]++;
            //increment the number of datas having this frequency
            freq[datas[q[1]]]++;
            //decrement the number of datas having the old frequency of the treated data
            freq[datas[q[1]] - 1]--;
            //we cannot allow to have a negative number in our values
            if (freq[datas[q[1] - 1]] < 0) {
                freq[datas[q[1] - 1]] = 0;
            }
            break;
        case 2:
            //case 2 is like case 1 but the incrementation and decrementation will be reversed
            datas[q[1]]--;
            freq[datas[q[1]]]++;
            freq[datas[q[1]] + 1]--;
            if (freq[datas[q[1]] + 1] < 0) {
                freq[datas[q[1]] + 1] = 0;
            }
            if (datas[q[1]] < 0) {
                datas[q[1]] = 0;
            }
            break;
        case 3:
            //check whether this frequency exists in our map and at least one data have this frequency
            if (freq.find(q[1]) != freq.end() && freq[q[1]] > 0) {
                output.push_back(1);
            } else {
                output.push_back(0);
            }
            break;
        }
    }
    return output;
}


int frequencyQueriesChallenge() {
    using std::string, std::vector;
    string q_temp;
    getline(cin, q_temp);
    int q = stoi(ltrim(rtrim(q_temp)));
    vector<vector<int>> queries(q);
    for (int i = 0; i < q; i++) {
        queries[i].resize(2);
        string queries_row_temp_temp;
        getline(cin, queries_row_temp_temp);
        vector<string> queries_row_temp = split(rtrim(queries_row_temp_temp));
        for (int j = 0; j < 2; j++) {
            int queries_row_item = stoi(queries_row_temp[j]);
            queries[i][j] = queries_row_item;
        }
    }
    vector<int> ans = hrs::frequencyQuery(queries);
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i];
        if (i != ans.size() - 1)
            cout << endl;
    }
    cout << endl;
    return 0;
}