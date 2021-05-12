#include "Sort.h"

namespace MyNovelList {

    //Bubble sorts
    //------------
    DoubleLinkedList* MyNovelList::Sort::BubbleTitle(DoubleLinkedList* list, bool isBack)
    {
        if (isBack)
        {
            for (int i = 0; i <= list->size(); i++)
            {
                for (int j = 1; j < list->size(); j++)
                {
                    if ((*list)[j - 1]->data->title < (*list)[j]->data->title)
                    {
                        list->swap((*list)[j - 1], (*list)[j]);
                    }
                }
            }
        }
        else
        {
            for (int i = 0; i <= list->size(); i++)
            {
                for (int j = 1; j < list->size(); j++)
                {
                    if ((*list)[j - 1]->data->title > (*list)[j]->data->title)
                    {
                        list->swap((*list)[j - 1], (*list)[j]);
                    }
                }
            }
        }

        return list;
    }
    DoubleLinkedList* MyNovelList::Sort::BubbleAuthor(DoubleLinkedList* list, bool isBack)
    {
        if (isBack)
        {
            for (int i = 0; i <= list->size(); i++)
            {
                for (int j = 1; j < list->size(); j++)
                {
                    if ((*list)[j - 1]->data->author < (*list)[j]->data->author)
                    {
                        list->swap((*list)[j - 1], (*list)[j]);
                    }
                }
            }
        }
        else
        {
            for (int i = 0; i <= list->size(); i++)
            {
                for (int j = 1; j < list->size(); j++)
                {
                    if ((*list)[j - 1]->data->author > (*list)[j]->data->author)
                    {
                        list->swap((*list)[j - 1], (*list)[j]);
                    }
                }
            }
        }

        return list;
    }
    DoubleLinkedList* MyNovelList::Sort::BubbleSeries(DoubleLinkedList* list, bool isBack)
    {
        if (isBack)
        {
            for (int i = 0; i <= list->size(); i++)
            {
                for (int j = 1; j < list->size(); j++)
                {
                    if ((*list)[j - 1]->data->series < (*list)[j]->data->series)
                    {
                        list->swap((*list)[j - 1], (*list)[j]);
                    }
                }
            }
        }
        else
        {
            for (int i = 0; i <= list->size(); i++)
            {
                for (int j = 1; j < list->size(); j++)
                {
                    if ((*list)[j - 1]->data->series > (*list)[j]->data->series)
                    {
                        list->swap((*list)[j - 1], (*list)[j]);
                    }
                }
            }
        }

        return list;
    }
    DoubleLinkedList* MyNovelList::Sort::BubbleScore(DoubleLinkedList* list, bool isBack)
    {
        if (isBack)
        {
            for (int i = 0; i <= list->size(); i++)
            {
                for (int j = 1; j < list->size(); j++)
                {
                    if ((*list)[j - 1]->data->score < (*list)[j]->data->score)
                    {
                        list->swap((*list)[j - 1], (*list)[j]);
                    }
                }
            }
        }
        else
        {
            for (int i = 0; i <= list->size(); i++)
            {
                for (int j = 1; j < list->size(); j++)
                {
                    if ((*list)[j - 1]->data->score > (*list)[j]->data->score)
                    {
                        list->swap((*list)[j - 1], (*list)[j]);
                    }
                }
            }
        }

        return list;
    }

    //Selection sorts
    //---------------
    DoubleLinkedList* Sort::SelectionTitle(DoubleLinkedList* list, bool isBack)
    {
        if (isBack)
        {
            for (int i = 0; i <= list->size(); i++)
            {
                auto max = (*list)[i];
                auto maxIndex = i;

                for (int j = i; j < list->size(); j++)
                {
                    if ((*list)[j]->data->title > max->data->title)
                    {
                        max = (*list)[j];
                        maxIndex = j;
                    }
                }

                if (maxIndex != i)
                    list->swap((*list)[i], (*list)[maxIndex]);
            }
        }
        else
        {
            for (int i = 0; i <= list->size(); i++)
            {
                auto min = (*list)[i];
                auto minIndex = i;

                for (int j = i; j < list->size(); j++)
                {
                    if ((*list)[j]->data->title < min->data->title)
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
    DoubleLinkedList* Sort::SelectionAuthor(DoubleLinkedList* list, bool isBack)
    {
        if (isBack)
        {
            for (int i = 0; i <= list->size(); i++)
            {
                auto max = (*list)[i];
                auto maxIndex = i;

                for (int j = i; j < list->size(); j++)
                {
                    if ((*list)[j]->data->author > max->data->author)
                    {
                        max = (*list)[j];
                        maxIndex = j;
                    }
                }

                if (maxIndex != i)
                    list->swap((*list)[i], (*list)[maxIndex]);
            }
        }
        else
        {
            for (int i = 0; i <= list->size(); i++)
            {
                auto min = (*list)[i];
                auto minIndex = i;

                for (int j = i; j < list->size(); j++)
                {
                    if ((*list)[j]->data->author < min->data->author)
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
    DoubleLinkedList* Sort::SelectionSeries(DoubleLinkedList* list, bool isBack)
    {
        if (isBack)
        {
            for (int i = 0; i <= list->size(); i++)
            {
                auto max = (*list)[i];
                auto maxIndex = i;

                for (int j = i; j < list->size(); j++)
                {
                    if ((*list)[j]->data->series > max->data->series)
                    {
                        max = (*list)[j];
                        maxIndex = j;
                    }
                }

                if (maxIndex != i)
                    list->swap((*list)[i], (*list)[maxIndex]);
            }
        }
        else
        {
            for (int i = 0; i <= list->size(); i++)
            {
                auto min = (*list)[i];
                auto minIndex = i;

                for (int j = i; j < list->size(); j++)
                {
                    if ((*list)[j]->data->series < min->data->series)
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
    DoubleLinkedList* Sort::SelectionScore(DoubleLinkedList* list, bool isBack)
    {
        if (isBack)
        {
            for (int i = 0; i <= list->size(); i++)
            {
                auto max = (*list)[i];
                auto maxIndex = i;

                for (int j = i; j < list->size(); j++)
                {
                    if ((*list)[j]->data->score > max->data->score)
                    {
                        max = (*list)[j];
                        maxIndex = j;
                    }
                }

                if (maxIndex != i)
                    list->swap((*list)[i], (*list)[maxIndex]);
            }
        }
        else
        {
            for (int i = 0; i <= list->size(); i++)
            {
                auto min = (*list)[i];
                auto minIndex = i;

                for (int j = i; j < list->size(); j++)
                {
                    if ((*list)[j]->data->score < min->data->score)
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

    //Insertion sorts
    //---------------
    DoubleLinkedList* Sort::InsertionTitle(DoubleLinkedList* list, bool isBack)
    {
        if (isBack)
        {
            for (int i = 1; i <= list->size(); i++)
            {
                auto key = (*list)[i];
                int j = i;
                while (j > 0 && (*list)[j - 1]->data->title < key->data->title)
                {
                    list->swap((*list)[j - 1], (*list)[j]);
                    j = j - 1;
                }
                list->swap((*list)[j], key);
            }
        }
        else
        {
            for (int i = 1; i <= list->size(); i++)
            {
                auto key = (*list)[i];
                int j = i;
                while (j > 0 && (*list)[j - 1]->data->title > key->data->title)
                {
                    list->swap((*list)[j - 1], (*list)[j]);
                    j = j - 1;
                }
                list->swap((*list)[j], key);
            }
        }

        return list;
    }

    DoubleLinkedList* Sort::InsertionAuthor(DoubleLinkedList* list, bool isBack)
    {
        if (isBack)
        {
            for (int i = 1; i <= list->size(); i++)
            {
                auto key = (*list)[i];
                int j = i;
                while (j > 0 && (*list)[j - 1]->data->author < key->data->author)
                {
                    list->swap((*list)[j - 1], (*list)[j]);
                    j = j - 1;
                }
                list->swap((*list)[j], key);
            }
        }
        else
        {
            for (int i = 1; i <= list->size(); i++)
            {
                auto key = (*list)[i];
                int j = i;
                while (j > 0 && (*list)[j - 1]->data->author > key->data->author)
                {
                    list->swap((*list)[j - 1], (*list)[j]);
                    j = j - 1;
                }
                list->swap((*list)[j], key);
            }
        }

        return list;
    }

    DoubleLinkedList* Sort::InsertionSeries(DoubleLinkedList* list, bool isBack)
    {
        if (isBack)
        {
            for (int i = 1; i <= list->size(); i++)
            {
                auto key = (*list)[i];
                int j = i;
                while (j > 0 && (*list)[j - 1]->data->series < key->data->series)
                {
                    list->swap((*list)[j - 1], (*list)[j]);
                    j = j - 1;
                }
                list->swap((*list)[j], key);
            }
        }
        else
        {
            for (int i = 1; i <= list->size(); i++)
            {
                auto key = (*list)[i];
                int j = i;
                while (j > 0 && (*list)[j - 1]->data->series > key->data->series)
                {
                    list->swap((*list)[j - 1], (*list)[j]);
                    j = j - 1;
                }
                list->swap((*list)[j], key);
            }
        }

        return list;
    }

    DoubleLinkedList* Sort::InsertionScore(DoubleLinkedList* list, bool isBack)
    {
        if (isBack)
        {
            for (int i = 1; i <= list->size(); i++)
            {
                auto key = (*list)[i];
                int j = i;
                while (j > 0 && (*list)[j - 1]->data->score < key->data->score)
                {
                    list->swap((*list)[j - 1], (*list)[j]);
                    j = j - 1;
                }
                list->swap((*list)[j], key);
            }
        }
        else
        {
            for (int i = 1; i <= list->size(); i++)
            {
                auto key = (*list)[i];
                int j = i;
                while (j > 0 && (*list)[j - 1]->data->score > key->data->score)
                {
                    list->swap((*list)[j - 1], (*list)[j]);
                    j = j - 1;
                }
                list->swap((*list)[j], key);
            }
        }

        return list;
    }

}