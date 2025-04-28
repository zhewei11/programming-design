#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

typedef struct node NODE;

void displayLinkedList(NODE* head) {
    NODE* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void deleteNode(NODE** head, int value) {
    NODE* current = *head;
    NODE* prev = NULL;

    // If the node to be deleted is the head node
    if (current != NULL && current->data == value) {
        *head = current->next;
        free(current);
        return;
    }

    // Find the node to be deleted
    while (current != NULL && current->data != value) {
        prev = current;
        current = current->next;
    }

    // If the node is found
    if (current != NULL) {
        prev->next = current->next;
        free(current);
    }
}

int main() {
    NODE* pa, * pb, * pc, * pd, * ptr;
    pa = (NODE*)malloc(sizeof(NODE));
    pb = (NODE*)malloc(sizeof(NODE));
    pc = (NODE*)malloc(sizeof(NODE));
    pd = (NODE*)malloc(sizeof(NODE));

    pa->data = 12;
    pa->next = pb;
    pb->data = 38;
    pb->next = pc;
    pc->data = 64;
    pc->next = pd;
    pd->data = 37;
    pd->next = NULL;

    printf("Original Linked List: ");
    displayLinkedList(pa);

    // Delete node 38
    deleteNode(&pa, 38);

    printf("Linked List after deletion: ");
    displayLinkedList(pa);

    // Delete node 64
    deleteNode(&pa, 64);

    printf("Linked List after second deletion: ");
    displayLinkedList(pa);

    return 0;
}

