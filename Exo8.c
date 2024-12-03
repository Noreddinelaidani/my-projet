#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

Node* merge(Node* L1, Node* L2) {
    if (!L1) return L2;
    if (!L2) return L1;

    Node* mergedHead = NULL;
    if (L1->data < L2->data) {
        mergedHead = L1;
        L1 = L1->next;
    } else {
        mergedHead = L2;
        L2 = L2->next;
    }

    Node* current = mergedHead;
    while (L1 && L2) {
        if (L1->data < L2->data) {
            current->next = L1;
            L1 = L1->next;
        } else {
            current->next = L2;
            L2 = L2->next;
        }
        current = current->next;
    }

    if (L1) current->next = L1;
    if (L2) current->next = L2;

    return mergedHead;
}

void printList(Node* head) {
    while (head) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    Node* L1 = createNode(1);
    L1->next = createNode(3);
    L1->next->next = createNode(5);

    Node* L2 = createNode(2);
    L2->next = createNode(4);
    L2->next->next = createNode(6);

    Node* mergedList = merge(L1, L2);
    printList(mergedList);

    return 0;
}