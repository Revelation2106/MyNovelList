#pragma once

#include <string>
#include <vector>

namespace MyNovelList {

	struct Book
	{
		std::string title;
		std::string author;
		bool isSeries;
		std::string series;
		std::string volume;
		std::string score;
	};

	class Node 
	{
	public:
		int key;
		Book* data;
		Node* next;
		Node* previous;

	public:
		Node() = default;
		Node(int k, Book* d)
		{
			key = k;
			data = d;
		}
	};

	class DoubleLinkedList
	{
	public:
		Node* head;

	private:
		int count = 0;

	public:
		DoubleLinkedList()
		{
			head = NULL;
		}
		DoubleLinkedList(Node* n)
		{
			head = n;
		}

		Node* checkNodeExists(int k);

		void appendNode(Node* n);
		void prependNode(Node* n);
		void insertNodeAfter(int k, Node* n);

		void deleteNodeByKey(int k);

		void updateNodeByKey(int k, Book* d);

		Node* operator[](int index);

		int size() { return count; }

		int DoubleLinkedList::areTheyNeighbours(Node* A, Node* B);
		void DoubleLinkedList::refreshOuterPointers(Node* A);
		void swap(Node* A, Node* B);
	};

}