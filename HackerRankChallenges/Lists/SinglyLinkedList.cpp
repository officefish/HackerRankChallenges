
#include "./SinglyLinkedList.h"


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

    // TODO: need to rename and repackage this:
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

}
