#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list.
 *   
 * @list: A pointer to the head of the doubly linked list.
 */
void insertion_sort_list(listint_t **list)
{
    if (list == NULL || *list == NULL || (*list)->next == NULL)
        return;

    listint_t *sorted = NULL, *current = *list;

    while (current != NULL)
    {
        listint_t *next = current->next;
        listint_t *currentNode = current;

        if (sorted == NULL || sorted->n >= currentNode->n)
        {
            currentNode->next = sorted;
            currentNode->prev = NULL;

            if (sorted != NULL)
                sorted->prev = currentNode;

            sorted = currentNode;
        }
        else
        {
            listint_t *temp = sorted;

            while (temp != NULL && temp->n < currentNode->n)
                temp = temp->next;

            currentNode->next = temp;
            currentNode->prev = temp ? temp->prev : NULL;

            if (currentNode->prev != NULL)
                currentNode->prev->next = currentNode;

            if (temp != NULL)
                temp->prev = currentNode;

            if (temp == sorted)
                sorted = currentNode;
        }

        current = next;

        if (current != NULL)
            current->prev = NULL;

        *list = sorted;
        print_list(*list);
    }
}
