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

	void Print(SinglyLinkedListNode* head);
	void ReversePrint(SinglyLinkedListNode* head);
	SinglyLinkedListNode* InsertNodeAtHead(SinglyLinkedListNode* llist, int data);
	SinglyLinkedListNode* InsertNodeAtTail(SinglyLinkedListNode* head, int data);
	SinglyLinkedListNode* InsertNodeAtPosition(SinglyLinkedListNode* head, int data, int position);
	int GetNodeData(SinglyLinkedListNode* head, int position);
	int GetNodeDataFromTail(SinglyLinkedListNode* head, int positionFromTail);
	SinglyLinkedListNode* DeleteNode(SinglyLinkedListNode* head, int position);
	SinglyLinkedListNode* DeleteNodeByValue(SinglyLinkedListNode* head, int value);
	SinglyLinkedListNode* Reverse(SinglyLinkedListNode* head);
	bool CompareLists(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2);
	SinglyLinkedListNode* Sort(SinglyLinkedListNode* head);
	SinglyLinkedListNode* MergeSorted(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2);
	int MergedEntyNodeValue (SinglyLinkedListNode* head1, SinglyLinkedListNode* head2);
	SinglyLinkedListNode* RemoveDuplicatesInSorted(SinglyLinkedListNode* head);
	bool HasCycle(SinglyLinkedListNode* head);
}

