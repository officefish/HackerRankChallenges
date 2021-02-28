/*
Hackerrank::Challenges::JumpingOnTheClouds
description: https://www.hackerrank.com/challenges/jumping-on-the-clouds/
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
using std::streamsize;
using std::numeric_limits;


int jumpingOnClouds(vector<int> clouds) {
    
    int currentCloud;
    const size_t cloudsSize = clouds.size();
    size_t jumpsCounter = 0;

    for (int i = 0; i < cloudsSize; i++) {
        currentCloud = clouds[i];
        
        if (i + 2 < cloudsSize && !clouds[i + 2]) {
            ++i;
            jumpsCounter++;
        }
        else if(i + 1 < cloudsSize) {
            jumpsCounter++;
        }
    }

    return jumpsCounter;
}


int jumpingOnCloudsChallenge() {

    string hackerrank_output_str = output_str("HACKERRANK_OUTPUT_PATH");
    ofstream fout(hackerrank_output_str);

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string c_temp_temp;
    getline(cin, c_temp_temp);

    vector<string> c_temp = split_string(c_temp_temp);

    vector<int> c(n);

    for (int i = 0; i < n; i++) {
        int c_item = stoi(c_temp[i]);

        c[i] = c_item;
    }

    int result = jumpingOnClouds(c);

    fout << result << "\n";
    cout << "\n" << result << "\n";
    
    fout.close();

    return 0;
}