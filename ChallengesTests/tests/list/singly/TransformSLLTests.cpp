//#include "./slltests.h"
//
//namespace slltests {
//
//    TEST(SLLTests_Transform, Reverse_CorrectInput) {
//        // initial
//        SinglyLinkedList* llist1 = new SinglyLinkedList();
//        vector<int> data1{ 5, 4, 3, 2, 1 };
//        InsertNodeInRange(llist1, data1);
//        // reverse
//        llist1->head = sll::Reverse(llist1->head);
//        string listStr = ToString(llist1->head);
//        string output{ "1, 2, 3, 4, 5" };
//        EXPECT_EQ(output, listStr);
//
//        sll::FreeSinglyLinkedList(llist1->head);
//    }
//
//    TEST(SLLTests_Transform, ReverseBetween_CorrectInput) {
//        // initial
//        SinglyLinkedList* llist1 = new SinglyLinkedList();
//        vector<int> data1{ 5, 4, 3, 2, 1 };
//        InsertNodeInRange(llist1, data1);
//        // reverse
//        llist1->head = sll::ReverseBetween(llist1->head, 2, 5);
//        string listStr = ToString(llist1->head);
//        string output{ "5, 1, 2, 3, 4" };
//        EXPECT_EQ(output, listStr);
//
//        sll::FreeSinglyLinkedList(llist1->head);
//    }
//
//    TEST(SLLTests_Transform, ReverseBetween_NegativeIndex) {
//        // initial
//        SinglyLinkedList* llist1 = new SinglyLinkedList();
//        vector<int> data1{ 5, 4, 3, 2, 1 };
//        InsertNodeInRange(llist1, data1);
//        // reverse
//        llist1->head = sll::ReverseBetween(llist1->head, -1, 5);
//        string listStr = ToString(llist1->head);
//        string output{ "1, 2, 3, 4, 5" };
//        EXPECT_EQ(output, listStr);
//
//        sll::FreeSinglyLinkedList(llist1->head);
//    }
//
//    TEST(SLLTests_Transform, ReverseBetween_OutOfRangeIndex) {
//        // initial
//        SinglyLinkedList* llist1 = new SinglyLinkedList();
//        vector<int> data1{ 5, 4, 3, 2, 1 };
//        InsertNodeInRange(llist1, data1);
//        // reverse
//        llist1->head = sll::ReverseBetween(llist1->head, 1, 7);
//        string listStr = ToString(llist1->head);
//        string output{ "1, 2, 3, 4, 5" };
//        EXPECT_EQ(output, listStr);
//
//        sll::FreeSinglyLinkedList(llist1->head);
//    }
//
//
//    TEST(SLLTests_Transform, Partition_CorrectInput) {
//        // initial
//        SinglyLinkedList* llist1 = new SinglyLinkedList();
//        vector<int> data1{ 1, 2, 4, 4, 5, 2, 3, 4, 5 };
//        InsertNodeInRange(llist1, data1);
//
//        llist1->head = sll::Partition(llist1->head, 2);
//        string listStr = ToString(llist1->head);
//        string output{ "1, 2, 2, 4, 4, 5, 3, 4, 5" };
//        //TEST_TIMEOUT_BEGIN
//        EXPECT_EQ(output, listStr);
//        //TEST_TIMEOUT_FAIL_END(1000)
//
//        sll::FreeSinglyLinkedList(llist1->head);
//    }
//
//    TEST(SLLTests_Transform, Segregate_Test1) {
//        // initial
//        SinglyLinkedList* llist1 = new SinglyLinkedList();
//        vector<int> data1{ 1, 2, 4, 4, 5, 0, 3, 1, 0 };
//        InsertNodeInRange(llist1, data1);
//
//        llist1->head = sll::Partition(llist1->head, 2);
//        string listStr = ToString(llist1->head);
//        string output{ "1, 0, 1, 0, 2, 4, 4, 5, 3" };
//        //TEST_TIMEOUT_BEGIN
//        EXPECT_EQ(output, listStr);
//        //TEST_TIMEOUT_FAIL_END(1000)
//
//        sll::FreeSinglyLinkedList(llist1->head);
//    }
//
//
//    TEST(SLLTests_Transform, SortBubble_CorrectInput) {
//        // initial
//        SinglyLinkedList* llist1 = new SinglyLinkedList();
//        vector<int> data1{ 1, 6, 2, 7, 3, 8, 4, 9, 5 };
//        InsertNodeInRange(llist1, data1);
//        llist1->head = sll::SortBubble(llist1->head);
//        // insert
//        string listStr = ToString(llist1->head);
//        string output{ "1, 2, 3, 4, 5, 6, 7, 8, 9" };
//        EXPECT_EQ(output, listStr);
//
//        sll::FreeSinglyLinkedList(llist1->head);
//    }
//
//    TEST(SLLTests_Transform, SortInsert_CorrectInput) {
//        // initial
//        SinglyLinkedList* llist1 = new SinglyLinkedList();
//        vector<int> data1{ 8, 2, 3, 1, 5, 7, 6, 4 };
//        InsertNodeInRange(llist1, data1);
//        // insert data in sorted list
//        llist1->head = sll::SortInsert(llist1->head);
//        string listStr = ToString(llist1->head);
//        string output{ "1, 2, 3, 4, 5, 6, 7, 8" };
//        EXPECT_EQ(output, listStr);
//
//        sll::FreeSinglyLinkedList(llist1->head);
//    }
//
//    TEST(SLLTests_Transform, SortReorder_CorrectInput) {
//        // initial
//        SinglyLinkedList* llist1 = new SinglyLinkedList();
//        vector<int> data1{ 1, 2, 3, 4, 5, 6, 7, 8 };
//        InsertNodeInRange(llist1, data1);
//        // insert data in sorted list
//        llist1->head = sll::Reorder(llist1->head);
//        llist1->head = sll::SortReorder(llist1->head);
//        string listStr = ToString(llist1->head);
//        string output{ "1, 2, 3, 4, 5, 6, 7, 8" };
//        EXPECT_EQ(output, listStr);
//
//        sll::FreeSinglyLinkedList(llist1->head);
//    }
//
//    TEST(SLLTests_Transform, SwapByReferences_CorrectInput) {
//        // initial
//        SinglyLinkedList* llist1 = new SinglyLinkedList();
//        vector<int> data1{ 1, 2, 3, 4, 5, 6, 7, 8 };
//        InsertNodeInRange(llist1, data1);
//        // insert data in sorted list
//
//        SinglyLinkedListNode* node1 = sll::GetNode(llist1->head, 2);
//        SinglyLinkedListNode* node2 = sll::GetNode(llist1->head, 5);
//        llist1->head = sll::SwapNext(llist1->head, node1, node2);
//        string listStr = ToString(llist1->head);
//        string output{ "1, 2, 3, 7, 5, 6, 4, 8" };
//        EXPECT_EQ(output, listStr);
//
//        sll::FreeSinglyLinkedList(llist1->head);
//    }
//
//    TEST(SLLTests_Transform, SwapByIndex_CorrectInput) {
//        // initial
//        SinglyLinkedList* llist1 = new SinglyLinkedList();
//        vector<int> data1{ 1, 2, 3, 4, 5, 6, 7, 8 };
//        InsertNodeInRange(llist1, data1);
//        // insert data in sorted list
//        llist1->head = sll::Swap(llist1->head, 2, 7);
//        string listStr = ToString(llist1->head);
//        string output{ "1, 7, 3, 4, 5, 6, 2, 8" };
//        EXPECT_EQ(output, listStr);
//
//        sll::FreeSinglyLinkedList(llist1->head);
//    }
//    TEST(SLLTests_Transform, PairwiseSwap_CorrectInput) {
//        // initial
//        SinglyLinkedList* llist1 = new SinglyLinkedList();
//        vector<int> data1{ 1, 2, 3, 4, 5, 6, 7, 8 };
//        InsertNodeInRange(llist1, data1);
//        // insert data in sorted list
//        llist1->head = sll::PairwiseSwap(llist1->head);
//        string listStr = ToString(llist1->head);
//        string output{ "2, 1, 4, 3, 6, 5, 8, 7" };
//        EXPECT_EQ(output, listStr);
//
//        sll::FreeSinglyLinkedList(llist1->head);
//    }
//
//    TEST(SLLTests_Transform, SwapZigZag_CorrectInput) {
//
//        SinglyLinkedList* llist1 = new SinglyLinkedList();
//        vector<int> data1{ 1, 2, 3, 4 };
//        InsertNodeInRange(llist1, data1);
//
//        llist1->head = sll::SwapZigZag(llist1->head);
//        string listStr = ToString(llist1->head);
//        string output{ "1, 3, 2, 4" };
//        EXPECT_EQ(output, listStr);
//
//        sll::FreeSinglyLinkedList(llist1->head);
//
//        SinglyLinkedList* llist2 = new SinglyLinkedList();
//        vector<int> data2{ 11, 15, 20, 5, 10 };
//        InsertNodeInRange(llist2, data2);
//
//        llist2->head = sll::SwapZigZag(llist2->head);
//        string listStr2 = ToString(llist1->head);
//        string output2{ "20, 5, 15, 10" };
//        EXPECT_EQ(output2, listStr2);
//
//        sll::FreeSinglyLinkedList(llist2->head);
//    }
//
//    TEST(SLLTests_Transform, DecimalValue_4_Bits_Input) {
//
//        SinglyLinkedList* llist1 = new SinglyLinkedList();
//        vector<int> data1{ 0, 1, 1 };
//        InsertNodeInRange(llist1, data1);
//
//        long long unsigned int n1 = sll::DecimalValue(llist1->head);
//        EXPECT_EQ(3, n1);
//
//        SinglyLinkedList* llist2 = new SinglyLinkedList();
//        vector<int> data2{ 1, 1, 1, 0 };
//        InsertNodeInRange(llist2, data2);
//
//        long long unsigned int n2 = sll::DecimalValue(llist2->head);
//        EXPECT_EQ(14, n2);
//
//        sll::FreeSinglyLinkedList(llist1->head);
//        sll::FreeSinglyLinkedList(llist2->head);
//    }
//}
