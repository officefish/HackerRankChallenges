#include "../.././SinglyLinkedList.h"

namespace sll {



    void SplitMiddle(SinglyLinkedListNode* head, SinglyLinkedListNode** left, SinglyLinkedListNode** right) {
        if (not head) return;
        if (not head->next) {
            (*left) = head;
            return;
        }
        (*left) = head;
        SinglyLinkedListNode* tmp = GetPrevMiddleNode(head);
        (*right) = tmp->next;
        tmp->next = nullptr;
    }

    void SplitAlternate(SinglyLinkedListNode* head, SinglyLinkedListNode** even, SinglyLinkedListNode** odd) {
        if (not head) return;
        if (not head->next) {
            (*even) = head;
            (*odd) = nullptr;
        }
        (*even) = new  SinglyLinkedListNode(0);
        (*odd) = new  SinglyLinkedListNode(0);
        SinglyLinkedListNode* e = *even, * o = *odd;
        int count = 0;
        while (head) {
            if (count % 2) {
                o->next = head;
                o = o->next;
            }
            else {
                e->next = head;
                e = e->next;
            }
            count++;
            head = head->next;
        }
        o->next = nullptr;
        e->next = nullptr;
        (*even) = (*even)->next;
        (*odd) = (*odd)->next;
    }

    void AlternatingSplitList(SinglyLinkedListNode* head,
        SinglyLinkedListNode* split1, SinglyLinkedListNode* split2) {
        if (!head) return;
        if (!(head->next)) {
            split1 = head;
            split2 = NULL;
            return;
        }
        bool p = true;
        split1 = NULL;
        split2 = NULL;
        SinglyLinkedListNode* tail1 = NULL;
        SinglyLinkedListNode* tail2 = NULL;
        while (head) {
            if (p == true) {
                if (split1 == NULL) {
                    split1 = head;
                    tail1 = head;
                }
                else {
                    tail1->next = head;
                    tail1 = tail1->next;
                }
                head = head->next;
                p = false;
            }
            else {
                if (split2 == NULL) {
                    split2 = head;
                    tail2 = head;
                }
                else {
                    tail2->next = head;
                    tail2 = tail2->next;
                }
                head = head->next;
                p = true;
            }
        }
        tail1->next = NULL;
        tail2->next = NULL;
    }
}