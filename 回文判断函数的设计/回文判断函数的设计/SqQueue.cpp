#include "SqQueue.h"
#include <stdio.h>
#include <stdlib.h>
void InitQueue(SqQueue*& Q)
{
	Q = (SqQueue*)malloc(sizeof(SqQueue));
	Q->front = Q->rear = 0;
}

void DestroyQueue(SqQueue* Q)
{
	free(Q);
}

bool QueueEmpty(SqQueue* Q)
{
	if (Q->front == Q->rear)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool QueueFull(SqQueue* Q)
{
	if (Q->front == (Q->rear + 1) % MAXSIZE)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool EnQueue(SqQueue*& Q, ElemType e)
{
	if (QueueFull(Q) == 1)
	{
		return false;
	}
	else
	{
		Q->data[Q->rear] = e;
		Q->rear = (Q->rear + 1);
		return true;
	}
}

bool DeQueue(SqQueue*& Q, ElemType &e)
{
	if (QueueEmpty(Q) == 1)
	{
		return false;
	}
	else
	{
		e = Q->data[Q->front];
		Q->front = (Q->front + 1) % MAXSIZE;
		return true;
	}
}

bool GetHead(SqQueue*& Q, ElemType& e)
{
	if (QueueEmpty(Q) == 1)
	{
		return false;
	}
	else
	{
		e = Q->data[Q->front];
		return true;
	}
}

