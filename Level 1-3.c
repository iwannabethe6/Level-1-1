#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

//A.����������󳤶�����ݴ�
#define MAX_SIZE 100

//B.������Ҫ������ɾ��������
//	�������������delValɾ��ֵ��insPos����λ�ã�insVal����ֵ

//	������3:
//	1.ɾ��ָ��ֵ���������鳤��-1
//	2.ָ������λ�ã������±�Ϊ����λ��-1
//	3.����ָ��ֵ���Զ����鳤��+1��ǰ��������ߴ�MAX_SIZE���ݴ�

int main()
{	
	//һ������
	//�������������iΪ�����±�,arr1[MAX_SIZE]Ϊ���飬lengthΪ���鳤�ȣ���Ч���ȣ�
	//delVal, insPos, insVal �ֱ�Ϊɾ��ֵ������λ�ã�����ֵ
	int i;
	int arr1[MAX_SIZE] = { 8, 91, 54, 3, 7 };
	int length = 5;

	int delVal, insPos, insVal;
	
	//��������
	//��˳���ӡ��ǰ�����е��������
	for (i = 0; i < length; i++)
	{
		printf("%d ",arr1[i]);
	}
	//��ʾ����Ҫɾ����Ԫ��ֵ�������λ�ã������ֵ
	printf("������Ҫɾ����Ԫ��ֵ�������λ�ã���1��ʼ���������ֵ��\n");
	scanf("%d %d %d", &delVal, &insPos, &insVal);

	//2.1ɾ��Ԫ��
	//������������û��Ҫɾ����ֵ������found����1������0
	int found = 0;
	for (i = 0; i < length; i++)
	{
		if (arr1[i] == delVal)
		{
			found = 1;
			break;
		}
	}
		//���found = 1 ��ɾ������������±�Ϊ length-1
		if (found)
		{
			for (int j = i; j < length - 1; j++)
			{
				arr1[j] = arr1[j + 1];
			}
			length--;
		}
	//2.2����Ԫ��(���뵽�� insPos ��λ�ã������±�Ϊ insPos-1)
	for (int j = length; j > insPos-1; j--)
	{
		arr1[j] = arr1[j - 1];
	}
	arr1[insPos - 1] = insVal;
	length++;

	//�����ع�
	printf("������˳�������Ϊ:\n");
		for (i = 0; i < length; i++)
		{
			printf("%d ", arr1[i]);
		}
		printf("\n");

	return 0;
}