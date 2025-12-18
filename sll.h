#define SLL_OK 1
#define SLL_ERR_NULL -1
#define SLL_ERR_NO_MEM -2
#define SLL_ERR_EMPTY -3
#define SLL_ERR_OUT_OF_BOUNDS -4

typedef struct List List;

/**
 * Create a singly linked list.
 */
List *SLL_createList();

/**
 * Insert the given data at the beginning of the given list.
 */
int SLL_addFront(List *l, int data);

/**
 * Insert the given data at the end of the given list.
 */
int SLL_addEnd(List *l, int data);

/**
 * Get the data at the given index from the given list.
 */
int SLL_get(List *l, int index, int *out);

/**
 * Get the length of the linked list.
 */
int SLL_getLength(List *l, int *out);

/**
 * For each node of the given list, execute the callback function, which
 * itself takes in an integer.
 */
int SLL_traverse(List *l, void (*callback)(int data));

/**
 * Remove the node at the beginning of the given list.
 */
int SLL_removeHead(List *l);

/**
 * Remove the node at the end of the given list.
 */
int SLL_removeEnd(List *l);
