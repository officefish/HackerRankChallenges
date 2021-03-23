/*
Hackerrank::Challenges::Arrays::DynamicArray
description: https://www.hackerrank.com/challenges/dynamic-array/problem
*/

#include <algorithm>
#include ".././Challenges.h"

#include ".././HackerRankMiscellaneous.h"
using hr::split, hr::rtrim;

namespace{
    typedef std::vector<std::vector<int>> matrix;
}

std::vector<int> DynamicArray(int n, matrix queries) {
    matrix seq(queries.size());
    int32_t lastAnswer = 0;
    int32_t index, position;
    std::vector<int> result;

    for (auto& q : queries) {
        index = (q[1] ^ lastAnswer) % n;
        if (q[0] == 1)
            seq[index].push_back(q[2]);
        else {
            position = q[2] % seq[index].size();
            lastAnswer = seq[index][position];
            result.push_back(lastAnswer);
        }
    }
    return result;
}

int dynamicArrayChallenge() {
    using std::cin, std::cout, std::endl;
    using std::streamsize, std::numeric_limits;
    using std::vector, std::string;

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);
    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));
    int n = stoi(first_multiple_input[0]);
    int q = stoi(first_multiple_input[1]);
    vector<vector<int>> queries(q);
    for (int i = 0; i < q; i++) {
        queries[i].resize(3);
        string queries_row_temp_temp;
        getline(cin, queries_row_temp_temp);
        vector<string> queries_row_temp = split(rtrim(queries_row_temp_temp));
        for (int j = 0; j < 3; j++) {
            int queries_row_item = stoi(queries_row_temp[j]);
            queries[i][j] = queries_row_item;
        }
    }

    vector<int> result = DynamicArray(n, queries);

    for (int i = 0; i < result.size(); i++) {
        cout << result[i];
        if (i != result.size() - 1) {
            cout << "\n";
        }
    }
    cout << "\n";
    return 0;
}

/*
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <string>
#include <cstring>
#include <cassert>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <bitset>
#include <iostream>

#define pb push_back
#define all(x) (x).begin(), (x).end()

#ifdef KAZAR
  #define eprintf(...) fprintf(stderr,__VA_ARGS__)
#else
  #define eprintf(...) 0
#endif

using namespace std;

template<class T> inline void umax(T &a,T b){if(a < b) a = b;}
template<class T> inline void umin(T &a,T b){if(a > b) a = b;}
template<class T> inline T abs(T a){return a > 0 ? a : -a;}

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;

const int inf = 1e9 + 143;
const ll longinf = 1e18 + 143;

inline int read(){int x;scanf(" %d",&x);return x;}

int main(){

#ifdef KAZAR
  freopen("f.input","r",stdin);
  freopen("f.output","w",stdout);
  freopen("error","w",stderr);
#endif

  int n = read();
  int q = read();
  assert(1 <= n && n <= 1e5);
  assert(1 <= q && q <= 1e5);
  int lastans = 0;
  vector<vi> seq(n);
  for (int i = 0; i < q; i++) {
    int t = read();
    int x = read();
    int y = read();
    int real_x = (x ^ lastans) % n;
    if (t == 1) {
      seq[real_x].pb(y);
    } else {
      assert(seq[real_x].size());
      lastans = seq[real_x][y % seq[real_x].size()];
      printf("%d\n", lastans);
    }
  }

  return 0;
}

*/