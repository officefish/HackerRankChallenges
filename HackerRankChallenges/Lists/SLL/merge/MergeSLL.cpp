#include "../.././SinglyLinkedList.h"

namespace sll {


    SinglyLinkedListNode* MergeSorted(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
        if (head1 == nullptr || head2 == nullptr) return nullptr;
        SinglyLinkedListNode* l1 = head1;
        SinglyLinkedListNode* l2 = head2;
        SinglyLinkedListNode* head;
        SinglyLinkedListNode* current;
        if (l1->data < l2->data) {
            head = l1;
            l1 = l1->next;
        }
        else {
            head = l2;
            l2 = l2->next;
        }
        current = head;
        for (;;) {
            if (l1 == nullptr && l2 == nullptr) {
                return head;
            }
            else if (l1 == nullptr) {
                current->next = l2;
                current = l2;
                l2 = l2->next;
            }
            else if (l2 == nullptr) {
                current->next = l1;
                current = l1;
                l1 = l1->next;
            }
            else {
                if (l1->data < l2->data) {
                    current->next = l1;
                    current = l1;
                    l1 = l1->next;
                }
                else {
                    current->next = l2;
                    current = l2;
                    l2 = l2->next;
                }
            }
        }
        return head;
    }

    SinglyLinkedListNode* MergeAlternate(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
        // Assign dummy Node
        SinglyLinkedListNode* head = new SinglyLinkedListNode(0);

        // curr is the pointer to this dummy Node, which will
        // be used to form the new list
        SinglyLinkedListNode* curr = head;
        while (head1 || head2) {
            // First add the element from list
            if (head1) {
                curr->next = head1;
                curr = curr->next;
                head1 = head1->next;
            }
            // Then add the element from the second list
            if (head2) {
                curr->next = head2;
                curr = curr->next;
                head2 = head2->next;
            }
        }
        // Assign the head of the new list to head pointer
        head = head->next;
        return head;
    }

    // Main function that inserts nodes of linked list q into p at
    // alternate positions. Since head of first list never changes
    // and head of second list may change, we need single pointer
    // for first list and double pointer for second list.
    void MergeAlternateModular(SinglyLinkedListNode** head1, SinglyLinkedListNode** head2) {
        SinglyLinkedListNode* curr1 = *head1, * curr2 = *head2;
        SinglyLinkedListNode* next1 = NULL, * next2 = NULL;

        // While there are avialable positions in list1
        while (curr1 != NULL && curr2 != NULL) {
            // Save next pointers
            next1 = curr1->next;
            next2 = curr2->next;
            // Make curr1 as next of curr2
            curr1->next = curr2;
            curr2->next = next1;
            // Update current pointers for next iteration
            curr1 = next1;
            curr2 = next2;
        }
        *head2 = curr2;
    }

    SinglyLinkedListNode* MergeInReverseOrder(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2)
    {
        // your code goes here
        // your code goes here
        if (not head1 and not head2) return nullptr;
        SinglyLinkedListNode* res = NULL;
        while (head1 and head2) {
            if (head1->data <= head2->data) {
                SinglyLinkedListNode* temp = head1->next;
                head1->next = res;
                res = head1;
                head1 = temp;
            }
            else {
                SinglyLinkedListNode* temp = head2->next;
                head2->next = res;
                res = head2;
                head2 = temp;
            }
        }
        while (head1) {
            SinglyLinkedListNode* temp = head1->next;
            head1->next = res;
            res = head1;
            head1 = temp;
        }
        while (head2) {
            SinglyLinkedListNode* temp = head2->next;
            head2->next = res;
            res = head2;
            head2 = temp;
        }
        return res;
    }

}