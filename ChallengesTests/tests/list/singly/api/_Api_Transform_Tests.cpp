#include ".././slltests.h"
namespace slltests {

    TEST(SLLTests_API, _7_0_Partial_Permutation_Set) {
        SinglyLinkedList list;
        list.partial_permutation(7, false);
        string output = { "{5040, 720, 120, 24, 6, 2, 1}" };
        EXPECT_EQ(output, list.toString());
    }

    TEST(SLLTests_API, _7_0_Partial_Permutation_Result) {
        SinglyLinkedList list;
        list.partial_permutation(7, true);
        string output = { "{5040}" };
        EXPECT_EQ(output, list.toString());
    }

    TEST(SLLTests_API, _7_0_Partial_Combination_Set) {
        SinglyLinkedList list;
        list.partial_combination(7, 5, false);
        string output = { "{2520, 360, 60, 12, 3, 1}" };
        EXPECT_EQ(output, list.toString());
    }

    TEST(SLLTests_API, _7_0_Partial_Combination_Result) {
        SinglyLinkedList list;
        list.partial_combination(7, 5, true);
        string output = { "{2520}" };
        EXPECT_EQ(output, list.toString());
    }

    TEST(SLLTests_API, _7_0_Partial_Reflection_Set) {
        SinglyLinkedList list;
        list.partial_reflection(7, 5, false);
        string output = { "{21, 15, 10, 6, 3, 1}" };
        EXPECT_EQ(output, list.toString());
    }

    TEST(SLLTests_API, _7_0_Partial_Reflection_Result) {
        SinglyLinkedList list;
        list.partial_reflection(7, 5, true);
        string output = { "{21}" };
        EXPECT_EQ(output, list.toString());
    }

    TEST(SLLTests_API, _7_1_Repeat_10) {
        SinglyLinkedList list{1};
        list.repeat(10);
        string output = { "{1, 1, 1, 1, 1, 1, 1, 1, 1, 1}" };
        EXPECT_EQ(output, list.toString());
    }
}
