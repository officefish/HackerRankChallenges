/*
Hackerrank::Challenges:Sorting:Comparator
description: https://www.hackerrank.com/challenges/ctci-comparator-sorting
*/


#include "Challenges.h"

#include "HackerRankMiscellaneous.h"
using hr::split_string;

using std::cout;
using std::endl;
using std::cin;
using std::streamsize;
using std::numeric_limits;
using std::sort;
using std::string;

class Player {
public:
    string name = { "" };
    int score = { 0 };

    //void name(string t_name) { m_name = t_name; }
    //string name() { return m_name; }

    //void score(int t_score) { m_score = t_score; }
    //int score() { return m_score; }

private:
    //int m_score;
    //string m_name;
    
};

class Checker {
public:
    // complete this method
    static int comparator(Player a, Player b);


};

int Checker::comparator(Player a, Player b) {
    
    int index = { 0 };

    if (a.score - b.score) {
        index = a.score - b.score > 0 ? 1 : -1;
    }

    if (!index) {
        return a.name.compare(b.name) > 0 ? -1 : 1;
    }

    return index;
}



bool compare(Player a, Player b) {
    if (Checker::comparator(a, b) == -1)
        return false;
    return true;
}

int comparatorSortChallenge() {
    int n;
    cin >> n;
    vector< Player > players;
    string name;
    int score;
    for (int i = 0; i < n; i++) {
        cin >> name >> score;
        Player player;
        player.name = name, player.score = score;
        players.push_back(player);
    }
    sort(players.begin(), players.end(), compare);
    for (int i = 0; i < players.size(); i++) {
        cout << players[i].name << " " << players[i].score << endl;
    }
    return 0;
}