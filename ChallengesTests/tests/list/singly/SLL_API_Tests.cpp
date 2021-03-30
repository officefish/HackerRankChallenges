#include "./slltests.h"

namespace slltests {
    TEST(SLLTests_API, _0_1_Constructor) {
       SinglyLinkedList llist1;
       EXPECT_EQ(true, true);
    }

    TEST(SLLTests_API, _0_1_Constructor_toString) {
        SinglyLinkedList llist1;
        EXPECT_EQ("{}", llist1.toString());
    }

    TEST(SLLTests_API, _0_2_UniformConstructor) {
        SinglyLinkedList llist2{ 1, 2, 3 };
        EXPECT_EQ(true, true);
    }

    TEST(SLLTests_API, _0_2_UniformConstructor_toString) {
        SinglyLinkedList llist3{ 1, 2, 3 };
        string output = { "{1, 2, 3}" };
        string toStr = llist3.toString();
        EXPECT_EQ(output, toStr);
    }

    TEST(SLLTests_API, _0_3_UniformConstructor_Reference) {
        SinglyLinkedList * llist = new SinglyLinkedList{ 1, 2, 3 };
        delete llist;
        EXPECT_EQ(true, true);
    }

    TEST(SLLTests_API, _0_3_UniformConstructor_Reference_toString) {
        SinglyLinkedList* llist = new SinglyLinkedList{ 1, 2, 3 };
        string output = { "{1, 2, 3}" };
        string toStr = llist->toString();
        delete llist;
        EXPECT_EQ(output, toStr);
    }

    TEST(SLLTests_API, _0_4_Constructor_u_ptr) {
        std::unique_ptr<SinglyLinkedList> u_ptr = std::make_unique<SinglyLinkedList>();
        EXPECT_EQ(true, true);
    }

    TEST(SLLTests_API, _0_4_Constructor_u_ptr_toString) {
        std::unique_ptr<SinglyLinkedList> u_ptr = std::make_unique<SinglyLinkedList>();
        string output = { "{}" };
        string toStr = u_ptr->toString();
        EXPECT_EQ(output, toStr);
    }

    TEST(SLLTests_API, _0_5_CopyConstructor) {
        SinglyLinkedList a{ 1, 2, 3 };
        SinglyLinkedList b = a;
        EXPECT_EQ(true, true);
    }

    TEST(SLLTests_API, _0_5_CopyConstructor_EqualsData) {
        SinglyLinkedList a{ 1, 2, 3 };
        SinglyLinkedList b = a;
        EXPECT_EQ(a.toString(), b.toString());
    }

    TEST(SLLTests_API, _0_6_IntInsert) {
        SinglyLinkedList llist4;
        llist4.insert(1);
        string output = { "{1}" };
        EXPECT_EQ(output, llist4.toString());
    }

    TEST(SLLTests_API, _0_6_InitializeListInsert) {
        SinglyLinkedList llist5;
        llist5.insert({ 1, 2, 3 });
        string output = { "{1, 2, 3}" };
        EXPECT_EQ(output, llist5.toString());
    }

    TEST(SLLTests_API, _1_1_Insert_Int) {
        SinglyLinkedList list{ 2, 3, 4 };
        list.insert(1);
        string output = { "{1, 2, 3, 4}" };
        EXPECT_EQ(output, list.toString());
    }

    TEST(SLLTests_API, _1_1_Insert_InitializeList) {
        SinglyLinkedList list{ 4, 5, 6 };
        list.insert({ 1, 2, 3 });
        string output = { "{1, 2, 3, 4, 5, 6}" };
        EXPECT_EQ(output, list.toString());
    }

    TEST(SLLTests_API, _1_1_Insert_OneToAnother) {
        SinglyLinkedList list{ 4, 5, 6 };
        SinglyLinkedList list2{ 1, 2, 3 };
        list.insert(list2);
        string output = { "{1, 2, 3, 4, 5, 6}" };
        EXPECT_EQ(output, list.toString());
    }

    TEST(SLLTests_API, _1_2_BackInsert_Int) {
        SinglyLinkedList list{ 1, 2, 3 };
        list.back_insert(4);
        string output = { "{1, 2, 3, 4}" };
        EXPECT_EQ(output, list.toString());
    }

    TEST(SLLTests_API, _1_2_BackInsert_InitializeList) {
        SinglyLinkedList list{ 1, 2, 3 };
        list.back_insert({ 4, 5, 6 });
        string output = { "{1, 2, 3, 4, 5, 6}" };
        EXPECT_EQ(output, list.toString());
    }

    TEST(SLLTests_API, _1_2_BackInsert_OneToAnother) {
        SinglyLinkedList list{ 1, 2, 3 };
        SinglyLinkedList list2{ 4, 5, 6 };
        list.back_insert(list2);
        string output = { "{1, 2, 3, 4, 5, 6}" };
        EXPECT_EQ(output, list.toString());
    }

    TEST(SLLTests_API, _1_3_MiddleInsert_Int_Odd) {
        SinglyLinkedList list{ 1, 2, 4, 5 };
        list.middle_insert(3);
        string output = { "{1, 2, 3, 4, 5}" };
        EXPECT_EQ(output, list.toString());
    }

    TEST(SLLTests_API, _1_3_MiddleInsert_Int_Even) {
        SinglyLinkedList list{ 1, 3, 4 };
        list.middle_insert(2);
        string output = { "{1, 2, 3, 4}" };
        EXPECT_EQ(output, list.toString());
    }

    TEST(SLLTests_API, _1_3_MiddleInsert_InitializeList_Odd) {
        SinglyLinkedList list{ 1, 2, 5, 6 };
        list.middle_insert({ 3, 4 });
        string output = { "{1, 2, 3, 4, 5, 6}" };
        EXPECT_EQ(output, list.toString());
    }

    TEST(SLLTests_API, _1_3_MiddleInsert_InitializeList_Even) {
        SinglyLinkedList list{ 1, 2, 5, 6, 7 };
        list.middle_insert({ 3, 4 });
        string output = { "{1, 2, 3, 4, 5, 6, 7}" };
        EXPECT_EQ(output, list.toString());
    }

    TEST(SLLTests_API, _1_3_MiddleInsert_OneToAnother_Odd) {
        SinglyLinkedList list{ 1, 2, 5, 6 };
        SinglyLinkedList list2{ 3, 4 };
        list.middle_insert(list2);
        string output = { "{1, 2, 3, 4, 5, 6}" };
        EXPECT_EQ(output, list.toString());
    }

    TEST(SLLTests_API, _1_3_MiddleInsert_OneToAnother_Even) {
        SinglyLinkedList list{ 1, 2, 5, 6, 7 };
        SinglyLinkedList list2{ 3, 4 };
        list.middle_insert(list2);
        string output = { "{1, 2, 3, 4, 5, 6, 7}" };
        EXPECT_EQ(output, list.toString());
    }

    TEST(SLLTests_API, _1_4_IndexInsert_Int_Odd) {
        SinglyLinkedList list{ 1, 2, 4, 5 };
        list.index_insert(3, 2);
        string output = { "{1, 2, 3, 4, 5}" };
        EXPECT_EQ(output, list.toString());
    }

    TEST(SLLTests_API, _1_4_IndexInsert_Int_Even) {
        SinglyLinkedList list{ 1, 3, 4 };
        list.index_insert(2, 1);
        string output = { "{1, 2, 3, 4}" };
        EXPECT_EQ(output, list.toString());
    }

    TEST(SLLTests_API, _1_4_IndexInsert_Int_ZeroIndex) {
        SinglyLinkedList list{ 2, 3, 4, 5 };
        list.index_insert(1, 0);
        string output = { "{1, 2, 3, 4, 5}" };
        EXPECT_EQ(output, list.toString());
    }

    TEST(SLLTests_API, _1_4_IndexInsert_Int_NegativeIndex) {
        SinglyLinkedList list{ 2, 3, 4, 5 };
        list.index_insert(1, -2);
        string output = { "{2, 3, 4, 5, 1}" };
        EXPECT_EQ(output, list.toString());
    }

    TEST(SLLTests_API, _1_4_IndexInsert_Int_OutOfRangeIndex) {
        SinglyLinkedList list{ 1, 2, 3, 4, 5 };
        list.index_insert(6, 10);
        string output = { "{1, 2, 3, 4, 5, 6}" };
        EXPECT_EQ(output, list.toString());
    }

    TEST(SLLTests_API, _1_4_IndexInsert_Int_OutOfRangeIndex_INT32_MAX) {
        SinglyLinkedList list{ 1, 2, 3, 4, 5 };
        list.index_insert(6, INT32_MAX);
        string output = { "{1, 2, 3, 4, 5, 6}" };
        EXPECT_EQ(output, list.toString());
    }

    TEST(SLLTests_API, _1_4_IndexInsert_InitializeList_Odd) {
        SinglyLinkedList list{ 1, 2, 5, 6 };
        list.index_insert({ 3, 4 }, 2);
        string output = { "{1, 2, 3, 4, 5, 6}" };
        EXPECT_EQ(output, list.toString());
    }

    TEST(SLLTests_API, _1_4_IndexInsert_InitializeList_Even) {
        SinglyLinkedList list{ 1, 2, 5, 6, 7 };
        list.index_insert({ 3, 4 }, 2);
        string output = { "{1, 2, 3, 4, 5, 6, 7}" };
        EXPECT_EQ(output, list.toString());
    }

    TEST(SLLTests_API, _1_4_IndexInsert_InitializeList_ZeroIndex) {
        SinglyLinkedList list{ 1, 2, 3, 4, 5 };
        list.index_insert({ 10, 10 }, 0);
        string output = { "{10, 10, 1, 2, 3, 4, 5}" };
        EXPECT_EQ(output, list.toString());
    }

    TEST(SLLTests_API, _1_4_IndexInsert_InitializeList_NegativeIndex) {
        SinglyLinkedList list{ 1, 2, 3, 4, 5 };
        list.index_insert({ 10, 10 }, -1);
        string output = { "{1, 2, 3, 4, 5, 10, 10}" };
        EXPECT_EQ(output, list.toString());
    }

    TEST(SLLTests_API, _1_4_IndexInsert_InitializeList_OutOfRangeIndex) {
        SinglyLinkedList list{ 1, 2, 3, 4, 5 };
        list.index_insert({ 10, 10 }, 10);
        string output = { "{1, 2, 3, 4, 5, 10, 10}" };
        EXPECT_EQ(output, list.toString());
    }

    TEST(SLLTests_API, _1_4_IndexInsert_InitializeList_OutOfRangeIndex_INT32_MAX) {
        SinglyLinkedList list{ 1, 2, 3, 4, 5 };
        list.index_insert({ 10, 10 }, INT32_MAX);
        string output = { "{1, 2, 3, 4, 5, 10, 10}" };
        EXPECT_EQ(output, list.toString());
    }


    TEST(SLLTests_API, _1_4_IndexInsert_OneToAnother_Odd) {
        SinglyLinkedList list{ 1, 2, 5, 6 };
        SinglyLinkedList list2{ 3, 4 };
        list.index_insert(list2, 2);
        string output = { "{1, 2, 3, 4, 5, 6}" };
        EXPECT_EQ(output, list.toString());
    }

    TEST(SLLTests_API, _1_4_IndexInsert_OneToAnother_Even) {
        SinglyLinkedList list{ 1, 2, 5, 6, 7 };
        SinglyLinkedList list2{ 3, 4 };
        list.index_insert(list2, 2);
        string output = { "{1, 2, 3, 4, 5, 6, 7}" };
        EXPECT_EQ(output, list.toString());
    }

    TEST(SLLTests_API, _1_4_IndexInsert_OneToAnother_ZeroIndex) {
        SinglyLinkedList list{ 1, 2, 3, 4, 5 };
        SinglyLinkedList list2{ 10, 10 };
        list.index_insert(list2, 0);
        string output = { "{10, 10, 1, 2, 3, 4, 5}" };
        EXPECT_EQ(output, list.toString());
    }

    TEST(SLLTests_API, _1_4_IndexInsert_OneToAnother_NegativeIndex) {
        SinglyLinkedList list{ 1, 2, 3, 4, 5 };
        SinglyLinkedList list2{ 10, 10 };
        list.index_insert(list2, -1);
        string output = { "{1, 2, 3, 4, 5, 10, 10}" };
        EXPECT_EQ(output, list.toString());
    }

    TEST(SLLTests_API, _1_4_IndexInsert_OneToAnother_OutOfRangeIndex) {
        SinglyLinkedList list{ 1, 2, 3, 4, 5 };
        SinglyLinkedList list2{ 10, 10 };
        list.index_insert(list2, 10);
        string output = { "{1, 2, 3, 4, 5, 10, 10}" };
        EXPECT_EQ(output, list.toString());
    }

    TEST(SLLTests_API, _1_4_IndexInsert_OneToAnother_OutOfRangeIndex_INT32_MAX) {
        SinglyLinkedList list{ 1, 2, 3, 4, 5 };
        SinglyLinkedList list2{ 10, 10 };
        list.index_insert(list2, INT32_MAX);
        string output = { "{1, 2, 3, 4, 5, 10, 10}" };
        EXPECT_EQ(output, list.toString());
    }

    TEST(SLLTests_API, _1_5_AlternateInsert_InitaliserLizt_DefaultFrequency) {
        SinglyLinkedList list{ 1, 2, 3, 4, 5 };
        list.alternate_insert({ 10, 20, 30, 40, 50 });
        string output = { "{1, 10, 2, 20, 3, 30, 4, 40, 5, 50}" };
        EXPECT_EQ(output, list.toString());
    }

    TEST(SLLTests_API, _1_5_AlternateInsert_InitaliserLizt_ZeroFrequency) {
        SinglyLinkedList list{ 1, 2, 3, 4, 5 };
        list.alternate_insert({ 10, 20, 30, 40, 50 }, 0);
        string output = { "{1, 10, 2, 20, 3, 30, 4, 40, 5, 50}" };
        EXPECT_EQ(output, list.toString());
    }

    TEST(SLLTests_API, _1_5_AlternateInsert_InitaliserLizt_FrequencyIncrement) {
        SinglyLinkedList list{ 1, 2, 3, 4, 5 };
        list.alternate_insert({ 10, 20, 30, 40, 50 }, 3);
        string output = { "{1, 2, 3, 10, 20, 30, 4, 5, 40, 50}" };
        EXPECT_EQ(output, list.toString());
    }

    TEST(SLLTests_API, _1_5_AlternateInsert_InitaliserLizt_OutOfRange) {
        SinglyLinkedList list{ 1, 2, 3, 4, 5 };
        list.alternate_insert({ 10, 20, 30, 40, 50 }, 10);
        string output = { "{1, 2, 3, 4, 5, 10, 20, 30, 40, 50}" };
        EXPECT_EQ(output, list.toString());
    }

    TEST(SLLTests_API, _1_5_AlternateInsert_OneTwoAnother_DefaultFrequency) {
        SinglyLinkedList list{ 1, 2, 3, 4, 5 };
        SinglyLinkedList list2{ 10, 20, 30, 40, 50 };
        list.alternate_insert(list2);
        string output = { "{1, 10, 2, 20, 3, 30, 4, 40, 5, 50}" };
        EXPECT_EQ(output, list.toString());
    }

    TEST(SLLTests_API, _1_5_AlternateInsert_OneTwoAnother_ZeroFrequency) {
        SinglyLinkedList list{ 1, 2, 3, 4, 5 };
        SinglyLinkedList list2{ 10, 20, 30, 40, 50 };
        list.alternate_insert(list2, 0);
        string output = { "{1, 10, 2, 20, 3, 30, 4, 40, 5, 50}" };
        EXPECT_EQ(output, list.toString());
    }

    TEST(SLLTests_API, _1_5_AlternateInsert_OneTwoAnother_FrequencyIncrement) {
        SinglyLinkedList list{ 1, 2, 3, 4, 5 };
        SinglyLinkedList list2{ 10, 20, 30, 40, 50 };
        list.alternate_insert(list2, 3);
        string output = { "{1, 2, 3, 10, 20, 30, 4, 5, 40, 50}" };
        EXPECT_EQ(output, list.toString());
    }

    TEST(SLLTests_API, _1_5_AlternateInsert_OneTwoAnother_OutOfRange) {
        SinglyLinkedList list{ 1, 2, 3, 4, 5 };
        SinglyLinkedList list2{ 10, 20, 30, 40, 50 };
        list.alternate_insert(list2, 10);
        string output = { "{1, 2, 3, 4, 5, 10, 20, 30, 40, 50}" };
        EXPECT_EQ(output, list.toString());
    }
    
}