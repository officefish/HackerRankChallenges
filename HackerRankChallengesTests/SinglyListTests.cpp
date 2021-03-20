#include <iostream>
#include <vector>
#include <sstream>

#include "pch.h"
#include "../HackerRankChallenges/SinglyLinkedList.h"


namespace {
    using std::cin, std::cout, std::endl;
    using std::max;
    using std::streamsize, std::numeric_limits;
    using sll::SinglyLinkedList, sll::SinglyLinkedListNode;
    using std::vector, std::string;

    void InsertNodeInRange(SinglyLinkedList* llist, const vector<int>& datas) {
        for (const auto& i : datas) {
            llist->InsertNode(i);
        }
    }

    string ToString(SinglyLinkedListNode* node) {
        std::stringstream ss;
        while (node != nullptr) {
            ss << node->data << ", ";
            node = node->next;
        }
        return ss.str();
    }
}

TEST(SinglyListChallengesTests, InsertNodeInHeadTest_01) {

    // initial
    SinglyLinkedList* llist1 = new SinglyLinkedList();
    vector<int> data1{ 4, 5, 6, 7, 8, 9 };
    InsertNodeInRange(llist1, data1);

    // dynamicInput
    //SinglyLinkedList* llist2;
    SinglyLinkedListNode* llist2_head = nullptr;
    vector<int> data2{ 3, 2, 1 };
    for (const auto& i : data2) {
        llist2_head = sll::InsertNodeAtHead(llist1->head, i);
    }
    string listStr = ToString(llist2_head);
    string output{ "1, 2, 3, 4, 5, 6, 7, 8, 9 " };
    EXPECT_EQ(output, listStr);
}