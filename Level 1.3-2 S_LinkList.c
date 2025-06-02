#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

// 单链表节点结构体
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// 创建初始链表：节点值依次为 8, 91, 54, 3, 7
Node* createInitialList() {
    int initVals[] = { 8, 91, 54, 3, 7 };
    int n = 5;

    Node* head = NULL;
    Node* tail = NULL;
    for (int i = 0; i < n; i++) {
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->data = initVals[i];
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    return head;
}

// 打印链表内容
void printList(Node* head) {
    Node* cur = head;
    while (cur != NULL) {
        printf("%d ", cur->data);
        cur = cur->next;
    }
    printf("\n");
}

// 删除值为 delVal 的第一个节点
// 返回删除后的新头指针（如果删除的是头节点，head 会更新）
Node* deleteByValue(Node* head, int delVal) {
    Node* prev = NULL;
    Node* cur = head;

    while (cur != NULL) {
        if (cur->data == delVal) {
            // 找到要删除的节点
            if (prev == NULL) {
                // 删除头节点
                head = cur->next;
            }
            else {
                prev->next = cur->next;
            }
            free(cur);
            break;
        }
        prev = cur;
        cur = cur->next;
    }
    return head;
}

// 在链表的第 pos 位置（1-based）插入值 insVal
// 如果 pos == 1，就把新节点插到头部
// 返回插入后的头指针
Node* insertAtPosition(Node* head, int pos, int insVal) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = insVal;
    newNode->next = NULL;

    if (pos == 1) {
        newNode->next = head;
        return newNode;
    }

    Node* cur = head;
    // 找到第 (pos-1) 个节点（如果链表长度 < pos-1，则插到尾部）
    for (int i = 1; i < pos - 1 && cur != NULL; i++) {
        cur = cur->next;
    }

    if (cur == NULL) {
        // 链表长度不足，直接插到尾部
        // 先找尾部
        cur = head;
        while (cur->next != NULL) {
            cur = cur->next;
        }
        cur->next = newNode;
    }
    else {
        // 正常插入
        newNode->next = cur->next;
        cur->next = newNode;
    }

    return head;
}

int main() {
    // 1. 创建初始链表
    Node* head = createInitialList();

    // 2. 打印初始链表
    printf("初始链表内容：\n");
    printList(head);

    // 3. 读入要删除的值、插入的位置和插入值
    int delVal, insPos, insVal;
    printf("请输入要删除的元素值、插入的位置（从1开始）、插入的元素值：\n");
    scanf("%d %d %d", &delVal, &insPos, &insVal);

    // 4. 删除 delVal
    head = deleteByValue(head, delVal);

    // 5. 在第 insPos 位置插入 insVal
    head = insertAtPosition(head, insPos, insVal);

    // 6. 打印操作后链表内容
    printf("操作后链表内容：\n");
    printList(head);

    return 0;
}
