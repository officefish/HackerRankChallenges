/*
Hackerrank::Challenges::TemplateChallenge
description: https://www.hackerrank.com/challenges/c-class-templates
Solution Copyright(c) 2021 Officefish / Techies Team.
*/
#include ".././Challenges.h"

/* for better performance
// The static start_up fumction speeds up cout and #define changes endl to '\n',
// that prevents flushing buffer for each line.

int start_up() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}
int static r = start_up();
#define endl '\n';
*/

template <class T> class AddElements {
    T element;
public:
    AddElements(T i) : element(i) {}
    T add(T i) { return element + i; }
};

template <> class AddElements <std::string> {
    std::string element;
public:
    AddElements(std::string i) : element(i) {}
    std::string concatenate(std::string element2) { return element + element2; }
};

int classTemplateChallenge() {
    using std::cin, std::cout, std::endl;
    using std::string;

    int n, i;
    cin >> n;
    for (i = 0; i < n; i++) {
        string type;
        cin >> type;
        if (type == "float") {
            double element1, element2;
            cin >> element1 >> element2;
            AddElements<double> myfloat(element1);
            cout << myfloat.add(element2) << endl;
        }
        else if (type == "int") {
            int element1, element2;
            cin >> element1 >> element2;
            AddElements<int> myint(element1);
            cout << myint.add(element2) << endl;
        }
        else if (type == "string") {
            string element1, element2;
            cin >> element1 >> element2;
            AddElements<string> mystring(element1);
            cout << mystring.concatenate(element2) << endl;
        }
    }
    return 0;
}