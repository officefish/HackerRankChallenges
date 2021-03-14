/*
Hackerrank::Challenges::Day8:DictionariesandMaps
description:https://www.hackerrank.com/challenges/30-dictionaries-and-maps/
or below this page
Solution Copyright (c) 2021 Officefish / Techies Team.
*/

#include <string>
#include <map>
#include <stdexcept>
#include <unordered_map>
#include <variant>

#include "./Challenges.h"

int day8MapsChallenge() {
    using std::cout;
    using std::endl;
    using std::cin;
    using std::numeric_limits;
    using std::streamsize;
    using std::unordered_map;
    using std::string;

    int32_t q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    string user;
    int32_t phoneNumber;
    unordered_map<string, int32_t> phoneBook;
    //Container container(0);
    for (int32_t i = 0; i < q; ++i) {
        cin >> user >> phoneNumber;
        //cout << "name:" << user << ", phone: " << phoneNumber << endl;
        if (!phoneBook[user]) {
            phoneBook[user] = phoneNumber;
        }
    }
    while (cin >> user) {
        if (phoneBook.find(user) != phoneBook.end()) {
            cout << user << "=" << phoneBook.find(user)->second << endl;
        } else {
            cout << "Not found" << endl;
        }
    }
    return 0;
}

/*
class Container {
public:
    Container(int8_t initMode);
    void addPair(string name, int32_t number);
    int8_t mode;
private:
    std::_Container_base* _container;
    std::map<string, int32_t> _map;
    std::unordered_map<string, int32_t> _umap;

};

Container::Container(int8_t m) {
    mode = m >= 0 && m <= 2 ? m : 0;
    switch (mode) {
    case 0:
        //_container should be Map;
        break;
    case 1:
        //_container should be Dictionary;
        break;
    case 2:
        //_container should be HashMap;
        break;
    }
}
*/

//void Container::addPair(string name, int32_t number) {

//}


/*
Objective
Today, we're learning about Key-Value pair mappings using a Map or Dictionary data structure.
Check out the Tutorial tab for learning materials and an instructional video!

Task
Given 'n' names and phone numbers, assemble a phone book that maps friends' names to their respective phone numbers.
You will then be given an unknown number of names to query your phone book for.
For each 'name' queried, print the associated entry from your phone book on a new line in the form name=phoneNumber;
if an entry for 'name' is not found, print Not found instead.

Note: Your phone book should be a Dictionary/Map/HashMap data structure.

Input Format

The first line contains an integer 'n', denoting the number of entries in the phone book.
Each of the  subsequent lines describes an entry in the form of 2 space-separated values on a single line.
The first value is a friend's name, and the second value is an 8-digit phone number.

After the n lines of phone book entries, there are an unknown number of lines of queries.
Each line (query) contains a  to look up, and you must continue reading lines until there is no more input.

Note: Names consist of lowercase English alphabetic letters and are first names only.

Constraints

1 <= n <= 10^5
1 <= queries <= 10^5

Output Format

On a new line for each query, print Not found if the name has no corresponding entry in the phone book;
otherwise, print the full 'name' and 'phoneNumber' in the format name=phoneNumber.

Sample Input

3
sam 99912222
tom 11122222
harry 12299933
sam
edward
harry

Sample Output

sam=99912222
Not found
harry=12299933
Explanation

We add the following n = 3 (Key,Value) pairs to our map so it looks like this:

phoneBook = { {sam, 99912222}, {tom, 11122222}, {harry, 12299933} }

We then process each query and print key=value if the queried  is found in the map; otherwise, we print Not found.

Query 0: sam
Sam is one of the keys in our dictionary, so we print sam=99912222.

Query 1: edward
Edward is not one of the keys in our dictionary, so we print Not found.

Query 2: harry
Harry is one of the keys in our dictionary, so we print harry=12299933.
*/