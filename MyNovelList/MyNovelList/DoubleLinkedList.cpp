#include "DoubleLinkedList.h"

namespace MyNovelList {

	Node* DoubleLinkedList::checkNodeExists(int k)
	{
		Node* temp = nullptr;
		Node* ptr = head;

		while (ptr != nullptr)
		{
			if (ptr->key == k)
			{
				temp = ptr;
				break;
			}

			ptr = ptr->next;
		}

		return temp;
	}

	void DoubleLinkedList::appendNode(Node* n)
	{
		if (checkNodeExists(n->key) != nullptr)
		{
			//Error: node exists
		}
		else
		{
			if (head == nullptr)
			{
				//n set to head
				head = n;
			}
			else
			{
				Node* ptr = head;
				while (ptr->next != nullptr)
				{
					ptr = ptr->next;
				}
			
				//Append node and set previous pointer
				ptr->next = n;
				n->previous = ptr;
			}
			count++;
		}
	}

	void DoubleLinkedList::prependNode(Node* n)
	{
		if (checkNodeExists(n->key) != nullptr)
		{
			//Error: node exists
		}
		else
		{
			if (head == nullptr)
			{
				//n set to head
				head = n;
			}
			else
			{
				//Prepends node and sets next pointer
				head->previous = n;
				n->next = head;

				head = n;

			}
			count++;
		}
	}

	void DoubleLinkedList::insertNodeAfter(int k, Node* n)
	{
		Node* ptr = checkNodeExists(k);
		if (ptr == nullptr)
		{
			//Error: no node exists with key value specified
		}
		else
		{
			if (checkNodeExists(n->key) != nullptr)
			{
				//Error: node already exists
			}
			else
			{
				Node* nextNode = ptr->next;

				if (nextNode == nullptr)
				{
					//Append n at the end of the list
					ptr->next = n;
					n->previous = ptr;
				}
				else
				{
					//Append n after node with key of value k
					n->next = nextNode;
					nextNode->previous = n;
					n->previous = ptr;
					ptr->next = n;
				}
				count++;
			}
		}
	}

	void DoubleLinkedList::deleteNodeByKey(int k)
	{
		Node* ptr = checkNodeExists(k);
		if (ptr == nullptr)
		{
			//Error: no node exists with key value specified
		}
		else
		{
			if (head->key == k)
			{
				//k = head, so set head to next
				head = head->next;
				head->previous = nullptr;
			}
			else
			{
				Node* nextNode = ptr->next;
				Node* prevNode = ptr->previous;

				if (nextNode == nullptr)
				{
					//k deleted at end of linked list
					prevNode->next = nullptr;
				}
				else
				{
					//k deleted in between nodes
					prevNode->next = nextNode;
					nextNode->previous = prevNode;
				}
			}
			count--;
		}
	}

	void DoubleLinkedList::updateNodeByKey(int k, Book* d)
	{
		Node* ptr = checkNodeExists(k);
		if (ptr != nullptr)
		{
			//Successfully update data
			ptr->data = d;
		}
		else
		{
			//Error: node doesn't exist with key value k
		}
	}

	Node* DoubleLinkedList::operator[](int index)
	{
		Node* temp = head;

		for (int i = 0; i < index; i++)
		{
			if (temp->next)
				temp = temp->next;
		}

		return temp;
	}

	int DoubleLinkedList::areTheyNeighbours(Node* A, Node* B) 
	{
		return (A->next == B && B->previous == A) || (A->previous == B && B->next == A);
	}
	void DoubleLinkedList::refreshOuterPointers(Node* A) 
	{
		if (A->previous != nullptr)
			A->previous->next = A;

		if (A->next != nullptr)
			A->next->previous = A;
	}
	void DoubleLinkedList::swap(Node* A, Node* B) {
		Node* swapperVector[4];
		Node* temp;

		if (A == B) return;

		if (A == head)
			head = B;

		if (B->next == A) {
			temp = A;
			A = B;
			B = temp;
		}

		swapperVector[0] = A->previous;
		swapperVector[1] = B->previous;
		swapperVector[2] = A->next;
		swapperVector[3] = B->next;

		if (areTheyNeighbours(A, B)) {
			A->previous = swapperVector[2];
			B->previous = swapperVector[0];
			A->next = swapperVector[3];
			B->next = swapperVector[1];
		}
		else {
			A->previous = swapperVector[1];
			B->previous = swapperVector[0];
			A->next = swapperVector[3];
			B->next = swapperVector[2];
		}

		refreshOuterPointers(A);
		refreshOuterPointers(B);
	}

}