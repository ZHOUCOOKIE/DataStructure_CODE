//计算机215 202110244532 周俊安
#include "SqStack.h"
#include <stdio.h>
void main()
{
	SqStack* S;
	ElemType e;
	printf("初始化栈\n");
	InitStack(S);
	printf("判断栈是否为空 %d\n", StackEmpty(S));
	printf("依次压入字母A、B、C、D\n");
	Push(S, 'A');
	Push(S, 'B');
	Push(S, 'C');
	Push(S, 'D');
	printf("判断栈是否为空 %d，是否为满 %d\n", StackEmpty(S), StackFull(S));
	Push(S, 'E');
	Push(S, 'F');
	Push(S, 'G');
	printf("再依次压入字母E、F、G并判断栈是否为满 %d\n", StackFull(S));
	GetStack(S, e);
	printf("取栈顶元素：%c\n", e);
	printf("依次弹出栈S的所有元素并显示:");
	for (; S->top > 0; )
	{
		Pop(S, e);
		printf("%c", e);
	}
	printf("\n释放顺序栈S");
	DestroyStack(S);
}

