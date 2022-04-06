//计算机215 202110244532 周俊安
#include "SqQueue.h"
#include <stdio.h>

int main()
{
	SqQueue* Q;
	ElemType e;
	printf("初始化循环队列Q\n");
	InitQueue(Q);
	printf("判断队列Q是否为空:%d\n",QueueEmpty(Q));
	EnQueue(Q, 'A');
	EnQueue(Q, 'B');
	EnQueue(Q, 'C');
	EnQueue(Q, 'D');
	printf("依次入对字母A、B、C、D\n");
	printf("判断队列Q是否为空:%d，是否为满:%d\n", QueueEmpty(Q),QueueFull(Q));
	printf("再依次入对字母E:%d、F:%d、G:%d\n", EnQueue(Q, 'G'), EnQueue(Q, 'F'), EnQueue(Q, 'E'));
	printf("判断队列Q是否为满:%d\n", QueueFull(Q));
	GetHead(Q, e);
	printf("取队首元素并输出:%c\n",e);
	printf("依次出队Q的所有元素并显示:");
	while (QueueEmpty(Q) == 0)
	{
		DeQueue(Q, e);
		printf("%c、", e);
	}
	printf("\n释放队列Q\n");
	DestroyQueue(Q);
	return 0;
}