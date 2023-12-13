#ifndef SEARCH_ALGOS_H
#define SEARCH_ALGOS_H

#include <stdio.h>
#include <stdlib.h>

/* Linear Search */
int linear_search(int *array, size_t size, int value);

/* Binary Search */
int binary_search(int *array, size_t size, int value);

/* Jump Search */
int jump_search(int *array, size_t size, int value);

/* Interpolation Search */
int interpolation_search(int *array, size_t size, int value);

/* Exponential Search */
int exponential_search(int *array, size_t size, int value);

/* Advanced Binary Search */
int advanced_binary(int *array, size_t size, int value);

/* Jump Search in Linked List */
typedef struct skiplist_s
{
    int n;
    size_t index;
    struct skiplist_s *next;
    struct skiplist_s *express;
} skiplist_t;

skiplist_t *linear_skip(skiplist_t *list, int value);
skiplist_t *jump_search_linked_list(skiplist_t *head, int value);
skiplist_t *create_skiplist(int *array, size_t size);
void print_skiplist(const skiplist_t *list);
void free_skiplist(skiplist_t *list);

#endif /* SEARCH_ALGOS_H */
