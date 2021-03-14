/*
Hackerrank::Challenges::JumpingOnTheClouds
description:https://www.hackerrank.com/challenges/30-operators
*/


#include "Challenges.h"

#include "HackerRankMiscellaneous.h"
using hr::output_str;
using hr::split_string;

using std::cout;
using std::endl;
using std::cin;
using std::streamsize;
using std::numeric_limits;

void solve(double meal_cost, int tip_percent, int tax_percent) {

    double m_tax_percent, m_tip_percent;

    m_tax_percent = static_cast<double>(tax_percent) / 100;
    m_tip_percent = static_cast<double>(tip_percent) / 100;

    m_tax_percent *= meal_cost;
    m_tip_percent *= meal_cost;

    // int total_cost = static_cast<int> (meal_cost + m_tax_percent + m_tip_percent) inaccurate!;
    // also do not use because of warning 4244
    // use floor operator instead!

    int total_cost = int(floor(meal_cost + m_tax_percent + m_tip_percent));

    //cout << "The total meal cost is " << total_cost << " dollars.";
    cout << total_cost << endl;

}

int day3OperatorsChallenge()
{
    double meal_cost;
    cin >> meal_cost;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int tip_percent;
    cin >> tip_percent;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int tax_percent;
    cin >> tax_percent;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    solve(meal_cost, tip_percent, tax_percent);

    return 0;
}