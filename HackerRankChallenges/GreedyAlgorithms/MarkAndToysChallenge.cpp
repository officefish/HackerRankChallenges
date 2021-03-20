/*
Hackerrank::Challenges::MarkAndToys
description:https://www.hackerrank.com/challenges/mark-and-toys/
*/

#include <algorithm>

#include ".././Challenges.h"
#include ".././HackerRankMiscellaneous.h"
using hr::split_string;

using std::cout;
using std::endl;
using std::cin;
using std::streamsize;
using std::numeric_limits;
using std::sort;

int hrs::maximumToys(vector<int> prices, int k) {
    int counter = { 0 }, remainder = { k };
    sort(prices.begin(), prices.end());
    while (prices.size() && remainder >= prices[0]) {
        remainder -= prices[0];
        ++counter;
        prices.erase(prices.begin());
    }
    return counter;
}

int markAndToysChallenge() {
    using std::string, std::vector;
    string nk_temp;
    getline(cin, nk_temp);
    vector<string> nk = split_string(nk_temp);
    int n = stoi(nk[0]);
    int k = stoi(nk[1]);
    string prices_temp_temp;
    getline(cin, prices_temp_temp);
    vector<string> prices_temp = split_string(prices_temp_temp);
    vector<int> prices(n);
    for (int i = 0; i < n; i++) {
        int prices_item = stoi(prices_temp[i]);
        prices[i] = prices_item;
    }
    int result = hrs::maximumToys(prices, k);
    cout << result << "\n";
    return 0;
}

/*
Mark will able to maximize the amount of toys he can buy by getting as many of the cheapest ones as his budget allows.
This is a good tip torwards sorting the array - as well as this problem falling under the Sorting category, of course.

However, there is one interesting thing to notice. If you think about bubble sort,
it always drags the highest value it can find to the far end of the array,
repeating that process but stopping one position before each time,
until the end poition matches the beggining the array, meaning that it is sorted.
With that in mind, if we sort the array in a decreasing order,
dragging the smallest value to the end, we can say for sure that the value at the end position
after each iteration is the smallest one we found this round.

What does this mean? That you don't have to sort the entire array. After each bubble sort pass,
make Mark buy the cheapest toy you found in it and deduct it from his budget.
If you reach a point where he can't afford the cheapest toy in a pass,
then he won't be able to afford any of the remaining and already have the maximum number of toys he could have bought,
so you can abort your sorting there to save some time.

Commentator: https://www.hackerrank.com/yanr_dasilva?hr_r=1
*/