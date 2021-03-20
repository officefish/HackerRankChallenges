/*
Solution Copyright(c) 2021 Officefish / Techies Team.
*/
#include ".././Challenges.h"
#include "./DoubleLinkedList.h"

namespace {
    using std::cin, std::cout, std::endl;
    using std::max;
    using std::streamsize, std::numeric_limits;
    using dll::DoublyLinkedList, dll::DoublyLinkedListNode;

    void InsertNodeInRange(DoublyLinkedList* llist, int llist_count) {
        for (int i = 0; i < llist_count; i++) {
            int llist_item;
            cin >> llist_item;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            llist->InsertNode(llist_item);
        }
    }
}

int sortedInsertChallenge() {
    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        DoublyLinkedList* llist = new DoublyLinkedList();

        int llist_count;
        cin >> llist_count;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        InsertNodeInRange(llist, llist_count);

        int data;
        cin >> data;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        DoublyLinkedListNode* llist1 = dll::SortedInsert(llist->head, data);

        dll::PrintDoublyLinkedList(llist1, " ", cout);
        cout << "\n";

        dll::FreeDoublyLinkedList(llist1);
    }
    return 0;
}
