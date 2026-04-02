#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "DoubleLinkedList.h"

// 공백 이중 연결 리스트를 생성하는 연산
linkedList_h* createLinkedList_h(void) {
    linkedList_h* DL;
    DL = (linkedList_h*)malloc(sizeof(linkedList_h));
    DL->head = NULL;
    return DL;
}

// 이중 연결 리스트를 순서대로 출력하는 연산
void printList(linkedList_h* DL) {
    listNode* p;
    printf(" DL = (");
    p = DL->head;
    while (p != NULL) {
        printf("%s", p->data);
        p = p->rlink;
        if (p != NULL) printf(", ");
    }
    printf(") \n");
}

// pre 노드 뒤에 새 노드를 삽입하는 연산
void insertNode(linkedList_h* DL, listNode* pre, char* x) {
    listNode* newNode;
    newNode = (listNode*)malloc(sizeof(listNode));
    strcpy(newNode->data, x);

    if (DL->head == NULL) { // 공백 리스트인 경우
        newNode->rlink = NULL;
        newNode->llink = NULL;
        DL->head = newNode;
    }
    else {
        newNode->rlink = pre->rlink;
        pre->rlink = newNode;
        newNode->llink = pre;
        if (newNode->rlink != NULL) { // 삽입 자리에 다음 노드가 있는 경우
            newNode->rlink->llink = newNode;
        }
    }
}

// 이중 연결 리스트에서 old 노드를 삭제하는 연산
void deleteNode(linkedList_h* DL, listNode* old) {
    if (DL->head == NULL || old == NULL) return; // 공백이거나 삭제할 노드가 없는 경우

    if (old->llink != NULL) { // 삭제 노드에 이전 노드가 있는 경우
        old->llink->rlink = old->rlink;
    } else { // 삭제 노드가 첫 번째 노드인 경우
        DL->head = old->rlink;
    }

    if (old->rlink != NULL) { // 삭제 노드에 다음 노드가 있는 경우
        old->rlink->llink = old->llink;
    }

    free(old);
}

// 리스트에서 데이터를 탐색하는 연산
listNode* searchNode(linkedList_h* DL, char* x) {
    listNode* temp = DL->head;
    while (temp != NULL) {
        if (strcmp(temp->data, x) == 0) return temp;
        else temp = temp->rlink;
    }
    return temp;
}