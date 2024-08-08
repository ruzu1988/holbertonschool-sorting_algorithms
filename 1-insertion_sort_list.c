#include <stdio.h>
#include "sort.h"

/**
 * swap_nodes - Intercambia dos nodos de una lista doblemente enlazada
 * @list: Double pointer
 * @node1: Primer nodo a intercambiar
 * @node2: Segundo nodo a intercambiar
 *
 */

void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2)
{
  if (node1->prev)
    node1->prev->next = node2;
  else
    *list = node2;

  if (node2->next)
    node2->next->prev = node1;

  node1->next = node2->next;
  node2->prev = node1->prev;
  node2->next = node1;
  node1->prev = node2;
}

/**
 * insertion_sort_list - Ordena una lista doblemente enlazada de enteros
 * en orden ascendente usando el algoritmo de ordenamiento por inserción
 * @list: Doble puntero a la lista a ser ordenada
 */

void insertion_sort_list(listint_t **list)
{
  listint_t *current, *temp;

  if (list == NULL || *list == NULL || (*list)->next == NULL)
    return;

  current = (*list)->next;
  while (current != NULL)
  {
    temp = current;
    while (temp->prev != NULL && temp->prev->n > temp->n)
    {
      swap_nodes(list, temp->prev, temp);
      print_list(*list);
    }
    current = current->next;
  }
}

