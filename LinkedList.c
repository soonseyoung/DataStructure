#include "LinkedList.h"

// 노드 생성
Node* getNode() {
    Node* newNode = (Node*)malloc(sizeof(Node));
    return newNode;
}

// 중간 삽입 (pre 뒤에 삽입)
void insertNode(Node** L, Node* pre, int x) {
    Node* newNode = getNode();
    newNode->data = x;

    if (*L == NULL) { // 공백 리스트
        newNode->link = NULL;
        *L = newNode;
    } else {
        newNode->link = pre->link;
        pre->link = newNode;
    }
}

// 마지막 삽입
void insertLastNode(Node** L, int x) {
    Node* newNode = getNode();
    newNode->data = x;
    newNode->link = NULL;

    if (*L == NULL) {
        *L = newNode;
    } else {
        Node* temp = *L;
        while (temp->link != NULL) {
            temp = temp->link;
        }
        temp->link = newNode;
    }
}

// 삭제 (pre 다음 노드 삭제)
void deleteNode(Node* pre) {
    if (pre == NULL || pre->link == NULL) return;

    Node* old = pre->link;
    pre->link = old->link;
    free(old);
}

// 탐색
Node* searchNode(Node* L, int x) {
    Node* temp = L;

    while (temp != NULL) {
        if (temp->data == x)
            return temp;
        temp = temp->link;
    }
    return NULL;
}

// 리스트 역순
void reverseList(Node** L) {
    Node* prev = NULL;
    Node* current = *L;
    Node* next = NULL;

    while (current != NULL) {
        next = current->link;
        current->link = prev;
        prev = current;
        current = next;
    }
    *L = prev;
}

// 출력
void printList(Node* L) {
    Node* temp = L;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->link;
    }
    printf("NULL\n");
}