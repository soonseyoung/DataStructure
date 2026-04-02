#ifndef LISTS_H
#define LISTS_H

#define MAX_SIZE 100

typedef int element;

typedef struct {
    element data[MAX_SIZE];
    int size;
} List;

void initList(List* L);
void insertList(List* L, int pos, element item);
void deleteList(List* L, int pos);
void printList(List* L);

#endif