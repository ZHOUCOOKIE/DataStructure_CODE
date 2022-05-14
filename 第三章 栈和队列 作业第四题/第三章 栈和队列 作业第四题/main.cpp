//计算机215 202110244532 周俊安
#include <stdio.h>
#include <stdlib.h>
#include "QNode.h"

int main()
{
	Queue queue, * q;
	q = &queue;
	int e;
	InitQueue(q);
	EnQueue(q, 1);
	EnQueue(q, 2);
	EnQueue(q, 3);
	EnQueue(q, 4);
	EnQueue(q, 5);
	print(q);
	DeQueue(q, e);
	DeQueue(q, e);
	print(q);
	return 0;
}