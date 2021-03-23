/*
Hackerrank::Challenges::WarmUpChallenges
Solution Copyright (c) 2021 Officefish / Techies Team.
*/
#include "../.././Challenges.h"
#include <algorithm>
#include <utility>
#include <numeric>
#include <sstream>
#include <iomanip>
#include <ctime>
#include <map>

std::pair<size_t, size_t> hrs::minMaxSum(std::vector<int32_t> row) {
    // too slow! O(n^4)
    //int max = *max_element(arr.begin(), arr.end()) * -1;
    //int min = *min_element(arr.begin(), arr.end()) * -1;
    //cout << accumulate(arr.begin(), arr.end(), max) << " ";
    //cout << accumulate(arr.begin(), arr.end(), min);
    // manually O(n)
    int max = INT32_MIN;
    int min = INT32_MAX;
    size_t sum = 0;
    for (size_t i = 0; i < row.size(); ++i) {
        sum += row[i];
        min = row[i] < min ? row[i] : min;
        max = row[i] > max ? row[i] : max;
    }
    std::pair<size_t, size_t> mm(sum - max, sum - min);
    return mm;
}   // description: https://www.hackerrank.com/challenges/mini-max-sum/

size_t hrs::accumulate(std::vector<int32_t> row) {
    return  std::accumulate(row.begin(), row.end(), 0);
}   // description: https://www.hackerrank.com/challenges/simple-array-sum/

std::pair<int8_t, int8_t>hrs::compareTheTriplets(vector<int16_t> a, vector<int16_t> b) {
    int8_t aScores = 0, bScores = 0;
    int8_t counter = 2;
    while (counter >= 0) {
        if (a[counter] != b[counter])
            a[counter] > b[counter] ? aScores += 1 : bScores += 1;
        --counter;
    }
    return std::make_pair(aScores, bScores);
    //std::cout << triplet.first << " " << triplet.second<< '\n';
    //return { aScores, bScores };
}   // https://www.hackerrank.com/challenges/compare-the-triplets/

int16_t hrs::diagonalDifference(std::vector<std::vector<int8_t>> arr) {
    int16_t aDiagonal{ 0 }, bDiagonal{ 0 };
    size_t begin{ 0 }, end{ arr.size() };
    for (size_t x = begin, y = end - 1; x < end; ++x, --y) {
        aDiagonal += arr[x][x];
        bDiagonal += arr[x][y];
        //cout << "[" << x <<"][" << x << "]:" << arr[x][x] << " ";
        //cout << "[" << x <<"][" << y << "]:" << arr[x][y] << endl;
    }
    return abs(aDiagonal - bDiagonal);
}   // description: https://www.hackerrank.com/challenges/diagonal-difference/

std::string hrs::plusMinus(std::vector<int16_t> arr) {
    double positive{ 0 }, negative{ 0 }, zeros{ 0 };
    for (size_t i = 0; i < arr.size(); ++i) {
        if (arr[i])
            arr[i] > 0 ? ++positive : ++negative;
        else
            ++zeros;
    }
    std::stringstream ss;
    ss << std::setprecision(6) << positive / arr.size() << std::endl;
    ss << std::setprecision(6) << negative / arr.size() << std::endl;
    ss << std::setprecision(6) << zeros / arr.size() << std::endl;
    //std::cout << ss.str();
    return ss.str();
}   // description: https://www.hackerrank.com/challenges/plus-minus/

std::string hrs::staircase(int8_t n) {
    // fun
    int8_t n2{ n };
    std::stringstream ss;
    while (n2--) {
        int8_t n3 = n - n2;
        ss << std::setw(n2 + 1) << std::right;
        while (n3--) ss << "#";
        ss << std::endl;
    }
    //std::cout << ss.str();
    return ss.str();
    /* boring
    int8_t n2{ n - 1 };
    while (n2 >= 0) {
        int8_t n3 = n2;
        int8_t n4 = n - n2;
        while (n3) { ss << " "; --n3; }
        while (n4) { ss << "#"; --n4; }
        ss << std::endl; --n2;
    }*/
    //std::cout << ss.str();
    //return ss.str();
}   // https://www.hackerrank.com/challenges/staircase


int64_t hrs::birthdayCakeCandles(std::vector<int32_t> candles) {
    // std solution but O(n * 2);
    int32_t max = *std::max_element(candles.begin(), candles.end());
    return count(candles.begin(), candles.end(), max);

    /* O(n) + O(n) std::max uses :)
    int32_t maxAge = INT32_MIN;
    std::map<int32_t, int32_t> freq;
    for (auto& candle : candles) {
        freq[candle]++;
        maxAge = std::max(maxAge, int32_t(candle));
    }
    return freq[maxAge];
    */
}   // description: https://www.hackerrank.com/challenges/birthday-cake-candles


extern "C" char* strptime(const char* s,
    const char* f,
    struct tm* tm) {
    // Isn't the C++ standard lib nice? std::get_time is defined such that its
    // format parameters are the exact same as strptime. Of course, we have to
    // create a string stream first, and imbue it with the current C locale, and
    // we also have to make sure we return the right things if it fails, or
    // if it succeeds, but this is still far simpler an implementation than any
    // of the versions in any of the C standard libraries.
    std::istringstream input(s);
    input.imbue(std::locale(setlocale(LC_ALL, nullptr)));
    input >> std::get_time(tm, f);
    if (input.fail()) {
        return nullptr;
    }
    return (char*)(s + input.tellg());
}

std::string hrs::timeConversion(std::string s, std::string iPattern, std::string oPattern) {
    struct tm input_tm;
    strptime(s.c_str(),iPattern.c_str() , &input_tm); // "%r"
    time_t t = mktime(&input_tm);
    char mbstr[100];

    struct tm output_tm;
    localtime_s(&output_tm, &t);
    strftime(mbstr, sizeof(mbstr), oPattern.c_str(), &output_tm); // "%T"
    return std::string(mbstr);
}   // description: https://www.hackerrank.com/challenges/time-conversion/problem
    // advanced:   http://www.cplusplus.com/reference/ctime/strftime/