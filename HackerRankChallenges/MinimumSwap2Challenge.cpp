/*
Hackerrank::Challenges::MinimumSwap2Challenge
description: https://www.hackerrank.com/challenges/minimum-swaps-2/
*/

#include "Challenges.h"

#include "HackerRankMiscellaneous.h"
using hr::split_string;

using std::cout;
using std::endl;
using std::cin;
using std::streamsize;
using std::numeric_limits;

int hrs::minimumSwaps(vector<int> input) {
    
    int swaps = 0;
    size_t counter = 0;
    const size_t INPUT_SIZE = input.size();

    int currentValue;
    int tempValue;

    while (counter < INPUT_SIZE) {
        currentValue = input[counter];
        if (currentValue != counter + 1) {
            tempValue = input[size_t(currentValue) - 1];
            input[size_t(currentValue) - 1] = currentValue;
            input[counter] = tempValue;
            ++swaps;
        }
        else {
            ++counter;
        }
    }

    return swaps;
}

int minimumSwap2Challenge() {
	
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

    int res = hrs::minimumSwaps(arr);

    cout << res << endl;
    
	return 0;
}

