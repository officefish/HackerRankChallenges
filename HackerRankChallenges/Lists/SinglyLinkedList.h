#pragma once
#include <iostream>
#include <unordered_set>
#include <algorithm>
#include <set>
#include <stack>

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
	SinglyLinkedListNode* InsertInSortedNode(SinglyLinkedListNode* head, SinglyLinkedListNode* target);
	SinglyLinkedListNode* InsertInSortedData(SinglyLinkedListNode* head, int data);

	SinglyLinkedListNode* GetNode(SinglyLinkedListNode* head, int position);
	SinglyLinkedListNode* GetNodeFromTail(SinglyLinkedListNode* head, int position);
	SinglyLinkedListNode* GetMiddleNode(SinglyLinkedListNode* head);
	SinglyLinkedListNode* GetPrevMiddleNode(SinglyLinkedListNode* head);
	SinglyLinkedListNode* GetFractionalNode(SinglyLinkedListNode* head, int k);
	SinglyLinkedListNode* GetModularNode(SinglyLinkedListNode* head, int k);
	int GetNodeData(SinglyLinkedListNode* head, int position);
	int GetNodeFromTailData(SinglyLinkedListNode* head, int positionFromTail);
	int GetMiddleNodeData(SinglyLinkedListNode* head);
	int GetFractionalNodeData(SinglyLinkedListNode* head, int k);
	int GetModularNodeData(SinglyLinkedListNode* head, int k);
	std::unordered_set<uintptr_t> GetNodeAddresses(SinglyLinkedListNode* head);

	SinglyLinkedListNode* DeleteNode(SinglyLinkedListNode* head, int position);
	SinglyLinkedListNode* DeleteNodeByValue(SinglyLinkedListNode* head, int value);
	SinglyLinkedListNode* DeleteMiddle(SinglyLinkedListNode* head);
	SinglyLinkedListNode* DeleteEveryNthNode(SinglyLinkedListNode* head, int Nth);
	SinglyLinkedListNode* DeleteBetween(SinglyLinkedListNode* head, int M, int N);
	SinglyLinkedListNode* DeleteBetweenRange(SinglyLinkedListNode* head, int M, int N);
	void DeleteWithoutHeadPointer(SinglyLinkedListNode* node);
	SinglyLinkedListNode* RemoveDublicates(SinglyLinkedListNode* head);
	SinglyLinkedListNode* RemoveDublicatesPairs(SinglyLinkedListNode* head);
	SinglyLinkedListNode* RemoveDuplicatesInSorted(SinglyLinkedListNode* head);
	SinglyLinkedListNode* DeleteNodesWithRightGreater(SinglyLinkedListNode* head);

	void SplitMiddle(SinglyLinkedListNode* head, SinglyLinkedListNode** left, SinglyLinkedListNode** right);
	void SplitAlternate(SinglyLinkedListNode* head, SinglyLinkedListNode** even, SinglyLinkedListNode** odd);

	SinglyLinkedListNode* Merge(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2);
	SinglyLinkedListNode* MergeSorted(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2);
	SinglyLinkedListNode* MergeAlternate(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2);
	void MergeAlternateModular(SinglyLinkedListNode** head1, SinglyLinkedListNode** head2);
	SinglyLinkedListNode* MergeSortedReverse(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2);

	SinglyLinkedListNode* Reverse(SinglyLinkedListNode* head);
	SinglyLinkedListNode* ReverseBetween(SinglyLinkedListNode* head, int m, int n);
	SinglyLinkedListNode* ReverseAlternate(SinglyLinkedListNode* head);
	SinglyLinkedListNode* Partition(SinglyLinkedListNode* head, int x);
	SinglyLinkedListNode* Segregate(SinglyLinkedListNode* head);
	SinglyLinkedListNode* SegregateAlternate(SinglyLinkedListNode* head);
	SinglyLinkedListNode* SortAbsolute(SinglyLinkedListNode* head);
	SinglyLinkedListNode* SortBubble(SinglyLinkedListNode* head);
	SinglyLinkedListNode* SortInsert(SinglyLinkedListNode* head);
	SinglyLinkedListNode* SortReorder(SinglyLinkedListNode* head);
	SinglyLinkedListNode* Rotate(SinglyLinkedListNode* head, int Nth);
	SinglyLinkedListNode* Reorder(SinglyLinkedListNode* head);
	SinglyLinkedListNode* RearangeAlternate(SinglyLinkedListNode* head);
	SinglyLinkedListNode* SwapData(SinglyLinkedListNode* head, SinglyLinkedListNode* xNode, SinglyLinkedListNode* yNode);
	SinglyLinkedListNode* Swap(SinglyLinkedListNode* head, SinglyLinkedListNode* xNode, SinglyLinkedListNode* yNode);
	SinglyLinkedListNode* Swap(SinglyLinkedListNode* head, int x_index, int y_index);
	SinglyLinkedListNode* PairwiseSwap(SinglyLinkedListNode* head);
	SinglyLinkedListNode* SwapZigZag(SinglyLinkedListNode* head);

	bool CompareLists(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2);
	int CountCommonNodes(SinglyLinkedListNode* node1, SinglyLinkedListNode* node2);
	int CountPairsWithSameSum(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2, int value);
	SinglyLinkedListNode* FindIntersection(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2);
	SinglyLinkedListNode* FindIntersectionEnty(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2);
	int FindIntersectionEntyValue (SinglyLinkedListNode* head1, SinglyLinkedListNode* head2);
	SinglyLinkedListNode* FindIntersectionEntyRecursively(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2);
	int FindIntersectionEntyDataRecursively(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2);
	bool HasCycle(SinglyLinkedListNode* head);
	bool IsPalindrome(SinglyLinkedListNode* head);
	int MaxPalingrome(SinglyLinkedListNode* head);



	int SumNth(SinglyLinkedListNode* head, int nth);
}

