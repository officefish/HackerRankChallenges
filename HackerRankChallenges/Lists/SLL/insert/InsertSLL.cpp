#include "../.././SinglyLinkedList.h"

namespace sll {

    s_ptr Insert(s_ptr head, int data) {
        s_ptr newNode = std::make_shared<Node>(data);
        if (head) newNode->next = head;
        return newNode;
    }

    s_ptr BackInsert(s_ptr head, int data) {
        s_ptr newNode = std::make_shared<Node>(data);
        if (not head) return newNode;
        s_ptr current = head;
        while (current->next)
            current = current->next;
        current->next = newNode;
        return head;
    }

    s_ptr MiddleInsert(s_ptr head, int data) {
        s_ptr newNode = std::make_shared<Node>(data);
        if (not head) return newNode;
        s_ptr prev = GetPrevMiddle(head);
        newNode->next = prev->next;
        prev->next = newNode;
        return head;
    }

    s_ptr MiddleInsert(const s_ptr head1, const s_ptr head2) {
        if (not head1) return head2;
        if (not head2) return head1;
        s_ptr prev = GetPrevMiddle(head1);
        if (not prev) return head1;
        s_ptr current = head2;
        while (current->next)
            current = current->next;
        current->next = prev->next;
        prev->next = head2;
        return head1;
    }

    s_ptr IndexInsert(s_ptr head, int data, size_t index) {
        s_ptr newNode = std::make_shared<Node>(data);
        if (not head) return newNode;
        if (not index) {
            newNode->next = head;
            return newNode;
        }
        s_ptr prev = index ? GetByIndexOrLast(head, index - 1) : head;
        if (not prev) {
            newNode->next = head;
            return newNode;
        } else {
            newNode->next = prev->next;
            prev->next = newNode;
        }
        return head;
    }

    s_ptr IndexInsert(const s_ptr head1, const s_ptr head2, size_t index) {
        if (not head1) return head2;
        if (not head2) return head1;
        s_ptr prev = index ? GetByIndexOrLast(head1, index - 1) : head1;
        if (prev == head1)
            return Merge(head2, head1);
        s_ptr current = head2;
        while (current->next)
            current = current->next;
        current->next = prev->next;
        prev->next = head2;
        return head1;
    }

    s_ptr AlternateInsert(s_ptr head1, s_ptr head2, size_t frequency) {
        if (not frequency) frequency = 1;
        if (not head1) return head2;
        if (not head2) return head1;
        s_ptr dummy = std::make_shared<Node>(0);
        s_ptr dummyHead = dummy;
        size_t counter = 0;
        bool flag = true;
        bool end1 = false, end2 = false;
        s_ptr current = nullptr;
        for (;;) {
            if (counter == frequency) {
                flag = flag == true ? false : true;
                counter = 0;
            }
            ++counter;
            if (flag) {
                if (end1) continue;
                current = head1;
                if (head1->next) head1 = head1->next;
                else end1 = true;
            }
            else {
                if (end2) continue;
                current = head2;
                if (head2->next) head2 = head2->next;
                else end2 = true;
            }
            dummy->next = current;
            dummy = dummy->next;
            dummy->next = nullptr;
            if (end1 and end2) break;

        }
        return dummyHead->next;
    }

    s_ptr GroupInsert(s_ptr head1, s_ptr head2, size_t frequency) {
        if (not frequency) frequency = 1;
        if (not head1) return head2;
        if (not head2) return head1;
        s_ptr dummy = std::make_shared<Node>(0);
        s_ptr dummyHead = dummy;
        size_t counter = 0;
        bool flag = true;
        s_ptr current = head1;
        for (;;) {
            if (counter == frequency) {
                flag = false;
                counter = 0;
            }
            if (flag) {
                if (not current) break;
                ++counter;
                dummy->next = current;
                current = current->next;
                dummy = dummy->next;
            } else {
                s_ptr group_ptr = Copy(head2);
                while (group_ptr) {
                    dummy->next = group_ptr;
                    dummy = dummy->next;
                    group_ptr = group_ptr->next;
                }
                flag = true;
            }

        }
        //dummy->next = nullptr;
        return dummyHead->next;
    }

    s_ptr Repeat(s_ptr head, size_t limit) {
        if (not head) return nullptr;
        s_ptr dummy = std::make_shared <Node>(0);
        s_ptr dummy_head = dummy;
        for (size_t i = 0; i < limit; ++i) {
            s_ptr current = head;
            while (current) {
                dummy->next = std::make_shared <Node>(current->data);
                dummy = dummy->next;
                current = current->next;
            }
        }
        dummy_head = dummy_head->next;
        return dummy_head;
    }

}
//    SinglyLinkedListNode* InsertNodeAtPosition(SinglyLinkedListNode* head, int data, int position) {
//        SinglyLinkedListNode* newNode = new SinglyLinkedListNode(data);
//        SinglyLinkedListNode* previous = nullptr;
//        // empty list or 0 position
//        if (head == nullptr) return newNode;
//        if (position < 0) return head;
//        if (position == 0) {
//            newNode->next = head;
//            return newNode;
//        }
//        SinglyLinkedListNode* current = head;
//        while (position - 1 > 0) {
//            previous = current;
//            current = current->next;
//            --position;
//            if (current == nullptr) {
//                previous->next = newNode;
//                return head; // out of range
//            }
//        }
//        newNode->next = current->next;
//        current->next = newNode;
//        return head;
//    }
//
//    SinglyLinkedListNode* InsertNodeAtMiddle(SinglyLinkedListNode* head, int data) {
//        SinglyLinkedListNode* newNode = new SinglyLinkedListNode(data);
//        if (!head) return newNode;
//        SinglyLinkedListNode* slow = head;
//        SinglyLinkedListNode* prev = nullptr;
//        SinglyLinkedListNode* fast = head;
//        while (fast && fast->next) {
//            prev = slow;
//            slow = slow->next;
//            fast = fast->next->next;
//        }
//        newNode->next = slow;
//        if (prev) prev->next = newNode;
//        return head;
//    }
//
//
//
//
//    SinglyLinkedListNode* InsertInSortedNode(SinglyLinkedListNode* head, SinglyLinkedListNode* target) {
//        if (!head && target) {
//            target->next = head;
//            return target;
//        }
//        SinglyLinkedListNode* curr = head;
//        SinglyLinkedListNode* prev = nullptr;
//        while (curr) {
//            if (target->data < curr->data) {
//                if (prev) {
//                    prev->next = target;
//                    target->next = curr;
//                    return head;
//                } else {
//                    target->next = curr;
//                    return target;
//                }
//            }
//            prev = curr;
//            curr = curr->next;
//        }
//        if (prev) {
//            target->next = prev->next;
//            prev->next = target;
//        }
//        return head;
//    }
//
//    SinglyLinkedListNode* InsertInSortedData(SinglyLinkedListNode* head, int data) {
//        SinglyLinkedListNode* target = new SinglyLinkedListNode(data);
//        head = InsertInSortedNode(head, target);
//        return head;
//    }
//
//    SinglyLinkedListNode* InsertInCircularSorted(SinglyLinkedListNode* head, int data) {
//        SinglyLinkedListNode* current = head;
//        SinglyLinkedListNode* new_Node = new SinglyLinkedListNode(data);
//
//        // Case 1 of the above algo
//        if (current == NULL)
//        {
//            new_Node->next = new_Node;
//            return new_Node;
//        }
//
//        // Case 2 of the above algo
//        else if (current->data >= new_Node->data)
//        {
//            /* If value is smaller than head's value then
//            we need to change next of last Node */
//            while (current->next != head)
//                current = current->next;
//
//            current->next = new_Node;
//            new_Node->next = head;
//            return new_Node;
//        }
//
//        // Case 3 of the above algo
//        else
//        {
//            /* Locate the Node before the point of insertion */
//            while (current->next != head &&
//                current->next->data < new_Node->data)
//                current = current->next;
//
//            new_Node->next = current->next;
//            current->next = new_Node;
//            return head;
//        }
//    }
//}
