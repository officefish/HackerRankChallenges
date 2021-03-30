#pragma once
#include <iostream>
#include <unordered_set>
#include <algorithm>
#include <set>
#include <stack>

namespace sll {

	class SinglyLinkedListNode final {
	public:
		int data;
		std::shared_ptr<SinglyLinkedListNode> next;

		SinglyLinkedListNode(const SinglyLinkedListNode&) = delete;
		SinglyLinkedListNode() = default;
		~SinglyLinkedListNode();
		SinglyLinkedListNode(int node_data);
		std::shared_ptr<SinglyLinkedListNode> GetTail(const std::shared_ptr<SinglyLinkedListNode> head);
	};
	class SinglyLinkedList final {
	public:
		std::shared_ptr<SinglyLinkedListNode> head;

		explicit SinglyLinkedList();
		SinglyLinkedList(int data);
		SinglyLinkedList(const SinglyLinkedList&);
		SinglyLinkedList(const std::initializer_list<int>& list);
		~SinglyLinkedList();

		SinglyLinkedList& insert(int data);
		SinglyLinkedList& insert(const std::initializer_list<int>& list);
		SinglyLinkedList& insert(const SinglyLinkedList& head);
		SinglyLinkedList& back_insert(int data);
		SinglyLinkedList& back_insert(const std::initializer_list<int>& list);
		SinglyLinkedList& back_insert(const SinglyLinkedList& head);
		SinglyLinkedList& middle_insert(int data);
		SinglyLinkedList& middle_insert(const std::initializer_list<int>& list);
		SinglyLinkedList& middle_insert(const SinglyLinkedList& head);
		SinglyLinkedList& index_insert(int data, int index);
		SinglyLinkedList& index_insert(const std::initializer_list<int>& list, size_t index);
		SinglyLinkedList& index_insert(const SinglyLinkedList& head, size_t index);
		SinglyLinkedList& alternate_insert(const std::initializer_list<int>& list, size_t frequency = 1);
		SinglyLinkedList& alternate_insert(const SinglyLinkedList& head, size_t frequency = 1);
		SinglyLinkedList& group_insert(const std::initializer_list<int>& list, size_t frequency = 1);
		SinglyLinkedList& group_insert(const SinglyLinkedList& head, size_t frequency = 1);


		SinglyLinkedList& erase(size_t from, size_t count);
		SinglyLinkedList& erase_between(size_t from, size_t to);

		SinglyLinkedList concat(const std::initializer_list<int>& list = {});

		SinglyLinkedList& repeat(size_t limit);

		SinglyLinkedList& partial_permutation(int32_t limit, bool resultOnly = true);
		SinglyLinkedList& partial_combination(int32_t limit, int32_t factors, bool resultOnly = true);
		SinglyLinkedList& partial_reflection(int32_t limit, int32_t factors, bool resultOnly = true);

		SinglyLinkedList& print(std::string sep, std::ostream& cout);
		SinglyLinkedList& print();
		SinglyLinkedList& reverse_print(std::string sep, std::ostream& cout);
		SinglyLinkedList& reverse_print();



		std::string toString();
		//SinglyLinkedList* free();

		int size() const;
	};

	typedef SinglyLinkedListNode Node;
	typedef std::shared_ptr<SinglyLinkedListNode> s_ptr;
	typedef std::weak_ptr<SinglyLinkedListNode> w_ptr;

	s_ptr Clear(s_ptr head, size_t from = 0);
	void Free(const s_ptr head);

	int Size(s_ptr head);
	void Print(const s_ptr head, std::string sep, std::ostream& cout);
	void ReversePrint(const s_ptr head, std::string sep, std::ostream& cout);

	s_ptr Copy(const s_ptr head);

	s_ptr Insert(const s_ptr head, int data);
	s_ptr BackInsert(const s_ptr head, int data);
	s_ptr MiddleInsert(const s_ptr head, int data);
	s_ptr MiddleInsert(const s_ptr head, s_ptr head2);
	s_ptr IndexInsert(s_ptr head, int data, size_t index);
	s_ptr IndexInsert(const s_ptr head1, const s_ptr head2, size_t index);
	s_ptr AlternateInsert(const s_ptr head1, const s_ptr head2, size_t frequency);
	s_ptr GroupInsert(const s_ptr head1, const s_ptr head2, size_t frequency);
	s_ptr Repeat(s_ptr head, size_t limit);

	s_ptr Erase(s_ptr, size_t begin, size_t count);
	s_ptr EraseBetween(s_ptr head, size_t begin, size_t end);

	s_ptr Merge(const s_ptr head, const std::initializer_list<int>&);
	s_ptr Merge(s_ptr head1, s_ptr head2);
	s_ptr BackMerge(const s_ptr head, const std::initializer_list<int>&);

	s_ptr GetPrevMiddle(const s_ptr head);
	s_ptr GetByIndex(s_ptr head, size_t index);
	s_ptr GetByIndexOrLast(s_ptr head, size_t index);

	s_ptr PartialPermutation(s_ptr head, int32_t limit);
	s_ptr PartialPermutationConstant(s_ptr head, int32_t n);
	s_ptr PartialCombination(s_ptr head, int32_t limit, int32_t factors);
	s_ptr PartialCombinationConstant(s_ptr head, int32_t n, int32_t k);
	s_ptr PartialReflection(s_ptr head, int32_t limit, int32_t factors);
	s_ptr PartialReflectionConstant(s_ptr head, int32_t n, int32_t k);

	/*
	SinglyLinkedListNode* InsertInSortedNode(SinglyLinkedListNode* head, SinglyLinkedListNode* target);
	SinglyLinkedListNode* InsertInSortedData(SinglyLinkedListNode* head, int data);
	SinglyLinkedListNode* InsertInCircularSorted(SinglyLinkedListNode* head, int data);

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
	SinglyLinkedListNode* MergeSortedRecurenly(SinglyLinkedListNode* a, SinglyLinkedListNode* b);

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
	SinglyLinkedListNode* SwapNext(SinglyLinkedListNode* head, SinglyLinkedListNode* xNode, SinglyLinkedListNode* yNode);
	SinglyLinkedListNode* Swap(SinglyLinkedListNode* head, int x_index, int y_index);
	SinglyLinkedListNode* PairwiseSwap(SinglyLinkedListNode* head);
	SinglyLinkedListNode* SwapZigZag(SinglyLinkedListNode* head);
	long long unsigned int DecimalValue(SinglyLinkedListNode* head);

	bool CompareLists(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2);
	int CountCommonNodes(SinglyLinkedListNode* node1, SinglyLinkedListNode* node2);
	int CountPairsWithSameSum(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2, int value);
	SinglyLinkedListNode* FindIntersection(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2);
	SinglyLinkedListNode* FindIntersectionEnty(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2);
	int FindIntersectionEntyValue (SinglyLinkedListNode* head1, SinglyLinkedListNode* head2);
	SinglyLinkedListNode* FindIntersectionEntyRecursively(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2);
	int FindIntersectionEntyDataRecursively(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2);
	bool IsPalindrome(SinglyLinkedListNode* head);
	int MaxPalingrome(SinglyLinkedListNode* head);
	bool HasCycle(SinglyLinkedListNode* head);
	int CountNodesinLoop(SinglyLinkedListNode* head);
	SinglyLinkedListNode* GetCycleBeginNode(SinglyLinkedListNode* head);
	SinglyLinkedListNode* GetCycleEndNode(SinglyLinkedListNode* head);
	SinglyLinkedListNode* BreakCycle(SinglyLinkedListNode* head);
	void SplitCycle(SinglyLinkedListNode* head, SinglyLinkedListNode** head1_ref, SinglyLinkedListNode** head2_ref);

	int SumNth(SinglyLinkedListNode* head, int nth);
	*/
}

