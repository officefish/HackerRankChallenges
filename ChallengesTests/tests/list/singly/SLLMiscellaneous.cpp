//#include "./slltests.h"
//
//
//    void slltests::InsertNodeInRange(SinglyLinkedList* llist, const vector<int>& datas) {
//        for (const auto& i : datas) {
//            llist->insert(i);
//        }
//    }
//
//    std::string slltests::ToString(SinglyLinkedListNode* node) {
//        std::stringstream ss;
//        int counter = 0;
//        while (node != nullptr) {
//            ss << node->data;
//            node = node->next;
//            if (node != nullptr)
//                ss << ", ";
//            if (counter++ > 1000)
//                break;
//        }
//        return ss.str();
//    }
//
//    std::string slltests::ToStringLoop(SinglyLinkedListNode* node, SinglyLinkedListNode* end) {
//        std::stringstream ss;
//        while (node != nullptr) {
//            ss << node->data;
//            if (node == end) break;
//            node = node->next;
//            if (node != nullptr)
//                ss << ", ";
//
//        }
//        return ss.str();
//    }
//
