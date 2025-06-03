#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

void MergeList(List La, List Lb, List& Lc) {
	//һ�����Ա�La��Lb �е�����Ԫ�ذ�ֵ�ǵݼ�����
	//�鲢La��Lb�õ��µ����Ա�Lc,Lc������Ԫ��Ҳ��ֵ�ǵݼ�����
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