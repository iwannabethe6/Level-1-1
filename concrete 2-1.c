#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

//宏定义区域
#define MAX_SIZE 100 //定义线性表最大长度
#define OK 
#define ERROR 0

//类型定义
typedef ElemType;
typedef status; 

// 顺序表结构体
typedef struct {
    ElemType data[MAX_SIZE];//数组存储元素
    int length;//当前长度
} SqList;

// 比较两个元素是否相等
Status equal(ElemType a, ElemType b) {
    return a == b;
}

// 获取顺序表的长度
int ListLength(SqList L) {
    return L.length;
}

// 获取L中第i个元素（1开始）赋值给e
void GetElem(SqList L, int i, ElemType* e) {
    if (i < 1 || i > L.length) return;
    *e = L.data[i - 1];
}

// 查找第一个与e满足cmp关系的元素位置（1开始），不存在返回0
int LocateElem(SqList L, ElemType e, Status(*cmp)(ElemType, ElemType)) {
    for (int i = 0; i < L.length; i++) {
        if (cmp(L.data[i], e)) {
            return i + 1;
        }
    }
    return 0;
}

// 在L中第pos位置插入元素e（1开始），成功返回OK
Status ListInsert(SqList* L, int pos, ElemType e) {
    if (pos < 1 || pos > L->length + 1 || L->length >= MAXSIZE)
        return ERROR;

// 将后面的元素向后移动
    for (int i = L->length - 1; i >= pos - 1; i--) {
        L->data[i + 1] = L->data[i];
    }

    L->data[pos - 1] = e;
    L->length++;
    return OK;
}

// 集合A = A ∪ B，将Lb中不在La中的元素插入La末尾
void Union(SqList* La, SqList Lb) {
    int La_len = ListLength(*La);
    int Lb_len = ListLength(Lb);
    ElemType e;

    for (int i = 1; i <= Lb_len; i++) {
        GetElem(Lb, i, &e);
        if (!LocateElem(*La, e, equal)) {
            ListInsert(La, ++La_len, e); // 插入末尾
        }
    }
}

// 打印线性表
void PrintList(SqList L) {
    for (int i = 0; i < L.length; i++) {
        printf("%d ", L.data[i]);
    }
    printf("\n");
}

// 主函数测试
int main() {
    SqList La = { {1, 2, 3}, 3 };     // 集合A
    SqList Lb = { {3, 4, 5}, 3 };     // 集合B

    printf("La原始：");
    PrintList(La);

    printf("Lb原始：");
    PrintList(Lb);

    Union(&La, Lb);  // A = A ∪ B

    printf("合并后La：");
    PrintList(La);

    return 0;
}
