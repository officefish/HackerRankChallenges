/*
Hackerrank::Chalenges::JumpingOnTheClouds

There is a new mobile game that starts with consecutively numbered clouds. Some of the clouds are thunderheads and others are cumulus. The player can jump on any cumulus cloud having a number that is equal to the number of the current cloud plus  or . The player must avoid the thunderheads. Determine the minimum number of jumps it will take to jump from the starting postion to the last cloud. It is always possible to win the game.

For each game, you will get an array of clouds numbered  if they are safe or  if they must be avoided.

Example

c = [0,1,0,0,0,1,0]

Index the array from 0 ... 6. 
The number on each cloud is its index in the list so the player must avoid the clouds at indices 1 and 5. 
They could follow these two paths: 0 -> 2 -> 4 -> 6 or 0 -> 2 -> 3 -> 4 -> 6. The first path takes 3 jumps while the second takes 4. Return 3.

Function Description

Complete the jumpingOnClouds function in the editor below.

jumpingOnClouds has the following parameter(s):

int c[n]: an array of binary integers
Returns

int: the minimum number of jumps required
Input Format

The first line contains an integer n, the total number of clouds. The second line contains n space-separated binary integers describing clouds c[i] where 0 <= i < n.

Constraints

2 <= n <= 100
c[i] ∈ {0,1}
c[0] = c[n - 1] = 0;

Output Format

Print the minimum number of jumps needed to win the game.

Sample Input 0

7
0 0 1 0 0 1 0

Sample Output 0

4


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


int JumpingOnClouds(vector<int> clouds) {
    
    int currentCloud;
    const size_t cloudsSize = clouds.size();
    size_t jumpsCounter = 0;

    for (int i = 0; i < cloudsSize; i++) {
        currentCloud = clouds[i];
        
        if (i + 2 < cloudsSize && !clouds[i + 2]) {
            ++i;
            jumpsCounter++;
        }
        else if(i + 1 < cloudsSize) {
            jumpsCounter++;
        }
    }

    return jumpsCounter;
}


int JumpingOnCloudsChallenge() {

    string hackerrank_output_str = output_str("HACKERRANK_OUTPUT_PATH");
    ofstream fout(hackerrank_output_str);

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string c_temp_temp;
    getline(cin, c_temp_temp);

    vector<string> c_temp = split_string(c_temp_temp);

    vector<int> c(n);

    for (int i = 0; i < n; i++) {
        int c_item = stoi(c_temp[i]);

        c[i] = c_item;
    }

    int result = JumpingOnClouds(c);

    fout << result << "\n";
    cout << "\n" << result << "\n";
    
    fout.close();

    return 0;
}