#include "LinkedList.h"

int main() {
    Node* L = NULL;

    // 마지막 삽입
    insertLastNode(&L, 10);
    insertLastNode(&L, 20);
    insertLastNode(&L, 30);

    printf("초기 리스트:\n");
    printList(L);

    // 중간 삽입 (20 뒤에 25 삽입)
    Node* pre = searchNode(L, 20);
    if (pre != NULL) {
        insertNode(&L, pre, 25);
    }

    printf("\n삽입 후:\n");
    printList(L);

    // 삭제 (20 다음 노드 삭제 → 25 삭제됨)
    deleteNode(pre);

    printf("\n삭제 후:\n");
    printList(L);

    // 탐색
    Node* result = searchNode(L, 30);
    if (result != NULL)
        printf("\n30 찾음!\n");
    else
        printf("\n30 없음\n");

    // 역순
    reverseList(&L);
    printf("\n역순 리스트:\n");
    printList(L);

    return 0;
}