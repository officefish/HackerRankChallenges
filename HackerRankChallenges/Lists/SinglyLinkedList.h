#pragma once
#include <iostream>

namespace sll {
	class SinglyLinkedListNode {
	public:
		int data;
		SinglyLinkedListNode* next;
		SinglyLinkedListNode() = default;
		~SinglyLinkedListNode() = default;
		SinglyLinkedListNode(int node_data);
		SinglyLinkedListNode* GetTail(SinglyLinkedListNode* head);
	};
	class SinglyLinkedList {
	public:
		SinglyLinkedListNode* head;
		SinglyLinkedListNode* tail;
		SinglyLinkedList();
		~SinglyLinkedList() = default;
		void InsertNode(int data);
		int size();
	};
	int Size(SinglyLinkedListNode* head);
	void PrintSinglyLinkedList(SinglyLinkedListNode* node, std::string sep, std::ostream& cout);
	void FreeSinglyLinkedList(SinglyLinkedListNode* node);
	SinglyLinkedListNode* Sort(SinglyLinkedListNode* head);
	void Print(SinglyLinkedListNode* head);
	void ReversePrint(SinglyLinkedListNode* head);
	SinglyLinkedListNode* InsertNodeAtHead(SinglyLinkedListNode* llist, int data);
	SinglyLinkedListNode* InsertNodeAtTail(SinglyLinkedListNode* head, int data);
	SinglyLinkedListNode* InsertNodeAtPosition(SinglyLinkedListNode* head, int data, int position);
	SinglyLinkedListNode* DeleteNode(SinglyLinkedListNode* head, int position);
	SinglyLinkedListNode* Reverse(SinglyLinkedListNode* head);
	int GetNodeData(SinglyLinkedListNode* head, int positionFromTail);
	bool CompareLists(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2);
	SinglyLinkedListNode* MergeSorted(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2);
	int MergedEntyNodeValue (SinglyLinkedListNode* head1, SinglyLinkedListNode* head2);
	SinglyLinkedListNode* RemoveDuplicatesInSorted(SinglyLinkedListNode* head1);
	bool HasCycle(SinglyLinkedListNode* head);
}

