#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

// ������ڵ�ṹ��
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// ������ʼ�����ڵ�ֵ����Ϊ 8, 91, 54, 3, 7
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

// ��ӡ��������
void printList(Node* head) {
    Node* cur = head;
    while (cur != NULL) {
        printf("%d ", cur->data);
        cur = cur->next;
    }
    printf("\n");
}

// ɾ��ֵΪ delVal �ĵ�һ���ڵ�
// ����ɾ�������ͷָ�루���ɾ������ͷ�ڵ㣬head ����£�
Node* deleteByValue(Node* head, int delVal) {
    Node* prev = NULL;
    Node* cur = head;

    while (cur != NULL) {
        if (cur->data == delVal) {
            // �ҵ�Ҫɾ���Ľڵ�
            if (prev == NULL) {
                // ɾ��ͷ�ڵ�
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

// ������ĵ� pos λ�ã�1-based������ֵ insVal
// ��� pos == 1���Ͱ��½ڵ�嵽ͷ��
// ���ز�����ͷָ��
Node* insertAtPosition(Node* head, int pos, int insVal) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = insVal;
    newNode->next = NULL;

    if (pos == 1) {
        newNode->next = head;
        return newNode;
    }

    Node* cur = head;
    // �ҵ��� (pos-1) ���ڵ㣨��������� < pos-1����嵽β����
    for (int i = 1; i < pos - 1 && cur != NULL; i++) {
        cur = cur->next;
    }

    if (cur == NULL) {
        // �����Ȳ��㣬ֱ�Ӳ嵽β��
        // ����β��
        cur = head;
        while (cur->next != NULL) {
            cur = cur->next;
        }
        cur->next = newNode;
    }
    else {
        // ��������
        newNode->next = cur->next;
        cur->next = newNode;
    }

    return head;
}

int main() {
    // 1. ������ʼ����
    Node* head = createInitialList();

    // 2. ��ӡ��ʼ����
    printf("��ʼ�������ݣ�\n");
    printList(head);

    // 3. ����Ҫɾ����ֵ�������λ�úͲ���ֵ
    int delVal, insPos, insVal;
    printf("������Ҫɾ����Ԫ��ֵ�������λ�ã���1��ʼ���������Ԫ��ֵ��\n");
    scanf("%d %d %d", &delVal, &insPos, &insVal);

    // 4. ɾ�� delVal
    head = deleteByValue(head, delVal);

    // 5. �ڵ� insPos λ�ò��� insVal
    head = insertAtPosition(head, insPos, insVal);

    // 6. ��ӡ��������������
    printf("�������������ݣ�\n");
    printList(head);

    return 0;
}
