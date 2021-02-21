/*
Hackerrank::Challenges::NewYearChaos
description: https://www.hackerrank.com/challenges/new-year-chaos/
*/

#include "Challenges.h"

#include "HackerRankMiscellaneous.h"
using hr::split_string;

#include <bits/stdc++.h>

using std::cout;
using std::endl;
using std::cin;
using std::max;
using std::numeric_limits;
using std::ofstream;
using std::streamsize;

void MinimumBribes(vector<int> q) {

    const int QUEUE_SIZE = q.size();

    int bribesCounter = 0;
    int currentValue;
    int minIndex;

    for (int i = QUEUE_SIZE - 1; i >= 0; i--) {

        currentValue = q[i];

        if (currentValue > i + 3) {
            cout << "Too chaotic" << endl;
            return;
        }

        // Because of "Too chaotic" condition we can optimize second loop; 
        minIndex = max(0 , currentValue - 3);
        
        for (int j = minIndex; j < i; j++)
            if (q[j] > currentValue) bribesCounter++;

    }

    cout << bribesCounter << endl;

}

int NewYearChaosChallenge() {

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        string q_temp_temp;
        getline(cin, q_temp_temp);

        vector<string> q_temp = split_string(q_temp_temp);

        vector<int> q(n);

        for (int i = 0; i < n; i++) {
            int q_item = stoi(q_temp[i]);

            q[i] = q_item;
        }

        MinimumBribes(q);
    }

    return 0;
}