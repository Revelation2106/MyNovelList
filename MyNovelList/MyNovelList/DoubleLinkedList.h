#pragma once

/*

Name: Thomas Cole

Student ID: B00269678

I declare that the following code was produced by myself for the Algorithms & Collections - COMP09044 - module and that this is my own work.

I am aware of the penalties incurred by submitting in full or in part work that is not my own and that was developed by third parties that are not appropriately acknowledged.

*/

#include <string>
#include <vector>

namespace MyNovelList {

	/// <summary>
	/// Stores the title, author, series, volume and score.
	/// Has the bool isSeries - which decides if the series and volume parameters should be filled.
	/// </summary>
	struct Book
	{
		std::string title;
		std::string author;
		bool isSeries = false;
		std::string series = "";
		int volume = 1;
		int score;
	};

	// Node class used in the doubly linked list.
	class Node
	{
	public:
		int key;
		Book* data;
		Node* next;
		Node* previous;

	public:
		// Default constructor.
		Node() = default;

		/// <summary>
		/// Constructor.
		/// </summary>
		/// <param name="k - key integer"></param>
		/// <param name="d - book struct"></param>
		Node(int k, Book* d)
		{
			key = k;
			data = d;
		}
		~Node()
		{
			delete data;
		}
	};

	class DoubleLinkedList
	{
	public:
		// Reference to head of the list.
		Node* head;

	private:
		// Count is used in serialisation for tracking the true key value.
		int count = 0;

	public:
		// Default constructor.
		DoubleLinkedList()
		{
			head = nullptr;
		}
		/// <summary>
		/// Constructor. Takes a node which will be set as the head. 
		/// </summary>
		/// <param name="n - head node"></param>
		DoubleLinkedList(Node* n)
		{
			head = n;
		}

		/// <summary>
		/// Checks if a node exists by searching through the list 
		/// based on the key passed to the function.
		/// </summary>
		/// <param name="k - key to search by"></param>
		/// <returns>Node pointer if it exists, otherwise nullptr</returns>
		Node* checkNodeExists(int k);

		/// <summary>
		/// Adds a node to the end of the list.
		/// </summary>
		/// <param name="n - node to insert"></param>
		void appendNode(Node* n);
		/// <summary>
		/// Adds a node to the start of the list.
		/// </summary>
		/// <param name="n - node to insert"></param>
		void prependNode(Node* n);

		/// <summary>
		/// Adds a node to the list after a given node.
		/// </summary>
		/// <param name="k - key of node to insert after"></param>
		/// <param name="n - node to be inserted"></param>
		void insertNodeAfter(int k, Node* n);

		/// <summary>
		/// Deletes a node from the list.
		/// </summary>
		/// <param name="k - key of node to be deleted"></param>
		void deleteNodeByKey(int k);

		/// <summary>
		/// Updates a node in the list.
		/// </summary>
		/// <param name="k - key of node to be updated"></param>
		/// <param name="d - book data to replace the current data"></param>
		void updateNodeByKey(int k, Book* d);

		/// <summary>
		/// Operater overload for the [] operation. 
		/// Allows iteration through the list in loops.
		/// </summary>
		/// <param name="Index integer"></param>
		/// <returns>Node pointer at the index</returns>
		Node* operator[](int index);

		/// <summary>
		/// Returns the size of the list.
		/// </summary>
		/// <returns>Count</returns>
		int size() { return count; }

		/// <summary>
		/// Checks if two nodes are next to each other in the list.
		/// </summary>
		/// <param name="A - first node"></param>
		/// <param name="B - second node"></param>
		/// <returns>Returns 1 if nodes are neighbours</returns>
		int areTheyNeighbours(Node* A, Node* B);

		/// <summary>
		/// Refreshes ->next and ->previous node connections.
		/// Used in the swap function
		/// </summary>
		/// <param name="A - node"></param>
		void refreshOuterPointers(Node* A);

		/// <summary>
		/// Swaps two specified nodes in the list.
		/// </summary>
		/// <param name="A - first node"></param>
		/// <param name="B - second node"></param>
		void swap(Node* A, Node* B);
	};

}