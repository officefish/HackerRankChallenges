/*
Hackerrank::Challenges::SpecialStringAgain
description:https://www.hackerrank.com/challenges/special-palindrome-again
Solution Copyright (c) 2021 Officefish / Techies Team.
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


/*
template <typename C>
struct reverse_wrapper {

    C& c_;
    reverse_wrapper(C& c) : c_(c) {}

    typename C::reverse_iterator begin() { return c_.rbegin(); }
    typename C::reverse_iterator end() { return c_.rend(); }
};

template <typename C, size_t N>
struct reverse_wrapper< C[N] > {

    C(&c_)[N];
    reverse_wrapper(C(&c)[N]) : c_(c) {}

    typename std::reverse_iterator<const C*> begin() { return std::rbegin(c_); }
    typename std::reverse_iterator<const C*> end() { return std::rend(c_); }
};


template <typename C>
reverse_wrapper<C> r_wrap(C& c) {
    return reverse_wrapper<C>(c);
}
*/

vector<int> hrs::reverseRange(char style, const vector<int>& input) {
    vector<int> output;
    switch (style) {
    case 1: {
        size_t counter { input.size() };
        while (counter) {
            --counter;
            output.push_back(input[counter]);
        }
        break;
    }
    case 2: {
        for (size_t i = input.size(); i-- > 0; ) {
            output.push_back(input[i]);
            if (!i) break;
        }
        break;
    }
    case 3: {
        std::vector<int>::const_iterator it;
        for (it = input.begin(); it != input.end(); ++it) {
            output.push_back(*it);
        }
        std::reverse(output.begin(), output.end());
        break;
    }
    case 4: {
        std::reverse_copy(
            input.begin(), input.end(), std::back_inserter(output));
        // std::reverse_copy(
        // std::rbegin(input), std::rend(input), std::begin(output)); (1)
        break;
    }
    case 5: {
        /*
        for (auto i : r_wrap(input)) {
            output.push_back(i);
        }
        */
        break;
    }
    case 6: {
        // C++ 20
#if __cplusplus > 201703L
        std::ranges::reverse_view rv { input };
        for (int i : rv)
            output.push_back(i);
#endif
        break;
    }
    case 7: {
        // C++ 20
#if __cplusplus > 201703L
        for (int i : input | std::views::reverse)
            output.push_back(i);
#endif
        break;
    }
    default:
        output = vector<int>(input.rbegin(), input.rend());
    }
    return output;
}


int day7ArraysChallange() {
    using std::cout;
    using std::endl;
    using std::cin;
    using std::string;
    using std::numeric_limits;
    using std::streamsize;
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = hr::split_string(arr_temp_temp);

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);
        arr[i] = arr_item;
    }

    vector<int> output;
    for (int i = 1; i <= 7; ++i) {
        output = hrs::reverseRange(i, arr);
        cout << "reversed with style (" << i << ") : ";
        if (output.size()) {
            for (auto v : output) {
                cout << v << " ";
            }
            cout << endl;
        } else {
            cout << "Empty, should be compiled with c++20" << endl;
        }
    }
    return 0;
}

/*
Objective
Today, we will learn about the Array data structure. 
Check out the Tutorial tab for learning materials and an instructional video.

Task
Given an array, A, of N integers, print A's elements in reverse order as a single line of space-separated numbers.

Example

A = [1, 2, 3, 4]

Print 4 3 2 1. Each integer is separated by one space.

Input Format

The first line contains an integer, N (the size of our array).
The second line contains N space-separated integers that describe array A's elements.

Constraints

1 <= N <= 1000

1 <= A[i] <= 10000, where A[i] is the i-th integer in the array.

Output Format

Print the elements of array A in reverse order as a single line of space-separated numbers.

Sample Input

4
1 4 3 2
Sample Output

2 3 4 1
*/

/*(1)
Firstly, your usage of the copy_backward() function is riddled with fallacy as (from what I am assuming) 
you are attempting to reverse the order of the elements inputted by the user via copying the elements 
to a new container in the reverse order starting from the end of the new container, which is nugatory 
in reversing the original order as the copy_backward() function merely copies the elements 
to the specified container in the reverse order rather than actually reversing the order of the elements.

Secondly, as for the actual source of the error, the container which you are copying to (reversed) 
is empty which makes it too small to store any passed data, triggering an undefined behavior.

Using the function reverse_copy() will resolve your problem regarding the reversal of the order of elements
and the function back_inserter() will allow you to add elements to an empty container as it constructs 
an iterator which can be used to add elements towards the end of the container.

Replace your copy_backward() function call with the following function call: 
std::reverse_copy(toReverse.begin(), toReverse.end(), std::back_inserter(reversed)).

Furthermore, the pound (#) character in your input is not filtered from the elements 
stored in the toReverse container (which, as per my assumption, must be filtered). 
Add a condition like if (input != '#') before adding the element to the toReverse container
*/
