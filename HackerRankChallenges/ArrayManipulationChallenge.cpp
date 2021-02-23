/*
	Hackerrank::Challenges::ArrayManipulationChallenge
	description: https://www.hackerrank.com/challenges/crush

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

/*

Input:

10 4

2 6 8
3 5 7
1 8 1
5 9 15

Procedure:

[ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
[ 0, 8, 8, 8, 8, 8, 0, 0, 0, 0]
[ 0, 8,15,15,15, 8, 0, 0, 0, 0]
[ 1, 9,16,16,16, 9, 1, 1, 0, 0]
[ 1, 9,16,16,31,24,16,16, 1, 0]


Output:
31


*/

long ArrayManipulation(int n, vector<vector<int>> queries) {
    
    vector<int> accumulator(n, 0);

    long maxValue = 0;
    long accumulatorValue = 0;

    const int size = queries.size();

    int begin;
    int end;
    int value;
    int max;

    for (int i = 0; i < size; ++i) {

        begin = queries[i][0] - 1;
        end = queries[i][1];
        value = queries[i][2];

        /* Elegant *1 */

        accumulator[begin] += value;
        if (end < n) accumulator[end] -= value;
        
        /* Brut force */

        /*
        
        for (long j = begin; j < end; ++j) {


            accumulator[j] += value;
            //maxValue = accumulator[j] > maxValue ? accumulator[j] : maxValue;


            // this is better!
            if (accumulator[j] > maxValue)
                maxValue = accumulator[j];

            value -= value;
            if (value == queries[i][2] * -2)
                continue;
        }
        */


    }

    for (int i = 0; i < n; ++i) {

        accumulatorValue += accumulator[i];

        if (maxValue < accumulatorValue) maxValue = accumulatorValue;
    }

    return maxValue;
}

/*

Elegant explanation:

For every input line of a-b-k, you are given the range (a to b) where the values increase by k. 
So instead of keeping track of actual values increasing, just keep track of the rate of change (i.e. a slope)
in terms of where the rate started its increase and where it stopped its increase. 
This is done by adding k to the "a" position of your array and adding -k to the "b+1" position 
of your array for every input line a-b-k, and that's it. "b+1" is used because the increase still applied at "b".

The maximum final value is equivalent to the maximum accumulated "slope" starting from the first position, 
because it is the spot which incremented more than all other places. 
Accumulated "slope" means to you add slope changes in position 0 to position 1, 
then add that to position 2, and so forth, looking for the point where it was the greatest.

*/

int ArrayManipulationChallenge() {

    string hackerrank_output_str = output_str("HACKERRANK_OUTPUT_PATH");
    ofstream fout(hackerrank_output_str);

    string nm_temp;
    getline(cin, nm_temp);

    vector<string> nm = split_string(nm_temp);

    int n = stoi(nm[0]);

    int m = stoi(nm[1]);

    vector<vector<int>> queries(m);
    for (int i = 0; i < m; i++) {
        queries[i].resize(3);

        for (int j = 0; j < 3; j++) {
            cin >> queries[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    long result = ArrayManipulation(n, queries);

    cout << result << endl;
    
    fout << result << "\n";
    fout.close();

    return 0;
}