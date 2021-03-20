/*
Hackerrank::Challenges::Day12:Inheritance
description: https://www.hackerrank.com/challenges/box-it/
Solution Copyright (c) 2021 Officefish / Techies Team.
*/
#include "./Challenges.h"

class Box {
private:
    int16_t  _length, _breadth, _height;
    long long _volume{ 0 };
public:
    Box() : _length(0), _breadth(0), _height(0) {}
    Box(int16_t l, int16_t b, int16_t h) : _length(l), _breadth(b), _height(h) {}
    Box(const Box&);
    Box NewBox(int16_t l, int16_t b, int16_t h) {
        return Box(l, b, h);
    }
    int16_t getLength() { return _length; }
    int16_t getBreadth() { return _breadth; }
    int16_t getHeight() { return _height; }
    long long CalculateVolume() { return 1LL * _length * _breadth * _height; }
    friend std::ostream& operator<<(std::ostream& os, const Box& b);
    friend bool operator<(const Box& b1, const Box& b2);
    friend bool operator>(const Box& b1, const Box& b2);
};
Box::Box(const Box& b) {
    this->_length = b._length;
    this->_breadth = b._breadth;
    this->_height = b._height;
}
inline std::ostream& operator<<(std::ostream& os, const Box& b) {
    os << b._length << " " << b._breadth << " " << b._height;
    return os;
}
inline bool operator<(const Box& b1, const Box& b2) {
    bool output = false;
    if (b1._length < b2._length) {
        output = true;
    }
    else if (b1._breadth < b2._breadth
        && b1._length == b2._length) {
        output = true;
    }
    else if (b1._height < b2._height
        && b1._length == b2._length
        && b1._breadth == b2._breadth) {
        output = true;
    }
    return output;
}
inline bool operator>(const Box& b1, const Box& b2) {
    return b2._volume < b1._volume;
}

int boxItChallenge() {
	using std::cin, std::cout, std::endl;
	int n;
	cin >> n;
	Box temp;
	for (int i = 0; i < n; i++)	{
		int type;
		cin >> type;
		if (type == 1)
			cout << temp << endl;
		if (type == 2) {
			int l, b, h;
			cin >> l >> b >> h;
			Box NewBox(l, b, h);
			temp = NewBox;
			cout << temp << endl;
		}
		if (type == 3) {
			int l, b, h;
			cin >> l >> b >> h;
			Box NewBox(l, b, h);
			if (NewBox < temp) {
				cout << "Lesser\n";
			} else {
				cout << "Greater\n";
			}
		}
		if (type == 4) {
			cout << temp.CalculateVolume() << endl;
		}
		if (type == 5) {
			Box NewBox(temp);
			cout << NewBox << endl;
		}
	}
    return 0;
}
