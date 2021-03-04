/*
	Hackerrank::Challenges::RansomNote
	description: https://www.hackerrank.com/challenges/ctci-ransom-note
*/ 


#include "Challenges.h"

#include "HackerRankMiscellaneous.h"
using hr::split_string;

using std::cout;
using std::endl;
using std::cin;
using std::ofstream;

#include <unordered_map>
using std::unordered_map;
// https://en.cppreference.com/w/cpp/container/unordered_map


bool hrs::checkMagazine(vector<string> magazine, vector<string> note) {
    
    bool status = true;
    unordered_map<string, int> words;
    
    for (auto& it : magazine)
        words[it]++;

    for (auto& it : note) {
        if (words[it] > 0)
            words[it]--;
        else
        {
            status = false;
            break;
        }
    }
    
    return status;
}

int ransomNoteChallenge() {
    
    string mn_temp;
    getline(cin, mn_temp);

    vector<string> mn = split_string(mn_temp);

    int m = stoi(mn[0]);

    int n = stoi(mn[1]);

    string magazine_temp_temp;
    getline(cin, magazine_temp_temp);

    vector<string> magazine_temp = split_string(magazine_temp_temp);

    vector<string> magazine(m);

    for (int i = 0; i < m; i++) {
        string magazine_item = magazine_temp[i];

        magazine[i] = magazine_item;
    }

    string note_temp_temp;
    getline(cin, note_temp_temp);

    vector<string> note_temp = split_string(note_temp_temp);

    vector<string> note(n);

    for (int i = 0; i < n; i++) {
        string note_item = note_temp[i];

        note[i] = note_item;
    }

    hrs::checkMagazine(magazine, note) ? cout << "Yes" : cout << "No";
    cout << endl;

    return 0;
}