/*

Hackerrank::Chalenges::SockMerchant

There is a large pile of socks that must be paired by color.
Given an array of integers representing the color of each sock,
determine how many pairs of socks with matching colors there are.

Example:

n = 7; ar = [1,2,1,2,1,3,2];

There is one pair of color  and one of color . There are three odd socks left, one of each color. The number of pairs is .

Function Description:

Complete the sockMerchant function in the editor below.

sockMerchant has the following parameter(s):

int n: the number of socks in the pile
int ar[n]: the colors of each sock

Returns:

int: the number of pairs

Input Format:

The first line contains an integer , the number of socks represented in .
The second line contains  space-separated integers, , the colors of the socks in the pile.

Constraints:

1 <= n <= 100;
1 <= a[i] <= 100 where 0 <= i < n;

Sample Input

STDIN                       Function
-----                       --------
9                           n = 9
10 20 20 10 10 30 50 10 20  ar = [10, 20, 20, 10, 10, 30, 50, 10, 20]

Sample Output

3

*/

#include "Challenges.h"

#include "HackerRankMiscellaneous.h"
using hr::split_string;
using hr::output_str;

#include <bits/stdc++.h>

using std::cout;
using std::endl;
using std::cin;
using std::ofstream;
using std::streamsize;
using std::numeric_limits;

using std::min;
using std::max;

using std::string;
using std::vector;

using std::find;


int socksMerchantChallenge()
{
   
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string ar_temp_temp;
    getline(cin, ar_temp_temp);

    vector<string> ar_temp = split_string(ar_temp_temp);

    vector<int> ar(n);

    for (int i = 0; i < n; i++) {
        int ar_item = stoi(ar_temp[i]);

        ar[i] = ar_item;
    }

    int result = hrs::socksMerchant(n, ar);

    cout << result << "\n";
   
    return 0;


}

int hrs::socksMerchant(int totalSocks, vector<int> socks) {

    int pairs = 0;
    vector<int> needPairSocks = {};
    int currentSockId;
    std::vector<int>::iterator position;

    for (int i = 0; i < socks.size(); i++) {
        currentSockId = socks[i];
        position = find(needPairSocks.begin(), needPairSocks.end(), currentSockId);
        if (position != needPairSocks.end()) { // == myVector.end() means the element was not found
            needPairSocks.erase(position);
            ++pairs;
        }
        else {
            needPairSocks.push_back(currentSockId);
        }
    }

    return pairs;
}
