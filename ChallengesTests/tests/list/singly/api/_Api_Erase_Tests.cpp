#include ".././slltests.h"
namespace slltests {
    TEST(SLLTests_API, _2_0_Erase_ZeroIndex_OneElement) {
        SinglyLinkedList list{ 1, 2, 3, 4, 5, 6 };
        list.erase(0, 1);
        string output = { "{2, 3, 4, 5, 6}" };
        EXPECT_EQ(output, list.toString());
    }
    TEST(SLLTests_API, _2_0_Erase_CommonIndex_OneElement) {
        SinglyLinkedList list{ 1, 2, 3, 4, 5, 6 };
        list.erase(1, 1);
        string output = { "{1, 3, 4, 5, 6}" };
        EXPECT_EQ(output, list.toString());
    }

    TEST(SLLTests_API, _2_0_Erase_CommonIndex_SeveralElements) {
        SinglyLinkedList list{ 1, 2, 3, 4, 5, 6 };
        list.erase(1, 3);
        string output = { "{1, 5, 6}" };
        EXPECT_EQ(output, list.toString());
    }

    TEST(SLLTests_API, _2_0_Erase_CommonIndex_FullGroup) {
        SinglyLinkedList list{ 1, 2, 3, 4, 5, 6 };
        list.erase(1, 5);
        string output = { "{1}" };
        EXPECT_EQ(output, list.toString());
    }

    TEST(SLLTests_API, _2_0_Erase_CommonIndex_OutOfRangeCount) {
        SinglyLinkedList list{ 1, 2, 3, 4, 5, 6 };
        list.erase(1, 10);
        string output = { "{1}" };
        EXPECT_EQ(output, list.toString());
    }

    TEST(SLLTests_API, _2_0_Erase_ZeroIndex_OutOfRangeCount) {
        SinglyLinkedList list{ 1, 2, 3, 4, 5, 6 };
        list.erase(0, 10);
        string output = { "{}" };
        EXPECT_EQ(output, list.toString());
    }

    TEST(SLLTests_API, _2_0_Erase_StressArguments_OutOfRangeCount) {
        SinglyLinkedList list{ 1, 2, 3, 4, 5, 6 };
        string output = { "{}" };
        string output2 = { "{1, 2, 3, 4, 5, 6}" };
        EXPECT_EQ(output, list.concat().erase(0, INT32_MAX).toString());
        EXPECT_EQ(output, list.concat().erase(0, INT32_MIN).toString());
        EXPECT_EQ(output2, list.concat().erase(INT32_MAX - 1, INT32_MAX).toString());
        EXPECT_EQ(output2, list.concat().erase(INT32_MIN, INT32_MAX).toString());
    }

    TEST(SLLTests_API, _2_0_EraseBetween_CommonIndex_OneElement) {
        SinglyLinkedList list{ 1, 2, 3, 4, 5, 6 };
        list.erase_between(1, 1);
        string output = { "{1, 2, 3, 4, 5, 6}" };
        EXPECT_EQ(output, list.toString());
    }

    TEST(SLLTests_API, _2_0_EraseBetween_CommonIndex_SeveralElements) {
        SinglyLinkedList list{ 1, 2, 3, 4, 5, 6 };
        list.erase_between(1, 4);
        string output = { "{1, 5, 6}" };
        EXPECT_EQ(output, list.toString());
    }

    TEST(SLLTests_API, _2_0_EraseBetween_CommonIndex_FullGroup) {
        SinglyLinkedList list{ 1, 2, 3, 4, 5, 6 };
        list.erase_between(1, 6);
        string output = { "{1}" };
        EXPECT_EQ(output, list.toString());
    }

    TEST(SLLTests_API, _2_0_EraseBetween_RererseIndex_SeveralElements) {
        SinglyLinkedList list{ 1, 2, 3, 4, 5, 6 };
        list.erase_between(3, 1).print();
        string output = { "{1, 4, 5, 6}" };
        EXPECT_EQ(output, list.toString());
    }

    TEST(SLLTests_API, _2_0_EraseBetween_ReverseIndex_FullGroup) {
        SinglyLinkedList list{ 1, 2, 3, 4, 5, 6 };
        list.erase_between(5, 0).print();
        string output = { "{6}" };
        EXPECT_EQ(output, list.toString());
    }

    TEST(SLLTests_API, _2_0_EraseBetween_CommonIndex_OutOfRangeCount) {
        SinglyLinkedList list{ 1, 2, 3, 4, 5, 6 };
        list.erase_between(1, 10);
        string output = { "{1}" };
        EXPECT_EQ(output, list.toString());
    }

    TEST(SLLTests_API, _2_0_EraseBetween_ZeroIndex_OutOfRangeCount) {
        SinglyLinkedList list{ 1, 2, 3, 4, 5, 6 };
        list.erase_between(0, 10);
        string output = { "{}" };
        EXPECT_EQ(output, list.toString());
    }

    TEST(SLLTests_API, _2_0_EraseBetween_StressArguments_OutOfRangeCount) {
        SinglyLinkedList list{ 1, 2, 3, 4, 5, 6 };
        string output = { "{}" };
        string output2 = { "{1, 2, 3, 4, 5, 6}" };
        EXPECT_EQ(output, list.concat().erase_between(0, INT32_MAX).toString());
        EXPECT_EQ(output, list.concat().erase_between(0, INT32_MIN).toString());
        EXPECT_EQ(output2, list.concat().erase_between(INT32_MAX - 1, INT32_MAX).toString());
        EXPECT_EQ(output2, list.concat().erase_between(INT32_MIN, INT32_MAX).toString());
    }

}