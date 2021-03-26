#include "../.././SinglyLinkedList.h"

namespace sll {



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



    inline int CountCommonNodes(SinglyLinkedListNode* node1, SinglyLinkedListNode* node2) {
        if (node1 == NULL or node2 == NULL) return 0;
        int count = 0;
        while (node1 and node2) {
            if (node1->data == node2->data)
                ++count;
            node1 = node1->next;
            node2 = node2->next;
        }
        return count;
    }

    int CountPairsWithSameSum(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2, int sum) {
        if (not head1 or not head2) return 0;
        SinglyLinkedListNode* curr1 = head1;
        SinglyLinkedListNode* curr2 = head2;
        int counter = 0;
        std::set<int> values;
        while (curr1) {
            values.insert(curr1->data);
            curr1 = curr1->next;
        }
        while (curr2) {
            if (values.find(sum - curr2->data) != values.end()) counter++;
            curr2 = curr2->next;
        }
        return counter;
    }


    SinglyLinkedListNode* FindDataIntersection(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
        std::unordered_set<int> l2_datas;
        while (head2 != NULL) {
            l2_datas.insert(head2->data);
            head2 = head2->next;
        }
        SinglyLinkedListNode* start = NULL, * end = NULL;
        while (head1 != NULL) {
            if (l2_datas.find(head1->data) != l2_datas.end()) {
                if (start == NULL)
                    start = end = head1;
                else
                    end->next = head1; end = head1;
            }
            head1 = head1->next;
        }
        if (start != NULL) end->next = NULL;
        return start;
    }

    SinglyLinkedListNode* FindIntersection(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
        if (head1 == nullptr || head2 == nullptr) return nullptr;
        std::unordered_set<uintptr_t> a = GetNodeAddresses(head2);
        SinglyLinkedListNode* curr = head1;
        SinglyLinkedListNode* start = NULL, * end = NULL;
        while (curr != NULL) {
            if (a.find(reinterpret_cast<uintptr_t>(curr)) != a.end()) {
                if (start == NULL)
                    start = end = curr;
                else
                    end->next = curr; end = curr;
            }
            curr = curr->next;
        }
        if (start != NULL) {
            end->next = NULL;
        }
        return start;
    }

    SinglyLinkedListNode* FindIntersectionEntyRecursively(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
        if (not head1 or not head2) return nullptr;
        SinglyLinkedListNode* a = head1;
        SinglyLinkedListNode* b = head2;
        while (a != b) {
            a = not a ? head2 : a->next;
            b = not b ? head1 : b->next;
        }
        return a;
    }

    int FindIntersectionEntyDataRecursively(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
        SinglyLinkedListNode* output = FindIntersectionEntyRecursively(head1, head2);
        return output ? output->data : -1;
    }


    SinglyLinkedListNode* FindIntersectionEnty(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
        if (head1 == nullptr || head2 == nullptr) return nullptr;
        std::unordered_set<uintptr_t> a = GetNodeAddresses(head2);
        SinglyLinkedListNode* curr = head1;
        while (curr) {
            if (a.find(reinterpret_cast<uintptr_t>(curr)) != a.end()) return curr;
            curr = curr->next;
        }
        return nullptr;
    }

    int FindIntersectionEntyValue(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
        int output = -1;
        SinglyLinkedListNode* merged = FindIntersectionEnty(head1, head2);
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

    int MaxPalingrome(SinglyLinkedListNode* head) {
        int result{ 0 };
        SinglyLinkedListNode* curr = head;
        SinglyLinkedListNode* prev = nullptr, * next = nullptr;
        while (curr) {
            // The sublist from head to current reversed.
            next = curr->next;
            curr->next = prev;

            // check for odd length palindrome by finding longest common list elements
            // beginning from prev and from next (We exclude curr)
            result = std::max(result, 2 * CountCommonNodes(prev, next) + 1);

            // check for even length palindrome by finding longest common list elements
            // beginning from curr and from next
            result = std::max(result, 2 * CountCommonNodes(curr, next));

            // update prev and curr for next iteration
            prev = curr;
            curr = next;
        }
        return result;
    }

}