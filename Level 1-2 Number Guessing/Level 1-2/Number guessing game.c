#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main()
{
	//随机生成1-100的一个正整数
	int i,t,sum = 0;
	srand((unsigned int)time(NULL));
	t = rand() % 100 + 1;
	//循环输入一个1-100的数字，如果不在范围内提示重新输入
	
		printf("请输入1 - 100内的正整数喵\n");

	do
	{	
		//创建局部变量result存储用户输入值，应对用户输入的作弊字符
		int result = scanf("%d", &i);

		if (result != 1)
		{
			//清空输入缓存区
			while (getchar() != '\n');
			printf("请重新输入合法数字喵(不要输字母!)\n");
			continue;
		}

		if (!(i>=1 && i<=100))
		{
			printf("请重新输入合法数字喵\n");
			continue;
		}

		sum ++;

		if (i < t)
		{
			printf("猜小了\n");
		}
		else if (i > t)
		{
			printf("猜大了\n");
		}
		else
		{	
			printf("猜中啦\n");
			printf("你一共猜了%d次，恭喜！\n", sum);
		}

	} while (i != t);

	return 0;
}