#include "../.././SinglyLinkedList.h"

namespace sll {
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

    SinglyLinkedListNode* ReverseBetween(SinglyLinkedListNode* head, int m, int n) {
        if (!head or !head->next) return nullptr;
        SinglyLinkedListNode* prev = nullptr, * h1 = nullptr, * h2 = nullptr;
        SinglyLinkedListNode* curr = head, * next = curr->next;
        int count = 1;
        while (curr and count <= n) {
            if (count >= m and count <= n) {
                curr->next = prev;
                prev = curr;
                curr = next;
                if (next) next = next->next;
            }
            else {
                h1 = curr;
                curr = next;
                next = next->next;
            }
            count++;
        }
        if (!h1) {
            if (!curr)
                head = prev;
            else
                head->next = curr; head = prev;
        } else {
            h2 = h1->next;
            h1->next = prev;
            if (h2) h2->next = curr;
        }
        return head;
    }

    SinglyLinkedListNode* ReverseAlternate(SinglyLinkedListNode* head) {
        SinglyLinkedListNode* even = NULL, * odd = NULL;
        SplitAlternate(head, &even, &odd);
        odd = Reverse(odd);
        head = MergeAlternate(even, odd);
        return head;
    }

    SinglyLinkedListNode* ReverseEveryNth(SinglyLinkedListNode* head, int Nth) {
        SinglyLinkedListNode* prev = NULL;
        SinglyLinkedListNode* curr = head;
        SinglyLinkedListNode* q = NULL;
        int counter = Nth;
        while (counter-- && curr != NULL) {
            q = curr->next;
            curr->next = prev;
            prev = curr;
            curr = q;
        }
        if (head != NULL) head->next = ReverseEveryNth(q, Nth);
        return prev;
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

    SinglyLinkedListNode* Segregate(SinglyLinkedListNode* head) {
        return Partition(head, 1);
    }

    SinglyLinkedListNode* SegregateAlternate(SinglyLinkedListNode* head) {
        if (!head) return nullptr;
        if (!head->next) return head;
        SinglyLinkedListNode* even = new SinglyLinkedListNode(0);
        SinglyLinkedListNode* odd = new SinglyLinkedListNode(0);
        SinglyLinkedListNode* e = even, * o = odd;
        int count = 0;
        while (head and count++) {
            if (count & 1)o->next = head, o = o->next;
            else e->next = head, e = e->next;
            head = head->next;
        }
        e->next = odd->next;
        return even->next;
    }

    SinglyLinkedListNode* SortAbsolute(SinglyLinkedListNode* head) {
        if (!head or !head->next) {
            return head;
        }
        SinglyLinkedListNode* tail = head->next;
        SinglyLinkedListNode* prev = head;
        while (tail) {
            if (tail->data < 0) {
                prev->next = tail->next;
                tail->next = head;
                head = tail;
                tail = prev->next;
            }
            else {
                prev = tail;
                tail = tail->next;
            }
        }
        return head;
    }

    SinglyLinkedListNode* SortBubble(SinglyLinkedListNode* head) {
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

    SinglyLinkedListNode* SortReorder(SinglyLinkedListNode* head) {
        SinglyLinkedListNode* even = NULL, * odd = NULL;
        SplitAlternate(head, &even, &odd);
        odd = Reverse(odd);
        return MergeSorted(even, odd);
    }

    SinglyLinkedListNode* Rotate(SinglyLinkedListNode* head, int Nth) {
        if (Nth <= 0) return head;
        SinglyLinkedListNode* curr = head;
        int count = 0;

        while (curr && ++count < Nth)
            curr = curr->next;

        if (!curr) return head;

        SinglyLinkedListNode* NthNode = curr;
        while (curr->next)
            curr = curr->next;

        curr->next = head;
        head = NthNode->next;
        NthNode->next = nullptr;

        return head;
    }

    SinglyLinkedListNode* Reorder(SinglyLinkedListNode* head) {
        // 1) Find the middle point using tortoise and hare method.
        SinglyLinkedListNode* middle = GetPrevMiddleNode(head);
        // 2) Split the linked list into two halves using found middle point in step 1.
        SinglyLinkedListNode* head1 = head;
        SinglyLinkedListNode* head2 = middle->next;
        middle->next = NULL;
        // 3) Reverse the second half.
        head2 = Reverse(head2);
        // 4) Do alternate merge of first and second halves.
        return MergeAlternate(head1, head2);
    }

    SinglyLinkedListNode* RearangeAlternate(SinglyLinkedListNode* head) {
        if (head == NULL)
            return NULL;
        // Initialize first nodes of even and odd lists
        SinglyLinkedListNode* odd = head;
        SinglyLinkedListNode* even = head->next;

        // Remember the first node of even list so that we can connect the even list at the
        // end of odd list.
        SinglyLinkedListNode* evenFirst = even;
        while (true) {
            // If there are no more nodes, then connect first node of even list
            // to the last node of odd list
            if (!odd || !even || !(even->next)) {
                odd->next = evenFirst;
                break;
            }
            // Connecting odd nodes
            odd->next = even->next;
            odd = even->next;
            // If there are NO more even nodes after current odd.
            if (odd->next == NULL) {
                even->next = NULL;
                odd->next = evenFirst;
                break;
            }
            // Connecting even nodes
            even->next = odd->next;
            even = odd->next;
        }
        return head;
    }

    SinglyLinkedListNode* SwapData(SinglyLinkedListNode* head, SinglyLinkedListNode* xNode, SinglyLinkedListNode* yNode) {
        if (!head) return nullptr;
        if (!xNode or !yNode) return head;
        if (xNode == yNode) return head;
        std::swap(xNode->data, yNode->data);
        return head;
    }

    SinglyLinkedListNode* Swap(SinglyLinkedListNode* head, SinglyLinkedListNode* xNode, SinglyLinkedListNode* yNode) {
        if (!head) return nullptr;
        if (!head->next) return head;
        if (xNode == yNode) return head;
        SinglyLinkedListNode* curr = head;
        SinglyLinkedListNode* prevX = nullptr;
        SinglyLinkedListNode* prevY = nullptr;
        SinglyLinkedListNode* currX = nullptr;
        SinglyLinkedListNode* currY = nullptr;
        while (curr) {
            if (!prevX and xNode == curr->next)
                prevX = curr->next;
            if (!prevY and yNode == curr->next)
                prevY = curr->next;
            if (prevX and prevY) break;
            curr = curr->next;
        }
        if (!prevX or !prevY) return head;
        // swap
        currX = prevX->next;
        currY = prevY->next;
        currX->next = prevY->next->next;
        currY->next = prevX->next->next;
        prevX->next = currY;
        prevY->next = currX;
        return head;
    }

    SinglyLinkedListNode* Swap(SinglyLinkedListNode* head, int key1, int key2) {
        auto swap {
            [](SinglyLinkedListNode** f, SinglyLinkedListNode** s) {
                SinglyLinkedListNode* tmp = *f;
                *f = *s;
                *s = tmp;
            }
        };
        if (key1 == key2) return head;
        SinglyLinkedListNode** first = &head;

        while (*first && (*first)->data != key1)
            first = &(*first)->next;

        if (*first == NULL) return head;
        SinglyLinkedListNode** second = &head;

        while (*second && (*second)->data != key2)
            second = &(*second)->next;

        if (*second == NULL) return head;
        swap(first, second);
        swap(&(*first)->next, &(*second)->next);

        return head;
    }


    SinglyLinkedListNode* SwapZigZag(SinglyLinkedListNode* head) {
        bool flag = true;
        // Traverse linked list starting from head.
        SinglyLinkedListNode* current = head;
        while (current->next != NULL) {
            if (flag) {
                if (current->data > current->next->data) {
                    std::swap(current->data, current->next->data);
                }
            } else {
                if (current->data < current->next->data) {
                    std::swap(current->data, current->next->data);
                }
            }
            current = current->next;
            flag = !flag;  /* flip flag for reverse checking */
        }
        return head;
    }

    SinglyLinkedListNode* PairwiseSwap(SinglyLinkedListNode* head) {
        SinglyLinkedListNode* prev = NULL;
        SinglyLinkedListNode* next = NULL;
        SinglyLinkedListNode* curr = head;
        int c = 0;
        while (curr && c < 2) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            c++;
        }
        if (next != NULL)
            head->next = PairwiseSwap(next);
        return prev;
    }

}