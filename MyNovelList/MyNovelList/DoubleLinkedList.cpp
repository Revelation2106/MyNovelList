#include "DoubleLinkedList.h"

namespace MyNovelList {

	Node* DoubleLinkedList::checkNodeExists(int k)
	{
		// Temporary node
		Node* temp = nullptr;
		// Node pointer initially set to head
		Node* ptr = head;

		// Loop through the list while the node pointer is not nullptr
		while (ptr != nullptr)
		{
			// If the node pointer key matches the specified key, 
			// set the temporary node to the node pointer and exit the loop 
			if (ptr->key == k)
			{
				temp = ptr;
				break;
			}

			// If the key doesn't match, set the node pointer to the next node in the list
			ptr = ptr->next;
		}

		// Return the temporary node
		return temp;
	}

	void DoubleLinkedList::appendNode(Node* n)
	{
		// Check if the node already exists
		if (checkNodeExists(n->key) != nullptr)
		{
			// Do nothing
		}
		else
		{
			// Check if the list doesn't exist yet
			if (head == nullptr)
			{
				// Set head to the new node
				head = n;
			}
			else
			{
				// Loop through the list until the last node is found
				Node* ptr = head;
				while (ptr->next != nullptr)
				{
					ptr = ptr->next;
				}
			
				// Append node and set previous pointer
				ptr->next = n;
				n->previous = ptr;
			}

			// Increment true key count as new node was created
			count++;
		}
	}

	void DoubleLinkedList::prependNode(Node* n)
	{
		// Check if the node already exists
		if (checkNodeExists(n->key) != nullptr)
		{
			// Do nothing
		}
		else
		{
			// Check if the list doesn't exist yet
			if (head == nullptr)
			{
				// Set head to the new node
				head = n;
			}
			else
			{
				// Prepends node and sets next pointer
				head->previous = n;
				n->next = head;

				head = n;

			}

			// Increment true key count as new node was created
			count++;
		}
	}

	void DoubleLinkedList::insertNodeAfter(int k, Node* n)
	{
		// Node pointer initially set to point to the node with key value k
		Node* ptr = checkNodeExists(k);

		// If ptr is nullptr then the node doesn't exist
		if (ptr == nullptr)
		{
			// Do nothing as no node exists with key value specified
		}
		else
		{
			// Check if the node exists and has a key
			if (checkNodeExists(n->key) != nullptr)
			{
				// Do nothing as node already exists
			}
			else
			{
				// Temporary node pointing to the next node
				Node* nextNode = ptr->next;

				// If there is no next node
				if (nextNode == nullptr)
				{
					// Append n at the end of the list
					ptr->next = n;
					n->previous = ptr;
				}
				else
				{
					// Append n after node with key of value k
					n->next = nextNode;
					nextNode->previous = n;
					n->previous = ptr;
					ptr->next = n;
				}

				// Increment true key count as new node was created
				count++;
			}
		}
	}

	void DoubleLinkedList::deleteNodeByKey(int k)
	{
		// Node pointer initially set to point to the node with key value k
		Node* ptr = checkNodeExists(k);

		// If ptr is nullptr then the node doesn't exist
		if (ptr == nullptr)
		{
			// Do nothing as no node exists with key value specified
			return;
		}

		// If the head's key equals the key value k
		if (head->key == k)
		{
			// Set head to next
			if (head->next == nullptr)
			{
				head = nullptr;
				count = 0;
			}
			else
			{
				head = head->next;
				head->previous = nullptr;
				count--;
			}

			return;
		}

		// Temporary node pointing to the next node
		Node* nextNode = ptr->next;
		// Temporary node pointing to the previous node
		Node* prevNode = ptr->previous;

		// K was deleted inbetween nodes
		prevNode->next = nextNode;

		// Check if nextNode is null (item was at the tail of the list)
		if (nextNode != nullptr)
			nextNode->previous = prevNode;

		// Decrement true key count as node was deleted
		count--;

		delete ptr;
	}

	void DoubleLinkedList::updateNodeByKey(int k, Book* d)
	{
		// Node pointer initially set to point to the node with key value k
		Node* ptr = checkNodeExists(k);

		// If the node exists
		if (ptr != nullptr)
		{
			// Successfully update data
			ptr->data = d;
		}
		else
		{
			// Do nothing as node doesn't exist with key value k
		}
	}

	Node* DoubleLinkedList::operator[](int index)
	{
		// Temporary node initially set to head
		Node* temp = head;

		// Loop through until the size of the given index
		for (int i = 0; i < index; i++)
		{
			// If a next node exists, set temp to it
			if (temp->next)
				temp = temp->next;
		}

		// Return the temporary node
		return temp;
	}

	int DoubleLinkedList::areTheyNeighbours(Node* A, Node* B) 
	{
		// Returns 1 if A->next equals B and B->previous equals A,
		// or if A->previous equals B and B->next equals A
		return (A->next == B && B->previous == A) || (A->previous == B && B->next == A);
	}

	void DoubleLinkedList::refreshOuterPointers(Node* A) 
	{
		// If A has a previous node, set its next node to A
		if (A->previous != nullptr)
			A->previous->next = A;

		// If A has a next node, set its previous node to A
		if (A->next != nullptr)
			A->next->previous = A;
	}

	void DoubleLinkedList::swap(Node* A, Node* B) 
	{
		// Temporary array of nodes used for determining neighbours
		Node* swapperVector[4];

		// Temporary node
		Node* temp;

		// If A is the same as B then there is no need to swap
		if (A == B) return;

		// If A is the head then move the head to B
		if (A == head)
			head = B;

		// If B comes before A
		if (B->next == A) {
			// Reverse them
			temp = A;
			A = B;
			B = temp;
		}

		// Set array parameters appropriately
		swapperVector[0] = A->previous;
		swapperVector[1] = B->previous;
		swapperVector[2] = A->next;
		swapperVector[3] = B->next;

		// Check if A and B are neighbours 
		if (areTheyNeighbours(A, B)) 
		{
			// Update nodes appropriately
			A->previous = swapperVector[2];
			B->previous = swapperVector[0];
			A->next = swapperVector[3];
			B->next = swapperVector[1];
		}
		else 
		{
			// Update nodes appropriately
			A->previous = swapperVector[1];
			B->previous = swapperVector[0];
			A->next = swapperVector[3];
			B->next = swapperVector[2];
		}

		// Refresh next and previous pointers for A and B
		refreshOuterPointers(A);
		refreshOuterPointers(B);
	}

}