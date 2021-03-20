#pragma once
#include <iostream>

namespace dll {
	using std::ostream, std::string;

	class DoublyLinkedListNode {
	public:
		int data;
		DoublyLinkedListNode* next;
		DoublyLinkedListNode* prev;
		DoublyLinkedListNode() = default;
		~DoublyLinkedListNode() = default;
		DoublyLinkedListNode(int node_data);
};
	class DoublyLinkedList {
	public:
		DoublyLinkedListNode* head;
		DoublyLinkedListNode* tail;
		DoublyLinkedList();
		~DoublyLinkedList() = default;
		void InsertNode(int data);
		int size();
	};

	void PrintDoublyLinkedList(DoublyLinkedListNode* node, string sep, ostream& cout);
	void FreeDoublyLinkedList(DoublyLinkedListNode* node);
	DoublyLinkedListNode* SortedInsert(DoublyLinkedListNode* node, int data);
	DoublyLinkedListNode* Reverse(DoublyLinkedListNode* head);
}
