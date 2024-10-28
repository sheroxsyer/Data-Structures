/**
 * Max-Heap for strings implemented with a max-heap binary tree
 * Insertion (enqueue) in O(log n)
 * Deletion (dequeue) in O(log n)
 */
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <iostream>

using namespace std;

#define PARENT(A) ((A - 1) / 2)
#define LEFT(A) (2 * A + 1)
#define RIGHT(A) (2 * A + 2)

typedef struct Element {
    int priority;
    char *word;
} Element;

// Abstract data type (not visible ouside this translation unit)
typedef struct Heap {
    int capacity;
    int count;
    Element *array;
} Heap;

const int initial_capacity = 4;

/**
 * Initialize the priority queue.
 * @param queue Uninitialized address of a pointer to a queue.
 */
void heap_init(Heap **h)
{
    *h = malloc(sizeof(Heap));
    assert(*h != NULL);
    (*h)->count = 0;
    (*h)->capacity = initial_capacity;
    (*h)->array = (Element *) malloc(sizeof(Element) * (*h)->capacity);
    assert((*h)->array != NULL);
}

static void swap(Element *a, Element *b)
{
    Element *swapped = a;
    *a = *b;
    *b = *swapped;
}

static void heapify(Element *el, int index, int count)
{
    int left = LEFT(index), right = RIGHT(index);
    int largest = index;

    if (left <= count && el[left].priority > el[largest].priority)
        largest = left;

    if (right <= count && el[right].priority > el[largest].priority)
        largest = right;

    if(largest != index) {
        swap(&el[index], &el[largest]);
        heapify(el, largest, count);
    }
}

/**
 * Insert a new element into the priority queue.
 * @param queue Initialized queue
 * @param str String to be inserted
 * @param priority String priority
 */
void heap_enqueue(Heap *h, char *str, int priority)
{
    // Resize the heap if too small
    if (h->count == h->capacity) {
        h->capacity += 1;
        h->array = realloc(h->array, sizeof(Element) * h->capacity);
        assert(h->array);
    }

    // Find out where to put the element and put it
    int index = h->count++;
    while(index && h->array[PARENT(index)].priority >= priority) {
        h->array[index] = h->array[PARENT(index)];
        index = PARENT(index);
    }

    // Store the new element at the right position
    char *word = malloc(strlen(str) + 1);
    assert(word != NULL);
    strcpy(word, str);
    h->array[index].word = word;
    h->array[index].priority = priority;
}

/**
 * Delete the highest priority element.
 * @param queue Initialized queue
 * @param str Destination for the string
 * @param size Size of the destination space
 * @return Priority of the removed element
 */
int heap_dequeue(Heap *h, char *word, size_t size)
{
    Element el = h->array[--h->count];
    #ifdef SHRINK // Resize the priority list to free space
    if (h->count <= h->size + 2 && h->size > initial_size) {
        h->size -= 1;
        h->array = realloc(h->array, sizeof(int) * h->size);
        assert(h->array);
    }
    #endif

    // Access the element
    int priority = h->array[0].priority;
    if(word != NULL)
        strncpy(word, h->array[0].word, size);
    free(h->array[0].word);

    // Reorder the heap
    h->array[0] = el;
    heapify(h->array, 0, h->count);

    return priority;
}

/**
 * Iterate through all the items in the queue in the order or priority.
 * @param queue Initialized queue
 * @param cb Function callback called for every element in the queue
 */
void heap_iterate(Heap *h, void (*cb)(char *word, int priority)) {
    for(int i=0; i<h->count; ++i) {
        cb(h->array[i].word, h->array[i].priority);
    }
}