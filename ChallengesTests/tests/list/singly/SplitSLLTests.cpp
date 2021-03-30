//#include "./slltests.h"
//
//namespace slltests {
//    TEST(SLLTests_Split, SplitMiddle_CorrectInput) {
//
//        SinglyLinkedList* llist1 = new SinglyLinkedList();
//        std::vector<int> data1{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//        InsertNodeInRange(llist1, data1);
//
//        SinglyLinkedListNode* left = nullptr;
//        SinglyLinkedListNode* right = nullptr;
//
//        sll::SplitMiddle(llist1->head, &left, &right);
//
//        string leftStr = ToString(left);
//        string output1{ "1, 2, 3, 4, 5" };
//        EXPECT_EQ(output1, leftStr);
//
//        string rightStr = ToString(right);
//        string output2{ "6, 7, 8, 9, 10" };
//        EXPECT_EQ(output2, rightStr);
//    }
//
//    TEST(SLLTests_Split, SplitAlternate_CorrectInput) {
//
//        SinglyLinkedList* llist1 = new SinglyLinkedList();
//        std::vector<int> data1{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//        InsertNodeInRange(llist1, data1);
//
//        SinglyLinkedListNode* left = nullptr;
//        SinglyLinkedListNode* right = nullptr;
//
//        sll::SplitAlternate(llist1->head, &left, &right);
//
//        string leftStr = ToString(left);
//        string output1{ "1, 3, 5, 7, 9" };
//        EXPECT_EQ(output1, leftStr);
//
//        string rightStr = ToString(right);
//        string output2{ "2, 4, 6, 8, 10" };
//        EXPECT_EQ(output2, rightStr);
//    }
//
//    TEST(SLLTests_Validate, BreakCycle_HasCycle) {
//        // initial
//        SinglyLinkedList* llist1 = new SinglyLinkedList();
//        vector<int> data1{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//        InsertNodeInRange(llist1, data1);
//        // cycling
//        llist1->tail->next = llist1->head->next;
//
//        llist1->head = sll::BreakCycle(llist1->head);
//        string listStr = ToString(llist1->head);
//        string output{ "1, 2, 3, 4, 5, 6, 7, 8, 9, 10" };
//        EXPECT_EQ(output, listStr);
//
//        sll::FreeSinglyLinkedList(llist1->head);
//    }
//
//    TEST(SLLTests_Validate, BreakCycle_HasCycle_HeadIsBegin) {
//        // initial
//        SinglyLinkedList* llist1 = new SinglyLinkedList();
//        vector<int> data1{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//        InsertNodeInRange(llist1, data1);
//        // cycling
//        llist1->tail->next = llist1->head;
//
//        llist1->head = sll::BreakCycle(llist1->head);
//        string listStr = ToString(llist1->head);
//        string output{ "1, 2, 3, 4, 5, 6, 7, 8, 9, 10" };
//        EXPECT_EQ(output, listStr);
//
//        sll::FreeSinglyLinkedList(llist1->head);
//    }
//
//    TEST(SLLTests_Validate, SplitCycle_HasCycle) {
//        // initial
//        SinglyLinkedList* llist1 = new SinglyLinkedList();
//        vector<int> data1{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//        InsertNodeInRange(llist1, data1);
//        // cycling
//        llist1->tail->next = llist1->head->next->next;
//        SinglyLinkedListNode* llist2_h = nullptr;
//        SinglyLinkedListNode* llist3_h = nullptr;
//
//        sll::SplitCycle(llist1->head, &llist2_h, &llist3_h);
//
//        string listStr1 = ToString(llist2_h);
//        string output1{ "1, 2" };
//        EXPECT_EQ(output1, listStr1);
//        string listStr2 = ToString(llist3_h);
//        string output2{ "3, 4, 5, 6, 7, 8, 9, 10" };
//        EXPECT_EQ(output2, listStr2);
//
//        sll::FreeSinglyLinkedList(llist2_h);
//        sll::FreeSinglyLinkedList(llist3_h);
//    }
//
//    TEST(SLLTests_Validate, SplitCycle_HeadisEnd) {
//        // initial
//        SinglyLinkedList* llist1 = new SinglyLinkedList();
//        vector<int> data1{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//        InsertNodeInRange(llist1, data1);
//        // cycling
//        llist1->tail->next = llist1->head;
//        SinglyLinkedListNode* llist2_h = nullptr;
//        SinglyLinkedListNode* llist3_h = nullptr;
//
//        sll::SplitCycle(llist1->head, &llist2_h, &llist3_h);
//
//        string listStr1 = ToString(llist2_h);
//        string output1{ "1, 2, 3, 4, 5, 6, 7, 8, 9, 10" };
//        EXPECT_EQ(output1, listStr1);
//
//        EXPECT_EQ(true, llist3_h == nullptr);
//
//        sll::FreeSinglyLinkedList(llist2_h);
//
//    }
//
//
//
//}
