/*
Hackerrank::Challenges::JumpingOnTheClouds
description: https://www.hackerrank.com/challenges/jumping-on-the-clouds/
*/

#include ".././Challenges.h"
#include ".././HackerRankMiscellaneous.h"
using hr::split_string;

using std::cout;
using std::endl;
using std::cin;
using std::ofstream;
using std::streamsize;
using std::numeric_limits;

int hrs::jumpingOnClouds(vector<int> clouds) {
    int currentCloud;
    const size_t cloudsSize = clouds.size();
    int jumpsCounter = 0;
    for (size_t i = 0; i < cloudsSize; i++) {
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
    using std::string, std::vector;
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
    int result = hrs::jumpingOnClouds(c);
    cout << "\n" << result << "\n";
    return 0;
}