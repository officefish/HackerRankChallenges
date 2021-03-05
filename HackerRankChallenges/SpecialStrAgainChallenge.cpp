/*
Hackerrank::Challenges::SpecialStringAgain
description:https://www.hackerrank.com/challenges/special-palindrome-again
*/
#include <string>
#include "./Challenges.h"
#include "./HackerRankMiscellaneous.h"

size_t partialSum(const size_t);
bool allCharactersSame(const std::string&);
bool allCharactersSameExceptMiddle(std::string*);
int countValidExceptMiddle(const size_t, const size_t, const std::string&);

using std::cout;
using std::endl;
using std::cin;
using std::streamsize;
using std::numeric_limits;
using std::string;

using hr::split_string;

size_t inline partialSum(size_t size) {
    if (size == 1) return size;
    size_t result = { 0 };
    for (size_t i = 1; i <= size; ++i) { result += i; }
    return result;
}

bool inline allCharactersSame(const std::string& s) {
    return (s.find_first_not_of(s[0]) == string::npos);
}

bool allCharactersSameExceptMiddle(string* s) {
    if ((*s).length() % 2 == 0) {
        return false;
    } else {
        size_t index = (((*s).length() + 1) / 2) - 1;
        (*s).erase(index, 1);
        return (allCharactersSame(*s));
    }
    return false;
}

int countValidExceptMiddle(
    const size_t index, const size_t sameCounter, const string& str) {
    int result = { 0 };
    size_t startIndex, endIndex;

    for (size_t i = sameCounter; i > 0; --i) {
        startIndex = index - i;
        endIndex = (i * 2) + 1;
        if (endIndex < str.size()) {
            string subStr = str.substr(startIndex, endIndex);
            if (allCharactersSameExceptMiddle(&subStr)) {
                ++result;
            }
        }
    }
    return result;
}

int64_t hrs::substrCount(size_t n, string s) {
    int64_t output = { 0 };

    if (n == 1) {
        ++output;
        return output;
    }

    size_t sameCharsCounter = { 1 };
    char character;
    for (size_t i = 0; i < n; ++i) {
        if (i == 0) continue;
        character = s[i];
        if (character == s[i - 1]) {
            ++sameCharsCounter;
            if (i + 1 < n) {
                continue;
            } else {
                output += partialSum(sameCharsCounter);
                return output;
            }
        } else {
            output += partialSum(sameCharsCounter);
            if (i + 1 == n) {
                ++output;
            } else {
                output += countValidExceptMiddle(i, sameCharsCounter, s);
                sameCharsCounter = 1;
            }
        }
    }
    return output;
}


// Brutforce O(n^3)
/*
long hrs::substrCount(int n, string s) {
    string currentStr;
    int counter;
    long output = 0;

    for (int i = 0; i < n; ++i) {
        counter = n - 1;
        while (counter >= i) {
            currentStr = s.substr(i, n - counter);
            if (allCharactersSame(currentStr)) {
                ++output;
            } else if (allCharactersSameExceptMiddle(currentStr)) {
                ++output;
            }
            --counter;
        }
    }
    return output;
}
*/

int specialStrAgainChallenge() {
    int64_t result = hrs::substrCount(10, "aaaabaaaab");
    cout << "result: " << result;
    /*
    
    ios_base::sync_with_stdio(false);
	cin.tie(NULL); 
    
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string s;
    getline(cin, s);

    long result = hrs::substrCount(n, s);
    cout << result << endl;
    */

    return 0;
}


/*
The simplest solution is to check the given condition for every possible substrings and count the valid ones.
This approach will take O(n^3) complexity.

To do this in a little better way we can store the cumulative sum of the occurrences of each character
in the string and again count the valid ones by using memoization. This approach will take O(n^2) complexity.

To solve it efficiently we have to consider 2 Cases:

Case 1: All special substrings have same character:

We can handle this case by simply counting the same continuous character 
and using formula K * (K + 1) / 2 (total number of substring possible : Here K is count of Continuous same char).

Case2 : All special substrings have same character except one in the middle:

We can handle this case by storing count of same character in another temporary array called same_char_count[n] 
of size n and pick each character one-by-one and check its previous and forward character are equal or not, 
if equal then there are minimum between same_char_count[previous] and same_char_count[forward] substring(s) possible.

So, we count total substrings from both cases.

*/

/*
int solution()
{
    int n,c,i=0,j,ans=0;
    cin>>n;

    string s;
    cin>>s;

    int same_char_count[n]={0};

    while(i<n) {
        j=i+1,c=1;
        while(j<n && s[i]==s[j]) {
            ++j,++c;
        }

        //total substrings which have all same char(s)
        ans+=(c*(c+1))>>1;
        same_char_count[i]=c;
        i=j;
    }

    for(j=1;j<n-1;++j) {
        if(s[j]==s[j-1]) {
            same_char_count[j] = same_char_count[j-1];
        }

        //odd length substr(s) which has middle element diiferent
        if(s[j-1]==s[j+1] && s[j]!=s[j-1]) {
            ans += min(same_char_count[j-1], same_char_count[j+1]);
        }
    }
    cout<<ans<<endl;

    return 0;
}
*/


