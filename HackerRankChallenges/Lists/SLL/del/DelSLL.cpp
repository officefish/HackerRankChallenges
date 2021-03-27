#include "../.././SinglyLinkedList.h"

namespace sll {

    SinglyLinkedListNode* DeleteNode(SinglyLinkedListNode* head, int position) {
        if (head == nullptr || position < 0) return head;
        SinglyLinkedListNode* currentNode = head;
        SinglyLinkedListNode* previousNode = nullptr;
        if (position == 0) {
            if (head->next != nullptr)
                head = head->next;
            free(currentNode);
            return head;
        }
        while (position > 0) {
            previousNode = currentNode;
            currentNode = currentNode->next;
            --position;
            if (currentNode == nullptr) return head; // out of range
        }
        previousNode->next = currentNode->next;
        free(currentNode);
        return head;
    }

    SinglyLinkedListNode* DeleteNodeByValue(SinglyLinkedListNode* head, int value) {
        if (head == nullptr) return head;
        SinglyLinkedListNode* current = head;
        SinglyLinkedListNode* previous = nullptr;
        while (current != nullptr) {
            if (current->data == value) {
                SinglyLinkedListNode* tmp = current;
                current = current->next;
                if (previous != nullptr) previous->next = current;
                free(tmp);
            }
            else {
                previous = current;
                current = current->next;
            }
        }
        return head;
    }


    SinglyLinkedListNode* DeleteMiddle(SinglyLinkedListNode* head) {
        if (!head) return nullptr;
        SinglyLinkedListNode* slow = head;
        SinglyLinkedListNode* prev = nullptr;
        SinglyLinkedListNode* fast = head->next; // !
        int counter = 0;
        while (fast && fast->next) {
            counter++;
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        if (prev) prev->next = slow->next;
        delete slow;
        return head;
    }

    SinglyLinkedListNode* DeleteEveryNthNode(SinglyLinkedListNode* head, int Nth) {
        if (!head) return nullptr;
        //will always result in empty string
        if (Nth <= 1) {
            sll::FreeSinglyLinkedList(head);
            return nullptr;
        }
        SinglyLinkedListNode* curr = head, * prev = NULL;
        // Traverse list and delete every k-th node
        int count = 0;
        while (curr) {
            // increment Node count
            count++;
            // check if count is equal to k
            // if yes, then delete current Node
            if (Nth == count) {
                // put the next of current Node in
                // the next of previous Node
                SinglyLinkedListNode* tmp = curr;
                curr = curr->next;
                if (prev) prev->next = curr;
                delete (tmp);
                // set count = 0 to reach further k-th Node
                count = 0;
            }
            else {
                prev = curr;
                curr = curr->next;
            }
        }
        return head;
    }

    void DeleteWithoutHeadPointer(SinglyLinkedListNode* node) {
        SinglyLinkedListNode* prev = NULL;
        while (node->next) {
            node->data = std::move(node->next->data);
            prev = node;
            node = node->next;
        }
        if (prev) prev->next = NULL;
        delete (node);
    }

    SinglyLinkedListNode* RemoveDublicates(SinglyLinkedListNode* head) {
        std::multiset<int> datas;
        SinglyLinkedListNode* curr = head;
        SinglyLinkedListNode* prev = nullptr;
        while (curr) {
            if (datas.count(curr->data)) {
                SinglyLinkedListNode* tmp = curr;
                curr = curr->next;
                if (prev) prev->next = curr;
                delete (tmp);
            }
            else {
                datas.insert(curr->data);
                prev = curr;
                curr = curr->next;
            }
        }
        return head;
    }

    SinglyLinkedListNode* RemoveDublicatesPairs(SinglyLinkedListNode* head) {
        // create a dummy node that acts like a fake head of list
        // pointing to the original head
        SinglyLinkedListNode* dummy = new SinglyLinkedListNode(-1);
        // dummy node points to the original head
        dummy->next = head;
        // Node pointing to last node which has no duplicate.
        SinglyLinkedListNode* prev = dummy;
        // Node used to traverse the linked list.
        SinglyLinkedListNode* current = head;

        while (current != NULL) {
            // Until the current and previous values are same,
            // keep updating current
            while (current->next != NULL &&
                prev->next->data == current->next->data)
                current = current->next;
            // if current has unique value i.e current is not updated,
            // Move the prev pointer to next node
            if (prev->next == current)
                prev = prev->next;
            // when current is updated to the last duplicate
            // value of that segment, make prev the next of current
            else
                prev->next = current->next;

            current = current->next;
        }
        // update original head to the next of dummy node
        head = dummy->next;
        return head;
    }

    SinglyLinkedListNode* RemoveDuplicatesInSorted(SinglyLinkedListNode* head) {
        if (head == nullptr) return nullptr;
        SinglyLinkedListNode* current = head;
        while (current->next) {
            if (current && current->next && current->data == current->next->data) {
                SinglyLinkedListNode* temp = current->next;
                current->next = temp->next;
                free(temp);
            }
            else {
                current = current->next;
            }
        }
        return head;
    }

    SinglyLinkedListNode* DeleteNodesWithRightGreater(SinglyLinkedListNode* head) {
        if (head->next == NULL)
            return head;
        SinglyLinkedListNode* temp = DeleteNodesWithRightGreater(head->next);
        if (temp->data > head->data)
            return temp;
        else
            head->next = temp;
        return head;
    }

    SinglyLinkedListNode* DeleteBetween(SinglyLinkedListNode* head, int M, int N) {
        SinglyLinkedListNode* curr = head, * prev = nullptr;

        for (int i = 1; i < M and curr; i++)
            curr = curr->next;

        if (not curr or not curr->next)  return head;
        prev = curr;
        int x = N;
        while (x-- and prev)
            prev = prev->next;

        if (not prev) {
            curr->next = NULL;
            return head;
        }
        curr->next = prev->next;
        curr = prev->next;

        return head;
    }

    SinglyLinkedListNode* DeleteBetweenRange(SinglyLinkedListNode* head, int M, int N)
    {
        SinglyLinkedListNode* curr = head, * prev = nullptr;
        while (curr) {
            for (int i = 1; i < M and curr; i++)
                curr = curr->next;

            if (not curr or not curr->next)  return head;
            prev = curr;
            int x = N;
            while (x-- and prev)
                prev = prev->next;

            if (not prev) {
                curr->next = NULL;
                return head;
            }
            curr->next = prev->next;
            curr = prev->next;
        }
        return head;
    }

}