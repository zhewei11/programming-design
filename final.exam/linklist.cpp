#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// �w??��??��?��
struct Node {
    int data;
    struct Node* next;
};

// �b?���j����������?
struct Node* search(struct Node* head, int key) {
    struct Node* current = head;
    while (current != NULL) {
        if (current->data == key) {
            return current; // ���F����
        }
        current = current->next;
    }
    return NULL; // ����줸��
}

// �V?���K�[�s��������?
struct Node* insert(struct Node* head, int data) {
    // ?�ؤ@?�s??
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    // �p�G?��?�šA??�s???????
    if (head == NULL) {
        head = newNode;
    } else {
        // �M?��̦Z�@???�}?�s??�l�[���Z��
        struct Node* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
    return head;
}

// ??��?����������?
struct Node* deleteNode(struct Node* head, int key) {
    struct Node* current = head;
    struct Node* prev = NULL;

    // �p�G�n?���������O???
    if (current != NULL && current->data == key) {
        head = current->next;
        free(current);
        return head;
    }

    // �b�ѧE��?���j���n?��������
    while (current != NULL && current->data != key) {
        prev = current;
        current = current->next;
    }

    // �p�G���F�n?���������A??��??
    if (current != NULL) {
        prev->next = current->next;
        free(current);
    }
	else printf("error\n"); 
    return head;
}

// ?��?����?
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

    // �V?�����J����
    head = insert(head, 10);
    head = insert(head, 20);
    head = insert(head, 30);
    head = insert(head, 40);

    // ?��?��?�e
    printf("�ت��e�G");
    display(head);

    // �b?���j������
    int key;
    printf("��M�çR������:");
    scanf("%d",&key);
    struct Node* searchResult = search(head, key);
    if (searchResult != NULL) {
        printf("�b�ت���줸�� %d�C\n", key);
    } else {
        printf("�b�ت�����줸�� %d�C\n", key);
    }

    // ??��?������
    int deleteKey = key;
    head = deleteNode(head, deleteKey);

    // ?�ܧ�s�Z��?��?�e
    printf("�R�������Z���ت��e�G");
    display(head);

    return 0;
}

