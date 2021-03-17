/*
Hackerrank::Challenges::PreprocessorChallenge
description: https://www.hackerrank.com/challenges/preprocessor-solution
Solution Copyright(c) 2021 Officefish / Techies Team.
http://www.cplusplus.com/doc/tutorial/preprocessor/
*/
#include "./Challenges.h"

//#pragma warning(disable: 4307)
#pragma warning(disable: 4244)
#define INF 1e9//(1<<31)-1 //(unsigned)!((int)0)
#define FUNCTION(name,operator) inline void name(int &current, int candidate) {!(current operator candidate) ? current = candidate : false;}
#define io(v) std::cin>>v
#define toStr(str) #str
#define foreach(v, i) for (int i = 0; i < v.size(); ++i)

#if !defined toStr || !defined io || !defined FUNCTION || !defined INF
#error Missing preprocessor definitions
#endif

FUNCTION(minimum, < )
FUNCTION(maximum, > )

int preprocessorChallenge() {
	int n; std::cin >> n;
	std::vector<int> v(n);
	foreach(v, i) {
		io(v)[i];
	}
	int mn = INF;
	int mx = -INF;
	foreach(v, i) {
		minimum(mn, v[i]);
		maximum(mx, v[i]);
	}
	int ans = mx - mn;
	std::cout << toStr(Result = ) << ' ' << ans;
	return 0;
}