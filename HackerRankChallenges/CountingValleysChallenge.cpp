/*
Hackerrank::Challenges::CountingValley

An avid hiker keeps meticulous records of their hikes. During the last hike that took exactly  steps, for every step it was noted if it was an uphill, , or a downhill,  step. Hikes always start and end at sea level, and each step up or down represents a  unit change in altitude. We define the following terms:

A mountain is a sequence of consecutive steps above sea level, starting with a step up from sea level and ending with a step down to sea level.
A valley is a sequence of consecutive steps below sea level, starting with a step down from sea level and ending with a step up to sea level.
Given the sequence of up and down steps during a hike, find and print the number of valleys walked through.

Example

steps = 8 path = [DDUUUUDD]

The hiker first enters a valley  units deep. Then they climb out and up onto a mountain  units high. Finally, the hiker returns to sea level and ends the hike.

Function Description

Complete the countingValleys function in the editor below.

countingValleys has the following parameter(s):

int steps: the number of steps on the hike
string path: a string describing the path
Returns

int: the number of valleys traversed
Input Format

The first line contains an integer , the number of steps in the hike.
The second line contains a single string , of  characters that describe the path.

Constraints

2 <= steps <= 10^6 //10 in 6 degree
path[i] i ∈ {U,D}

Sample Input

8
UDDDUDUU

Sample Output

1

*/


#include "Challenges.h"

#include "HackerRankMiscellaneous.h"
using hr::output_str;
using hr::ltrim;
using hr::rtrim;

#include <bits/stdc++.h>
using std::ofstream;
using std::cin;
using std::cout;
using std::stoi;

int CountingValleys(int steps, string path) {

    int height = 0;
    const int skyline = 0;
    int valleysCounter = 0;
    bool inValley = false;

    for (size_t i = 0; i < steps; ++i) {
        
        path[i] == 'U' ? ++height : --height;
        
        if (height < 0 && !inValley) {
            inValley = true;
            ++valleysCounter;
        }
        if (height >= 0 && inValley) {
            inValley = false;
        }

    }

    return valleysCounter;
}

int CountingValleysChallenge() {
    
    string hackerrank_output_str = output_str("HACKERRANK_OUTPUT_PATH");
    ofstream fout(hackerrank_output_str);

    string steps_temp;
    getline(cin, steps_temp);

    int steps = stoi(ltrim(rtrim(steps_temp)));

    string path;
    getline(cin, path);

    int result = CountingValleys(steps, path);

    fout << result << "\n";
    cout << "\n" << result << "\n";

    fout.close();

    return 0;
}

