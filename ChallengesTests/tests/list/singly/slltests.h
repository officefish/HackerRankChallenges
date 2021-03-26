#pragma once
#include "../ChallengesTests/./pch.h"
#include "./Challenges.h"
#include "./Lists/SinglyLinkedList.h"

namespace slltests {

    using std::cin, std::cout, std::endl;
    using std::max;
    using std::streamsize, std::numeric_limits;
    using sll::SinglyLinkedList, sll::SinglyLinkedListNode;
    using std::vector, std::string;

    void InsertNodeInRange(SinglyLinkedList* llist, const vector<int>& datas);
    string ToString(SinglyLinkedListNode* node);

}
