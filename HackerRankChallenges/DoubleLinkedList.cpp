#include "./DoubleLinkedList.h"
#include <algorithm>

namespace dll {

    DoublyLinkedListNode::DoublyLinkedListNode(int node_data) {
        this->data = node_data;
        this->next = nullptr;
        this->prev = nullptr;
    }

    DoublyLinkedList::DoublyLinkedList() {
        this->head = nullptr;
        this->tail = nullptr;
    }

    void DoublyLinkedList::InsertNode(int node_data) {
        DoublyLinkedListNode* node = new DoublyLinkedListNode(node_data);
        if (!this->head) {
            this->head = node;
        } else {
            this->tail->next = node;
            node->prev = this->tail;
        }
        this->tail = node;
    }

    void PrintDoublyLinkedList(DoublyLinkedListNode* node, string sep, ostream& cout) {
        while (node) {
            cout << node->data;
            node = node->next;
            if (node)
                cout << sep;
        }
    }
    void FreeDoublyLinkedList(DoublyLinkedListNode* node) {
        while (node) {
            DoublyLinkedListNode* temp = node;
            node = node->next;
            free(temp);
        }
    }

    DoublyLinkedListNode* SortedInsert(DoublyLinkedListNode* head, int data) {
        DoublyLinkedListNode* target = new DoublyLinkedListNode(data);
        DoublyLinkedListNode* current = head;
        if (head == nullptr)
            return target;
        while (current != nullptr) {
            if (target->data < current->data) {
                if(current->prev != nullptr)
                    current->prev->next = target;
                if (current->next != nullptr)
                    target->next = current->next;
                return head;
            }
            current = current->next;
        }
        return head;
    }
    DoublyLinkedListNode* Reverse(DoublyLinkedListNode* head) {
        DoublyLinkedListNode* current = head;
        DoublyLinkedListNode* previous = nullptr;
        while (current != nullptr) {
            previous = current->prev;
            current->prev = current->next;
            current->next = previous;
            head = current;
            current = current->prev;
        }
        return head;
    }

}