#include <iostream>
#include <vector>
#include <sstream>

#include ".././pch.h"
#include "./Challenges.h"
#include "./Lists/SinglyLinkedList.h"

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
            ss << node->data;
            node = node->next;
            if (node != nullptr)
                ss << ", ";
        }
        return ss.str();
    }
}

TEST(SinglyListChallengesTests, InsertNodeInHeadTest_01) {

    // initial
    SinglyLinkedList* llist1 = new SinglyLinkedList();
    vector<int> data1{ 4, 5, 6, 7, 8, 9 };
    InsertNodeInRange(llist1, data1);
    // instert
    vector<int> data2{ 3, 2, 1 };
    for (const auto& i : data2) {
        llist1->head = sll::InsertNodeAtHead(llist1->head, i);
    }
    string listStr = ToString(llist1->head);
    string output{ "1, 2, 3, 4, 5, 6, 7, 8, 9" };
    EXPECT_EQ(output, listStr);

    sll::FreeSinglyLinkedList(llist1->head);
}

TEST(SinglyListChallengesTests, InsertNodeInTailTest_01) {

    // initial
    SinglyLinkedList* llist1 = new SinglyLinkedList();
    vector<int> data1{ 1, 2, 3, 4, 5, 6 };
    InsertNodeInRange(llist1, data1);
    // insert
    vector<int> data2{ 7, 8, 9 };
    for (const auto& i : data2) {
        llist1->head = sll::InsertNodeAtTail(llist1->head, i);
    }
    string listStr = ToString(llist1->head);
    string output{ "1, 2, 3, 4, 5, 6, 7, 8, 9" };
    EXPECT_EQ(output, listStr);

    sll::FreeSinglyLinkedList(llist1->head);
}

TEST(SinglyListChallengesTests, InsertNodeAtPositionTest_CorrectInput) {
    // initial
    SinglyLinkedList* llist1 = new SinglyLinkedList();
    vector<int> data1{ 1, 2, 3, 7, 8, 9 };
    InsertNodeInRange(llist1, data1);
    // insert
    vector<int> data2{ 4, 5, 6 };
    for (const auto& i : data2) {
        llist1->head = sll::InsertNodeAtPosition(llist1->head, i, i - 1);
    }
    string listStr = ToString(llist1->head);
    string output{ "1, 2, 3, 4, 5, 6, 7, 8, 9" };
    EXPECT_EQ(output, listStr);

    sll::FreeSinglyLinkedList(llist1->head);
}

TEST(SinglyListChallengesTests, InsertNodeAtPositionTest_NegativeIndex) {
    // initial
    SinglyLinkedList* llist1 = new SinglyLinkedList();
    vector<int> data1{ 1, 2, 3, 4, 5};
    InsertNodeInRange(llist1, data1);
    // insert
    llist1->head = sll::InsertNodeAtPosition(llist1->head, 0, -1);
    string listStr = ToString(llist1->head);
    string output{ "1, 2, 3, 4, 5" };
    EXPECT_EQ(output, listStr);

    sll::FreeSinglyLinkedList(llist1->head);
}

TEST(SinglyListChallengesTests, InsertNodeAtPositionTest_ListSizeIndex) {
    // initial
    SinglyLinkedList* llist1 = new SinglyLinkedList();
    vector<int> data1{ 1, 2, 3, 4, 5 };
    InsertNodeInRange(llist1, data1);
    // insert
    llist1->head = sll::InsertNodeAtPosition(llist1->head, 6, 5);
    string listStr = ToString(llist1->head);
    string output{ "1, 2, 3, 4, 5, 6" };
    EXPECT_EQ(output, listStr);

    sll::FreeSinglyLinkedList(llist1->head);
}
TEST(SinglyListChallengesTests, InsertNodeAtPositionTest_MoreThanSizeIndex) {
    // initial
    SinglyLinkedList* llist1 = new SinglyLinkedList();
    vector<int> data1{ 1, 2, 3, 4, 5 };
    InsertNodeInRange(llist1, data1);
    // insert
    llist1->head = sll::InsertNodeAtPosition(llist1->head, 6, 6);
    string listStr = ToString(llist1->head);
    string output{ "1, 2, 3, 4, 5, 6" };
    EXPECT_EQ(output, listStr);

    sll::FreeSinglyLinkedList(llist1->head);
}

TEST(SinglyListChallengesTests, DeleteNodeTest_CorrectRequest) {
    // initial
    SinglyLinkedList* llist1 = new SinglyLinkedList();
    vector<int> data1{ 1, 9, 2, 9, 3, 9, 4, 9, 5, 9 };
    InsertNodeInRange(llist1, data1);
    // delete
    vector<int> indexes{ 9, 7, 5, 3, 1 };
    for (const auto& i : indexes) {
        llist1->head = sll::DeleteNode(llist1->head, i);
    }
    string listStr = ToString(llist1->head);
    string output{ "1, 2, 3, 4, 5" };
    EXPECT_EQ(output, listStr);

    sll::FreeSinglyLinkedList(llist1->head);
}

TEST(SinglyListChallengesTests, DeleteNodeTest_NegativeIndex) {
    // initial
    SinglyLinkedList* llist1 = new SinglyLinkedList();
    vector<int> data1{ 1, 2, 3, 4, 5};
    InsertNodeInRange(llist1, data1);
    // delete
    llist1->head = sll::DeleteNode(llist1->head, -1);
    string listStr = ToString(llist1->head);
    string output{ "1, 2, 3, 4, 5" };
    EXPECT_EQ(output, listStr);

    sll::FreeSinglyLinkedList(llist1->head);
}

TEST(SinglyListChallengesTests, DeleteNodeTest_OutOfRangeIndex) {
    // initial
    SinglyLinkedList* llist1 = new SinglyLinkedList();
    vector<int> data1{ 1, 2, 3, 4, 5 };
    InsertNodeInRange(llist1, data1);
    // delete
    llist1->head = sll::DeleteNode(llist1->head, 5);
    string listStr = ToString(llist1->head);
    string output{ "1, 2, 3, 4, 5" };
    EXPECT_EQ(output, listStr);
}

TEST(SinglyListChallengesTests, DeleteNodeByValue_Test1) {
    // initial
    SinglyLinkedList* llist1 = new SinglyLinkedList();
    vector<int> data1{ 1, 9, 2, 9, 3, 9, 4, 9, 5, 9 };
    InsertNodeInRange(llist1, data1);
    // delete
    llist1->head = sll::DeleteNodeByValue(llist1->head, 9);
    string listStr = ToString(llist1->head);
    string output{ "1, 2, 3, 4, 5" };
    EXPECT_EQ(output, listStr);

    sll::FreeSinglyLinkedList(llist1->head);

}

TEST(SinglyListChallengesTests, GetNodeData_CorrectInput) {
    // initial
    SinglyLinkedList* llist1 = new SinglyLinkedList();
    vector<int> data1{ 1, 2, 3, 4, 5 };
    InsertNodeInRange(llist1, data1);
    // getData
    int output = sll::GetNodeData(llist1->head, 0);
    EXPECT_EQ(output, 1);
    output = sll::GetNodeData(llist1->head, 1);
    EXPECT_EQ(output, 2);
    output = sll::GetNodeData(llist1->head, 2);
    EXPECT_EQ(output, 3);
    output = sll::GetNodeData(llist1->head, 3);
    EXPECT_EQ(output, 4);
    output = sll::GetNodeData(llist1->head, 4);
    EXPECT_EQ(output, 5);

    sll::FreeSinglyLinkedList(llist1->head);
}

TEST(SinglyListChallengesTests, GetNodeDataFromTail_CorrectInput) {
    // initial
    SinglyLinkedList* llist1 = new SinglyLinkedList();
    vector<int> data1{ 1, 2, 3, 4, 5 };
    InsertNodeInRange(llist1, data1);
    // getDataFromTail
    int output = sll::GetNodeDataFromTail(llist1->head, 4);
    EXPECT_EQ(output, 1);
    output = sll::GetNodeDataFromTail(llist1->head, 3);
    EXPECT_EQ(output, 2);
    output = sll::GetNodeDataFromTail(llist1->head, 2);
    EXPECT_EQ(output, 3);
    output = sll::GetNodeDataFromTail(llist1->head, 1);
    EXPECT_EQ(output, 4);
    output = sll::GetNodeDataFromTail(llist1->head, 0);
    EXPECT_EQ(output, 5);

    sll::FreeSinglyLinkedList(llist1->head);
}

TEST(SinglyListChallengesTests, Reverse_Test1) {
    // initial
    SinglyLinkedList* llist1 = new SinglyLinkedList();
    vector<int> data1{ 5, 4, 3, 2, 1 };
    InsertNodeInRange(llist1, data1);
    // reverse
    llist1->head = sll::Reverse(llist1->head);
    string listStr = ToString(llist1->head);
    string output{ "1, 2, 3, 4, 5" };
    EXPECT_EQ(output, listStr);

    sll::FreeSinglyLinkedList(llist1->head);
}

TEST(SinglyListChallengesTests, CompareLists_Test_True) {
    // initial
    SinglyLinkedList* llist1 = new SinglyLinkedList();
    vector<int> data1{ 1, 2, 3, 4, 5 };
    InsertNodeInRange(llist1, data1);
    SinglyLinkedList* llist2 = new SinglyLinkedList();
    InsertNodeInRange(llist2, data1);
    // compare
    bool equals = sll::CompareLists(llist1->head, llist2->head);
    EXPECT_EQ(true, equals);

    sll::FreeSinglyLinkedList(llist1->head);
    sll::FreeSinglyLinkedList(llist2->head);
}

TEST(SinglyListChallengesTests, CompareLists_Test_False) {
    // initial
    SinglyLinkedList* llist1 = new SinglyLinkedList();
    vector<int> data1{ 1, 2, 3, 4, 5 };
    InsertNodeInRange(llist1, data1);
    SinglyLinkedList* llist2 = new SinglyLinkedList();
    vector<int> data2{ 6, 7, 8, 9, 10 };
    InsertNodeInRange(llist2, data2);
    // compare
    bool equals = sll::CompareLists(llist1->head, llist2->head);
    EXPECT_EQ(false, equals);

    sll::FreeSinglyLinkedList(llist1->head);
    sll::FreeSinglyLinkedList(llist2->head);
}

TEST(SinglyListChallengesTests, SortList_Test1) {
    // initial
    SinglyLinkedList* llist1 = new SinglyLinkedList();
    vector<int> data1{ 1, 6, 2, 7, 3, 8, 4, 9, 5 };
    InsertNodeInRange(llist1, data1);
    llist1->head = sll::Sort(llist1->head);
    // insert
    string listStr = ToString(llist1->head);
    string output{ "1, 2, 3, 4, 5, 6, 7, 8, 9" };
    EXPECT_EQ(output, listStr);

    sll::FreeSinglyLinkedList(llist1->head);
}

TEST(SinglyListChallengesTests, MergeSorted_Test1) {
    // initial
    SinglyLinkedList* llist1 = new SinglyLinkedList();
    vector<int> data1{ 1, 2, 3, 4, 5 };
    InsertNodeInRange(llist1, data1);
    SinglyLinkedList* llist2 = new SinglyLinkedList();
    vector<int> data2{ 6, 7, 8, 9, 10 };
    InsertNodeInRange(llist2, data2);

    // mergeSorted
    SinglyLinkedList* llist3 = new SinglyLinkedList();
    llist3->head = sll::MergeSorted(llist1->head, llist2->head);

    string listStr = ToString(llist3->head);
    string output{ "1, 2, 3, 4, 5, 6, 7, 8, 9, 10" };
    EXPECT_EQ(output, listStr);

    sll::FreeSinglyLinkedList(llist3->head);
}

TEST(SinglyListChallengesTests, RemoveDublicatesInSorted_Test1) {
    // initial
    SinglyLinkedList* llist1 = new SinglyLinkedList();
    vector<int> data1{ 1, 1, 2, 2, 3, 3, 4, 4, 5, 5 };
    InsertNodeInRange(llist1, data1);
    // removeDublicates
    llist1->head = sll::RemoveDuplicatesInSorted(llist1->head);
    string listStr = ToString(llist1->head);
    string output{ "1, 2, 3, 4, 5" };
    EXPECT_EQ(output, listStr);

    sll::FreeSinglyLinkedList(llist1->head);
}

TEST(SinglyListChallengesTests, HasCycle_Test_True) {
    // initial
    SinglyLinkedList* llist1 = new SinglyLinkedList();
    vector<int> data1{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    InsertNodeInRange(llist1, data1);
    // cycling
    llist1->tail->next = llist1->head;
    //hasCycle check
    bool hasCycle = sll::HasCycle(llist1->head);
    EXPECT_EQ(true, hasCycle);
}

TEST(SinglyListChallengesTests, HasCycle_Test_False) {
    // initial
    SinglyLinkedList* llist1 = new SinglyLinkedList();
    vector<int> data1{ 1, 2, 3, 4, 5 };
    InsertNodeInRange(llist1, data1);
    // hasCycle check
    bool hasCycle = sll::HasCycle(llist1->head);
    EXPECT_EQ(false, hasCycle);

    sll::FreeSinglyLinkedList(llist1->head);
}

TEST(SinglyListChallengesTests, FreeList_NotCycled) {
    // initial
    SinglyLinkedList* llist1 = new SinglyLinkedList();
    vector<int> data1{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    InsertNodeInRange(llist1, data1);
    sll::FreeSinglyLinkedList(llist1->head);
    //llist1->tail->next = llist1->head;
    // cycling
    //hasCycle check
    EXPECT_EQ(true, true);
}

TEST(SinglyListChallengesTests, FreeList_Cycled) {
    // initial
    SinglyLinkedList* llist1 = new SinglyLinkedList();
    vector<int> data1{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    InsertNodeInRange(llist1, data1);

    llist1->tail->next = llist1->head;
    sll::FreeSinglyLinkedList(llist1->head);
    EXPECT_EQ(true, true);
}





