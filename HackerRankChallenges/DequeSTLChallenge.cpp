/*
    Hackerrank::Challenges::DequeSTL
    description: https://www.hackerrank.com/challenges/deque-stl
*/
#include <algorithm>
#include <deque>
#include "Challenges.h"

using std::cout;
using std::endl;
using std::cin;
using std::deque;
using std::sort;
using std::begin;
using std::end;
//using std::distance;


// A Dequeue (Double ended queue) based method for printing maixmum element of
// all subarrays of size k
void printKMax(int arr[], int n, int k) {

    deque<int>  Qi(k);                                          // (1)
    int i;

    for (i = 0; i < k; ++i)                                     // (2)
    {
        while ((!Qi.empty()) && arr[i] >= arr[Qi.back()])       // (3)
            Qi.pop_back();                                      // (4)

        Qi.push_back(i);                                        // (5)
    }

    for (; i < n; ++i)                                          // (6)
    {
        cout << arr[Qi.front()] << " ";                         // (7)

        while ((!Qi.empty()) && Qi.front() <= i - k)            // (8)
            Qi.pop_front();                                     // (9)

        while ((!Qi.empty()) && arr[i] >= arr[Qi.back()])       // (10)
            Qi.pop_back();                                      // (11)

        Qi.push_back(i);                                        // (12)
    }

    cout << arr[Qi.front()] << endl;                            // (13)

/*
    (1)     Create a Double Ended Queue, Qi that will store indexes of array elements
            The queue will store indexes of useful elements in every window and it will
            maintain decreasing order of values from front to rear in Qi, i.e.,
            arr[Qi.front[]] to arr[Qi.rear()] are sorted in decreasing order.

    (2)     Process first k (or first window) elements of array.

    (3)     For very element, the previous smaller elements are useless so remove them from Qi
    (4)     Remove from rear

    (5)     Add new element at rear of queue

    (6)     Process rest of the elements, i.e., from arr[k] to arr[n-1]

    (7)     The element at the front of the queue is the largest element of previous window, so print it

    (8)     Remove the elements which are out of this window
    (9)     Remove from front of queue

    (10)    Remove all elements smaller than the currently being added element (remove useless elements)
    (11)    Remove from back of queue

    (12)    Add current element at the rear of Qi

    (13)    Print the maximum element of last window
*/

    /*
        Brutforce:

        int subsCount = n - k + 1;

        deque<deque<int>> data(subsCount);
        deque<int> output = deque<int>();

        for (int i = 0; i < subsCount; ++i) {

            data[i] = deque<int>();

            for (int j = i; j < k + i; ++j) {
                data[i].push_back(arr[j]);
            }

            sort(begin(data[i]), end(data[i]));
            output.push_back(data[i][data[i].size() - 1]);

        }

        for (auto v : output) {
            cout << v << " ";
        }
        cout << endl;
    */



}

/* Solution with templates and recursion */
#include <future>

template<typename T>
T* FindMax(T* begin, T* end)
{
    int half = (begin - end) / 2;
    T* res = nullptr;
    if (half > 512)
    {
        std::future<T*> res1 = std::async(FindMax<T>, begin, begin + half);
        std::future<T*> res2 = std::async(FindMax<T>, begin, begin + half);
        res = *res1.get() > * res2.get() ? res1.get() : res2.get();
    }
    else
    {
        res = std::max_element(begin, end);
    }
    return res;
}

template<typename T>
void PrintKMaxTemplate(T arr[], int n, int k) {
    T* ptr = arr;
    T* maxPtr = FindMax<T>(ptr, ptr + k);
    cout << *maxPtr;
    ptr += k;
    for (; ptr < arr + n; ptr++) {
        if (*ptr >= *maxPtr) {
            maxPtr = ptr;
        }
        if (ptr - k == maxPtr) {
            maxPtr = FindMax<T>(ptr - k + 1, ptr + 1);
        }
        cout << " " << *maxPtr;
    }
    cout << endl;
}

int dequeSTLChallenge() {

    int t;
    cin >> t;
    while (t > 0) {
        int n, k;
        cin >> n >> k;
        int i;
        int* arr = new int[n];
        for (i = 0; i < n; i++)
            cin >> arr[i];
        //PrintKMaxTemplate(arr, n, k);
        printKMax(arr, n, k);
        delete[] arr;
        t--;
    }
    return 0;
}