#pragma once

#include "DoubleLinkedList.h"

namespace MyNovelList {

	class Sort
	{
	public:
		//Bubble sorts
		//------------
		/// <summary>
		/// Performs Bubble Sort on the titles.
		/// </summary>
		/// <param name="list - linked list to sort"></param>
		/// <param name="isBack - false to sort in ascending order, true to sort in descending"></param>
		/// <returns>Sorted list</returns>
		static DoubleLinkedList* BubbleTitle(DoubleLinkedList* list, bool isBack = false);

		/// <summary>
		/// Performs Bubble Sort on the authors.
		/// </summary>
		/// <param name="list - linked list to sort"></param>
		/// <param name="isBack - false to sort in ascending order, true to sort in descending"></param>
		/// <returns>Sorted list</returns>
		static DoubleLinkedList* BubbleAuthor(DoubleLinkedList* list, bool isBack = false);

		/// <summary>
		/// Performs Bubble Sort on the series'.
		/// </summary>
		/// <param name="list - linked list to sort"></param>
		/// <param name="isBack - false to sort in ascending order, true to sort in descending"></param>
		/// <returns>Sorted list</returns>
		static DoubleLinkedList* BubbleSeries(DoubleLinkedList* list, bool isBack = false);

		/// <summary>
		/// Performs Bubble Sort on the scores.
		/// </summary>
		/// <param name="list - linked list to sort"></param>
		/// <param name="isBack - false to sort in ascending order, true to sort in descending"></param>
		/// <returns>Sorted list</returns>
		static DoubleLinkedList* BubbleScore(DoubleLinkedList* list, bool isBack = false);

		//Selection sorts
		//---------------
		/// <summary>
		/// Performs Selection Sort on the titles.
		/// </summary>
		/// <param name="list - linked list to sort"></param>
		/// <param name="isBack - false to sort in ascending order, true to sort in descending"></param>
		/// <returns>Sorted list</returns>
		static DoubleLinkedList* SelectionTitle(DoubleLinkedList* list, bool isBack = false);

		/// <summary>
		/// Performs Selection Sort on the authors.
		/// </summary>
		/// <param name="list - linked list to sort"></param>
		/// <param name="isBack - false to sort in ascending order, true to sort in descending"></param>
		/// <returns>Sorted list</returns>
		static DoubleLinkedList* SelectionAuthor(DoubleLinkedList* list, bool isBack = false);

		/// <summary>
		/// Performs Selection Sort on the series'.
		/// </summary>
		/// <param name="list - linked list to sort"></param>
		/// <param name="isBack - false to sort in ascending order, true to sort in descending"></param>
		/// <returns>Sorted list</returns>
		static DoubleLinkedList* SelectionSeries(DoubleLinkedList* list, bool isBack = false);

		/// <summary>
		/// Performs Selection Sort on the scores.
		/// </summary>
		/// <param name="list - linked list to sort"></param>
		/// <param name="isBack - false to sort in ascending order, true to sort in descending"></param>
		/// <returns>Sorted list</returns>
		static DoubleLinkedList* SelectionScore(DoubleLinkedList* list, bool isBack = false);

		//Insertion sorts
		//---------------
		/// <summary>
		/// Performs Insertion Sort on the titles.
		/// </summary>
		/// <param name="list - linked list to sort"></param>
		/// <param name="isBack - false to sort in ascending order, true to sort in descending"></param>
		/// <returns>Sorted list</returns>
		static DoubleLinkedList* InsertionTitle(DoubleLinkedList* list, bool isBack = false);

		/// <summary>
		/// Performs Insertion Sort on the authors.
		/// </summary>
		/// <param name="list - linked list to sort"></param>
		/// <param name="isBack - false to sort in ascending order, true to sort in descending"></param>
		/// <returns>Sorted list</returns>
		static DoubleLinkedList* InsertionAuthor(DoubleLinkedList* list, bool isBack = false);

		/// <summary>
		/// Performs Insertion Sort on the series'.
		/// </summary>
		/// <param name="list - linked list to sort"></param>
		/// <param name="isBack - false to sort in ascending order, true to sort in descending"></param>
		/// <returns>Sorted list</returns>
		static DoubleLinkedList* InsertionSeries(DoubleLinkedList* list, bool isBack = false);

		/// <summary>
		/// Performs Insertion Sort on the scores.
		/// </summary>
		/// <param name="list - linked list to sort"></param>
		/// <param name="isBack - false to sort in ascending order, true to sort in descending"></param>
		/// <returns>Sorted list</returns>
		static DoubleLinkedList* InsertionScore(DoubleLinkedList* list, bool isBack = false);

		//Shell sorts
		//---------------
		/// <summary>
		/// Performs Shell Sort on the titles.
		/// </summary>
		/// <param name="list - linked list to sort"></param>
		/// <param name="isBack - false to sort in ascending order, true to sort in descending"></param>
		/// <returns>Sorted list</returns>
		static DoubleLinkedList* ShellTitle(DoubleLinkedList* list, bool isBack = false);

		/// <summary>
		/// Performs Shell Sort on the authors.
		/// </summary>
		/// <param name="list - linked list to sort"></param>
		/// <param name="isBack - false to sort in ascending order, true to sort in descending"></param>
		/// <returns>Sorted list</returns>
		static DoubleLinkedList* ShellAuthor(DoubleLinkedList* list, bool isBack = false);

		/// <summary>
		/// Performs Shell Sort on the series'.
		/// </summary>
		/// <param name="list - linked list to sort"></param>
		/// <param name="isBack - false to sort in ascending order, true to sort in descending"></param>
		/// <returns>Sorted list</returns>
		static DoubleLinkedList* ShellSeries(DoubleLinkedList* list, bool isBack = false);

		/// <summary>
		/// Performs Shell Sort on the scores.
		/// </summary>
		/// <param name="list - linked list to sort"></param>
		/// <param name="isBack - false to sort in ascending order, true to sort in descending"></param>
		/// <returns>Sorted list</returns>
		static DoubleLinkedList* ShellScore(DoubleLinkedList* list, bool isBack = false);
	};

}