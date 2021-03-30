//#include "./slltests.h"
//
//namespace slltests {
//
//    TEST(SLLTests_Get, GetNode_CorrectIndex) {
//        // initial
//        SinglyLinkedList* llist1 = new SinglyLinkedList();
//        // insert
//        vector<int> data1{ 1, 2, 3, 4, 5 };
//        InsertNodeInRange(llist1, data1);
//
//        SinglyLinkedListNode* node0 = sll::GetNode(llist1->head, 0);
//        EXPECT_EQ(1, node0->data);
//        SinglyLinkedListNode* node1 = sll::GetNode(llist1->head, 1);
//        EXPECT_EQ(2, node1->data);
//        SinglyLinkedListNode* node2 = sll::GetNode(llist1->head, 2);
//        EXPECT_EQ(3, node2->data);
//        SinglyLinkedListNode* node3 = sll::GetNode(llist1->head, 3);
//        EXPECT_EQ(4, node3->data);
//        SinglyLinkedListNode* node4 = sll::GetNode(llist1->head, 4);
//        EXPECT_EQ(5, node4->data);
//
//        sll::FreeSinglyLinkedList(llist1->head);
//    }
//
//
//    TEST(SLLTests_Get, GetNode_NegativeIndex) {
//        // initial
//        SinglyLinkedList* llist1 = new SinglyLinkedList();
//        // insert
//        vector<int> data1{ 1, 2, 3, 4, 5 };
//        InsertNodeInRange(llist1, data1);
//
//        SinglyLinkedListNode* node0 = sll::GetNode(llist1->head, -1);
//        EXPECT_EQ(true, node0 == NULL);
//
//        sll::FreeSinglyLinkedList(llist1->head);
//    }
//
//    TEST(SLLTests_Get, GetNode_OutOfRangeIndex) {
//        // initial
//        SinglyLinkedList* llist1 = new SinglyLinkedList();
//        // insert
//        vector<int> data1{ 1, 2, 3, 4, 5 };
//        InsertNodeInRange(llist1, data1);
//
//        SinglyLinkedListNode* node0 = sll::GetNode(llist1->head, 6);
//        EXPECT_EQ(true, node0 == NULL);
//
//        sll::FreeSinglyLinkedList(llist1->head);
//    }
//
//    TEST(SLLTests_Get, GetNodeData_CorrectIndex) {
//        // initial
//        SinglyLinkedList* llist1 = new SinglyLinkedList();
//        // insert
//        vector<int> data{ 1, 2, 3, 4, 5 };
//        InsertNodeInRange(llist1, data);
//
//        int data0 = sll::GetNodeData(llist1->head, 0);
//        EXPECT_EQ(1, data0);
//        int data1 = sll::GetNodeData(llist1->head, 1);
//        EXPECT_EQ(2, data1);
//        int data2 = sll::GetNodeData(llist1->head, 2);
//        EXPECT_EQ(3, data2);
//        int data3 = sll::GetNodeData(llist1->head, 3);
//        EXPECT_EQ(4, data3);
//        int data4 = sll::GetNodeData(llist1->head, 4);
//        EXPECT_EQ(5, data4);
//
//        sll::FreeSinglyLinkedList(llist1->head);
//    }
//    TEST(SLLTests_Get, GetNodeData_NegativeIndex) {
//        // initial
//        SinglyLinkedList* llist1 = new SinglyLinkedList();
//        // insert
//        vector<int> data{ 1, 2, 3, 4, 5 };
//        InsertNodeInRange(llist1, data);
//
//        int dataNegative = sll::GetNodeData(llist1->head, -1);
//        EXPECT_EQ(-1, dataNegative);
//
//        sll::FreeSinglyLinkedList(llist1->head);
//    }
//
//    TEST(SLLTests_Get, GetNodeData_OutOfRangeIndex) {
//        // initial
//        SinglyLinkedList* llist1 = new SinglyLinkedList();
//        // insert
//        vector<int> data{ 1, 2, 3, 4, 5 };
//        InsertNodeInRange(llist1, data);
//
//        int dataOutofRange = sll::GetNodeData(llist1->head, 5);
//        EXPECT_EQ(-1, dataOutofRange);
//
//        sll::FreeSinglyLinkedList(llist1->head);
//    }
//
//    TEST(SLLTests_Get, GetNodeFromTail_CorrectIndex) {
//        // initial
//        SinglyLinkedList* llist1 = new SinglyLinkedList();
//        // insert
//        vector<int> data1{ 1, 2, 3, 4, 5 };
//        InsertNodeInRange(llist1, data1);
//
//        SinglyLinkedListNode* node0 = sll::GetNodeFromTail(llist1->head, 0);
//        EXPECT_EQ(5, node0->data);
//        SinglyLinkedListNode* node1 = sll::GetNodeFromTail(llist1->head, 1);
//        EXPECT_EQ(4, node1->data);
//        SinglyLinkedListNode* node2 = sll::GetNodeFromTail(llist1->head, 2);
//        EXPECT_EQ(3, node2->data);
//        SinglyLinkedListNode* node3 = sll::GetNodeFromTail(llist1->head, 3);
//        EXPECT_EQ(2, node3->data);
//        SinglyLinkedListNode* node4 = sll::GetNodeFromTail(llist1->head, 4);
//        EXPECT_EQ(1, node4->data);
//
//        sll::FreeSinglyLinkedList(llist1->head);
//    }
//
//    TEST(SLLTests_Get, GetNodeFromTail_NegativeIndex) {
//        // initial
//        SinglyLinkedList* llist1 = new SinglyLinkedList();
//        // insert
//        vector<int> data1{ 1, 2, 3, 4, 5 };
//        InsertNodeInRange(llist1, data1);
//
//        SinglyLinkedListNode* node0 = sll::GetNodeFromTail(llist1->head, -1);
//        EXPECT_EQ(true, node0 == NULL);
//
//        sll::FreeSinglyLinkedList(llist1->head);
//    }
//
//    TEST(SLLTests_Get, GetNodeFromTail_OutOfRangeIndex) {
//        // initial
//        SinglyLinkedList* llist1 = new SinglyLinkedList();
//        // insert
//        vector<int> data1{ 1, 2, 3, 4, 5 };
//        InsertNodeInRange(llist1, data1);
//
//        SinglyLinkedListNode* node0 = sll::GetNodeFromTail(llist1->head, 6);
//        EXPECT_EQ(true, node0 == NULL);
//
//        sll::FreeSinglyLinkedList(llist1->head);
//    }
//
//    TEST(SLLTests_Get, GetNodeFromTailData_CorrectIndex) {
//        // initial
//        SinglyLinkedList* llist1 = new SinglyLinkedList();
//        // insert
//        vector<int> data{ 1, 2, 3, 4, 5 };
//        InsertNodeInRange(llist1, data);
//
//        int data0 = sll::GetNodeFromTailData(llist1->head, 0);
//        EXPECT_EQ(5, data0);
//        int data1 = sll::GetNodeFromTailData(llist1->head, 1);
//        EXPECT_EQ(4, data1);
//        int data2 = sll::GetNodeFromTailData(llist1->head, 2);
//        EXPECT_EQ(3, data2);
//        int data3 = sll::GetNodeFromTailData(llist1->head, 3);
//        EXPECT_EQ(2, data3);
//        int data4 = sll::GetNodeFromTailData(llist1->head, 4);
//        EXPECT_EQ(1, data4);
//
//        sll::FreeSinglyLinkedList(llist1->head);
//    }
//
//    TEST(SLLTests_Get, GetNodeFromTailData_NegativeIndex) {
//        // initial
//        SinglyLinkedList* llist1 = new SinglyLinkedList();
//        // insert
//        vector<int> data{ 1, 2, 3, 4, 5 };
//        InsertNodeInRange(llist1, data);
//
//        int dataNegative = sll::GetNodeFromTailData(llist1->head, -1);
//        EXPECT_EQ(-1, dataNegative);
//
//        sll::FreeSinglyLinkedList(llist1->head);
//    }
//
//    TEST(SLLTests_Get, GetNodeFromTailData_OutOfRangeIndex) {
//        // initial
//        SinglyLinkedList* llist1 = new SinglyLinkedList();
//        // insert
//        vector<int> data{ 1, 2, 3, 4, 5 };
//        InsertNodeInRange(llist1, data);
//
//        int dataOutofRange = sll::GetNodeFromTailData(llist1->head, 5);
//        EXPECT_EQ(-1, dataOutofRange);
//
//        sll::FreeSinglyLinkedList(llist1->head);
//    }
//
//    TEST(SLLTests_Get, GetMiddleNode_InEven) {
//        // initial
//        SinglyLinkedList* llist1 = new SinglyLinkedList();
//        // insert
//        vector<int> data{ 1, 2, 3, 4, 5 };
//        InsertNodeInRange(llist1, data);
//
//        SinglyLinkedListNode* middleNode = sll::GetMiddleNode(llist1->head);
//        EXPECT_EQ(3, middleNode->data);
//
//        sll::FreeSinglyLinkedList(llist1->head);
//    }
//
//    TEST(SLLTests_Get, GetMiddleNode_InOdd) {
//        // initial
//        SinglyLinkedList* llist1 = new SinglyLinkedList();
//        // insert
//        vector<int> data{ 1, 2, 3, 4, 5, 6 };
//        InsertNodeInRange(llist1, data);
//
//        SinglyLinkedListNode* middleNode = sll::GetMiddleNode(llist1->head);
//        EXPECT_EQ(4, middleNode->data);
//
//        sll::FreeSinglyLinkedList(llist1->head);
//    }
//
//    TEST(SLLTests_Get, GetMiddleNodeData_InEven) {
//        // initial
//        SinglyLinkedList* llist1 = new SinglyLinkedList();
//        // insert
//        vector<int> data{ 1, 2, 3, 4, 5 };
//        InsertNodeInRange(llist1, data);
//
//        int middleNodeData = sll::GetMiddleNodeData(llist1->head);
//        EXPECT_EQ(3, middleNodeData);
//
//        sll::FreeSinglyLinkedList(llist1->head);
//    }
//
//    TEST(SLLTests_Get, GetMiddleNodeData_InOdd) {
//        // initial
//        SinglyLinkedList* llist1 = new SinglyLinkedList();
//        // insert
//        vector<int> data{ 1, 2, 3, 4, 5, 6 };
//        InsertNodeInRange(llist1, data);
//
//        int middleNodeData = sll::GetMiddleNodeData(llist1->head);
//        EXPECT_EQ(4, middleNodeData);
//
//        sll::FreeSinglyLinkedList(llist1->head);
//    }
//
//    TEST(SLLTests_Get, GetMiddlePrevNode_InEven) {
//        // initial
//        SinglyLinkedList* llist1 = new SinglyLinkedList();
//        // insert
//        vector<int> data{ 1, 2, 3, 4, 5 };
//        InsertNodeInRange(llist1, data);
//
//        SinglyLinkedListNode* prevMiddleNode = sll::GetPrevMiddleNode(llist1->head);
//        EXPECT_EQ(2, prevMiddleNode->data);
//
//        sll::FreeSinglyLinkedList(llist1->head);
//    }
//
//    TEST(SLLTests_Get, GetPrevMiddleNode_InOdd) {
//        // initial
//        SinglyLinkedList* llist1 = new SinglyLinkedList();
//        // insert
//        vector<int> data{ 1, 2, 3, 4, 5, 6 };
//        InsertNodeInRange(llist1, data);
//
//        SinglyLinkedListNode* prevMiddleNode = sll::GetPrevMiddleNode(llist1->head);
//        EXPECT_EQ(3, prevMiddleNode->data);
//
//        sll::FreeSinglyLinkedList(llist1->head);
//    }
//
//    TEST(SLLTests_Get, GetFractionalNode_CorrectIndex) {
//
//        SinglyLinkedList* llist1 = new SinglyLinkedList();
//        vector<int> data1{ 1, 2, 3, 4, 5, 6 };
//        InsertNodeInRange(llist1, data1);
//
//        SinglyLinkedListNode* fractionalNode1 = sll::GetFractionalNode(llist1->head, 2);
//        EXPECT_EQ(3, fractionalNode1->data);
//
//        sll::FreeSinglyLinkedList(llist1->head);
//
//        SinglyLinkedList* llist2 = new SinglyLinkedList();
//        vector<int> data2{ 2, 7, 9, 3, 5 };
//        InsertNodeInRange(llist2, data2);
//
//        SinglyLinkedListNode* fractionalNode2 = sll::GetFractionalNode(llist2->head, 3);
//        EXPECT_EQ(7, fractionalNode2->data);
//
//        sll::FreeSinglyLinkedList(llist2->head);
//    }
//
//    TEST(SLLTests_Get, GetFractionalNode_NegativeIndex) {
//
//        SinglyLinkedList* llist1 = new SinglyLinkedList();
//        vector<int> data1{ 1, 2, 3, 4, 5, 6 };
//        InsertNodeInRange(llist1, data1);
//
//        SinglyLinkedListNode* fractionalNode1 = sll::GetFractionalNode(llist1->head, -1);
//        EXPECT_EQ(true, fractionalNode1 == nullptr);
//
//        sll::FreeSinglyLinkedList(llist1->head);
//    }
//
//    TEST(SLLTests_Get, GetFractionalNode_OutOfRangeIndex) {
//
//        SinglyLinkedList* llist1 = new SinglyLinkedList();
//        vector<int> data1{ 1, 2, 3, 4, 5, 6 };
//        InsertNodeInRange(llist1, data1);
//
//        SinglyLinkedListNode* fractionalNode1 = sll::GetFractionalNode(llist1->head, 7);
//        EXPECT_EQ(true, fractionalNode1 == nullptr);
//
//        sll::FreeSinglyLinkedList(llist1->head);
//    }
//
//    TEST(SLLTests_Get, GetFractionalNodeData_CorrectIndex) {
//
//        SinglyLinkedList* llist1 = new SinglyLinkedList();
//        vector<int> data1{ 1, 2, 3, 4, 5, 6 };
//        InsertNodeInRange(llist1, data1);
//
//        int fractionalData1 = sll::GetFractionalNodeData(llist1->head, 2);
//        EXPECT_EQ(3, fractionalData1);
//
//        sll::FreeSinglyLinkedList(llist1->head);
//
//        SinglyLinkedList* llist2 = new SinglyLinkedList();
//        vector<int> data2{ 2, 7, 9, 3, 5 };
//        InsertNodeInRange(llist2, data2);
//
//        int fractionalData2 = sll::GetFractionalNodeData(llist2->head, 3);
//        EXPECT_EQ(7, fractionalData2);
//
//        sll::FreeSinglyLinkedList(llist2->head);
//    }
//
//    TEST(SLLTests_Get, GetFractionalNodeData_NegativeIndex) {
//
//        SinglyLinkedList* llist1 = new SinglyLinkedList();
//        vector<int> data1{ 1, 2, 3, 4, 5, 6 };
//        InsertNodeInRange(llist1, data1);
//
//        int fractionalNodeData = sll::GetFractionalNodeData(llist1->head, -1);
//        EXPECT_EQ(-1, fractionalNodeData);
//
//        sll::FreeSinglyLinkedList(llist1->head);
//    }
//
//    TEST(SLLTests_Get, GetFractionalNodeData_OutOfRangeIndex) {
//
//        SinglyLinkedList* llist1 = new SinglyLinkedList();
//        vector<int> data1{ 1, 2, 3, 4, 5, 6 };
//        InsertNodeInRange(llist1, data1);
//
//        int fractionalNodeData = sll::GetFractionalNodeData(llist1->head, 7);
//        EXPECT_EQ(-1, fractionalNodeData);
//
//        sll::FreeSinglyLinkedList(llist1->head);
//    }
//
//    TEST(SLLTests_Get, GetModularNode_CorrectIndex) {
//
//        SinglyLinkedList* llist1 = new SinglyLinkedList();
//        vector<int> data1{ 1, 2, 3, 4, 5, 6, 7 };
//        InsertNodeInRange(llist1, data1);
//
//        SinglyLinkedListNode* modularNode1 = sll::GetModularNode(llist1->head, 3);
//        EXPECT_EQ(6, modularNode1->data);
//
//        sll::FreeSinglyLinkedList(llist1->head);
//
//        SinglyLinkedList* llist2 = new SinglyLinkedList();
//        vector<int> data2{ 3, 7, 1, 9, 8 };
//        InsertNodeInRange(llist2, data2);
//
//        SinglyLinkedListNode* modularNode2 = sll::GetModularNode(llist2->head, 2);
//        EXPECT_EQ(9, modularNode2->data);
//
//        sll::FreeSinglyLinkedList(llist2->head);
//    }
//
//    TEST(SLLTests_Get, GetModularNodeData_CorrectIndex) {
//
//        SinglyLinkedList* llist1 = new SinglyLinkedList();
//        vector<int> data1{ 1, 2, 3, 4, 5, 6, 7 };
//        InsertNodeInRange(llist1, data1);
//
//        int modular1 = sll::GetModularNodeData(llist1->head, 3);
//        EXPECT_EQ(6, modular1);
//
//        sll::FreeSinglyLinkedList(llist1->head);
//
//        SinglyLinkedList* llist2 = new SinglyLinkedList();
//        vector<int> data2{ 3, 7, 1, 9, 8 };
//        InsertNodeInRange(llist2, data2);
//
//        int modular2 = sll::GetModularNodeData(llist2->head, 2);
//        EXPECT_EQ(9, modular2);
//
//        sll::FreeSinglyLinkedList(llist2->head);
//    }
//
//
//    TEST(SLLTests_Get, GetNodeAddresses_CorrectInput) {
//
//        SinglyLinkedList* llist1 = new SinglyLinkedList();
//        vector<int> data1{ 1, 2, 3 };
//        InsertNodeInRange(llist1, data1);
//
//        SinglyLinkedListNode* node0 = sll::GetNode(llist1->head, 0);
//        SinglyLinkedListNode* node1 = sll::GetNode(llist1->head, 1);
//        SinglyLinkedListNode* node2 = sll::GetNode(llist1->head, 2);
//
//        std::unordered_set<uintptr_t> a = sll::GetNodeAddresses(llist1->head);
//
//        bool status0 = a.find(reinterpret_cast<uintptr_t>(node0)) != a.end();
//        EXPECT_EQ(true, status0);
//        bool status1 = a.find(reinterpret_cast<uintptr_t>(node1)) != a.end();
//        EXPECT_EQ(true, status1);
//        bool status2 = a.find(reinterpret_cast<uintptr_t>(node2)) != a.end();
//        EXPECT_EQ(true, status2);
//
//        sll::FreeSinglyLinkedList(llist1->head);
//    }
//}
