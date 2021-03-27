#include "./slltests.h"

namespace slltests {
    TEST(SLLTests_Split, SplitMiddle_CorrectInput) {

        SinglyLinkedList* llist1 = new SinglyLinkedList();
        std::vector<int> data1{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
        InsertNodeInRange(llist1, data1);

        SinglyLinkedListNode* left = nullptr;
        SinglyLinkedListNode* right = nullptr;

        sll::SplitMiddle(llist1->head, &left, &right);

        string leftStr = ToString(left);
        string output1{ "1, 2, 3, 4, 5" };
        EXPECT_EQ(output1, leftStr);

        string rightStr = ToString(right);
        string output2{ "6, 7, 8, 9, 10" };
        EXPECT_EQ(output2, rightStr);
    }

    TEST(SLLTests_Split, SplitAlternate_CorrectInput) {

        SinglyLinkedList* llist1 = new SinglyLinkedList();
        std::vector<int> data1{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
        InsertNodeInRange(llist1, data1);

        SinglyLinkedListNode* left = nullptr;
        SinglyLinkedListNode* right = nullptr;

        sll::SplitAlternate(llist1->head, &left, &right);

        string leftStr = ToString(left);
        string output1{ "1, 3, 5, 7, 9" };
        EXPECT_EQ(output1, leftStr);

        string rightStr = ToString(right);
        string output2{ "2, 4, 6, 8, 10" };
        EXPECT_EQ(output2, rightStr);
    }
}
