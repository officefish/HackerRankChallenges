/*
Hackerrank::Challenges::Day12:Inheritance
description:https://www.hackerrank.com/challenges/30-inheritance
or below this page
Solution Copyright (c) 2021 Officefish / Techies Team.
habr::Inheritance https://habr.com/ru/post/445948/
Advanced. Virtual functions, destructor: https://habr.com/ru/post/64280/
crtp: https://ru.wikipedia.org/wiki/Curiously_recurring_template_pattern
*/
#include "./Challenges.h"
#include <algorithm>
#include <numeric>

using std::cin, std::cout, std::endl;
using std::string, std::vector;

class Person {
protected:
	string firstName;
	string lastName;
	int id;
public:
	Person(string firstName, string lastName, int identification) {
		this->firstName = firstName;
		this->lastName = lastName;
		this->id = identification;
	}
	void printPerson() {
		cout << "Name: " << lastName << ", " << firstName << "\nID: " << id << "\n";
	}
};

class Student : public Person {
private:
	vector<int> testScores;
	int8_t toAverage(double);
public:
	Student(string firstName, string lastName, int identification, vector<int> scores)
		: Person(firstName, lastName, identification), testScores(scores) {};
	int8_t calculate();
};

int8_t Student::toAverage(double exactValue) {
	int8_t value = int8_t(exactValue);
	if (value >= 90) return 'O';
	if (value >= 80) return 'E';
	if (value >= 70) return 'A';
	if (value >= 55) return 'P';
	if (value >= 40) return 'D';
	return 'T';
	/*
	switch (value) {
	case 90 ... 100 : return 'O';
	case 80 ... 89  : return 'E';
	case 70 ... 79  : return 'A';
	case 55 ... 69  : return 'P';
	case 40 ... 54  : return 'D';
	default: return 'T';
	} // seems, this is not working statement :(
	*/
}

int8_t Student::calculate() {
	double exactValue = std::accumulate(testScores.begin(), testScores.end(), 0.0) / testScores.size();
	return toAverage(exactValue);
}

int day12InheritanceChallenge() {
	string firstName;
	string lastName;
	int id;
	int numScores;
	cin >> firstName >> lastName >> id >> numScores;
	vector<int> scores;
	for (int i = 0; i < numScores; i++) {
		int tmpScore;
		cin >> tmpScore;
		scores.push_back(tmpScore);
	}
	Student* s = new Student(firstName, lastName, id, scores);
	s->printPerson();
	cout << "Grade: " << s->calculate() << "\n";
	return 0;
}

/*
Task
You are given two classes, Person and Student, where Person is the base class and Student is the derived class.
Completed code for Person and a declaration for Student are provided for you in the editor.
Observe that Student inherits all the properties of Person.

Complete the Student class by writing the following:

A Student class constructor, which has 4 parameters:
A string, firstName.
A string, lastName.
An integer, idNumber.
An integer array (or vector) of test scores, scores
.
A char calculate() method that calculates a Student object's average and returns the grade character representative
of their calculated average:

Grading Scale:
O - 90 <= a <= 100
E - 80 <= a < 90
A - 70 <= a < 80
P - 55 <= a < 70
D - 40 <= a < 55
T - a < 40

Input Format

The locked stub code in the editor reads the input and calls the Student class constructor with the necessary arguments.
It also calls the calculate method which takes no arguments.

The first line contains firstName, lastName, and idNumber, separated by a space. The second line contains the number of test scores.
The third line of space-separated integers describes scores.

Constraints
1 <= length of first name, last name <= 10
length of idNumber = 7
0 <= score <= 100

Output Format
Output is handled by the locked stub code. Your output will be correct if your Student class constructor and calculate()
method are properly implemented.

Sample Input
Heraldo Memelli 8135627
2
100 80

Sample Output
Name: Memelli, Heraldo
ID: 8135627
Grade: O

 Explanation
This student had 2 scores to average: 100 and 80. The student's average grade is (100 + 90) / 2 = 90.
An average grade of 90 corresponds to the letter grade O,
so the calculate() method should return the character'O'.
*/