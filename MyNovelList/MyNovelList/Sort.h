#pragma once

#include "DoubleLinkedList.h"

namespace MyNovelList {

	class Sort
	{
	public:
		static DoubleLinkedList* BubbleTitle(DoubleLinkedList* list);
		static DoubleLinkedList* BubbleTitleBack(DoubleLinkedList* list);
		static DoubleLinkedList* BubbleAuthor(DoubleLinkedList* list);
		static DoubleLinkedList* BubbleAuthorBack(DoubleLinkedList* list);
		static DoubleLinkedList* BubbleSeries(DoubleLinkedList* list);
		static DoubleLinkedList* BubbleSeriesBack(DoubleLinkedList* list);
		static DoubleLinkedList* BubbleScore(DoubleLinkedList* list);
		static DoubleLinkedList* BubbleScoreBack(DoubleLinkedList* list);

		static DoubleLinkedList* SelectionTitle(DoubleLinkedList* list);
		static DoubleLinkedList* SelectionTitleBack(DoubleLinkedList* list);
		static DoubleLinkedList* SelectionAuthor(DoubleLinkedList* list);
		static DoubleLinkedList* SelectionAuthorBack(DoubleLinkedList* list);
		static DoubleLinkedList* SelectionSeries(DoubleLinkedList* list);
		static DoubleLinkedList* SelectionSeriesBack(DoubleLinkedList* list);
		static DoubleLinkedList* SelectionScore(DoubleLinkedList* list);
		static DoubleLinkedList* SelectionScoreBack(DoubleLinkedList* list);

	};

}