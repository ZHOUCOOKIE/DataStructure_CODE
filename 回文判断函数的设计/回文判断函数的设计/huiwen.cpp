//计算机215 202110244532 周俊安
#include "SqQueue.h"
#include "SqStack.h"
#include <stdio.h>

bool Palindrome(SqStack*& S, SqQueue*& Q, ElemType e[])
{
	ElemType a1 = 1, a2 = 1;
	int i = 0, judge = 0;
	while (e[i] != '\n')//将字符数组中的元素逐个存入栈和队列
	{
		Push(S, e[i]);
		EnQueue(Q, e[i]);
		i++;
	}

	while (a1 == a2)//由于栈是后进先出，队列是先进先出，回文数是对称的，所以只要出栈元素和出队元素恒等即满足回文数要求，下面说明跳出循环条件
	{
		judge++;
		Pop(S, a1);
		DeQueue(Q, a2);
		if (judge - 1 == 0.5 * i || judge - 1 == int(0.5 * i))//当输入偶数个元素时，比较到数组长度一半即可证明是回文数；当输入奇数个元素时，比较到数组长度减一的一半即可证明是回文数
		{
			return true;
		}
	}
	return false;
}

int main()
{
	SqQueue* Q;
	SqStack* S;
	ElemType e[50], a1 = 1, a2 = 1;
	int i = 0, judge = 0;
	InitQueue(Q);//初始化
	InitStack(S);
	printf("请输入一个整形数字或者一串字母：");
	while ((e[i++] = getchar()) != '\n');//将输入的数字或者一串字母拆开，将单个字符从前往后存入字符数组e中
	printf("这个数字或者一串字母是否为回文数：%d", Palindrome(S, Q, e));
	DestroyQueue(Q);
	DestroyStack(S);
	return 0;
}