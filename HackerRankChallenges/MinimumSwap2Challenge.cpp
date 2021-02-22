/*
Hackerrank::Challenges::MinimumSwap2Challenge
description: https://www.hackerrank.com/challenges/minimum-swaps-2/
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

int MinimumSwaps(vector<int> input) {
    
    int swaps = 0;
    int counter = 0;
    const int INPUT_SIZE = input.size();

    int currentValue;
    int tempValue;

    while (counter < INPUT_SIZE) {
        currentValue = input[counter];
        if (currentValue != counter + 1) {
            tempValue = input[currentValue - 1];
            input[currentValue - 1] = currentValue;
            input[counter] = tempValue;
            ++swaps;
        }
        else {
            ++counter;
        }
    }

    return swaps;
}

int MinimumSwap2Challenge() {
	
    string hackerrank_output_str = output_str("HACKERRANK_OUTPUT_PATH");
    ofstream fout(hackerrank_output_str);

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split_string(arr_temp_temp);

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    int res = MinimumSwaps(arr);

    cout << res << endl;
    
    fout << res << "\n";
    fout.close();

	
	return 0;
}

