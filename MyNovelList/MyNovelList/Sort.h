#pragma once

#include "DoubleLinkedList.h"

namespace MyNovelList {

	class Sort
	{
	public:
		static DoubleLinkedList* BubbleTitle(DoubleLinkedList* list, bool isBack = false);
		static DoubleLinkedList* BubbleAuthor(DoubleLinkedList* list, bool isBack = false);
		static DoubleLinkedList* BubbleSeries(DoubleLinkedList* list, bool isBack = false);
		static DoubleLinkedList* BubbleScore(DoubleLinkedList* list, bool isBack = false);

		static DoubleLinkedList* SelectionTitle(DoubleLinkedList* list, bool isBack = false);
		static DoubleLinkedList* SelectionAuthor(DoubleLinkedList* list, bool isBack = false);
		static DoubleLinkedList* SelectionSeries(DoubleLinkedList* list, bool isBack = false);
		static DoubleLinkedList* SelectionScore(DoubleLinkedList* list, bool isBack = false);

		static DoubleLinkedList* InsertionTitle(DoubleLinkedList* list, bool isBack = false);
		static DoubleLinkedList* InsertionAuthor(DoubleLinkedList* list, bool isBack = false);
		static DoubleLinkedList* InsertionSeries(DoubleLinkedList* list, bool isBack = false);
		static DoubleLinkedList* InsertionScore(DoubleLinkedList* list, bool isBack = false);
	};

}