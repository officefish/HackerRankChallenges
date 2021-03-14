/*
Hackerrank::Challenges::CommonChild
description:https://www.hackerrank.com/challenges/common-child
Solution Copyright (c) 2021 Officefish / Techies Team.
theory: https://en.wikipedia.org/wiki/Longest_common_subsequence_problem
*/

#if __cplusplus > 201703L
#include <ranges>
#endif

#include <string>
#include <limits>
#include <algorithm>
#include <vector>

#include "./Challenges.h"
#include "./HackerRankMiscellaneous.h"

int hrs::commonChild(string s1, string s2) {
    size_t m = s1.size();
    size_t n = s2.size();
    vector<vector<uint8_t>> field(m+1, vector<uint8_t>(n+1, 0));
    for (size_t i = 0; i <= m; i++) {
        for (size_t j = 0; j <= n; j++) {
            if (i == 0 || j == 0) {
                field[i][j] = 0;
            } else if (s1[i - 1] == s2[j - 1]) {
                field[i][j] = 1 + field[i - 1][j - 1];
            } else {
                field[i][j] = std::max(field[i][j - 1], field[i - 1][j]);
            }
        }
    }
    return field[m][n];
}

int commonChildChallenge() {
    using std::cout;
    using std::endl;
    using std::cin;
    using std::numeric_limits;
    using std::streamsize;
    std::string s1, s2;
    getline(cin, s1);
    getline(cin, s2);
    int result = hrs::commonChild(s1, s2);
    return 0;
}

/*
������� ������ ������ ���������� ����� ��������� ��� ���� ����� s1 � s2,
����� ������� m � n ��������������, ����������� � ���������� ������� ��������
(m+1) * (n+1) �� ���������� �������, ��������, ��� ������� � ������ ���������� �� �������.

� ������� ��������� �������� ��� ����� SUBSEQUENCE � SUBEUENCS:

������������ ����� A{uv} � ������� ��� � ���� ����� ���������� ����� ���������, ���� ���������:

   SUBSEQUENCE
  000000000000
S 010010000000
U 002000010000
B 000300000000
E 000001001001
U 001000010000
E 000001002001
N 000000000300
C 000000000040
S 010010000000

�������� ���������� ����� ��������� UENC.

��������� ������ ��������� ���������� O(mn).
*/