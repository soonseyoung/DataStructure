#include <stdio.h>
#include "listS.h"

// 초기화
void initList(List* L) {
    L->size = 0;
}

// 삽입
void insertList(List* L, int pos, element item) {
    if (pos < 0 || pos > L->size || L->size >= MAX_SIZE) {
        printf("삽입 오류\n");
        return;
    }

    for (int i = L->size - 1; i >= pos; i--) {
        L->data[i + 1] = L->data[i];
    }

    L->data[pos] = item;
    L->size++;
}

// 삭제
void deleteList(List* L, int pos) {
    if (pos < 0 || pos >= L->size) {
        printf("삭제 오류\n");
        return;
    }

    for (int i = pos; i < L->size - 1; i++) {
        L->data[i] = L->data[i + 1];
    }

    L->size--;
}

// 출력
void printList(List* L) {
    for (int i = 0; i < L->size; i++) {
        printf("%d ", L->data[i]);
    }
    printf("\n");
}