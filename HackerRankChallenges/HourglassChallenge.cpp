
/*
Hackerrank::Challenges::Hourglass
description: https://www.hackerrank.com/challenges/2d-array
*/


#include "Challenges.h"

#include "HackerRankMiscellaneous.h"
using hr::split_string;

using std::cout;
using std::endl;
using std::cin;
using std::streamsize;
using std::numeric_limits;
using std::sort;

int hrs::hourglassSum(vector<vector<int>> arr) {
        
    const size_t FIELD_SIZE = 4;
    vector<int> sums(0);
    int sum;
       
    for (int i = 0; i < FIELD_SIZE; ++i) {
        
        for (int j = 0; j < FIELD_SIZE; ++j) {

            sum = arr[i][j]; sum += arr[i][j + 1]; sum += arr[i][j + 2];
            sum += arr[i + 1][j + 1];
            sum += arr[i + 2][j]; sum += arr[i + 2][j + 1]; sum += arr[i + 2][j + 2];

            sums.push_back(sum);
        }
    }
    
    sort(sums.begin(), sums.end());
    return sums[15];
}

int hourglassChallenge() {

    vector<vector<int>> arr(6);
    for (int i = 0; i < 6; i++) {
        arr[i].resize(6);

        for (int j = 0; j < 6; j++) {
            cin >> arr[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = hrs::hourglassSum(arr);
    
    cout << "\n" << result << "\n";
   
    return 0;
}