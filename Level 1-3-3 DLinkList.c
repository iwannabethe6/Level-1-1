#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

// ˫������ڵ㶨��
typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

// �����½ڵ�
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// ��ӡ����
void printList(Node* head) {
    Node* temp = head;
    printf("��������: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// ɾ����һ��ֵΪ value �Ľڵ�
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
                *headPtr = temp->next; // ɾ��ͷ���
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

// ��ָ��λ�ò����½ڵ㣨0 Ϊͷ��
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

// ��β������ڵ�
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

    // ��ʼ������ 8,91,54,3,7
    insertAtEnd(&head, 8);
    insertAtEnd(&head, 91);
    insertAtEnd(&head, 54);
    insertAtEnd(&head, 3);
    insertAtEnd(&head, 7);

    printList(head);

    int delVal, pos, insertVal, tailVal;

    printf("������Ҫɾ����ֵ: ");
    scanf("%d", &delVal);
    deleteValue(&head, delVal);
    printList(head);

    printf("������Ҫ�����λ�ã���0��ʼ���Ͳ����ֵ: ");
    scanf("%d %d", &pos, &insertVal);
    insertAtPosition(&head, pos, insertVal);
    printList(head);

    printf("������Ҫ��ĩβ�����ֵ: ");
    scanf("%d", &tailVal);
    insertAtEnd(&head, tailVal);
    printList(head);

    return 0;
}
