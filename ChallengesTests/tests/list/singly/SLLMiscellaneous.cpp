#include "./slltests.h"


    void slltests::InsertNodeInRange(SinglyLinkedList* llist, const vector<int>& datas) {
        for (const auto& i : datas) {
            llist->InsertNode(i);
        }
    }

    std::string slltests::ToString(SinglyLinkedListNode* node) {
        std::stringstream ss;
        while (node != nullptr) {
            ss << node->data;
            node = node->next;
            if (node != nullptr)
                ss << ", ";
        }
        return ss.str();
    }

