#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void remove_duplicates(Node* head) {
    Node* current = head;
    while (current != NULL) {
        Node* runner = current;
        while (runner->next != NULL) {
            if (runner->next->data == current->data) {
                Node* temp = runner->next;
                runner->next = runner->next->next;
                free(temp);
            } else {
                runner = runner->next;
            }
        }
        current = current->next;
    }
}

Node* create_node(int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void print_list(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void free_list(Node* head) {
    while (head != NULL) {
        Node* temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    Node* head = create_node(1);
    head->next = create_node(2);
    head->next->next = create_node(2);
    head->next->next->next = create_node(3);

    print_list(head);
    remove_duplicates(head);
    print_list(head);

    free_list(head);
    return 0;
}