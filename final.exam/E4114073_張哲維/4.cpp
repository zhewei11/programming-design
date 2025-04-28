#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

typedef struct node NODE;

NODE* createList(int arr[], int len){
    NODE *first, *temp, *last;
    first = (NODE*)malloc(sizeof(NODE));
    first->data = arr[0];
    first->next = NULL;
    last = first;

    for (int i = 1; i < len; i++) {
        temp = (NODE*)malloc(sizeof(NODE));
        temp->data = arr[i];
        temp->next = NULL;
        last->next = temp;
        last = temp;
    }

    return first;
}

void printList(NODE* first){
    NODE* temp = first;

    while (temp != NULL) {
        printf("andress=%2p, data=%2d,next=%2p \n",temp,temp->data,temp->next);
        temp = temp->next;
    }
    printf("\n");
}

NODE* checkDuplicate(NODE* first){
    NODE *current = first, *duplicate = NULL, *temp;

    while (current != NULL && current->next != NULL) {
        temp = current;

        while (temp->next != NULL) {
            if (current->data == temp->next->data) {
                duplicate = temp->next;
                temp->next = temp->next->next;
                printf("Duplicate number is %d \n",duplicate);
            } else {
                temp = temp->next;
            }
        }

        current = current->next;
        if(duplicate==0){
        	printf("No duplicate number");
		}
    }

    return first;
}

NODE* deleteNode(NODE *first, NODE *node){
    if (first == NULL || node == NULL) {
        return first;
    }

    if (first == node) {
        first = node->next;
        free(node);
        return first;
    }

    NODE *current = first;
    while (current->next != NULL && current->next != node) {
        current = current->next;
    }

    if (current->next == NULL) {
        return first;
    }

    current->next = node->next;
    free(node);
    return first;
}

void freeList(NODE* first){
    NODE *current, *previous;
    current = first;

    while(current != NULL) {
        previous = current;
        current = current->next;
        free(previous);
    }
}

int main() {
    int arr[] = {1,1,3,4,5};
    int length = sizeof(arr) / sizeof(arr[0]);
    NODE *first = createList(arr, length);

    printf("Original List:\n ");
    printList(first);
    
	checkDuplicate(first);
    printList(first);

    // Delete a node (for example, the first node)
    first = deleteNode(first, first);
    printf("List after removing duplicates: \n");
    printList(first);

    freeList(first);
    system("pause");
    return 0;
}

