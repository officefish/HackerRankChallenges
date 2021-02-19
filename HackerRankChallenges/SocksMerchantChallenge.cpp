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

vector <string> split_string(string);

int SockMerchant(int, vector<int>);

int SocksMerchantChallenge()
{
    char* pathAppData = nullptr;
    size_t sz = 0;

    errno_t err = _dupenv_s(&pathAppData, &sz, "HACKERRANK_OUTPUT_PATH");

    if (err != 0) {
        cout << "_depenv_s failed with error: " << err << endl;
        exit(1);
    }
    else if (pathAppData == nullptr) {
        cout << "_depenv_s char* is still nullptr" << endl;
        exit(2);
    }

    string hackerrank_output_str(pathAppData);
    free(pathAppData);

    ofstream fout(hackerrank_output_str);

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

    int result = SockMerchant(n, ar);

    cout << "SockMerchant result: " << result << "\n";
    fout << result << "\n";

    fout.close();

    return 0;


}

int SockMerchant(int totalSocks, vector<int> socks) {

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

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [](const char& x, const char& y) {
        return x == y and x == ' ';
        });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
