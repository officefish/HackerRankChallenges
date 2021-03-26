#include "./slltests.h"

    namespace slltests {
    TEST(SinglyListChallengesTests, MergeSorted_Test1) {
        // initial
        SinglyLinkedList* llist1 = new SinglyLinkedList();
        vector<int> data1{ 1, 2, 3, 4, 5 };
        InsertNodeInRange(llist1, data1);
        SinglyLinkedList* llist2 = new SinglyLinkedList();
        vector<int> data2{ 6, 7, 8, 9, 10 };
        InsertNodeInRange(llist2, data2);

        // mergeSorted
        SinglyLinkedList* llist3 = new SinglyLinkedList();
        llist3->head = sll::MergeSorted(llist1->head, llist2->head);

        string listStr = ToString(llist3->head);
        string output{ "1, 2, 3, 4, 5, 6, 7, 8, 9, 10" };
        EXPECT_EQ(output, listStr);

        sll::FreeSinglyLinkedList(llist3->head);
    }
}
