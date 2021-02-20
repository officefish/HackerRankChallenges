#include "HackerRankMiscellaneous.h"
#include <bits/stdc++.h>

using std::min;
using std::cout;
using std::endl;
using std::not1;
using std::ptr_fun;



vector<string> hr::split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [](const char& x, const char& y) {
        return x == y and x == ' ';
        });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}

string hr::output_str(const char* path) {
    char* pathAppData = nullptr;
    size_t sz = 0;

    errno_t err = _dupenv_s(&pathAppData, &sz, path);

    if (err != 0) {
        cout << "_depenv_s failed with error: " << err << endl;
        exit(1);
    }
    else if (pathAppData == nullptr) {
        cout << "_depenv_s char* is still nullptr" << endl;
        exit(2);
    }

    string hackerrank_output_str(pathAppData);
    free(pathAppData);

    return hackerrank_output_str;

}

string hr::ltrim(const string& str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string hr::rtrim(const string& str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
