#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

// 双向链表节点定义
typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

// 创建新节点
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// 打印链表
void printList(Node* head) {
    Node* temp = head;
    printf("链表内容: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// 删除第一个值为 value 的节点
void deleteValue(Node** headPtr, int value) {
    Node* temp = *headPtr;
    while (temp != NULL)
    {
        if (temp->data == value) 
        {
            if (temp->prev)
            {
                temp->prev->next = temp->next;
            }
            else
            {
                *headPtr = temp->next; // 删除头结点
            }

            if (temp->next)
            {
                temp->next->prev = temp->prev;
            }

            free(temp);
            return;
        }
        temp = temp->next;
    }
}

// 在指定位置插入新节点（0 为头）
void insertAtPosition(Node** head, int pos, int value) {
    Node* newNode = createNode(value);
    if (pos == 0) {
        newNode->next = *head;
        if (*head)
            (*head)->prev = newNode;
        *head = newNode;
        return;
    }

    Node* temp = *head;
    for (int i = 0; temp != NULL && i < pos - 1; i++)
        temp = temp->next;

    if (temp == NULL) return;

    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next)
        temp->next->prev = newNode;
    temp->next = newNode;
}

// 在尾部插入节点
void insertAtEnd(Node** head, int value) {
    Node* newNode = createNode(value);
    if (*head == NULL) {
        *head = newNode;
        return;
    }

    Node* temp = *head;
    while (temp->next)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
}

int main() {
    Node* head = NULL;

    // 初始化链表 8,91,54,3,7
    insertAtEnd(&head, 8);
    insertAtEnd(&head, 91);
    insertAtEnd(&head, 54);
    insertAtEnd(&head, 3);
    insertAtEnd(&head, 7);

    printList(head);

    int delVal, pos, insertVal, tailVal;

    printf("请输入要删除的值: ");
    scanf("%d", &delVal);
    deleteValue(&head, delVal);
    printList(head);

    printf("请输入要插入的位置（从0开始）和插入的值: ");
    scanf("%d %d", &pos, &insertVal);
    insertAtPosition(&head, pos, insertVal);
    printList(head);

    printf("请输入要在末尾插入的值: ");
    scanf("%d", &tailVal);
    insertAtEnd(&head, tailVal);
    printList(head);

    return 0;
}
