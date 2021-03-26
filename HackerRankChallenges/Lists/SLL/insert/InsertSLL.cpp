#include "../.././SinglyLinkedList.h"

namespace sll {
    SinglyLinkedListNode* InsertNodeAtHead(SinglyLinkedListNode* head, int data) {
        SinglyLinkedListNode* newNode = new SinglyLinkedListNode(data);
        if (head == nullptr) return newNode;
        newNode->next = head;
        return newNode;
    }
    SinglyLinkedListNode* InsertNodeAtTail(SinglyLinkedListNode* head, int data) {
        SinglyLinkedListNode* newNode = new SinglyLinkedListNode(data);
        if (head == nullptr) return newNode;
        SinglyLinkedListNode* currentNode = head;
        while (currentNode->next != nullptr) {
            currentNode = currentNode->next;
        }
        currentNode->next = newNode;
        return head;
    }
    SinglyLinkedListNode* InsertNodeAtPosition(SinglyLinkedListNode* head, int data, int position) {
        SinglyLinkedListNode* newNode = new SinglyLinkedListNode(data);
        SinglyLinkedListNode* previous = nullptr;
        // empty list or 0 position
        if (head == nullptr) return newNode;
        if (position < 0) return head;
        if (position == 0) {
            newNode->next = head;
            return newNode;
        }
        SinglyLinkedListNode* current = head;
        while (position - 1 > 0) {
            previous = current;
            current = current->next;
            --position;
            if (current == nullptr) {
                previous->next = newNode;
                return head; // out of range
            }
        }
        newNode->next = current->next;
        current->next = newNode;
        return head;
    }

    SinglyLinkedListNode* InsertNodeAtMiddle(SinglyLinkedListNode* head, int data) {
        SinglyLinkedListNode* newNode = new SinglyLinkedListNode(data);
        if (!head) return newNode;
        SinglyLinkedListNode* slow = head;
        SinglyLinkedListNode* prev = nullptr;
        SinglyLinkedListNode* fast = head;
        while (fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        newNode->next = slow;
        if (prev) prev->next = newNode;
        return head;
    }




    SinglyLinkedListNode* InsertInSortedNode(SinglyLinkedListNode* head, SinglyLinkedListNode* target) {
        if (!head && target) {
            target->next = head;
            return target;
        }
        SinglyLinkedListNode* curr = head;
        SinglyLinkedListNode* prev = nullptr;
        while (curr) {
            if (target->data < curr->data) {
                if (prev) {
                    prev->next = target;
                    target->next = curr;
                    return head;
                } else {
                    target->next = curr;
                    return target;
                }
            }
            prev = curr;
            curr = curr->next;
        }
        if (prev) {
            target->next = prev->next;
            prev->next = target;
        }
        return head;
    }

    SinglyLinkedListNode* InsertInSortedData(SinglyLinkedListNode* head, int data) {
        SinglyLinkedListNode* target = new SinglyLinkedListNode(data);
        head = InsertInSortedNode(head, target);
        return head;
    }
}
