#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

void MergeList(List La, List Lb, List& Lc) {
	//一致线性表La和Lb 中的数据元素按值非递减排列
	//归并La和Lb得到新的线性表Lc,Lc的数据元素也按值非递减排列
	InitList(Lc);
	int i = 1; int j = 1; int k = 0;
	int La_len = ListLength(La); 
	int Lb_len = ListLength(Lb);
	while ((i <= La_len && j <= Lb_len)
	{
		GetElem(La, i, &ai);
		GetElem(Lb, j, &bj);

		if (ai <= bj) {
			ListInsert(Lc, ++k, ai);
			++i;
		}
		else {
			ListInsert(Lc, ++k, bj);
			++j;
		}
	}

	while (i <= La_len) {
		GetElem(La, i++, &ai); 
		ListInsert(Lc, ++k, ai);
	}

	while (j <= Lb_len) {
		GetElem(La, j++, &bj);
		ListInsert(Lc, ++k, bj);
	}

}