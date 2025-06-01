#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

//A.定义数组最大长度提高容错
#define MAX_SIZE 100

//B.两大主要操作，删除，插入
//	三个输入变量，delVal删除值，insPos插入位置，insVal插入值

//	步骤有3:
//	1.删除指定值，并令数组长度-1
//	2.指定插入位置，数组下标为插入位置-1
//	3.插入指定值，自动数组长度+1（前面给了最大尺寸MAX_SIZE的容错）

int main()
{	
	//一、定义
	//定义基本变量，i为数组下标,arr1[MAX_SIZE]为数组，length为数组长度（有效长度）
	//delVal, insPos, insVal 分别为删除值，插入位置，插入值
	int i;
	int arr1[MAX_SIZE] = { 8, 91, 54, 3, 7 };
	int length = 5;

	int delVal, insPos, insVal;
	
	//二、操作
	//按顺序打印当前数组中的五个数字
	for (i = 0; i < length; i++)
	{
		printf("%d ",arr1[i]);
	}
	//提示输入要删除的元素值，插入的位置，插入的值
	printf("请输入要删除的元素值、插入的位置（从1开始）、插入的值：\n");
	scanf("%d %d %d", &delVal, &insPos, &insVal);

	//2.1删除元素
	//看看数组里有没有要删除的值，有则found返回1，无则0
	int found = 0;
	for (i = 0; i < length; i++)
	{
		if (arr1[i] == delVal)
		{
			found = 1;
			break;
		}
	}
		//如果found = 1 就删除，数组最大下标为 length-1
		if (found)
		{
			for (int j = i; j < length - 1; j++)
			{
				arr1[j] = arr1[j + 1];
			}
			length--;
		}
	//2.2插入元素(插入到第 insPos 个位置，数组下标为 insPos-1)
	for (int j = length; j > insPos-1; j--)
	{
		arr1[j] = arr1[j - 1];
	}
	arr1[insPos - 1] = insVal;
	length++;

	//三、回归
	printf("操作后顺序表内容为:\n");
		for (i = 0; i < length; i++)
		{
			printf("%d ", arr1[i]);
		}
		printf("\n");

	return 0;
}