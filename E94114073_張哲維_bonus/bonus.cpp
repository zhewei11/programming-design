#include <stdio.h>
#include <stdlib.h>
//data structure 
struct Node {
    int data;
    struct Node* next;
};
//establish the node and put element into the node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

	newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// combine two lists
void combineList(struct Node** list1, struct Node** list2) {
    if (*list1 == NULL) *list1 = *list2;
    
// establish a storage to temporarily put the node of list    
	else {
        struct Node* temp = *list1;
        
		while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = *list2;
    }
}

// insert element into the first node 
void insertFirstNode(struct Node** head, int data) 
{
// create the new node using 'createNode' function
    struct Node* newNode = createNode(data);  
    newNode->next = *head; // the next one of new node is the head of list 
    *head = newNode; 
}

// determine the length of list
int listLength(struct Node* head) {
    int length = 0;
// establish a storage to temporarily put the node of list     
    struct Node* temp = head; 
 
    while (temp != NULL) {
        length++; 
        temp = temp->next; // go to next node
    }
    return length;
}

// reverse the list 
void reverseList(struct Node** head) {
// create thre  storages to temporarily put nodes
    struct Node* pre = NULL;
    struct Node* cur = *head;
    struct Node* nextNode = NULL;

    while (cur != NULL) {
        nextNode = cur->next; // change directiom
        cur->next = pre; 
        pre = cur;            // move back
        cur = nextNode;
    }
    *head = pre;              //renew the head
}


void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    
    int arr1[] = {12, 43, 56, 34, 98};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    struct Node* list1 = NULL;
    for (int i = n1 - 1; i >= 0; i--) insertFirstNode(&list1, arr1[i]);

    int arr2[] = {36, 77, 99};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    struct Node* list2 = NULL;
    for (int i = n2 - 1; i >= 0; i--) insertFirstNode(&list2, arr2[i]);
    

    printf("List 1: ");
    printList(list1);
    printf("List 2: ");
    printList(list2);

    combineList(&list1, &list2);
    printf("Combined List: ");
    printList(list1);

    
    int numNodes, data;
    printf("Enter the number of nodes to insert: ");
    scanf("%d", &numNodes);
    for (int i = 0; i < numNodes; i++) 
	{
        printf("Enter the data for node %d: ", i + 1);
        scanf("%d", &data);
        insertFirstNode(&list1, data);
        printf("Updated List: ");
        printList(list1);
    }
    
    int length = listLength(list1);
    printf("Length of the list: %d\n", length);

    
    reverseList(&list1);
    printf("Reversed List: ");
    printList(list1);

    return 0;
}

