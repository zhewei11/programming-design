#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// 定??表中??的?构
struct Node {
    int data;
    struct Node* next;
};

// 在?表中搜索元素的函?
struct Node* search(struct Node* head, int key) {
    struct Node* current = head;
    while (current != NULL) {
        if (current->data == key) {
            return current; // 找到了元素
        }
        current = current->next;
    }
    return NULL; // 未找到元素
}

// 向?表中添加新元素的函?
struct Node* insert(struct Node* head, int data) {
    // ?建一?新??
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    // 如果?表?空，??新???????
    if (head == NULL) {
        head = newNode;
    } else {
        // 遍?到最后一???并?新??追加到其后面
        struct Node* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
    return head;
}

// ??表中?除元素的函?
struct Node* deleteNode(struct Node* head, int key) {
    struct Node* current = head;
    struct Node* prev = NULL;

    // 如果要?除的元素是???
    if (current != NULL && current->data == key) {
        head = current->next;
        free(current);
        return head;
    }

    // 在剩余的?表中搜索要?除的元素
    while (current != NULL && current->data != key) {
        prev = current;
        current = current->next;
    }

    // 如果找到了要?除的元素，??除??
    if (current != NULL) {
        prev->next = current->next;
        free(current);
    }
	else printf("error\n"); 
    return head;
}

// ?示?表的函?
void display(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;

    // 向?表中插入元素
    head = insert(head, 10);
    head = insert(head, 20);
    head = insert(head, 30);
    head = insert(head, 40);

    // ?示?表?容
    printf("建表內容：");
    display(head);

    // 在?表中搜索元素
    int key;
    printf("找尋並刪除元素:");
    scanf("%d",&key);
    struct Node* searchResult = search(head, key);
    if (searchResult != NULL) {
        printf("在建表中找到元素 %d。\n", key);
    } else {
        printf("在建表中未找到元素 %d。\n", key);
    }

    // ??表中?除元素
    int deleteKey = key;
    head = deleteNode(head, deleteKey);

    // ?示更新后的?表?容
    printf("刪除元素后的建表內容：");
    display(head);

    return 0;
}

