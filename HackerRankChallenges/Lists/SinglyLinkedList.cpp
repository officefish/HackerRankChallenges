
#include "./SinglyLinkedList.h"
#include <sstream>

namespace sll {

    SinglyLinkedListNode::SinglyLinkedListNode(int node_data) {
         this->data = node_data;
         this->next = nullptr;
    }

    SinglyLinkedListNode::~SinglyLinkedListNode() {
        this->next = nullptr;
    }

    s_ptr SinglyLinkedListNode::GetTail(const s_ptr head){
        std::shared_ptr<Node> current = head;
        while (current->next)
            current = current->next;
        return current;
    }

    SinglyLinkedList::SinglyLinkedList() {
         this->head = nullptr;
    }

    SinglyLinkedList::~SinglyLinkedList() {
        sll::Free(this->head);
        this->head = nullptr;
    }

    SinglyLinkedList::SinglyLinkedList(int data) {
        this->head = Insert(this->head, data);
    }

    SinglyLinkedList::SinglyLinkedList(const std::initializer_list<int>& list) {
        this->head = Merge(this->head, list);
    }

    SinglyLinkedList::SinglyLinkedList(const SinglyLinkedList& source) {
        this->head = Copy(source.head);
    }

    SinglyLinkedList& SinglyLinkedList::insert(const std::initializer_list<int>& list) {
        this->head = Merge(this->head, list);
        return *this;
    }

    SinglyLinkedList& SinglyLinkedList::insert(const SinglyLinkedList& list) {
        this->head = Merge(list.head, this->head);
        return *this;
    }

    SinglyLinkedList& SinglyLinkedList::insert(int data) {
        this->head = Insert(this->head, data);
        return *this;
    }

    SinglyLinkedList& SinglyLinkedList::back_insert(int data) {
        this->head = BackInsert(this->head, data);
        return *this;
    }

    SinglyLinkedList& SinglyLinkedList::back_insert(const std::initializer_list<int>& list) {
        this->head = BackMerge(this->head, list);
        return *this;
    }

    SinglyLinkedList& SinglyLinkedList::back_insert(const SinglyLinkedList& list) {
        this->head = Merge(this->head, list.head);
        return *this;
    }

    SinglyLinkedList& SinglyLinkedList::middle_insert(int data) {
        this->head = MiddleInsert(this->head, data);
        return *this;
    }

    SinglyLinkedList& SinglyLinkedList::middle_insert(const std::initializer_list<int>& list) {
        s_ptr tmp = Merge(tmp, list);
        this->head = MiddleInsert(this->head, tmp);
        return *this;
    }

    SinglyLinkedList& SinglyLinkedList::middle_insert(const SinglyLinkedList& list) {
        this->head = MiddleInsert(this->head, list.head);
        return *this;
    }

    SinglyLinkedList& SinglyLinkedList::index_insert(int data, int index) {
        this->head = IndexInsert(this->head, data, index);
        return *this;
    }

    SinglyLinkedList& SinglyLinkedList::index_insert(const std::initializer_list<int>& list, size_t index) {
        s_ptr tmp = Merge(tmp, list);
        this->head = IndexInsert(this->head, tmp, index);
        return *this;
    }

    SinglyLinkedList& SinglyLinkedList::index_insert(const SinglyLinkedList& list, size_t index) {
        this->head = IndexInsert(this->head, list.head, index);
        return *this;
    }

    SinglyLinkedList& SinglyLinkedList::alternate_insert(const std::initializer_list<int>& list, size_t frequency) {
        s_ptr tmp = Merge(tmp, list);
        this->head = AlternateInsert(this->head, tmp, frequency);
        return *this;

    }
    SinglyLinkedList& SinglyLinkedList::alternate_insert(const SinglyLinkedList& list, size_t frequency) {
        this->head = AlternateInsert(this->head, list.head, frequency);
        return *this;
    }
    SinglyLinkedList& SinglyLinkedList::group_insert(const std::initializer_list<int>& list, size_t frequency) {
        s_ptr tmp = Merge(tmp, list);
        this->head = GroupInsert(this->head, tmp, frequency);
        return *this;
    }

    SinglyLinkedList& SinglyLinkedList::group_insert(const SinglyLinkedList& list, size_t frequency) {
        this->head = GroupInsert(this->head, list.head, frequency);
        return *this;
    }

    SinglyLinkedList& SinglyLinkedList::erase(size_t from, size_t count) {
        this->head = Erase(this->head, from, count);
        return *this;
    }

    SinglyLinkedList& SinglyLinkedList::erase_between(size_t from, size_t to) {
        this->head = EraseBetween(this->head, from, to);
        return *this;
    }

    SinglyLinkedList SinglyLinkedList::concat(const std::initializer_list<int>& list) {
        SinglyLinkedList new_list;
        new_list.head = Copy(head);
        new_list.head = BackMerge(new_list.head, list);
        return new_list;
    }

    SinglyLinkedList& SinglyLinkedList::repeat(size_t limit) {
        this->head = Repeat(this->head, limit);
        return *this;
    }


    SinglyLinkedList& SinglyLinkedList::partial_permutation(int32_t limit, bool resultOnly) {
        if (resultOnly) {
            this->head = PartialPermutationConstant(this->head, limit);
            // Clear(1);
        } else {
            this->head = PartialPermutation(this->head, limit);
        }
        return *this;
    }

    SinglyLinkedList& SinglyLinkedList::partial_combination(int32_t limit, int32_t factors, bool resultOnly) {
        if (factors > limit) factors = limit;
        if (resultOnly)
            this->head = PartialCombinationConstant(this->head, limit, factors);
            // Clear(this->head, 1);
        else
            this->head = PartialCombination(this->head, limit, factors);
        return *this;
    }

    SinglyLinkedList& SinglyLinkedList::partial_reflection(int32_t limit, int32_t factors, bool resultOnly) {
        if (factors > limit) factors = limit;
        if (resultOnly)
            this->head = PartialReflectionConstant(this->head, limit, factors);
        // Clear(this->head, 1);
        else
            this->head = PartialReflection(this->head, limit, factors);
        return *this;
    }

    SinglyLinkedList& SinglyLinkedList::print(std::string sep, std::ostream& cout) {
        cout << "{ ";
        Print(this->head, sep, cout);
        cout << " }" << std::endl;
        return *this;
    }

    SinglyLinkedList& SinglyLinkedList::print() {
        this->print(", ", std::cout);
        return *this;
    }

    SinglyLinkedList& SinglyLinkedList::reverse_print(std::string sep, std::ostream& cout) {
        ReversePrint(this->head, sep, cout);
        cout << std::endl;
        return *this;
    }

    SinglyLinkedList& SinglyLinkedList::reverse_print() {
        this->reverse_print(" ", std::cout);
        return *this;
    }

    std::string SinglyLinkedList::toString() {
        std::stringstream ss;
        ss << "{";
        Print(this->head, ", ", ss);
        ss << "}";
        return ss.str();
    }

    int SinglyLinkedList::size() const {
        return sll::Size(this->head);
    }

    int Size(const s_ptr head) {
        int counter = { 0 };
        s_ptr current = head;
        while (current) {
            ++counter;
            current = current->next;
        }
        return counter;
    }

    void sll::Print(const s_ptr head, std::string sep, std::ostream& cout) {
        if (not head) return;
        cout << head->data;
        if (head->next) cout << sep;
        sll::Print(head->next, sep, cout);
    }

    void sll::ReversePrint(const s_ptr head, std::string sep, std::ostream& cout) {
        if (not head) return;
        sll::ReversePrint(head->next, sep, cout);
        cout << head->data << sep;
    }

    // TODO: need to rename and repackage this:
    /*
    SinglyLinkedListNode* AddSameSize(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2, int* carry) {
        SinglyLinkedListNode* temp;
        int car = 0;
        if (not head1 or not head2) return NULL;
        temp = AddSameSize(head1->next, head2->next, carry);
        car = head1->data + head2->data + (*carry);
        head2->data = (car) % 10;
        *carry = (car) / 10;
        return head2;
    }

    //Function to add remaining carry.
    void AddCarryToRemaining(SinglyLinkedListNode* head1, SinglyLinkedListNode* curr, int* carry, SinglyLinkedListNode** result) {
        if (head1 == curr) return;
        int car;
        AddCarryToRemaining(head1->next, curr, carry, result);
        if (head1->next == curr)
            head1->next = *result;

        car = (head1->data + *carry);
        head1->data = car % 10;
        *carry = (car) / 10;
        *result = head1;
    }

    int SumNth(SinglyLinkedListNode* head, int nth) {
        if (not head) return -1;
        int sum{0};
        while (head) {
            if (not nth--) return sum;
            sum += head->data;
            head = head->next;
        }
        return sum;
    }

    SinglyLinkedListNode* swapkthnode(SinglyLinkedListNode* head, int n, int k)
    {
        if (k > n)
            return head;

        if (k == n - k + 1)
            return head;

        SinglyLinkedListNode* temp1 = head, * temp2 = head;
        SinglyLinkedListNode* prev1 = NULL, * prev2 = NULL;

        for (int i = 1; i < n - k + 1; i++) {
            prev1 = temp1; temp1 = temp1->next;

        }

        for (int i = 1; i < k; i++) {
            prev2 = temp2; temp2 = temp2->next;
        }

        if (prev1)
            prev1->next = temp2;
        if (prev2)
            prev2->next = temp1;

        SinglyLinkedListNode* temp = temp1->next;
        temp1->next = temp2->next;
        temp2->next = temp;

        if (k == 1)
            head = temp1;
        if (k == n)
            head = temp2;
        return head;
    }

    SinglyLinkedListNode* proOfPolynomials(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2, int n1, int n2)
    {
        std::vector<int> arr;
        int i = 0, j = 0;
        SinglyLinkedListNode* temp1 = head1, * temp2 = head2;
        for (i = 0; i < n1; i++) {
            for (j = 0; j < n2; j++) {
                arr[i + j] = arr[i + j] + temp1->data * temp2->data;
                temp2 = temp2->next;
            }
            temp2 = head2;
            temp1 = temp1->next;
        }
        temp1 = head1; i = 0;
        while (temp1->next) {
            temp1->data = arr[i++];
            temp1 = temp1->next;
        }
        temp1->data = arr[i++];
        if (i < arr.size()) {
            temp1->next = head2;
            temp1 = temp1->next;
        } else
            temp1->next = nullptr;

        while (i < arr.size() and temp1) {
            temp1->data = arr[i++];
            if (i < arr.size())
                temp1 = temp1->next;
            else
                temp1->next = nullptr;
        }
        return head1;
    }
    */
}
