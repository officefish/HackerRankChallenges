
#include "./SinglyLinkedList.h"
#include <algorithm>
#include <set>
#include <stack>

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
        std::set<intptr_t> adresses;
        while (current != nullptr) {
            // cash current adress
            adresses.insert(reinterpret_cast<intptr_t>(current));
            // list loop
            SinglyLinkedListNode* temp = current;
            current = current->next;
            // if adress is not unique this list is circled,
            // so we stop go through
            auto search = adresses.find(reinterpret_cast<intptr_t>(current));
            if (search == adresses.end())
                free(temp);
            else
                return;
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
        if(prev) prev->next = newNode;
        return head;
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

    SinglyLinkedListNode* DeleteNthNode(SinglyLinkedListNode* head, int Nth) {
        if (!head) return nullptr;
        SinglyLinkedListNode* curr = head;
        SinglyLinkedListNode* prev;
        int count = 1;
        //will always result in empty string
        if (Nth == 1)
            return nullptr;
        while (curr != NULL && curr->next) {
            ++count;
            prev = curr;
            curr = curr->next;
            if (count == Nth) {
                SinglyLinkedListNode* tmp = curr;
                curr = curr->next;
                free(tmp);
                prev->next = curr;
                count = 1;
            }
        }
        return head;
    }

    SinglyLinkedListNode* RemoveDublicates(SinglyLinkedListNode* head) {
        std::multiset<int> datas;
        SinglyLinkedListNode* curr = head;
        SinglyLinkedListNode* prev = nullptr;
        while (curr) {
            if (datas.count(curr->data)) {
                if (prev) prev->next = curr->next;
                //deleting current node which contains duplicates.
                delete (curr);
            // else we just insert the data at current node
            // in setand update prev to the current node.
            } else {
                datas.insert(curr->data);
                prev = curr;
            }
            //updating current to the next node of prev node.
            curr = curr->next;
        }
        return head;
    }

    SinglyLinkedListNode* RemoveDuplicatesRecursively(SinglyLinkedListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;
        if (head->data == head->next->data) {
            SinglyLinkedListNode* tmp = head->next;
            head->next = head->next->next;
            free(tmp);
            RemoveDuplicatesRecursively(head);
        } else {
            RemoveDuplicatesRecursively(head->next);
        }
        return head;
    }

    SinglyLinkedListNode* RemoveOccurencesOfDublicates(SinglyLinkedListNode* head) {
        // create a dummy node that acts like a fake head of list
        // pointing to the original head
        SinglyLinkedListNode* dummy = new SinglyLinkedListNode(-1);
        // dummy node points to the original head
        dummy->next = head;
        // Node pointing to last node which has no duplicate.
        SinglyLinkedListNode* prev = dummy;
        // Node used to traverse the linked list.
        SinglyLinkedListNode* current = head;

        while (current != NULL)
        {
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
    SinglyLinkedListNode* GetMiddleNode(SinglyLinkedListNode* head) {
        SinglyLinkedListNode* slow = head;
        SinglyLinkedListNode* fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    int GetMiddleNodeData(SinglyLinkedListNode* head) {
        return GetMiddleNode(head)->data;
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

    SinglyLinkedListNode* Partition(SinglyLinkedListNode* head, int x) {
        /* Let us initialize first and last nodes of
      three linked lists
        1) Linked list of values smaller than x.
        2) Linked list of values equal to x.
        3) Linked list of values greater than x.*/
        SinglyLinkedListNode* smallerHead = NULL, * smallerLast = NULL;
        SinglyLinkedListNode* greaterLast = NULL, * greaterHead = NULL;
        SinglyLinkedListNode* equalHead = NULL, * equalLast = NULL;
        // Now iterate original list and connect nodes
        // of appropriate linked lists.
        while (head != NULL) {
            // If current node is equal to x, append it
            // to the list of x values
            if (head->data == x) {
                if (equalHead == NULL)
                    equalHead = equalLast = head;
                else {
                    equalLast->next = head;
                    equalLast = equalLast->next;
                }
            }
            // If current node is less than X, append
            // it to the list of smaller values
            else if (head->data < x) {
                if (smallerHead == NULL)
                    smallerLast = smallerHead = head;
                else {
                    smallerLast->next = head;
                    smallerLast = head;
                }
            }
            else // Append to the list of greater values
            {
                if (greaterHead == NULL)
                    greaterLast = greaterHead = head;
                else {
                    greaterLast->next = head;
                    greaterLast = head;
                }
            }
            head = head->next;
        }
        // Fix end of greater linked list to NULL if this
        // list has some nodes
        if (greaterLast != NULL) greaterLast->next = NULL;

        // Connect three lists

        // If smaller list is empty
        if (smallerHead == NULL) {
            if (equalHead == NULL) return greaterHead;
            equalLast->next = greaterHead;
            return equalHead;
        }
        // If smaller list is not empty
        // and equal list is empty
        if (equalHead == NULL) {
            smallerLast->next = greaterHead;
            return smallerHead;
        }
        // If both smaller and equal list
        // are non-empty
        smallerLast->next = equalHead;
        equalLast->next = greaterHead;
        return smallerHead;
    }

    SinglyLinkedListNode* BubbleSort(SinglyLinkedListNode* head) {
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

    SinglyLinkedListNode* SortInsert(SinglyLinkedListNode* head) {
        SinglyLinkedListNode* sorted = NULL;
        // Traverse the given linked list..
        SinglyLinkedListNode* curr = head;
        while (curr != NULL) {
            SinglyLinkedListNode* next = curr->next;
            sorted = InsertInSortedNode(sorted, curr);
            // Update current
            curr = next;
        }
        // Update head_ref to point to sorted linked list and return it..
        head = sorted;
        return head;
    }

    SinglyLinkedListNode* InsertInSortedData(SinglyLinkedListNode* head, int data) {
        SinglyLinkedListNode* target = new SinglyLinkedListNode(data);
        head = InsertInSortedNode(head, target);
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
        while (current->next) {
            if (current && current->next && current->data == current->next->data) {
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

    bool IsPalindrome(SinglyLinkedListNode* head) {
        std::stack<int> datas;
        int data;
        SinglyLinkedListNode* scout = head;
        while (scout) {
            datas.push(scout->data);
            scout = scout->next;
        }
        while (head && !datas.empty()) {
            data = datas.top(); datas.pop();
            if (head->data != data) return false;
            head = head->next;
        }
        return true;
    }

    void alternatingSplitList(SinglyLinkedListNode* head,
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
                } else {
                    tail1->next = head;
                    tail1 = tail1->next;
                }
                head = head->next;
                p = false;
            } else {
                if (split2 == NULL) {
                    split2 = head;
                    tail2 = head;
                } else {
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
