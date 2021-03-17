/*
Hackerrank::Challenges::Day18:QueuesAndStacks
description: https://www.hackerrank.com/challenges/cpp-maps
Solution Copyright(c) 2021 Officefish / Techies Team.
*/
#include "./Challenges.h"
#include <map>

inline void AddMark(std::map<std::string, int32_t>* map,
	const std::string student, const int32_t mark) {
	(*map)[student] += mark;
}
inline void EraseMarks(std::map<std::string, int32_t>* map,
	const std::string student) {
	map->erase(student);
}
inline void PrintMarks(std::map<std::string, int32_t>* map,
	const std::string student) {
	std::cout << (*map)[student] << std::endl;
}

int mapChallenge() {
	using std::cin;
	int32_t q, c, m; // queue, command, mark
	std::string s; // student name
	std::map<std::string, int32_t> map;

	cin >> q;
	for (int32_t i = 0; i < q; ++i) {
		cin >> c >> s;
		switch (c) {
		case 1:
			cin >> m;
			AddMark(&map, s, m);
			break;
		case 2:
			EraseMarks(&map, s);
			break;
		case 3:
			PrintMarks(&map, s);
			break;
		}
	}
	return 0;
}