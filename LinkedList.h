#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>

// 노드 구조체
typedef struct Node {
    int data;
    struct Node* link;
} Node;

// 함수 선언
Node* getNode();
void insertNode(Node** L, Node* pre, int x);
void insertLastNode(Node** L, int x);
void deleteNode(Node* pre);
Node* searchNode(Node* L, int x);
void reverseList(Node** L);
void printList(Node* L);

#endif