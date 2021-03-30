/*
Solution Copyright(c) 2021 Officefish / Techies Team.
*/
#include ".././Challenges.h"
#include "./SinglyLinkedList.h"

namespace {
    using std::cin, std::cout, std::endl;
    using std::max;
    using std::streamsize, std::numeric_limits;
    using sll::SinglyLinkedList, sll::SinglyLinkedListNode;

    void InsertNodeInRange(SinglyLinkedList* llist, int llist_count) {
        for (int i = 0; i < llist_count; i++) {
            int llist_item;
            cin >> llist_item;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            llist->insert(llist_item);
        }
    }

}

int listInitializeChallenge() {

    return 0;
}

int listUniformInitializeChallenge() {

   /* SinglyLinkedList list;
    list.partial_permutation(10).print();
    cout << endl;
    list.concat().partial_permutation(10,false).print();
    cout << endl;
    list.concat().partial_combination(7, 5).print();
    cout << endl;
    list.concat().partial_combination(7, 5, false).print();
    cout << endl;
    list.concat().partial_reflection(7, 5).repeat(7).print();
    cout << endl;
    list.concat().partial_reflection(7, 5, false).print();*/

    //SinglyLinkedList list{ 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    //SinglyLinkedList list2{ 10, 20, 30, 40, 50 };




    //SinglyLinkedList list{ 1, 3, 4 };
    //list.index_insert(2, 1).print();
    //SinglyLinkedList list{ 1, 2, 5, 6 };

    //list.index_insert(3, 2).print();
    //list.index_insert(4, 3).print();
    //list.index_insert(10, 0).print();
    //list.concat().index_insert(10, 100).print();
    //list.concat().erase(1, 5).print();
    //list.concat().erase_between(1, 5).print();
    SinglyLinkedList list{ 1, 2, 3, 4, 5, 6 };

    list.concat().erase_between(1, 1).print();
    list.concat().erase_between(1, 4).print();
    list.concat().erase_between(5, 0).print();

    //list.concat().erase(7, 5).print();
    //list.concat().erase_between(7, 5).print();

    //list.concat().erase(3, 9).print();
    //list.concat().erase_between(3, 9).print();
    //list.index_insert(list2, 2).print();

    //list.insert(list2).reverse_print(); // same

    return 0;
}

/*

int insertNodeAtHeadChallenge() {
    SinglyLinkedList* llist = new SinglyLinkedList();
    int llist_count;
    cin >> llist_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    for (int i = 0; i < llist_count; i++) {
        int llist_item;
        cin >> llist_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        SinglyLinkedListNode* llist_head = InsertNodeAtHead(llist->head, llist_item);
        llist->head = llist_head;
    }
    sll::Print(llist->head, " ", std::cout);
    std::cout << "\n";
    sll::FreeSinglyLinkedList(llist->head);
    return 0;
}

int insertNodeAtPositionChallenge() {
    SinglyLinkedList* llist = new SinglyLinkedList();
    int llist_count;
    cin >> llist_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    InsertNodeInRange(llist, llist_count);
    int data;
    cin >> data;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    int position;
    cin >> position;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    SinglyLinkedListNode* llist_head = reinterpret_cast<SinglyLinkedListNode*>(
        sll::InsertNodeAtPosition(llist->head, data, position)
    );
    sll::Print(llist_head, " ", std::cout);
    std::cout << "\n";
    FreeSinglyLinkedList(llist_head);
    return 0;
}

int deleteNodeChallenge() {
    SinglyLinkedList* llist = new SinglyLinkedList();
    int llist_count;
    cin >> llist_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    InsertNodeInRange(llist, llist_count);
    int position;
    cin >> position;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    SinglyLinkedListNode* llist1 = reinterpret_cast<SinglyLinkedListNode*>(
        sll::DeleteNode(llist->head, position)
    );
    sll::Print(llist1, " ", cout);
    cout << "\n";
    sll::FreeSinglyLinkedList(llist1);
    return 0;
}

int printListChallenge() {
    SinglyLinkedList* llist = new SinglyLinkedList();
    int llist_count;
    cin >> llist_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    InsertNodeInRange(llist, llist_count);
    Print(llist->head, " ", cout);
    return 0;
}

int printReverseChallenge() {
    int tests;
    cin >> tests;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    for (int tests_itr = 0; tests_itr < tests; tests_itr++) {
        sll::SinglyLinkedList* llist = new sll::SinglyLinkedList();
        int llist_count;
        cin >> llist_count;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        InsertNodeInRange(llist, llist_count);
        sll::ReversePrint(llist->head, " ", cout);
    }
    return 0;
}

int instertNodeAtTailChallenge() {
    SinglyLinkedList* llist = new SinglyLinkedList();
    int llist_count;
    cin >> llist_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    for (int i = 0; i < llist_count; i++) {
        int llist_item;
        cin >> llist_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        SinglyLinkedListNode* llist_head = InsertNodeAtTail(llist->head, llist_item);
        llist->head = llist_head;
    }
    sll::Print(llist->head, " ", cout);
    cout << "\n";
    sll::FreeSinglyLinkedList(llist->head);
    return 0;
}

int reverseListChallenge() {
    int tests;
    cin >> tests;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    for (int tests_itr = 0; tests_itr < tests; tests_itr++) {
        SinglyLinkedList* llist = new SinglyLinkedList();
        int llist_count;
        cin >> llist_count;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        InsertNodeInRange(llist, llist_count);
        SinglyLinkedListNode* llist1 = Reverse(llist->head);
        sll::Print(llist1, " ", cout);
        cout << "\n";
        sll::FreeSinglyLinkedList(llist1);
    }
    return 0;
}

int getNodeDataChallenge() {
    int tests;
    cin >> tests;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    for (int tests_itr = 0; tests_itr < tests; tests_itr++) {
        SinglyLinkedList* llist = new SinglyLinkedList();
        int llist_count;
        cin >> llist_count;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        InsertNodeInRange(llist, llist_count);
        int position;
        cin >> position;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        int result = sll::GetNodeData(llist->head, position);
        cout << result << "\n";
    }
    return 0;
}

int compareListsChallenge() {
    int tests;
    cin >> tests;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    for (int tests_itr = 0; tests_itr < tests; tests_itr++) {
        SinglyLinkedList* llist1 = new SinglyLinkedList();
        int llist1_count;
        cin >> llist1_count;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        InsertNodeInRange(llist1, llist1_count);

        SinglyLinkedList* llist2 = new SinglyLinkedList();
        int llist2_count;
        cin >> llist2_count;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        InsertNodeInRange(llist2, llist2_count);

        bool result = sll::CompareLists(llist1->head, llist2->head);
        cout << result << "\n";

        sll::FreeSinglyLinkedList(llist1->head);
        sll::FreeSinglyLinkedList(llist2->head);
    }
    return 0;
}

int sortListChallenge() {
    SinglyLinkedList* llist1 = new SinglyLinkedList();
    llist1->insert(1);
    llist1->insert(2);
    llist1->insert(3);
    llist1->insert(4);
    llist1->insert(5);

    //cout << llist1->size() << endl;

    SinglyLinkedList* llist2 = new SinglyLinkedList();
    llist2->insert(2);
    llist2->insert(4);
    llist2->insert(3);
    llist2->insert(5);
    llist2->insert(1);

    sll::SortBubble(llist2->head);

    sll::Print(llist2->head, " ", cout);

    bool result = sll::CompareLists(llist1->head, llist2->head);
    cout << std::boolalpha << result << "\n";

    sll::FreeSinglyLinkedList(llist1->head);
    sll::FreeSinglyLinkedList(llist2->head);

    return 0;
}

int mergeSinglySortedChallenge() {
    SinglyLinkedList* llist1 = new SinglyLinkedList();
    llist1->insert(1);
    llist1->insert(2);
    llist1->insert(1);
    llist1->insert(4);
    llist1->insert(3);

    SinglyLinkedList* llist2 = new SinglyLinkedList();
    llist2->insert(2);
    llist2->insert(4);
    llist2->insert(3);
    llist2->insert(5);
    llist2->insert(1);

    SinglyLinkedListNode* llist1_head = sll::SortBubble(llist1->head);
    SinglyLinkedListNode* llist2_head = sll::SortBubble(llist2->head);

    SinglyLinkedListNode* merged = sll::MergeSorted(llist1_head, llist2_head);

    sll::Print(merged, " ", cout);

    sll::FreeSinglyLinkedList(merged);
    return 0;
}

int findMergePointChallenge() {
    int tests;
    cin >> tests;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    for (int tests_itr = 0; tests_itr < tests; tests_itr++) {
        int index;
        cin >> index;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        SinglyLinkedList* llist1 = new SinglyLinkedList();
        int llist1_count;
        cin >> llist1_count;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        InsertNodeInRange(llist1, llist1_count);

        SinglyLinkedList* llist2 = new SinglyLinkedList();
        int llist2_count;
        cin >> llist2_count;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        InsertNodeInRange(llist2, llist2_count);

        SinglyLinkedListNode* ptr1 = llist1->head;
        SinglyLinkedListNode* ptr2 = llist2->head;

        for (int i = 0; i < llist1_count; i++) {
            if (i < index)
                ptr1 = ptr1->next;
        }
        for (int i = 0; i < llist2_count; i++) {
            if (i != llist2_count - 1)
                ptr2 = ptr2->next;
        }
        ptr2->next = ptr1;
        int result = sll::FindIntersectionEntyValue(llist1->head, llist2->head);
        cout << result << "\n";
    }
    return 0;
}

int removeDuplicatesInSortedChallenge() {
    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        SinglyLinkedList* llist = new SinglyLinkedList();

        int llist_count;
        cin >> llist_count;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        InsertNodeInRange(llist, llist_count);

        SinglyLinkedListNode* llist1 = sll::RemoveDuplicatesInSorted(llist->head);
        sll::Print(llist1, " ", cout);
        cout << "\n";
        sll::FreeSinglyLinkedList(llist1);
    }
    return 0;
}

void InsertNodeInRange(SinglyLinkedList* llist, const std::vector<int>& datas) {
    for (const auto& i : datas) {
        llist->insert(i);
    }
}

int listHasCycleChallenge() {
    int tests;
    cin >> tests;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int tests_itr = 0; tests_itr < tests; tests_itr++) {
        int index;
        cin >> index;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        SinglyLinkedList* llist = new SinglyLinkedList();

        int llist_count;
        cin >> llist_count;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        InsertNodeInRange(llist, llist_count);

        SinglyLinkedListNode* extra = new SinglyLinkedListNode(-1);
        SinglyLinkedListNode* temp = llist->head;

        for (int i = 0; i < llist_count; i++) {
            if (i == index) {
                extra = temp;
            }
            if (i != llist_count - 1) {
                temp = temp->next;
            }
        }

        temp->next = extra;
        bool result = sll::HasCycle(llist->head);
        cout << result << "\n";
    }
    return 0;
}

int deleteNthNodeChallenge() {
    SinglyLinkedList* llist1 = new SinglyLinkedList();
    std::vector<int> data1{ 1, 2, 3, 4, 5, 6 };
    InsertNodeInRange(llist1, data1);
    // delete
    llist1->head = sll::DeleteEveryNthNode(llist1->head, -1);
    sll::Print(llist1->head, " ", cout);
    return 0;
    //std::string listStr = ToString(llist1->head);
}

int countCommonNodesChallenge() {
    SinglyLinkedList* llist1 = new SinglyLinkedList();
    std::vector<int> data1{ 1, 2, 3, 4, 5 };
    InsertNodeInRange(llist1, data1);

    SinglyLinkedList* llist2 = new SinglyLinkedList();
    std::vector<int> data2{ 1, 2, 3, 4, 5 };
    InsertNodeInRange(llist2, data2);

    int result = sll::CountCommonNodes(llist1->head, llist2->head);
    cout << result << endl;
    return 0;
}

int splitMiddleChallenge() {

    cout << "SplitMiddleChallenge" << endl;

    SinglyLinkedList* llist1 = new SinglyLinkedList();
    std::vector<int> data1{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    InsertNodeInRange(llist1, data1);

    SinglyLinkedListNode* left = nullptr;
    SinglyLinkedListNode* right = nullptr;

    sll::SplitMiddle(llist1->head, &left, &right);
    cout << sll::Size(left) << " " << sll::Size(right) << endl;
    sll::Print(left, " ", cout);
    cout << endl;
    sll::Print(right, " ", cout);

    return 0;
}

int splitEvenOddChallenge() {

    SinglyLinkedList* llist1 = new SinglyLinkedList();
    std::vector<int> data1{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    InsertNodeInRange(llist1, data1);

    SinglyLinkedListNode* left = nullptr;
    SinglyLinkedListNode* right = nullptr;

    sll::SplitAlternate(llist1->head, &left, &right);
    cout << sll::Size(left) << " " << sll::Size(right) << endl;
    sll::Print(left, " ", cout);
    cout << endl;
    sll::Print(right, " ", cout);

    return 0;
}

int reorderChallenge() {

    SinglyLinkedList* llist1 = new SinglyLinkedList();
    std::vector<int> data1{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    InsertNodeInRange(llist1, data1);

    SinglyLinkedListNode* merged = sll::Reorder(llist1->head);
    //sll::ModularAlternateMerge(&left, &right);
    //cout << sll::Size(merged) << endl;
    sll::Print(merged, " ", cout);

    return 0;
}

*/
