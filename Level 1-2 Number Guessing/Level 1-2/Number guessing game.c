#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main()
{
	//�������1-100��һ��������
	int i,t,sum = 0;
	srand((unsigned int)time(NULL));
	t = rand() % 100 + 1;
	//ѭ������һ��1-100�����֣�������ڷ�Χ����ʾ��������
	
		printf("������1 - 100�ڵ���������\n");

	do
	{	
		//�����ֲ�����result�洢�û�����ֵ��Ӧ���û�����������ַ�
		int result = scanf("%d", &i);

		if (result != 1)
		{
			//������뻺����
			while (getchar() != '\n');
			printf("����������Ϸ�������(��Ҫ����ĸ!)\n");
			continue;
		}

		if (!(i>=1 && i<=100))
		{
			printf("����������Ϸ�������\n");
			continue;
		}

		sum ++;

		if (i < t)
		{
			printf("��С��\n");
		}
		else if (i > t)
		{
			printf("�´���\n");
		}
		else
		{	
			printf("������\n");
			printf("��һ������%d�Σ���ϲ��\n", sum);
		}

	} while (i != t);

	return 0;
}