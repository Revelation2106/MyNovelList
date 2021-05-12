#include "Sort.h"

namespace MyNovelList {

    //Bubble sorts
    //------------
    DoubleLinkedList* Sort::BubbleTitle(DoubleLinkedList* list, bool isBack)
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
                    if ((*list)[j - 1]->data->title < (*list)[j]->data->title)
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
                    if ((*list)[j - 1]->data->title > (*list)[j]->data->title)
                    {
                        list->swap((*list)[j - 1], (*list)[j]);
                    }
                }
            }
        }

        return list;
    }
    DoubleLinkedList* Sort::BubbleAuthor(DoubleLinkedList* list, bool isBack)
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
                    // If the node at j-1's author is alphabetically lower (Z < A for example)
                    if ((*list)[j - 1]->data->author < (*list)[j]->data->author)
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
            // the author is alpabetically higher (A > Z)
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
    DoubleLinkedList* Sort::BubbleSeries(DoubleLinkedList* list, bool isBack)
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
                    // If the node at j-1's series is alphabetically lower (Z < A for example)
                    if ((*list)[j - 1]->data->series < (*list)[j]->data->series)
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
            // the series is alpabetically higher (A > Z)
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
    DoubleLinkedList* Sort::BubbleScore(DoubleLinkedList* list, bool isBack)
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
                    // If the node at j-1's score is numerically lower
                    if ((*list)[j - 1]->data->score < (*list)[j]->data->score)
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
            // the score is numerically higher
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
                    if ((*list)[j]->data->title > max->data->title)
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
                    // If the node at j's author is alphabetically higher
                    if ((*list)[j]->data->author > max->data->author)
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
            // the author is alphabetically lower
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
                    // If the node at j's series is alphabetically higher
                    if ((*list)[j]->data->series > max->data->series)
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
            // the series is alphabetically lower
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
                    // If the node at j's score is alphabetically higher
                    if ((*list)[j]->data->score > max->data->score)
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
            // the score is numerically lower
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
                while (j > 0 && (*list)[j - 1]->data->title < key->data->title)
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
                while (j > 0 && (*list)[j - 1]->data->title > key->data->title)
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
    DoubleLinkedList* Sort::InsertionAuthor(DoubleLinkedList* list, bool isBack)
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

                // Loop while j > 0 and the node at index j-1's author is alphabetically 
                // lower than the temporary node's author
                while (j > 0 && (*list)[j - 1]->data->author < key->data->author)
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
            // the author is alphabetically higher
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

        // Return sorted list
        return list;
    }
    DoubleLinkedList* Sort::InsertionSeries(DoubleLinkedList* list, bool isBack)
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

                // Loop while j > 0 and the node at index j-1's series is alphabetically 
                // lower than the temporary node's series
                while (j > 0 && (*list)[j - 1]->data->series < key->data->series)
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
            // the series is alphabetically higher
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

        // Return sorted list
        return list;
    }
    DoubleLinkedList* Sort::InsertionScore(DoubleLinkedList* list, bool isBack)
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

                // Loop while j > 0 and the node at index j-1's score is numerically 
                // lower than the temporary node's score
                while (j > 0 && (*list)[j - 1]->data->score < key->data->score)
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
            // the score is alphabetically higher
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

        // Return sorted list
        return list;
    }

    //Shell sorts
    //---------------
    DoubleLinkedList* Sort::ShellTitle(DoubleLinkedList* list, bool isBack)
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
                    for (i = j; (i >= gap) && ((*list)[i - gap]->data->title < temp->data->title); i -= gap)
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

                    for (i = j; (i >= gap) && ((*list)[i - gap]->data->title > temp->data->title); i -= gap)
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
    DoubleLinkedList* Sort::ShellAuthor(DoubleLinkedList* list, bool isBack)
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

                    // Loop while i < j and if the author at index i-gap is 
                    // alphabeticaly lower than the author at index temp
                    for (i = j; (i >= gap) && ((*list)[i - gap]->data->author < temp->data->author); i -= gap)
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
            // the author is alphabetically higher
            for (int gap = list->size() / 2; gap > 0; gap /= 2)
            {
                for (int j = gap; j < list->size(); j++)
                {
                    auto temp = (*list)[j];
                    int i = 0;

                    for (i = j; (i >= gap) && ((*list)[i - gap]->data->author > temp->data->author); i -= gap)
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
    DoubleLinkedList* Sort::ShellSeries(DoubleLinkedList* list, bool isBack)
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

                    // Loop while i < j and if the series at index i-gap is 
                    // alphabeticaly lower than the series at index temp
                    for (i = j; (i >= gap) && ((*list)[i - gap]->data->series < temp->data->series); i -= gap)
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
            // the series is alphabetically higher
            for (int gap = list->size() / 2; gap > 0; gap /= 2)
            {
                for (int j = gap; j < list->size(); j++)
                {
                    auto temp = (*list)[j];
                    int i = 0;

                    for (i = j; (i >= gap) && ((*list)[i - gap]->data->series > temp->data->series); i -= gap)
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
    DoubleLinkedList* Sort::ShellScore(DoubleLinkedList* list, bool isBack)
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

                    // Loop while i < j and if the score at index i-gap is 
                    // numerically lower than the score at index temp
                    for (i = j; (i >= gap) && ((*list)[i - gap]->data->score < temp->data->score); i -= gap)
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
            // the score is numerically higher
            for (int gap = list->size() / 2; gap > 0; gap /= 2)
            {
                for (int j = gap; j < list->size(); j++)
                {
                    auto temp = (*list)[j];
                    int i = 0;

                    for (i = j; (i >= gap) && ((*list)[i - gap]->data->score > temp->data->score); i -= gap)
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

}