
#include "./SinglyLinkedList.h"
#include <algorithm>

namespace sll {

    SinglyLinkedListNode::SinglyLinkedListNode(int node_data) {
         this->data = node_data;
         this->next = nullptr;
    }

    SinglyLinkedListNode* SinglyLinkedListNode::GetTail(SinglyLinkedListNode* head){
        while (head->next != nullptr)
            head = head->next;
        return head;
    }

    SinglyLinkedList::SinglyLinkedList() {
         this->head = nullptr;
         this->tail = nullptr;
    }

    void SinglyLinkedList::InsertNode(int node_data) {
        SinglyLinkedListNode* node = new SinglyLinkedListNode(node_data);
        if (!this->head) {
            this->head = node;
        } else {
            this->tail->next = node;
        }
        this->tail = node;
    }

    int SinglyLinkedList::size() {
        return sll::Size(this->head);
    }

    int Size(SinglyLinkedListNode* head) {
        int counter = { 0 };
        SinglyLinkedListNode* current = head;
        while (current != NULL) {
            ++counter;
            current = current->next;
        }
        return counter;
    }

    void PrintSinglyLinkedList(SinglyLinkedListNode* node, std::string sep, std::ostream& cout) {
        while (node) {
            cout << node->data;
            node = node->next;
            if (node)
                cout << sep;
        }
    }
    void FreeSinglyLinkedList(SinglyLinkedListNode* head) {
        SinglyLinkedListNode* current = head;
        while (current != nullptr) {
            SinglyLinkedListNode* temp = current;
            current = current->next;
            free(temp);
            if (current == head) return;
        }
    }
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
        // double pointers are sexy!
        // SinglyLinkedListNode** pp = &head;
        // for (int i = 0; i < position - 1; ++i) {
        //    pp = &((*pp)->next);
        // }
        // newNode->next = (*pp)->next;
        // (*pp)->next = newNode;
        // return head;
    }
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
            } else {
                previous = current;
                current = current->next;
            }
        }
        return head;
    }

    SinglyLinkedListNode* Reverse(SinglyLinkedListNode* head) {
        SinglyLinkedListNode* tail, * currentNode;
        tail = nullptr;
        while (head != nullptr) {
            currentNode = head->next;
            head->next = tail;
            tail = head;
            head = currentNode;
        }
        return tail;
    }

    int GetNodeData(SinglyLinkedListNode* head, int position) {
        if (head == nullptr) NULL;
        int index = 0;
        SinglyLinkedListNode* currentNode = head;
        SinglyLinkedListNode* targetNode = head;
        while (currentNode != nullptr) {
            if (index++ == position) {
                targetNode = currentNode;
            }
            currentNode = currentNode->next;
        }
        return targetNode != nullptr ? targetNode->data : INT_MIN;
    }

    int GetNodeDataFromTail(SinglyLinkedListNode* head, int positionFromTail) {
        if (head == nullptr) NULL;
        int index = 0;
        SinglyLinkedListNode* currentNode = head;
        SinglyLinkedListNode* targetNode = head;
        while (currentNode != nullptr) {
            currentNode = currentNode->next;
            if (index++ > positionFromTail) {
                targetNode = targetNode->next;
            }
        }
        return targetNode != nullptr ? targetNode->data : INT_MIN;
    }

    bool CompareLists(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
        // recursion
        //if (head1 == nullptr && head2 == nullptr)
        //    return true;
        //else if (head1 == nullptr || head2 == nullptr)
        //    return false;
        //return (head1->data == head2->data) && CompareLists(head1->next, head2->next);
        // do while
        SinglyLinkedListNode* current1 = head1;
        SinglyLinkedListNode* current2 = head2;
        for (;;) {
            if (current1 == nullptr && current2 == nullptr)
                return true;
            else if (current1 == nullptr || current2 == nullptr)
                return false;
            else if (current1->data != current2->data)
                return false;
            current1 = current1->next;
            current2 = current2->next;
        }
    }

    SinglyLinkedListNode* Sort(SinglyLinkedListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
        SinglyLinkedListNode* index1, * index2;
        for (index1 = head; index1->next != NULL; index1 = index1->next) {
            for (index2 = index1->next; index2 != NULL; index2 = index2->next) {
                if (index1->data > index2->data) {
                    std::swap(index1->data, index2->data);
                }
            }
        }
        return head;
    }
    SinglyLinkedListNode* MergeSorted(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
        if (head1 == nullptr || head2 == nullptr) return nullptr;
        SinglyLinkedListNode* l1 = head1;
        SinglyLinkedListNode* l2 = head2;
        SinglyLinkedListNode* head;
        SinglyLinkedListNode* current;
        if (l1->data < l2->data) {
            head = l1;
            l1 = l1->next;
        } else {
            head = l2;
            l2 = l2->next;
        }
        current = head;
        for (;;) {
            if (l1 == nullptr && l2 == nullptr) {
                return head;
            } else if (l1 == nullptr) {
                current->next = l2;
                current = l2;
                l2 = l2->next;
            } else if (l2 == nullptr) {
                current->next = l1;
                current = l1;
                l1 = l1->next;
            } else {
                if (l1->data < l2->data) {
                    current->next = l1;
                    current = l1;
                    l1 = l1->next;
                } else {
                    current->next = l2;
                    current = l2;
                    l2 = l2->next;
                }
            }
        }
        return head;
    }

    SinglyLinkedListNode* RemoveDuplicatesInSorted(SinglyLinkedListNode* head) {
        if (head == nullptr) return nullptr;
        SinglyLinkedListNode* current = head;
        while (current->next != nullptr) {
            if (current != nullptr && current->data == current->next->data) {
                SinglyLinkedListNode* temp = current->next;
                current->next = temp->next;
                free(temp);
            } else {
                current = current->next;
            }
        }
        return head;
    }

    SinglyLinkedListNode* MergedEntyNode(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
        if (head1 == nullptr || head2 == nullptr) return nullptr;
        SinglyLinkedListNode* l1 = head1;
        SinglyLinkedListNode* l2 = head2;
        int counter = 0;
        while (l1 != l2) {
            //If you reached the end of one list start at the beginning of the other one l1
            if (l1->next == nullptr) {
                l1 = head2;
                if (counter++ == 3) return nullptr; // infinity loop protection
            } else {
                l1 = l1->next;
            }
            //Same for second list
            if (l2->next == nullptr) {
                l2 = head1;
                if (counter++ == 3) return nullptr; // infinity loop protection
            } else {
                l2 = l2->next;
            }
        }
        return l2;
    }

    int MergedEntyNodeValue(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
        int output = -1;
        SinglyLinkedListNode* merged = MergedEntyNode(head1, head2);
        if (merged != nullptr)
            output = merged->data;
        return output;
    }

    bool HasCycle(SinglyLinkedListNode* head) {
        if (head == nullptr || head->next == nullptr
         || head->next->next == nullptr) return false;
        SinglyLinkedListNode* slow;
        SinglyLinkedListNode* fast;
        for (slow = head, fast = head->next->next;
            slow != nullptr && slow->next != nullptr && fast != nullptr
            && fast->next != nullptr && fast->next->next != nullptr;
            slow = slow->next, fast = fast->next->next
            ) {
            if (slow == fast) return true;
        }
        return false;
    }

    void Print(SinglyLinkedListNode* head) {
        if (head == nullptr) return;
        std::cout << head->data << std::endl;
        Print(head->next);
    }

    void ReversePrint(SinglyLinkedListNode* head) {
        if (head == nullptr) return;
        ReversePrint(head->next);
        std::cout << head->data << std::endl;
    }
}
