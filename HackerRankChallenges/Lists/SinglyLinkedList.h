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
	SinglyLinkedListNode* InsertNodeAtMiddle(SinglyLinkedListNode* head, int data);
	int GetNodeData(SinglyLinkedListNode* head, int position);
	int GetNodeDataFromTail(SinglyLinkedListNode* head, int positionFromTail);
	SinglyLinkedListNode* GetMiddleNode(SinglyLinkedListNode* head);
	int GetMiddleNodeData(SinglyLinkedListNode* head);
	SinglyLinkedListNode* DeleteNode(SinglyLinkedListNode* head, int position);
	SinglyLinkedListNode* DeleteNodeByValue(SinglyLinkedListNode* head, int value);
	SinglyLinkedListNode* DeleteMiddle(SinglyLinkedListNode* head);
	SinglyLinkedListNode* DeleteNthNode(SinglyLinkedListNode* head, int Nth);
	SinglyLinkedListNode* RemoveDublicates(SinglyLinkedListNode* head);
	SinglyLinkedListNode* RemoveOccurencesOfDublicates(SinglyLinkedListNode* head);
	SinglyLinkedListNode* Reverse(SinglyLinkedListNode* head);
	bool CompareLists(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2);
	SinglyLinkedListNode* Partition(SinglyLinkedListNode* head, int x);
	SinglyLinkedListNode* BubbleSort(SinglyLinkedListNode* head);
	SinglyLinkedListNode* SortInsert(SinglyLinkedListNode* head);
	SinglyLinkedListNode* InsertInSortedData(SinglyLinkedListNode* head, int data);
	SinglyLinkedListNode* InsertInSortedNode(SinglyLinkedListNode* head, SinglyLinkedListNode* target);
	SinglyLinkedListNode* MergeSorted(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2);
	SinglyLinkedListNode* RemoveDuplicatesInSorted(SinglyLinkedListNode* head);
	int MergedEntyNodeValue (SinglyLinkedListNode* head1, SinglyLinkedListNode* head2);
	bool HasCycle(SinglyLinkedListNode* head);
	bool IsPalindrome(SinglyLinkedListNode* head);
	//
	void alternatingSplitList(SinglyLinkedListNode* head,
		SinglyLinkedListNode* split1, SinglyLinkedListNode* split2);
}

