//计算机215 202110244532 周俊安
#include "SqStack.h"
#include <stdio.h>

#pragma warning(disable : 4996)

void conversion(int N)
{
	ElemType e = 0, r = 2;
	SqStack* S;
	InitStack(S);
	while (N != 0)
	{
		Push(S, N % r);
		N /= r;
	}
	while (Pop(S, e))
	{
		printf("%d", e);
	}
	printf("\n");
	DestroyStack(S);
}

void main()
{
	ElemType N;
	printf("请输入十进制整数：");
	scanf("%d", &N);
	conversion(N);
}