/*
Hackerrank::Challenges:FraudulentActivityNotifications
description: https://www.hackerrank.com/challenges/fraudulent-activity-notifications
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
using std::vector;
using std::sort;
using std::priority_queue;

double calcMedian(vector<int> scores)
{
    size_t size = scores.size();

    if (size == 0)
    {
        return 0;  // Undefined, really.
    }
    else
    {
        if (size % 2 == 0)
        {
            return (double)(scores[size / 2 - 1] + scores[size / 2]) / 2.0;
        }
        else
        {
            return scores[size / 2];
        }
    }
}

int activityNotifications(vector<int> expenditure, int d) {
    
    int warnings = { 0 };
    int half_chunk = { d / 2 };
    int current_half_chunk;

    double median;
    
    // one more try to using queies but avoid second loop
    // still slow but fuck this challenge, it work's rather ok.
    // Look at esential solution, it is in the end of the page, by the way.

    int size = expenditure.size() - d;
    int recurrent;

    for (int i = 0; i < size; ++i) {

        recurrent = i + d;
        current_half_chunk = half_chunk + i;

        // too small interval so calc meridian without queries
        if (d < 4) {
            
            median = 0;
            for (int j = i; j < i + d; ++j) {
                median += expenditure[j];
            }
            median /= d;

        }
        // use queries for calc approximate meridian
        else {

            priority_queue<int> highers(expenditure.begin() + i, expenditure.begin() + current_half_chunk);
            priority_queue<int, std::vector<int>, std::greater<int>> lowers(expenditure.begin() + current_half_chunk, expenditure.begin() + recurrent);

            median = (double(lowers.top()) + double(highers.top())) / 2.0;
          
            /* not sure we about life cycles of these containers
            while (!lowers.empty()) {
                lowers.pop();
            }
            while (!highers.empty()) {
                highers.pop();
            }
            */
           
        }
        
        if (expenditure[recurrent] >= round(median * 2)) {
            ++warnings;
        }
    
    }


    // using priority queies for avoid sorting! 
    // p.s Still slow :(


    /*
    int size = expenditure.size() - d;
    int recurrent;

    priority_queue<int, std::vector<int>, std::greater<int>> lowers;
    priority_queue<int> highers;

    for (int i = 0; i < size; ++i) {

        recurrent = i + d;
        current_half_chunk = half_chunk + i;

        for (int j = i; j < i + d; ++j) {
            if (j < current_half_chunk) {
                highers.push(expenditure[j]);
            }
            else {
                lowers.push(expenditure[j]);
            }
        }

        if (d % 2 == 0) {
            median = (double(lowers.top()) + double(highers.top())) / 2.0;
        }
        else {
            median = lowers.top();
        }

        while (!lowers.empty()) {
            lowers.pop();
        }
        while (!highers.empty()) {
            highers.pop();
        }
       
        if (expenditure[recurrent] >= round(median * 2)) {
            ++warnings;
        }

    }
    */
       
    /*
    

    vector<int> chunk(d);

    // alternative loop, with using same vector still slow
    for (auto itr = expenditure.begin(); itr != expenditure.end() - d; ++itr)
    {
        
        std::copy(itr, itr + d, chunk.begin());
        sort(chunk.begin(), chunk.end());
        median = calcMedian(chunk);
        if (*(itr + d) >= 2 * median)
            ++warnings;
    }
    */

    /*
    int size = { static_cast<int>(expenditure.size() - d) };
    int recurrent;
    vector<int>::const_iterator first; // = myVec.begin() + 100000;
    vector<int>::const_iterator last; //= myVec.begin() + 101000;
    
    for (int i = 0; i < size; ++i) {
        recurrent = i + d;
        first = expenditure.begin() + i;
        last = expenditure.begin() + (i + d);
        vector<int> trailing(first, last);
        //for (auto v : trailing) {
        //    cout << v << " ";
        //}
        //cout << ": " << recurrent << endl;
        sort(trailing.begin(), trailing.end());
        median = calcMedian(trailing);
        cout << "median * 2: " << median * 2
            << ", recurrent: " << expenditure[recurrent] << endl;

        if (expenditure[recurrent] >= round(median * 2)) {
            ++warnings;
        }
    }*/

    return warnings;

}


int fraudNotChallenge() {

    std::ios_base::sync_with_stdio(0);

    string hackerrank_output_str = output_str("HACKERRANK_OUTPUT_PATH");
    ofstream fout(hackerrank_output_str);

    string nd_temp;
    getline(cin, nd_temp);

    vector<string> nd = split_string(nd_temp);

    int n = stoi(nd[0]);

    int d = stoi(nd[1]);

    string expenditure_temp_temp;
    getline(cin, expenditure_temp_temp);

    vector<string> expenditure_temp = split_string(expenditure_temp_temp);

    vector<int> expenditure(n);

    for (int i = 0; i < n; i++) {
        int expenditure_item = stoi(expenditure_temp[i]);

        expenditure[i] = expenditure_item;
    }

    int result = activityNotifications(expenditure, d);

    fout << result << "\n";
    cout << result << endl;

    fout.close();

    return 0;
}


/*

Esential solution

#include <bits/stdc++.h>
using namespace std;

#define SZ(x) ((int)(x.size()))
#define FOR(i,n) for(int (i)=0;(i)<(n);++(i))
#define FOREACH(i,t) for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define REP(i,a,b) for(int (i)=(a);(i)<=(b);++i)

typedef long long ll;
const int INF = 1e9;

const int N = 2e5;
const int V = 200;

int a[N];

int cnt[V+1];

int main()
{
    ios_base::sync_with_stdio(0);
    int n, d;
    cin >> n >> d;
    assert(n >= 1 && n <= N);
    assert(d >= 1 && d <= n);
    FOR(i, n) cin >> a[i];
    FOR(i, n) assert(a[i] >= 0 && a[i] <= V);
    int res = 0;

    FOR(i, d) cnt[a[i]]++;
    REP(i, d, n-1)
    {
        //SOLVE HERE
        int acc = 0;
        int low_median = -1, high_median = -1;
        REP(v, 0, V)
        {
            acc += cnt[v];
            if(low_median == -1 && acc >= int(floor((d+1)/2.0)))
            {
                low_median = v;
            }
            if(high_median == -1 && acc >= int(ceil((d+1)/2.0)))
            {
                high_median = v;
            }
        }
        assert(acc == d);
        int double_median = low_median + high_median;
        //cout << low_median << " " << high_median << " -> " << median << endl;
        if(a[i] >= double_median)
        {
            res++;
        }
        cnt[a[i-d]]--;
        cnt[a[i]]++;
    }
    cout << res << endl;
    return 0;
}

*/