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

Node* insert(Node* head, int data) {
    Node* newNode = createNode(data);
    newNode->next = head;
    return newNode;
}

Node* sort(Node* head) {
    if (!head || !head->next) return head;
    Node* current = head;
    Node* index = NULL;
    int temp;
    while (current) {
        index = current->next;
        while (index) {
            if (current->data > index->data) {
                temp = current->data;
                current->data = index->data;
                index->data = temp;
            }
            index = index->next;
        }
        current = current->next;
    }
    return head;
}

void printList(Node* head) {
    Node* current = head;
    while (current) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    Node* list = NULL;
    list = insert(list, 3);
    list = insert(list, 1);
    list = insert(list, 4);
    list = insert(list, 2);
    list = sort(list);
    printList(list);
    return 0;
}