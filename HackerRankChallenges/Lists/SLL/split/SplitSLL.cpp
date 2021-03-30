//#include "../.././SinglyLinkedList.h"
//
//namespace sll {
//
//
//
//    void SplitMiddle(SinglyLinkedListNode* head, SinglyLinkedListNode** left, SinglyLinkedListNode** right) {
//        if (not head) return;
//        if (not head->next) {
//            (*left) = head;
//            return;
//        }
//        (*left) = head;
//        SinglyLinkedListNode* tmp = GetPrevMiddleNode(head);
//        (*right) = tmp->next;
//        tmp->next = nullptr;
//    }
//
//    void SplitAlternate(SinglyLinkedListNode* head, SinglyLinkedListNode** even, SinglyLinkedListNode** odd) {
//        if (not head) return;
//        if (not head->next) {
//            (*even) = head;
//            (*odd) = nullptr;
//        }
//        (*even) = new  SinglyLinkedListNode(0);
//        (*odd) = new  SinglyLinkedListNode(0);
//        SinglyLinkedListNode* e = *even, * o = *odd;
//        int count = 0;
//        while (head) {
//            if (count % 2) {
//                o->next = head;
//                o = o->next;
//            } else {
//                e->next = head;
//                e = e->next;
//            }
//            count++;
//            head = head->next;
//        }
//        o->next = nullptr;
//        e->next = nullptr;
//        (*even) = (*even)->next;
//        (*odd) = (*odd)->next;
//    }
//  }