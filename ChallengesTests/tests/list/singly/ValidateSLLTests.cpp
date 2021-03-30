//#include "./slltests.h"
//namespace slltests {
//
//    TEST(SLLTests_Validate, CompareLists_True) {
//        // initial
//        SinglyLinkedList* llist1 = new SinglyLinkedList();
//        vector<int> data1{ 1, 2, 3, 4, 5 };
//        InsertNodeInRange(llist1, data1);
//        SinglyLinkedList* llist2 = new SinglyLinkedList();
//        InsertNodeInRange(llist2, data1);
//        // compare
//        bool equals = sll::CompareLists(llist1->head, llist2->head);
//
//        EXPECT_EQ(true, equals);
//
//        sll::FreeSinglyLinkedList(llist1->head);
//        sll::FreeSinglyLinkedList(llist2->head);
//    }
//
//
//    TEST(SLLTests_Validate, CompareLists_False) {
//        // initial
//        SinglyLinkedList* llist1 = new SinglyLinkedList();
//        vector<int> data1{ 1, 2, 3, 4, 5 };
//        InsertNodeInRange(llist1, data1);
//        SinglyLinkedList* llist2 = new SinglyLinkedList();
//        vector<int> data2{ 6, 7, 8, 9, 10 };
//        InsertNodeInRange(llist2, data2);
//        // compare
//        bool equals = sll::CompareLists(llist1->head, llist2->head);
//        EXPECT_EQ(false, equals);
//
//        sll::FreeSinglyLinkedList(llist1->head);
//        sll::FreeSinglyLinkedList(llist2->head);
//    }
//
//    TEST(SLLTests_Validate, CountCommonNodes_CorrectInput) {
//        // initial
//        SinglyLinkedList* llist1 = new SinglyLinkedList();
//        vector<int> data1{ 1, 2, 3, 4, 5 };
//        InsertNodeInRange(llist1, data1);
//
//        SinglyLinkedList* llist2 = new SinglyLinkedList();
//        vector<int> data2{ 1, 2, 3, 4, 5 };
//        InsertNodeInRange(llist2, data2);
//
//        //TEST_TIMEOUT_BEGIN
//        int result = sll::CountCommonNodes(llist1->head, llist2->head);
//        EXPECT_EQ(5, result);
//
//        SinglyLinkedListNode* tail1 = sll::GetNodeFromTail(llist1->head, 0);
//        SinglyLinkedListNode* tail2 = sll::GetNodeFromTail(llist2->head, 0);
//
//        int result2 = sll::CountCommonNodes(tail1, tail2);
//        EXPECT_EQ(1, result2);
//
//        sll::FreeSinglyLinkedList(llist1->head);
//        sll::FreeSinglyLinkedList(llist2->head);
//    }
//
//    TEST(SLLTests_Validate, HasCycle_Test_True) {
//        // initial
//        SinglyLinkedList* llist1 = new SinglyLinkedList();
//        vector<int> data1{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//        InsertNodeInRange(llist1, data1);
//        // cycling
//        llist1->tail->next = llist1->head;
//        //hasCycle check
//        bool hasCycle = sll::HasCycle(llist1->head);
//        EXPECT_EQ(true, hasCycle);
//
//        sll::FreeSinglyLinkedList(llist1->head);
//    }
//
//    TEST(SLLTests_Validate, HasCycle_Test_False) {
//        // initial
//        SinglyLinkedList* llist1 = new SinglyLinkedList();
//        vector<int> data1{ 1, 2, 3, 4, 5 };
//        InsertNodeInRange(llist1, data1);
//        // hasCycle check
//        bool hasCycle = sll::HasCycle(llist1->head);
//        EXPECT_EQ(false, hasCycle);
//
//        sll::FreeSinglyLinkedList(llist1->head);
//    }
//
//    TEST(SLLTests_Validate, CountNodesInLoop_HasCycle) {
//        // initial
//        SinglyLinkedList* llist1 = new SinglyLinkedList();
//        vector<int> data1{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//        InsertNodeInRange(llist1, data1);
//        // cycling
//        llist1->tail->next = llist1->head->next;
//        //hasCycle check
//        int count = sll::CountNodesinLoop(llist1->head);
//        EXPECT_EQ(9, count);
//
//        sll::FreeSinglyLinkedList(llist1->head);
//    }
//
//    TEST(SLLTests_Validate, CountNodesInLoop_No_HasCycle) {
//        // initial
//        SinglyLinkedList* llist1 = new SinglyLinkedList();
//        vector<int> data1{ 1, 2, 3, 4, 5 };
//        InsertNodeInRange(llist1, data1);
//        // hasCycle check
//        int count = sll::CountNodesinLoop(llist1->head);
//        EXPECT_EQ(0, count);
//
//        sll::FreeSinglyLinkedList(llist1->head);
//    }
//
//    TEST(SLLTests_Validate, GetCycleBeginNode_HasCycle) {
//        // initial
//        SinglyLinkedList* llist1 = new SinglyLinkedList();
//        vector<int> data1{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//        InsertNodeInRange(llist1, data1);
//        // cycling
//        llist1->tail->next = llist1->head->next;
//        //hasCycle check
//        SinglyLinkedListNode* begin = sll::GetCycleBeginNode(llist1->head);
//        EXPECT_EQ(2, begin->data);
//
//        sll::FreeSinglyLinkedList(llist1->head);
//    }
//
//    TEST(SLLTests_Validate, GetCycleBeginNode_HasCycle_HeadIsBegin) {
//        // initial
//        SinglyLinkedList* llist1 = new SinglyLinkedList();
//        vector<int> data1{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//        InsertNodeInRange(llist1, data1);
//        // cycling
//        llist1->tail->next = llist1->head;
//        //hasCycle check
//        SinglyLinkedListNode* begin = sll::GetCycleBeginNode(llist1->head);
//        EXPECT_EQ(1, begin->data);
//
//        sll::FreeSinglyLinkedList(llist1->head);
//    }
//
//    TEST(SLLTests_Validate, GetCycleEndNode_HasCycle) {
//        // initial
//        SinglyLinkedList* llist1 = new SinglyLinkedList();
//        vector<int> data1{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//        InsertNodeInRange(llist1, data1);
//        // cycling
//        llist1->tail->next = llist1->head->next;
//        //hasCycle check
//        SinglyLinkedListNode* end = sll::GetCycleEndNode(llist1->head);
//        EXPECT_EQ(10, end->data);
//
//        sll::FreeSinglyLinkedList(llist1->head);
//    }
//
//    TEST(SLLTests_Validate, GetCycleEndNode_HasCycle_HeadIsBegin) {
//        // initial
//        SinglyLinkedList* llist1 = new SinglyLinkedList();
//        vector<int> data1{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//        InsertNodeInRange(llist1, data1);
//        // cycling
//        llist1->tail->next = llist1->head;
//        //hasCycle check
//        SinglyLinkedListNode* end = sll::GetCycleEndNode(llist1->head);
//        EXPECT_EQ(10, end->data);
//
//        sll::FreeSinglyLinkedList(llist1->head);
//    }
//
//
//
//
//}
