#include <stdlib.h>
#include <stdio.h>
#include <string.h> 

struct employee {
    int num, score;
    char name[20]; // Increased name field length to 20 characters
    struct employee *next;
};

typedef struct employee node;
typedef node *link;

link findnode(link head, int num) {
    link ptr = head;
    while (ptr != NULL) {
        if (ptr->num == num)
            return ptr;
        ptr = ptr->next;
    }
    return ptr;
}

link insert(link head, link ptr, int num, int score, const char name[20]) {
    link insertnode = (link)malloc(sizeof(node));
    if (!insertnode)
        return NULL;
    insertnode->num = num;
    insertnode->score = score;
    strcpy(insertnode->name, name);
    insertnode->next = NULL;

    if (ptr == NULL) {
        insertnode->next = head;
        return insertnode;
    } else {
        if (ptr->next == NULL) {
            ptr->next = insertnode;
        } else {
            insertnode->next = ptr->next;
            ptr->next = insertnode;
        }
    }
    return head;
}

link deleteNode(link head, int num) {
    link prev = NULL;
    link current = head;

    // Check if the head node contains the employee to be deleted
    if (current != NULL && current->num == num) {
        head = current->next;
        free(current);
        return head;
    }

    // Search for the employee to be deleted
    while (current != NULL && current->num != num) {
        prev = current;
        current = current->next;
    }

    // If the employee is found, remove it from the linked list
    if (current != NULL) {
        prev->next = current->next;
        free(current);
    }

    return head;
}

void printEmployees(link head) {
    link ptr = head;
    printf("\n\t員工編號    姓名\t薪水\n");
    printf("--------------------------------------\n");
    while (ptr != NULL) {
        printf("\t[%2d]\t[ %-7s]\t[%3d]\n", ptr->num, ptr->name, ptr->score);
        ptr = ptr->next;
    }
}

int main() {
    link head, ptr, newnode;
    int new_num, new_score,b;
    char new_name[20];
    int i, j, position = 0, find;
    int data[12][2] = {
        {1001, 32367}, {1002, 24388}, {1003, 27556}, {1007, 31299},
        {1002, 42660}, {1014, 25676}, {1018, 44145}, {1043, 521822},
        {1031, 32769}, {1037, 21100}, {1041, 1046}, {1042,25576}
    };
    const char name[12][20] = {
        "A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L"
    };
    printf("員工編號 薪水 員工編號 薪水 員工編號 薪水 員工編號 薪水 \n");
    printf("-------------------------------------------------------------\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 4; j++)
            printf("[%4d] $%5d ", data[j * 3 + i][0], data[j * 3 + i][1]);
        printf("\n");
    }
    printf("-------------------------------------------------------------\n");

    head = (link)malloc(sizeof(node));
    if (!head) {
        printf("Error!\n");
        exit(1);
    }
    head->num = data[0][0];
    strcpy(head->name, name[0]);
    head->score = data[0][1];
    head->next = NULL;
    ptr = head;

    for (i = 1; i < 12; i++) {
        newnode = (link)malloc(sizeof(node));
        newnode->num = data[i][0];
        strcpy(newnode->name, name[i]);
        newnode->score = data[i][1];
        newnode->next = NULL;
        ptr->next = newnode;
        ptr = ptr->next;
    }

    while (1) {
    	printf("<1>加員工 <2>刪員工 <3>退出");
    	scanf("%d",&b);
        printf("\n");
        if(b==1){
		
        printf("輸入要插其後的員工代碼\n");
        printf("若不在其中新員工節點將放在首位\n");
        scanf("%d", &position);

        ptr = findnode(head, position);
        printf("新員工編號: ");
        scanf("%d", &new_num);
        printf("新員工薪水: ");
        scanf("%d", &new_score);
        printf("新員工姓名: ");
        scanf("%s", new_name);
        head = insert(head, ptr, new_num, new_score, new_name);
        
        printEmployees(head);
    }
		if(b==2){
		
		    int delete_num;
		    printf("\n");
		    printf("輸入要刪除的員工編號: ");
		    scanf("%d", &delete_num);
		    head = deleteNode(head, delete_num);
		    printEmployees(head);
		
		    // Free allocated memory for the linked list
		    while (head != NULL) {
		        ptr = head;
		        head = head->next;
		        free(ptr);
		    }
		}
		if(b==3) break;
	}

    system("pause");
    return 0;
}

