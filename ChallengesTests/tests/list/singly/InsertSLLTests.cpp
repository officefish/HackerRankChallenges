//#include "./slltests.h"
//
//
//namespace slltests {
//    TEST(SLLTests_Insert, InsertNodeAtHead_CorrectInput) {
//
//        // initial
//        SinglyLinkedList* llist1 = new SinglyLinkedList();
//        vector<int> data1{ 4, 5, 6, 7, 8, 9 };
//        InsertNodeInRange(llist1, data1);
//        // instert
//        vector<int> data2{ 3, 2, 1 };
//        for (const auto& i : data2) {
//            llist1->head = sll::InsertNodeAtHead(llist1->head, i);
//        }
//        string listStr = ToString(llist1->head);
//        string output{ "1, 2, 3, 4, 5, 6, 7, 8, 9" };
//        EXPECT_EQ(output, listStr);
//
//        sll::FreeSinglyLinkedList(llist1->head);
//    }
//
//    TEST(SLLTests_Insert, InsertNodeAtTail_CorrectInput) {
//
//        // initial
//        SinglyLinkedList* llist1 = new SinglyLinkedList();
//        vector<int> data1{ 1, 2, 3, 4, 5, 6 };
//        InsertNodeInRange(llist1, data1);
//        // insert
//        vector<int> data2{ 7, 8, 9 };
//        for (const auto& i : data2) {
//            llist1->head = sll::InsertNodeAtTail(llist1->head, i);
//        }
//        string listStr = ToString(llist1->head);
//        string output{ "1, 2, 3, 4, 5, 6, 7, 8, 9" };
//        EXPECT_EQ(output, listStr);
//
//        sll::FreeSinglyLinkedList(llist1->head);
//    }
//
//    TEST(SLLTests_Insert, InsertNodeAtPosition_CorrectInput) {
//        // initial
//        SinglyLinkedList* llist1 = new SinglyLinkedList();
//        vector<int> data1{ 1, 2, 3, 7, 8, 9 };
//        InsertNodeInRange(llist1, data1);
//        // insert
//        vector<int> data2{ 4, 5, 6 };
//        for (const auto& i : data2) {
//            llist1->head = sll::InsertNodeAtPosition(llist1->head, i, i - 1);
//        }
//        string listStr = ToString(llist1->head);
//        string output{ "1, 2, 3, 4, 5, 6, 7, 8, 9" };
//        EXPECT_EQ(output, listStr);
//
//        sll::FreeSinglyLinkedList(llist1->head);
//    }
//
//    TEST(SLLTests_Insert, InsertNodeAtPosition_NegativeIndex) {
//        // initial
//        SinglyLinkedList* llist1 = new SinglyLinkedList();
//        vector<int> data1{ 1, 2, 3, 4, 5 };
//        InsertNodeInRange(llist1, data1);
//        // insert
//        llist1->head = sll::InsertNodeAtPosition(llist1->head, 0, -1);
//        string listStr = ToString(llist1->head);
//        string output{ "1, 2, 3, 4, 5" };
//        EXPECT_EQ(output, listStr);
//
//        sll::FreeSinglyLinkedList(llist1->head);
//    }
//
//    TEST(SLLTests_Insert, InsertNodeAtPosition_ListSizeIndex) {
//        // initial
//        SinglyLinkedList* llist1 = new SinglyLinkedList();
//        vector<int> data1{ 1, 2, 3, 4, 5 };
//        InsertNodeInRange(llist1, data1);
//        // insert
//        llist1->head = sll::InsertNodeAtPosition(llist1->head, 6, 5);
//        string listStr = ToString(llist1->head);
//        string output{ "1, 2, 3, 4, 5, 6" };
//        EXPECT_EQ(output, listStr);
//
//        sll::FreeSinglyLinkedList(llist1->head);
//    }
//    TEST(SLLTests_Insert, InsertNodeAtPosition_MoreThanSizeIndex) {
//        // initial
//        SinglyLinkedList* llist1 = new SinglyLinkedList();
//        vector<int> data1{ 1, 2, 3, 4, 5 };
//        InsertNodeInRange(llist1, data1);
//        // insert
//        llist1->head = sll::InsertNodeAtPosition(llist1->head, 6, 6);
//        string listStr = ToString(llist1->head);
//        string output{ "1, 2, 3, 4, 5, 6" };
//        EXPECT_EQ(output, listStr);
//
//        sll::FreeSinglyLinkedList(llist1->head);
//    }
//
//    TEST(SLLTests_Insert, InsertNodeAtMiddle_InsertInOdd) {
//        // initial
//        SinglyLinkedList* llist1 = new SinglyLinkedList();
//        vector<int> data1{ 1, 2, 4, 5 };
//        InsertNodeInRange(llist1, data1);
//        // insert
//        llist1->head = sll::InsertNodeAtMiddle(llist1->head, 3);
//        string listStr = ToString(llist1->head);
//        string output{ "1, 2, 3, 4, 5" };
//        EXPECT_EQ(output, listStr);
//
//        sll::FreeSinglyLinkedList(llist1->head);
//    }
//
//    TEST(SLLTests_Insert, InsertNodeAtMiddle_InsertInEven) {
//        // initial
//        SinglyLinkedList* llist1 = new SinglyLinkedList();
//        vector<int> data1{ 1, 2, 4, 5, 6 };
//        InsertNodeInRange(llist1, data1);
//        // insert
//        llist1->head = sll::InsertNodeAtMiddle(llist1->head, 3);
//        string listStr = ToString(llist1->head);
//        string output{ "1, 2, 3, 4, 5, 6" };
//        EXPECT_EQ(output, listStr);
//
//        sll::FreeSinglyLinkedList(llist1->head);
//    }
//
//    TEST(SLLTests_Insert, InsertNodeAtMiddle_InsertInEmpty) {
//        // initial
//        SinglyLinkedList* llist1 = new SinglyLinkedList();
//        // insert
//        llist1->head = sll::InsertNodeAtMiddle(llist1->head, 1);
//        string listStr = ToString(llist1->head);
//        string output{ "1" };
//        EXPECT_EQ(output, listStr);
//
//        sll::FreeSinglyLinkedList(llist1->head);
//    }
//
//    TEST(SLLTests_Insert, InsertInSortedNode_CorrectInput) {
//        // initial
//        SinglyLinkedList* llist1 = new SinglyLinkedList();
//        vector<int> data1{ 1, 2, 3, 5, 6, 7 };
//        InsertNodeInRange(llist1, data1);
//        // insert node in sorted list
//        SinglyLinkedListNode* node = new SinglyLinkedListNode(4);
//        llist1->head = sll::InsertInSortedNode(llist1->head, node);
//        string listStr = ToString(llist1->head);
//        string output{ "1, 2, 3, 4, 5, 6, 7" };
//        EXPECT_EQ(output, listStr);
//
//        sll::FreeSinglyLinkedList(llist1->head);
//    }
//
//    TEST(SLLTests_Insert, InsertInSortedData_CorrectInput) {
//        // initial
//        SinglyLinkedList* llist1 = new SinglyLinkedList();
//        vector<int> data1{ 1, 2, 3, 5, 6, 7 };
//        InsertNodeInRange(llist1, data1);
//        // insert data in sorted list
//        llist1->head = sll::InsertInSortedData(llist1->head, 4);
//        string listStr = ToString(llist1->head);
//        string output{ "1, 2, 3, 4, 5, 6, 7" };
//        EXPECT_EQ(output, listStr);
//
//        sll::FreeSinglyLinkedList(llist1->head);
//    }
//
//    TEST(SLLTests_Validate, InsertInCircularSorted_CorrectIndex) {
//        // initial
//        SinglyLinkedList* llist1 = new SinglyLinkedList();
//        vector<int> data1{ 2, 3, 4, 5, 7, 8, 9 };
//        InsertNodeInRange(llist1, data1);
//        // cycling
//        SinglyLinkedListNode* end = sll::GetNodeFromTail(llist1->head, 0);
//        end->next = llist1->head;
//
//        llist1->head = sll::InsertInCircularSorted(llist1->head, 6);
//
//        string listStr1 = ToStringLoop(llist1->head, end);
//        string output1{ "2, 3, 4, 5, 6, 7, 8, 9" };
//        EXPECT_EQ(output1, listStr1);
//
//
//        sll::FreeSinglyLinkedList(llist1->head);
//
//    }
//
//    TEST(SLLTests_Validate, InsertInCircularSorted_ZeroIndex) {
//        // initial
//        SinglyLinkedList* llist1 = new SinglyLinkedList();
//        vector<int> data1{ 2, 3, 4, 5, 6, 7, 8, 9 };
//        InsertNodeInRange(llist1, data1);
//        // cycling
//        SinglyLinkedListNode* end = sll::GetNodeFromTail(llist1->head, 0);
//        end->next = llist1->head;
//
//        llist1->head = sll::InsertInCircularSorted(llist1->head, 1);
//
//        string listStr1 = ToStringLoop(llist1->head, end);
//        string output1{ "1, 2, 3, 4, 5, 6, 7, 8, 9" };
//        EXPECT_EQ(output1, listStr1);
//
//
//        sll::FreeSinglyLinkedList(llist1->head);
//
//    }
//
//    TEST(SLLTests_Validate, InsertInCircularSorted_OutOfRangeIndex) {
//        // initial
//        SinglyLinkedList* llist1 = new SinglyLinkedList();
//        vector<int> data1{ 2, 3, 4, 5, 6, 7, 8, 9 };
//        InsertNodeInRange(llist1, data1);
//        // cycling
//        SinglyLinkedListNode* end = sll::GetNodeFromTail(llist1->head, 0);
//        end->next = llist1->head;
//        // ignore sorting
//        llist1->head = sll::InsertInCircularSorted(llist1->head, 10);
//
//        string listStr1 = ToStringLoop(llist1->head, end);
//        string output1{ "2, 3, 4, 5, 6, 7, 8, 9" };
//        EXPECT_EQ(output1, listStr1);
//
//        sll::FreeSinglyLinkedList(llist1->head);
//
//    }
//}
