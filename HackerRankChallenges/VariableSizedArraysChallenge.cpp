/*
    Hackerrank::Challenges::VariableSizedArrays
    https://www.hackerrank.com/challenges/variable-sized-arrays
*/

#include "Challenges.h"


#include<bits/stdc++.h>
using std::cout;
using std::cin;
using std::endl;


int VariableSizedArraysChallenge (){

    int n, q, r, v, i, j;

    cin >> n >> q;

    int **data;                         // (1)
    data = new int * [n];               // (2)
    
    int* output = new int[q];
    
    for (i = 0; i < n; ++i) {           
        cin >> r;
        data[i] = new int[r];           // (3)
        for (j = 0; j < r; ++j) {
            cin >> v;
            data[i][j] = v;
        }
    }

    for (i = 0; i < q; ++i) {
        cin >> r >> v;
        output[i] = data[r][v];
    }

    for (i = 0; i < n; i++) {           // (4) 
        delete[] data[i];
    }
    delete[] data;

    for (i = 0; i < q; ++i) {
        cout << output[i] << endl;
    }

    delete[]output;


    /*
        (1) To access a two-dimensional array, declare a variable 'data' of type pointer to pointer to type
            (in this case it is a pointer to a pointer to an int).

        (2) The variable is initialized with the new operator, which allocates memory for an array of pointers to int.

        (3) In the loop, each element of the array of pointers is initialized with the new operator, which allocates memory for an array of int type.

        (4) Memory is freed in the exact reverse order: first, arrays of int values are destroyed, and then the array of pointers is destroyed.

    */

    return 0;
}