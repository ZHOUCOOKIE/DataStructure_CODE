//�����215 202110244532 �ܿ���
#include "SqStack.h"
#include <stdio.h>
void main()
{
	SqStack* S;
	ElemType e;
	printf("��ʼ��ջ\n");
	InitStack(S);
	printf("�ж�ջ�Ƿ�Ϊ�� %d\n", StackEmpty(S));
	printf("����ѹ����ĸA��B��C��D\n");
	Push(S, 'A');
	Push(S, 'B');
	Push(S, 'C');
	Push(S, 'D');
	printf("�ж�ջ�Ƿ�Ϊ�� %d���Ƿ�Ϊ�� %d\n", StackEmpty(S), StackFull(S));
	Push(S, 'E');
	Push(S, 'F');
	Push(S, 'G');
	printf("������ѹ����ĸE��F��G���ж�ջ�Ƿ�Ϊ�� %d\n", StackFull(S));
	GetStack(S, e);
	printf("ȡջ��Ԫ�أ�%c\n", e);
	printf("���ε���ջS������Ԫ�ز���ʾ:");
	for (; S->top > 0; )
	{
		Pop(S, e);
		printf("%c", e);
	}
	printf("\n�ͷ�˳��ջS");
	DestroyStack(S);
}

