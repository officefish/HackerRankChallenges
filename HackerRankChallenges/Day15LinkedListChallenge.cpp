/*
Hackerrank::Challenges::Day12:Inheritance
description:https://www.hackerrank.com/challenges/30-linked-list/problem
Solution Copyright (c) 2021 Officefish / Techies Team.
https://grisha.org/blog/2013/04/02/linus-on-understanding-pointers/
*/

#include "./Challenges.h"
#include <iostream>
#include <cstddef>
using namespace std;
class Node
{
public:
    int data;
    Node* next;
    Node(int d) {
        data = d;
        next = NULL;
    }
};
class Solution {
public:

    Node* insert(Node* head, int data) { //(*1)
        Node** pp = &head;
        while (*pp) pp = &((*pp)->next);
        *pp = new Node(data);
        return head;
    }

    void display(Node* head)
    {
        Node* start = head;
        while (start) {
            cout << start->data << " ";
            start = start->next;
        }
    }
};

int day15LinkedListChallenge() {
    Node* head = NULL;
    Solution mylist;
    int T, data;
    cin >> T;
    while (T-- > 0) {
        cin >> data;
        head = mylist.insert(head, data);
    }
    mylist.display(head);
    return 0;
}

/* (1)
It basically gets rid of the special treatment for the head: If you take a look at other code examples,
there is always the special case if (head == nullptr) where you have to distinct between changing the head pointer
or the next pointer of some element. So pp points to the pointer, that has to be changed
(where the new element is inserted), regardless whether the list was empty before or not.
The article I linked in that comment does the same, but for deletion of an element in a linked list.
*/

/*
A Node class is provided for you in the editor. A Node object has an integer data field, data,
and a Node instance pointer, next, pointing to another node (i.e.: the next node in the list).

A Node insert function is also declared in your editor. It has two parameters: a pointer, head,
pointing to the first node of a linked list, and an integer, data,
that must be added to the end of the list as a new Node object.

Task
Complete the insert function in your editor so that it creates a new Node (pass data as the Node constructor argument)
and inserts it at the tail of the linked list referenced by the head parameter.
Once the new node is added, return the reference to the head node.

Note: The head argument is null for an empty list.

Input Format
The first line contains T, the number of elements to insert.
Each of the next T lines contains an integer to insert at the end of the list.

Output Format
Return a reference to the head node of the linked list.

Sample Input

STDIN   Function
-----   --------
4       T = 4
2       first data = 2
3
4
1       fourth data = 1

Sample Output
2 3 4 1

*/