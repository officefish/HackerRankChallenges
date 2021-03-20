/*
Solution Copyright(c) 2021 Officefish / Techies Team.
*/
#include "./Challenges.h"
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
            llist->InsertNode(llist_item);
        }
    }

}

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
    sll::PrintSinglyLinkedList(llist->head, " ", std::cout);
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
    sll::PrintSinglyLinkedList(llist_head, " ", std::cout);
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
    sll::PrintSinglyLinkedList(llist1, " ", cout);
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
    Print(llist->head);
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
        sll::ReversePrint(llist->head);
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
    sll::PrintSinglyLinkedList(llist->head, " ", cout);
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
        sll::PrintSinglyLinkedList(llist1, " ", cout);
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
    llist1->InsertNode(1);
    llist1->InsertNode(2);
    llist1->InsertNode(3);
    llist1->InsertNode(4);
    llist1->InsertNode(5);

    //cout << llist1->size() << endl;

    SinglyLinkedList* llist2 = new SinglyLinkedList();
    llist2->InsertNode(2);
    llist2->InsertNode(4);
    llist2->InsertNode(3);
    llist2->InsertNode(5);
    llist2->InsertNode(1);

    sll::Sort(llist2->head);

    sll::PrintSinglyLinkedList(llist2->head, " ", cout);

    bool result = sll::CompareLists(llist1->head, llist2->head);
    cout << std::boolalpha << result << "\n";

    sll::FreeSinglyLinkedList(llist1->head);
    sll::FreeSinglyLinkedList(llist2->head);

    return 0;
}

int mergeSinglySortedChallenge() {
    SinglyLinkedList* llist1 = new SinglyLinkedList();
    llist1->InsertNode(1);
    llist1->InsertNode(2);
    llist1->InsertNode(1);
    llist1->InsertNode(4);
    llist1->InsertNode(3);

    SinglyLinkedList* llist2 = new SinglyLinkedList();
    llist2->InsertNode(2);
    llist2->InsertNode(4);
    llist2->InsertNode(3);
    llist2->InsertNode(5);
    llist2->InsertNode(1);

    SinglyLinkedListNode* llist1_head = sll::Sort(llist1->head);
    SinglyLinkedListNode* llist2_head = sll::Sort(llist2->head);

    SinglyLinkedListNode* merged = sll::MergeSorted(llist1_head, llist2_head);

    sll::PrintSinglyLinkedList(merged, " ", cout);

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
        int result = sll::MergedEntyNodeValue(llist1->head, llist2->head);
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
        sll::PrintSinglyLinkedList(llist1, " ", cout);
        cout << "\n";
        sll::FreeSinglyLinkedList(llist1);
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
