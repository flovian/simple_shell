#include "main.h"

/**
 * update_value - updates value field list_t node at given index
 * @h: head of list_t
 * @index: index of node to update
 * @value: new value
 *
 * Return: 0 success. -1 Otherwise
 */
int update_value(list_t *h, int index, const char *value)
{
	list_t *trav = h;

	if (h == NULL || index < 0 || value == NULL)
		return (-1);

	/* find node to update */
	while (index && trav)
	{
		index--;
		trav = trav->next;
	}

	/* update node */
	if (trav)
	{
		free(trav->value);
		trav->value = _strdup(value);
		/*printf("UPDATE SUCCESSFUL!!!!\n");*/
		return (0);
	}

	return (-1);
}

/**
 * delete_node_index - deletes the node at given name of a linked list
 * @head: pointer to the pointer of the 1st node in the list
 * @index: the index of the node that should be deleted
 *
 * Return: 0 is successful
 *         Otherwise -1
 */
int delete_node_index(list_t **head, int index)
{
	list_t *current, *del;
	int i;

	/* Check if list does not exist or list is empty */
	if (head == NULL || *head == NULL)
		return (-1);

	current = *head;

	/* Check if you are deleting the first node */
	if (index == 0)
	{
		*head = (*head)->next;
		free_node(current);
		return (0);
	}

	/* Node before deletion */
	for (i = 0; (i < index - 1) && current->next; i++)
		current = current->next;

	/* Delete the node */
	if (current->next && i == index - 1)
	{
		del = current->next;
		current->next = current->next->next;
		free_node(del);
	}

	return (0);
}
