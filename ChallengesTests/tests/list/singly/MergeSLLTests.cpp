#include "./slltests.h"

namespace slltests {

    TEST(SLLTests_Merge, Merge_CorrectInput) {
        // initial
        SinglyLinkedList* llist1 = new SinglyLinkedList();
        vector<int> data1{ 5, 4, 3, 2, 1 };
        InsertNodeInRange(llist1, data1);
        SinglyLinkedList* llist2 = new SinglyLinkedList();
        vector<int> data2{ 6, 7, 8, 9, 10 };
        InsertNodeInRange(llist2, data2);

        // mergeSorted
        SinglyLinkedList* llist3 = new SinglyLinkedList();
        llist3->head = sll::Merge(llist1->head, llist2->head);

        string listStr = ToString(llist3->head);
        string output{ "5, 4, 3, 2, 1, 6, 7, 8, 9, 10" };
        EXPECT_EQ(output, listStr);

        sll::FreeSinglyLinkedList(llist3->head);
    }

    TEST(SLLTests_Merge, MergeAlternate_CorrectInput) {
        // initial
        SinglyLinkedList* llist1 = new SinglyLinkedList();
        vector<int> data1{ 1, 2, 3, 4, 5 };
        InsertNodeInRange(llist1, data1);
        SinglyLinkedList* llist2 = new SinglyLinkedList();
        vector<int> data2{ 6, 7, 8, 9, 10 };
        InsertNodeInRange(llist2, data2);

        // mergeSorted
        SinglyLinkedList* llist3 = new SinglyLinkedList();
        llist3->head = sll::MergeAlternate(llist1->head, llist2->head);

        string listStr = ToString(llist3->head);
        string output{ "1, 6, 2, 7, 3, 8, 4, 9, 5, 10" };
        EXPECT_EQ(output, listStr);

        sll::FreeSinglyLinkedList(llist3->head);
    }

    TEST(SLLTests_Merge, MergeAlternateModular_CorrectInput) {
        // initial
        SinglyLinkedList* llist1 = new SinglyLinkedList();
        vector<int> data1{ 1, 2, 3, 4, 5 };
        InsertNodeInRange(llist1, data1);
        SinglyLinkedList* llist2 = new SinglyLinkedList();
        vector<int> data2{ 6, 7, 8, 9, 10 };
        InsertNodeInRange(llist2, data2);

        sll::MergeAlternateModular(&llist1->head, &llist2->head);

        string listStr = ToString(llist1->head);
        string output{ "1, 6, 2, 7, 3, 8, 4, 9, 5, 10" };
        EXPECT_EQ(output, listStr);

        sll::FreeSinglyLinkedList(llist1->head);
        sll::FreeSinglyLinkedList(llist2->head);
    }

    TEST(SLLTests_Merge, MergeSortedReverse_CorrectInput) {
        // initial
        SinglyLinkedList* llist1 = new SinglyLinkedList();
        vector<int> data1{ 5, 10, 15, 40 };
        InsertNodeInRange(llist1, data1);
        SinglyLinkedList* llist2 = new SinglyLinkedList();
        vector<int> data2{ 2, 3, 20 };
        InsertNodeInRange(llist2, data2);

        // mergeSorted
        SinglyLinkedList* llist3 = new SinglyLinkedList();
        llist3->head = sll::MergeSortedReverse(llist1->head, llist2->head);

        string listStr = ToString(llist3->head);
        string output{ "40, 20, 15, 10, 5, 3, 2" };
        EXPECT_EQ(output, listStr);

        sll::FreeSinglyLinkedList(llist3->head);
    }
    TEST(SLLTests_Merge, MergeSorted_CorrectInput) {
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
}
