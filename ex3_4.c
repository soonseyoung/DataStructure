#include <stdio.h>
#include "listS.h"

int main() {
    List L;
    initList(&L);

    insertList(&L, 0, 10);
    insertList(&L, 1, 20);
    insertList(&L, 1, 15);

    printList(&L);  // 10 15 20

    deleteList(&L, 1);
    printList(&L);  // 10 20

    return 0;
}