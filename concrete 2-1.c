#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

//�궨������
#define MAX_SIZE 100 //�������Ա���󳤶�
#define OK 
#define ERROR 0

//���Ͷ���
typedef ElemType;
typedef status; 

// ˳���ṹ��
typedef struct {
    ElemType data[MAX_SIZE];//����洢Ԫ��
    int length;//��ǰ����
} SqList;

// �Ƚ�����Ԫ���Ƿ����
Status equal(ElemType a, ElemType b) {
    return a == b;
}

// ��ȡ˳���ĳ���
int ListLength(SqList L) {
    return L.length;
}

// ��ȡL�е�i��Ԫ�أ�1��ʼ����ֵ��e
void GetElem(SqList L, int i, ElemType* e) {
    if (i < 1 || i > L.length) return;
    *e = L.data[i - 1];
}

// ���ҵ�һ����e����cmp��ϵ��Ԫ��λ�ã�1��ʼ���������ڷ���0
int LocateElem(SqList L, ElemType e, Status(*cmp)(ElemType, ElemType)) {
    for (int i = 0; i < L.length; i++) {
        if (cmp(L.data[i], e)) {
            return i + 1;
        }
    }
    return 0;
}

// ��L�е�posλ�ò���Ԫ��e��1��ʼ�����ɹ�����OK
Status ListInsert(SqList* L, int pos, ElemType e) {
    if (pos < 1 || pos > L->length + 1 || L->length >= MAXSIZE)
        return ERROR;

// �������Ԫ������ƶ�
    for (int i = L->length - 1; i >= pos - 1; i--) {
        L->data[i + 1] = L->data[i];
    }

    L->data[pos - 1] = e;
    L->length++;
    return OK;
}

// ����A = A �� B����Lb�в���La�е�Ԫ�ز���Laĩβ
void Union(SqList* La, SqList Lb) {
    int La_len = ListLength(*La);
    int Lb_len = ListLength(Lb);
    ElemType e;

    for (int i = 1; i <= Lb_len; i++) {
        GetElem(Lb, i, &e);
        if (!LocateElem(*La, e, equal)) {
            ListInsert(La, ++La_len, e); // ����ĩβ
        }
    }
}

// ��ӡ���Ա�
void PrintList(SqList L) {
    for (int i = 0; i < L.length; i++) {
        printf("%d ", L.data[i]);
    }
    printf("\n");
}

// ����������
int main() {
    SqList La = { {1, 2, 3}, 3 };     // ����A
    SqList Lb = { {3, 4, 5}, 3 };     // ����B

    printf("Laԭʼ��");
    PrintList(La);

    printf("Lbԭʼ��");
    PrintList(Lb);

    Union(&La, Lb);  // A = A �� B

    printf("�ϲ���La��");
    PrintList(La);

    return 0;
}
