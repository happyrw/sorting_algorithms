#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list in ascending order
 * using the Insertion sort algorithm
 * @list: Double pointer to the head of the linked list
 */
void insertion_sort_list(listint_t **list)
{
    if (list == NULL || *list == NULL || (*list)->next == NULL)
        return;

    listint_t *current;
    current = (*list)->next;
/* examines each node, compares it with the nodes before, to find the correct position for insertion.*/
    while (current != NULL)
    {
        listint_t *temp = current->next;
        listint_t *prev = current->prev;

        while (prev != NULL && prev->n > current->n)
        {
            prev->next = current->next;
            if (current->next != NULL)
                current->next->prev = prev;

            current->prev = prev->prev;
            current->next = prev;

            if (prev->prev != NULL)
                prev->prev->next = current;
            else
                *list = current;

            prev->prev = current;

            print_list(*list);

            prev = current->prev;
        }

        current = temp;
    }
}
