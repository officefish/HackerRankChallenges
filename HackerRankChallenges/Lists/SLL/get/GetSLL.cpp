#include "../.././SinglyLinkedList.h"

namespace sll {

	s_ptr GetPrevMiddle(s_ptr head) {
		s_ptr slow = head;
		s_ptr fast = head;
		s_ptr prev = nullptr;
		while (fast and fast->next) {
			prev = slow;
			slow = slow->next;
			fast = fast->next->next;
		}
		return prev;
	}

	s_ptr GetByIndex(s_ptr head, size_t index) {
		s_ptr slow = head;
		s_ptr prev = nullptr;
		for (size_t i = 0; i <= index; ++i) {
			prev = slow;
			slow = slow->next;
			if (not slow) return nullptr;
		}
		return prev;
	}

	s_ptr GetByIndexOrLast(s_ptr head, size_t index) {

		s_ptr slow = head;
		s_ptr prev = nullptr;
		for (size_t i = 0; i <= index; ++i) {
			prev = slow;
			slow = slow->next;
			if (not slow) return prev;
		}
		return prev;
	}

}
//
//    SinglyLinkedListNode* GetNode(SinglyLinkedListNode* head, int position) {
//        if (head == nullptr) NULL;
//        if (position < 0) return NULL;
//        int index = 0;
//        SinglyLinkedListNode* currentNode = head;
//        SinglyLinkedListNode* targetNode = nullptr;
//        while (currentNode != nullptr) {
//            if (index++ == position) {
//                targetNode = currentNode;
//            }
//            currentNode = currentNode->next;
//        }
//        return targetNode;
//    }
//    int GetNodeData(SinglyLinkedListNode* head, int position) {
//        SinglyLinkedListNode* target = GetNode(head, position);
//        return target != nullptr ? target->data : -1;
//    }
//
//    SinglyLinkedListNode* GetNodeFromTail(SinglyLinkedListNode* head, int positionFromTail) {
//        SinglyLinkedListNode* currNode = head, * nthNode = head;
//        //traversing first n elements with first pointer.
//        int n = ++positionFromTail; // (++) if find from end-1 it
//        while (n != 0) {
//            if (currNode == NULL)
//                return nullptr;
//            currNode = currNode->next;
//            n--;
//        }
//        //now traversing with both pointers and when first pointer gives null
//        //we have got the nth node from end in second pointer since the first
//        //pointer had already traversed n nodes and thus had difference of n
//        //nodes with second pointer.
//        while (currNode != NULL) {
//            nthNode = nthNode->next;
//            currNode = currNode->next;
//        }
//        //returning the data of nth node from end.
//        if (nthNode != NULL)
//            return nthNode;
//        else
//            return nullptr;
//    }
//    int GetNodeFromTailData(SinglyLinkedListNode* head, int positionFromTail) {
//        SinglyLinkedListNode* target = GetNodeFromTail(head, positionFromTail);
//        return target != nullptr ? target->data : -1;
//    }
//
//    SinglyLinkedListNode* GetMiddleNode(SinglyLinkedListNode* head) {
//        SinglyLinkedListNode* slow = head;
//        SinglyLinkedListNode* fast = head;
//        while (fast && fast->next) {
//            slow = slow->next;
//            fast = fast->next->next;
//        }
//        return slow;
//    }
//
//    SinglyLinkedListNode* GetPrevMiddleNode(SinglyLinkedListNode* head) {
//        SinglyLinkedListNode* slow = head;
//        SinglyLinkedListNode* fast = head;
//        SinglyLinkedListNode* prev = nullptr;
//        while (fast && fast->next) {
//            prev = slow;
//            slow = slow->next;
//            fast = fast->next->next;
//        }
//        return prev;
//    }
//
//    int GetMiddleNodeData(SinglyLinkedListNode* head) {
//        return GetMiddleNode(head)->data;
//    }
//
//
//
//    SinglyLinkedListNode* GetFractionalNode(SinglyLinkedListNode* head, int k) {
//
//        if (!head) return nullptr;
//        if (k <= 0) return nullptr;
//        SinglyLinkedListNode* fast = head;
//        SinglyLinkedListNode* slow = head;
//        int ctr = 1;
//        while (fast->next) {
//            fast = fast->next;
//            slow = (ctr++ % k == 0) ? slow->next : slow;
//        }
//        if (k > ctr) return nullptr;
//        return slow;
//    }
//
//    int GetFractionalNodeData(SinglyLinkedListNode* head, int k) {
//        SinglyLinkedListNode* target = GetFractionalNode(head, k);
//        return target ? target->data : -1;
//    }
//
//    SinglyLinkedListNode* GetModularNode(SinglyLinkedListNode* head, int k) {
//        if (k < 0) return nullptr;
//        int counter = 1;
//        SinglyLinkedListNode* modular = nullptr;
//        while (head) {
//            if (counter % k == 0) modular = head;
//            head = head->next;
//            counter++;
//        }
//        return modular;
//    }
//
//    int GetModularNodeData(SinglyLinkedListNode* head, int k) {
//        SinglyLinkedListNode* modular = GetModularNode(head, k);
//        return modular ? modular->data : -1;
//    }
//
//    std::unordered_set<uintptr_t> GetNodeAddresses(SinglyLinkedListNode* head) {
//        std::unordered_set<uintptr_t> a;
//        if (!head) return a;
//        SinglyLinkedListNode* curr = head;
//        while (curr) {
//            a.insert(reinterpret_cast<std::uintptr_t>(curr));
//            curr = curr->next;
//        }
//        return a;
//    }
//
//}
