//�����215 202110244532 �ܿ���
#include "SqQueue.h"
#include <stdio.h>

int main()
{
	SqQueue* Q;
	ElemType e;
	printf("��ʼ��ѭ������Q\n");
	InitQueue(Q);
	printf("�ж϶���Q�Ƿ�Ϊ��:%d\n",QueueEmpty(Q));
	EnQueue(Q, 'A');
	EnQueue(Q, 'B');
	EnQueue(Q, 'C');
	EnQueue(Q, 'D');
	printf("���������ĸA��B��C��D\n");
	printf("�ж϶���Q�Ƿ�Ϊ��:%d���Ƿ�Ϊ��:%d\n", QueueEmpty(Q),QueueFull(Q));
	printf("�����������ĸE:%d��F:%d��G:%d\n", EnQueue(Q, 'G'), EnQueue(Q, 'F'), EnQueue(Q, 'E'));
	printf("�ж϶���Q�Ƿ�Ϊ��:%d\n", QueueFull(Q));
	GetHead(Q, e);
	printf("ȡ����Ԫ�ز����:%c\n",e);
	printf("���γ���Q������Ԫ�ز���ʾ:");
	while (QueueEmpty(Q) == 0)
	{
		DeQueue(Q, e);
		printf("%c��", e);
	}
	printf("\n�ͷŶ���Q\n");
	DestroyQueue(Q);
	return 0;
}