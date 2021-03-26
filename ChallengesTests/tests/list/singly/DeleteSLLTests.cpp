#include "./slltests.h"

namespace slltests {
    TEST(SinglyListChallengesTests_DELETE, DeleteNode_CorrectRequest) {
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

    TEST(SinglyListChallengesTests_Delete, DeleteNode_NegativeIndex) {
        // initial
        SinglyLinkedList* llist1 = new SinglyLinkedList();
        vector<int> data1{ 1, 2, 3, 4, 5 };
        InsertNodeInRange(llist1, data1);
        // delete
        llist1->head = sll::DeleteNode(llist1->head, -1);
        string listStr = ToString(llist1->head);
        string output{ "1, 2, 3, 4, 5" };
        EXPECT_EQ(output, listStr);

        sll::FreeSinglyLinkedList(llist1->head);
    }

    TEST(SinglyListChallengesTests_Delete, DeleteNodeTest_OutOfRangeIndex) {
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

    TEST(SinglyListChallengesTests_Delete, DeleteNodeByValue_CorrectIndex) {
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

    TEST(SinglyListChallengesTests_Delete, DeleteMiddle_DeleteInOdd) {
        // initial
        SinglyLinkedList* llist1 = new SinglyLinkedList();
        vector<int> data1{ 1, 2, 9, 3, 4, 5 };
        InsertNodeInRange(llist1, data1);
        // delete
        llist1->head = sll::DeleteMiddle(llist1->head);
        string listStr = ToString(llist1->head);
        string output{ "1, 2, 3, 4, 5" };
        EXPECT_EQ(output, listStr);

        sll::FreeSinglyLinkedList(llist1->head);

    }

    TEST(SinglyListChallengesTests_Delete, DeleteMiddle_DeleteInEven) {
        // initial
        SinglyLinkedList* llist1 = new SinglyLinkedList();
        vector<int> data1{ 1, 2, 3, 9, 4, 5, 6 };
        InsertNodeInRange(llist1, data1);
        // delete
        llist1->head = sll::DeleteMiddle(llist1->head);
        string listStr = ToString(llist1->head);
        string output{ "1, 2, 3, 4, 5, 6" };
        EXPECT_EQ(output, listStr);

        sll::FreeSinglyLinkedList(llist1->head);
    }

    TEST(SinglyListChallengesTests_Delete, DeleteEveryNthNode_NoDevision) {
        // initial
        SinglyLinkedList* llist1 = new SinglyLinkedList();
        vector<int> data1{ 1, 2, 3, 4, 5, 6 };
        InsertNodeInRange(llist1, data1);
        // delete
        llist1->head = sll::DeleteEveryNthNode(llist1->head, 2);
        string listStr = ToString(llist1->head);
        string output{ "1, 3, 5" };
        EXPECT_EQ(output, listStr);

        sll::FreeSinglyLinkedList(llist1->head);

        SinglyLinkedList* llist2 = new SinglyLinkedList();
        InsertNodeInRange(llist2, data1);

        llist2->head = sll::DeleteEveryNthNode(llist2->head, 3);
        listStr = ToString(llist2->head);
        output = "1, 2, 4, 5";
        EXPECT_EQ(output, listStr);

        sll::FreeSinglyLinkedList(llist2->head);
    }

    TEST(SinglyListChallengesTests_Delete, DeleteEveryNthNode_LessThen_2_Index) {
        // initial
        SinglyLinkedList* llist1 = new SinglyLinkedList();
        vector<int> data1{ 1, 2, 3, 4, 5, 6 };
        InsertNodeInRange(llist1, data1);
        // delete
        llist1->head = sll::DeleteEveryNthNode(llist1->head, 1);
        EXPECT_EQ(true, llist1->head == nullptr);

        SinglyLinkedList* llist2 = new SinglyLinkedList();
        InsertNodeInRange(llist2, data1);

        llist2->head = sll::DeleteEveryNthNode(llist2->head, -1);
        EXPECT_EQ(true, llist2->head == nullptr);
    }

    TEST(SinglyListChallengesTests_Delete, DeleteEveryNthNode_OutOfRangeIndex) {

        SinglyLinkedList* llist1 = new SinglyLinkedList();
        vector<int> data1{ 1, 2, 3, 4, 5, 6 };
        InsertNodeInRange(llist1, data1);

        llist1->head = sll::DeleteEveryNthNode(llist1->head, 7);
        string listStr = ToString(llist1->head);
        string output{ "1, 2, 3, 4, 5, 6" };
        EXPECT_EQ(output, listStr);

        sll::FreeSinglyLinkedList(llist1->head);
    }

    TEST(SinglyListChallengesTests_Delete, RemoveDublicates_CorrectInput) {

        SinglyLinkedList* llist1 = new SinglyLinkedList();
        vector<int> data1{ 1, 2, 1, 3, 4, 2, 5, 4, 6, 6 };
        InsertNodeInRange(llist1, data1);

        llist1->head = sll::RemoveDublicates(llist1->head);
        string listStr = ToString(llist1->head);
        string output{ "1, 2, 3, 4, 5, 6" };
        EXPECT_EQ(output, listStr);

        sll::FreeSinglyLinkedList(llist1->head);
    }

    TEST(SinglyListChallengesTests_Delete, RemoveDublicatesPairs_CorrectInput) {

        SinglyLinkedList* llist1 = new SinglyLinkedList();
        vector<int> data1{ 1, 1, 2, 2, 3, 4, 4, 5, 6, 6 };
        InsertNodeInRange(llist1, data1);

        llist1->head = sll::RemoveDublicatesPairs(llist1->head);
        string listStr = ToString(llist1->head);
        string output{ "3, 5" };
        EXPECT_EQ(output, listStr);

        sll::FreeSinglyLinkedList(llist1->head);
    }

    TEST(SinglyListChallengesTests, RemoveDublicatesInSorted_CorrectInput) {
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

    TEST(SinglyListChallengesTests, FreeList_NotCycled) {
        // initial
        SinglyLinkedList* llist1 = new SinglyLinkedList();
        vector<int> data1{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
        InsertNodeInRange(llist1, data1);
        sll::FreeSinglyLinkedList(llist1->head);
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

}
