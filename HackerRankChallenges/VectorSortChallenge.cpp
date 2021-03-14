/*
Hackerrank::Challenges:CPP::VectorSort
description: https://www.hackerrank.com/challenges/rectangle-area
*/

#include <algorithm>
#include "Challenges.h"

using std::cout;
using std::endl;
using std::cin;
using std::vector;
using std::sort;

void vectorLooping(vector<int>&);

int vectorSortChallenge() {

	int length;
	cin >> length;

	vector<int> numbers(length);

	for (int i = 0; i < length; ++i) {
		cin >> numbers[i];
	}

	sort(numbers.begin(), numbers.end());

	for (auto num : numbers) {
		cout << num << " ";
	}

	cout << endl;

	//vectorLooping(numbers);

	return 0;
}

/*
	Vectors are same as dynamic arrays with the ability to resize itself automatically when an element is inserted or deleted,
	with their storage being handled automatically by the container.
	Vector elements are placed in contiguous storage so that they can be accessed and traversed using iterators.
	In vectors, data is inserted at the end. Inserting at the end takes differential time,
	as sometimes there may be a need of extending the array.
	Removing the last element takes only constant time because no resizing happens.
	Inserting and erasing at the beginning or in the middle is linear in time.

	Certain functions associated with the vector are:

	Iterators

	begin() – Returns an iterator pointing to the first element in the vector
	end() – Returns an iterator pointing to the theoretical element that follows the last element in the vector
	rbegin() – Returns a reverse iterator pointing to the last element in the vector (reverse beginning). It moves from last to first element
	rend() – Returns a reverse iterator pointing to the theoretical element preceding the first element in the vector (considered as reverse end)
	cbegin() – Returns a constant iterator pointing to the first element in the vector.
	cend() – Returns a constant iterator pointing to the theoretical element that follows the last element in the vector.
	crbegin() – Returns a constant reverse iterator pointing to the last element in the vector (reverse beginning). It moves from last to first element
	crend() – Returns a constant reverse iterator pointing to the theoretical element preceding the first element in the vector (considered as reverse end)

*/

void vectorLooping(vector<int>&g1) {


	cout << "Output of begin and end: ";
	for (auto i = g1.begin(); i != g1.end(); ++i)
		cout << *i << " ";

	cout << "\nOutput of cbegin and cend: ";
	for (auto i = g1.cbegin(); i != g1.cend(); ++i)
		cout << *i << " ";

	cout << "\nOutput of rbegin and rend: ";
	for (auto ir = g1.rbegin(); ir != g1.rend(); ++ir)
		cout << *ir << " ";

	cout << "\nOutput of crbegin and crend : ";
	for (auto ir = g1.crbegin(); ir != g1.crend(); ++ir)
		cout << *ir << " ";

}