#include "./slltests.h"

namespace slltests {

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

    TEST(SinglyListChallengesTests, ReverseBetween_Test1) {
        // initial
        SinglyLinkedList* llist1 = new SinglyLinkedList();
        vector<int> data1{ 5, 4, 3, 2, 1 };
        InsertNodeInRange(llist1, data1);
        // reverse
        llist1->head = sll::ReverseBetween(llist1->head, 2, 5);
        string listStr = ToString(llist1->head);
        string output{ "5, 1, 2, 3, 4" };
        EXPECT_EQ(output, listStr);

        sll::FreeSinglyLinkedList(llist1->head);
    }

    TEST(SinglyListChallengesTests, ReverseBetween_NegativeIndex) {
        // initial
        SinglyLinkedList* llist1 = new SinglyLinkedList();
        vector<int> data1{ 5, 4, 3, 2, 1 };
        InsertNodeInRange(llist1, data1);
        // reverse
        llist1->head = sll::ReverseBetween(llist1->head, -1, 5);
        string listStr = ToString(llist1->head);
        string output{ "1, 2, 3, 4, 5" };
        EXPECT_EQ(output, listStr);

        sll::FreeSinglyLinkedList(llist1->head);
    }

    TEST(SinglyListChallengesTests, ReverseBetween_OutOfRangeIndex) {
        // initial
        SinglyLinkedList* llist1 = new SinglyLinkedList();
        vector<int> data1{ 5, 4, 3, 2, 1 };
        InsertNodeInRange(llist1, data1);
        // reverse
        llist1->head = sll::ReverseBetween(llist1->head, 1, 7);
        string listStr = ToString(llist1->head);
        string output{ "1, 2, 3, 4, 5" };
        EXPECT_EQ(output, listStr);

        sll::FreeSinglyLinkedList(llist1->head);
    }


    TEST(SinglyListChallengesTests, Partition_Test1) {
        // initial
        SinglyLinkedList* llist1 = new SinglyLinkedList();
        vector<int> data1{ 1, 2, 4, 4, 5, 2, 3, 4, 5 };
        InsertNodeInRange(llist1, data1);

        llist1->head = sll::Partition(llist1->head, 2);
        string listStr = ToString(llist1->head);
        string output{ "1, 2, 2, 4, 4, 5, 3, 4, 5" };
        //TEST_TIMEOUT_BEGIN
        EXPECT_EQ(output, listStr);
        //TEST_TIMEOUT_FAIL_END(1000)

        sll::FreeSinglyLinkedList(llist1->head);
    }

    TEST(SinglyListChallengesTests, Segregate_Test1) {
        // initial
        SinglyLinkedList* llist1 = new SinglyLinkedList();
        vector<int> data1{ 1, 2, 4, 4, 5, 0, 3, 1, 0 };
        InsertNodeInRange(llist1, data1);

        llist1->head = sll::Partition(llist1->head, 2);
        string listStr = ToString(llist1->head);
        string output{ "1, 0, 1, 0, 2, 4, 4, 5, 3" };
        //TEST_TIMEOUT_BEGIN
        EXPECT_EQ(output, listStr);
        //TEST_TIMEOUT_FAIL_END(1000)

        sll::FreeSinglyLinkedList(llist1->head);
    }


    TEST(SinglyListChallengesTests, BubbleSortList_Test1) {
        // initial
        SinglyLinkedList* llist1 = new SinglyLinkedList();
        vector<int> data1{ 1, 6, 2, 7, 3, 8, 4, 9, 5 };
        InsertNodeInRange(llist1, data1);
        llist1->head = sll::SortBubble(llist1->head);
        // insert
        string listStr = ToString(llist1->head);
        string output{ "1, 2, 3, 4, 5, 6, 7, 8, 9" };
        EXPECT_EQ(output, listStr);

        sll::FreeSinglyLinkedList(llist1->head);
    }

    TEST(SinglyListChallengesTests, SortInsert_Test1) {
        // initial
        SinglyLinkedList* llist1 = new SinglyLinkedList();
        vector<int> data1{ 2, 3, 1, 5, 7, 6, 4 };
        InsertNodeInRange(llist1, data1);
        // insert data in sorted list
        llist1->head = sll::SortInsert(llist1->head);
        string listStr = ToString(llist1->head);
        string output{ "1, 2, 3, 4, 5, 6, 7" };
        EXPECT_EQ(output, listStr);

        sll::FreeSinglyLinkedList(llist1->head);
    }
}
