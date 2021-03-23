/*
Hackerrank::Challenges::Arrays - DS
description: https://www.hackerrank.com/challenges/arrays-ds
*/

#include <algorithm>
#include ".././Challenges.h"

#include ".././HackerRankMiscellaneous.h"
using hr::split_string;

namespace hrs {

    void reverseArray_c(int* input, int length) {
        int half = length / 2;
        for (int i = 0, j = length - 1;
            i < half, j >= half; ++i, --j) {
            int tmp = input[i];
            input[i] = input[j];
            input[j] = tmp;
        }
    }
    void reverseArray(vector<int32_t>* input) {
        size_t length{ input->size() }, half{ length / 2 };
        for (size_t i = 0, j = length - 1;
            i < half, j >= half; ++i, --j)
            std::swap((*input)[i], (*input)[j]);
    }

    inline void reverseArray_std(vector<int32_t>* input) {
        std::reverse(input->begin(), input->end());
    }
}

int reverseArrayChallenge_c() {
    using std::cin, std::cout, std::endl;
    using std::streamsize, std::numeric_limits;
    using std::vector, std::string;

    int arr_count;
    cin >> arr_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    string arr_temp_temp;
    getline(cin, arr_temp_temp);
    vector<string> arr_temp = split_string(arr_temp_temp);

    int* arr = new int[arr_count];
    for (int i = 0; i < arr_count; i++) {
        arr[i] = stoi(arr_temp[i]);
    }
    hrs::reverseArray_c(arr, arr_count);
    for (int i = 0; i < arr_count; i++) {
        cout << arr[i];
        if (i != arr_count - 1) {
            cout << " ";
        }
    }
    delete[] arr;
    cout << "\n";
    return 0;
}
int reverseArrayChallenge() {
    using std::cin, std::cout, std::endl;
    using std::streamsize, std::numeric_limits;
    using std::vector, std::string;

    int arr_count;
    cin >> arr_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    string arr_temp_temp;
    getline(cin, arr_temp_temp);
    vector<string> arr_temp = split_string(arr_temp_temp);

    vector<int32_t> arr;
    for (int i = 0; i < arr_count; i++) {
        arr.push_back(stoi(arr_temp[i]));
    }
    hrs::reverseArray(&arr);
    for (const auto& v : arr) {
        cout << v << " ";
    }
    cout << endl;
	return 0;
}

int reverseArraySTDChallenge() {
    using std::cin, std::cout, std::endl;
    using std::streamsize, std::numeric_limits;
    using std::vector, std::string;

    int arr_count;
    cin >> arr_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    string arr_temp_temp;
    getline(cin, arr_temp_temp);
    vector<string> arr_temp = split_string(arr_temp_temp);

    vector<int32_t> arr;
    for (int i = 0; i < arr_count; i++) {
        arr.push_back(stoi(arr_temp[i]));
    }
    hrs::reverseArray_std(&arr);
    for (const auto& v : arr) {
        cout << v << " ";
    }
    cout << endl;
    return 0;
}