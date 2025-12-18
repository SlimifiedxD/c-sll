#include "sll.h"
#include <stdlib.h>

typedef struct Node Node;
typedef struct List List;

static Node *createNode(int data);

struct Node
{
  int data;
  Node *next;
};

struct List
{
  Node *head;
  int length;
};

List *SLL_createList()
{
  List *l = (List *)malloc(sizeof(List));
  l->head = NULL;
  l->length = 0;
  return l;
}

int SLL_addFront(List *l, int data)
{
  if (l == NULL)
  {
    return SLL_ERR_NULL;
  }
  Node *n = createNode(data);
  if (n == NULL)
  {
    return SLL_ERR_NO_MEM;
  }
  n->next = l->head;
  l->head = n;
  l->length++;
  return SLL_OK;
}

int SLL_addEnd(List *l, int data)
{
  if (l == NULL)
  {
    return SLL_ERR_NULL;
  }
  Node *n = createNode(data);
  if (n == NULL)
  {
    return SLL_ERR_NO_MEM;
  }
  Node *cur = l->head;
  while (cur->next != NULL)
  {
    cur = cur->next;
  }
  cur->next = n;
  l->length++;
  return SLL_OK;
}

int SLL_get(List *l, int index, int *out)
{
  if (l == NULL || out == NULL)
  {
    return SLL_ERR_NULL;
  }
  if (l->head == NULL)
  {
    return SLL_ERR_EMPTY;
  }
  if (index < 0 || index >= l->length)
  {
    return SLL_ERR_OUT_OF_BOUNDS;
  }
  Node *cur = l->head;
  for (int i = 0; i < index; i++)
  {
    cur = cur->next;
  }
  *out = cur->data;
  return SLL_OK;
}

int SLL_getLength(List *l, int *out)
{
  if (l == NULL || out == NULL)
  {
    return SLL_ERR_NULL;
  }
  *out = l->length;
  return SLL_OK;
}

int SLL_traverse(List *l, void (*callback)(int data))
{
  Node *cur = l->head;
  for (int i = 0; i < l->length; i++)
  {
    callback(cur->data);
    cur = cur->next;
  }
  return SLL_OK;
}

int SLL_removeHead(List *l)
{
  if (l == NULL)
  {
    return SLL_ERR_NULL;
  }
  if (l->head == NULL)
  {
    return SLL_ERR_EMPTY;
  }
  Node *temp = l->head;
  l->head = temp->next;
  free(temp);
  l->length--;
  return SLL_OK;
}

int SLL_removeEnd(List *l)
{
  if (l == NULL)
  {
    return SLL_ERR_NULL;
  }
  if (l->head == NULL)
  {
    return SLL_ERR_EMPTY;
  }
  if (l->head->next == NULL)
  {
    free(l->head);
    l->head = NULL;
    l->length--;
    return SLL_OK;
  }
  Node *prev = l->head;
  Node *cur = l->head->next;
  while (cur->next != NULL)
  {
    prev = cur;
    cur = cur->next;
  }
  prev->next = NULL;
  free(cur);
  l->length--;
  return SLL_OK;
}

static Node *createNode(int data)
{
  Node *n = (Node *)malloc(sizeof *n);
  n->data = data;
  return n;
}
