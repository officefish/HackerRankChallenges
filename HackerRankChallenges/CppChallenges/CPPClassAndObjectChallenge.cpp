/*
Hackerrank::Challenges::Day12:Inheritance
description: https://www.hackerrank.com/challenges/classes-objects
Solution Copyright (c) 2021 Officefish / Techies Team.
*/
#include ".././Challenges.h"

class Student {
private:
	std::vector<int16_t> scores;
public:
	void input();
    int16_t calculateTotalScore();
};
void Student::input() {
    int16_t score;
    for (int16_t i = 0; i < 5; ++i) {
        std::cin >> score;
        scores.push_back(score);
    }
}
int16_t Student::calculateTotalScore() {
    int16_t t{ 0 };
    for (auto s : scores) t += s;
    return t;
}

/*
class Student {
  private:
    int scores[5];
    int sum;
  public:
    Student() : sum(0) {}
    int calculateTotalScore() {return sum;}
    void input() {
        for(int i=0; i<5; i++) {
            cin >> scores[i];
            sum+=scores[i];
        }
    }
};

*/

int classAndObjectChallenge() {
    int16_t n; // number of students
    std::cin >> n;
    std::vector<Student> s; // an array of n students
    for (int16_t i = 0; i < n; i++) {
        Student _s;
        _s.input();
        s.push_back(_s);
    }
    // calculate kristen's score
    int kristen_score = s[0].calculateTotalScore();
    // determine how many students scored higher than kristen
    int count = 0;
    for (int i = 1; i < n; i++) {
        int total = s[i].calculateTotalScore();
        if (total > kristen_score) {
            count++;
        }
    }
    // print result
    std::cout << count;
    return 0;
}