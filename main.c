#include "sll.h"
#include <stdio.h>

void printElement(int data) { printf("%d\n", data); }

int main()
{
  List *l = SLL_createList();
  if (!l)
  {
    return 1;
  }
  int out = 0;
  SLL_addFront(l, 3);
  SLL_addEnd(l, 9);
  SLL_get(l, 1, &out);
  SLL_traverse(l, &printElement);
}
