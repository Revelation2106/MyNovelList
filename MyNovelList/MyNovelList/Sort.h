#pragma once

/*

Name: Thomas Cole

Student ID: B00269678

I declare that the following code was produced by myself for the Algorithms & Collections - COMP09044 - module and that this is my own work.

I am aware of the penalties incurred by submitting in full or in part work that is not my own and that was developed by third parties that are not appropriately acknowledged.

*/

#include "DoubleLinkedList.h"

#include <functional>

namespace MyNovelList {

	class Sort
	{
	public:
		using CompareFunc = std::function<bool(Node*, Node*)>;
		using SortFunc = std::function<DoubleLinkedList* (DoubleLinkedList*, CompareFunc, bool)>;


		// Lambda definitions for comparators

		static constexpr auto CompareTitle = [](Node* first, Node* second)
		{
			return first->data->title > second->data->title;
		};
		static constexpr auto CompareAuthor = [](Node* first, Node* second)
		{
			return	first->data->author > second->data->author ||
					(first->data->author == second->data->author &&
					first->data->series > second->data->series) ||
					(first->data->series == second->data->series &&
					first->data->volume > second->data->volume);
		};
		static constexpr auto CompareSeries = [](Node* first, Node* second)
		{
			return	first->data->series > second->data->series ||
					(first->data->series == second->data->series &&
					first->data->volume > second->data->volume);
		};
		static constexpr auto CompareScore = [](Node* first, Node* second)
		{
			return first->data->score > second->data->score;
		};

		// Bubble sort
		//------------

		/// <summary>
		/// Performs Bubble Sort.
		/// </summary>
		/// <param name="list - linked list to sort"></param>
		/// <param name="comparator - lambda to compare"></param>
		/// <param name="isBack - false to sort in ascending order, true to sort in descending"></param>
		/// <returns>Sorted list</returns>
		static DoubleLinkedList* BubbleSort(DoubleLinkedList* list, CompareFunc comparator, bool isBack) 
		{
			// If sorting in descending order
			if (isBack)
			{
				// Loop until i is not <= the number of nodes in the list
				for (int i = 0; i <= list->size(); i++)
				{
					// Loop until j is not < the number of nodes in the list
					for (int j = 1; j < list->size(); j++)
					{
						// If the node at j-1's title is alphabetically lower (Z < A for example)
						if ( comparator((*list)[j], (*list)[j - 1]) )
						{
							// Swap the nodes
							list->swap((*list)[j - 1], (*list)[j]);
						}
					}
				}
			}
			else
			{
				// Same thing except the if statement checks if 
				// the title is alpabetically higher (A > Z)
				for (int i = 0; i <= list->size(); i++)
				{
					for (int j = 1; j < list->size(); j++)
					{
						if ( comparator((*list)[j - 1], (*list)[j]) )
						{
							list->swap((*list)[j - 1], (*list)[j]);
						}
					}
				}
			}

			return list;
		}

		// Selection sort
		//---------------

		/// <summary>
		/// Performs Selection Sort.
		/// </summary>
		/// <param name="list - linked list to sort"></param>
		/// <param name="comparator - lambda to compare"></param>
		/// <param name="isBack - false to sort in ascending order, true to sort in descending"></param>
		/// <returns>Sorted list</returns>
		static DoubleLinkedList* SelectionSort(DoubleLinkedList* list, CompareFunc comparator, bool isBack) 
		{
			// If sorting in descending order
			if (isBack)
			{
				// Loop until i is not <= the number of nodes in the list
				for (int i = 0; i <= list->size(); i++)
				{
					// Temporary node 
					auto max = (*list)[i];
					// Index of temporary node
					auto maxIndex = i;

					// Loop until j is not < the number of nodes in the list
					for (int j = i; j < list->size(); j++)
					{
						// If the node at j's title is alphabetically higher
						if (comparator((*list)[j], max))
						{
							// Set temporary node to equal the node at index j
							max = (*list)[j];
							// Increment the index of the temporary node
							maxIndex = j;
						}
					}

					// If the temporary node's index is not equal to i then 
					// swap nodes at index i and temporary index
					if (maxIndex != i)
						list->swap((*list)[i], (*list)[maxIndex]);
				}
			}
			else
			{
				// Same thing except the if statement checks if 
				// the title is alphabetically lower
				for (int i = 0; i <= list->size(); i++)
				{
					auto min = (*list)[i];
					auto minIndex = i;

					for (int j = i; j < list->size(); j++)
					{
						if (comparator(min, (*list)[j]))
						{
							min = (*list)[j];
							minIndex = j;
						}
					}

					if (minIndex != i)
						list->swap((*list)[i], (*list)[minIndex]);
				}
			}

			return list;
		}

		// Insertion sort
		//---------------
		/// <summary>
		/// Performs Insertion Sort. 
		/// </summary>
		/// <param name="list - linked list to sort"></param>
		/// <param name="isBack - false to sort in ascending order, true to sort in descending"></param>
		/// <returns>Sorted list</returns>
		static DoubleLinkedList* InsertionSort(DoubleLinkedList* list, CompareFunc comparator, bool isBack)
		{
			// If sorting in descending order
			if (isBack)
			{
				// Loop until i is not <= the number of nodes in the list
				for (int i = 1; i <= list->size(); i++)
				{
					// Temporary node 
					auto key = (*list)[i];
					// Temporary index 
					int j = i;

					// Loop while j > 0 and the node at index j-1's title is alphabetically 
					// lower than the temporary node's title
					while (j > 0 && comparator(key, (*list)[j - 1]))
					{
						// Swap the nodes at index j-1 and j
						list->swap((*list)[j - 1], (*list)[j]);
						// Decrement j by itself -1
						j = j - 1;
					}

					// Swap the nodes at index j and whatever the key is
					list->swap((*list)[j], key);
				}
			}
			else
			{
				// Same thing except the while statement checks if 
				// the title is alphabetically higher
				for (int i = 1; i <= list->size(); i++)
				{
					auto key = (*list)[i];
					int j = i;
					while (j > 0 && comparator((*list)[j - 1], key))
					{
						list->swap((*list)[j - 1], (*list)[j]);
						j = j - 1;
					}
					list->swap((*list)[j], key);
				}
			}

			// Return sorted list
			return list;
		}

		// Shell sort
		//-----------
		/// <summary>
		/// Performs Shell Sort.
		/// </summary>
		/// <param name="list - linked list to sort"></param>
		/// <param name="isBack - false to sort in ascending order, true to sort in descending"></param>
		/// <returns>Sorted list</returns>
		static DoubleLinkedList* ShellSort(DoubleLinkedList* list, CompareFunc comparator, bool isBack) 
		{
			// If sorting in descending order
			if (isBack)
			{
				// Loop through the size of the list divided by 2 in intervals of 2
				for (int gap = list->size() / 2; gap > 0; gap /= 2)
				{
					// Loop while j - gap is les than the number of nodes in the list
					for (int j = gap; j < list->size(); j++)
					{
						// Temporary node
						auto temp = (*list)[j];
						// Temporary index
						int i = 0;

						// Loop while i < j and if the title at index i-gap is 
						// alphabeticaly lower than the title at index temp
						for (i = j; (i >= gap) && comparator(temp, (*list)[i - gap]); i -= gap)
						{
							// Swap the nodes at index i-gap and i
							list->swap((*list)[i - gap], (*list)[i]);
						}

						// Swap the nodes at index i and temp
						list->swap((*list)[i], temp);
					}
				}
			}
			else
			{
				// Same thing except the third for loop checks if 
				// the title is alphabetically higher
				for (int gap = list->size() / 2; gap > 0; gap /= 2)
				{
					for (int j = gap; j < list->size(); j++)
					{
						auto temp = (*list)[j];
						int i = 0;

						for (i = j; (i >= gap) && comparator((*list)[i - gap], temp); i -= gap)
						{
							list->swap((*list)[i - gap], (*list)[i]);
						}

						list->swap((*list)[i], temp);
					}
				}
			}

			// Return sorted list
			return list;
		}
	};

}